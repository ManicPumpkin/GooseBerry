/**
@file	GB_Loader.cc
@brief	This file includes all loader functions
@author	drubner
@date	Created 2014-03-31
**/
//==================================================================
//	Include
//==================================================================
#include "GB_Loader.h"

//==================================================================
//	Functions
//==================================================================
/**
@fn		GB_Enum::gbResult GB_Loader::LoadPngFile(char * name, int * width, int * height, GLuint * texture)
@brief	Fuction to load an *.png file

Some helpful references:
http://blog.nobel-joergensen.com/2010/11/07/loading-a-png-as-texture-in-opengl-using-libpng/
http://examples.oreilly.de/english_examples/gff/CDROM/SOFTWARE/SOURCE/LIBPNG/EXAMPLE.C

**/
//==================================================================
GOOSEBERRY_API GB_Enum::gbResult GB_Loader::LoadPngFile(char * name, int * width, int * height, GLuint * texture)
{
	GB_LINFO("Loading texture: " + (string)name);
	png_byte		png_header[8];
	FILE			*file_ptr;

	fopen_s(&file_ptr, name, "rb");
	if (file_ptr == NULL)
	{
		GB_LERROR("Could not find texture file to load (" + (string)name + ")", "Unknown");
		return GB_Enum::GB_ERROR;
	}

	fread(png_header, 1, 8, file_ptr);
	if (png_sig_cmp(png_header, 0, 8))
	{
		GB_LERROR("Texture file is not a PNG file", "Unknown");
		fclose(file_ptr);
		return GB_Enum::GB_ERROR;
	}

	png_structp png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
	if (!png_ptr)
	{
		GB_LERROR("PNG_CREATE_READ_STRUCT returned 0", "Unknown");
		fclose(file_ptr);
		return GB_Enum::GB_ERROR;
	}

	png_infop info_ptr = png_create_info_struct(png_ptr);
	if (!info_ptr)
	{
		GB_LERROR("PNG_CREATE_INFO_STRUCT returned 0", "Unknown");
		png_destroy_read_struct(&png_ptr, &info_ptr, (png_infopp)NULL);
		fclose(file_ptr);
		return GB_Enum::GB_ERROR;
	}

	if (int val = setjmp(png_jmpbuf(png_ptr)))
	{
		stringstream str_stream;
		str_stream << val;
		GB_LERROR("Setjmp error: " + str_stream.str(), "Unknown");
		png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
		fclose(file_ptr);
		return GB_Enum::GB_ERROR;
	}

	// init reading of png
	png_init_io(png_ptr, file_ptr);

	// let libpng know you already read the first 8 bytes
	png_set_sig_bytes(png_ptr, 8);

	png_read_png(png_ptr, info_ptr, PNG_TRANSFORM_STRIP_16 | PNG_TRANSFORM_PACKING | PNG_TRANSFORM_EXPAND, NULL);

	png_uint_32 temp_width, temp_height;
	int  bit_depth, color_type;

	png_get_IHDR(png_ptr, info_ptr, &temp_width, &temp_height, &bit_depth, &color_type, NULL, NULL, NULL);
	if (width)
		*width = temp_width;
	if (height)
		*height = temp_height;

	unsigned int row_bytes = png_get_rowbytes(png_ptr, info_ptr);

	png_byte * image_data;
	image_data = (unsigned char*)malloc(row_bytes * temp_height);
	if (image_data == NULL)
	{
		GB_LERROR("Couldn't allocate memory for PNG image data", "Unknown");
		png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
		fclose(file_ptr);
		return GB_Enum::GB_ERROR;
	}

	png_bytepp row_pointers = png_get_rows(png_ptr, info_ptr);
	if (row_pointers == NULL)
	{
		GB_LERROR("Couldn't allocate memory for PNG row pointers", "Unknown");
		png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
		free(image_data);
		fclose(file_ptr);
		return GB_Enum::GB_ERROR;
	}

	for (unsigned int i = 0; i < temp_height; i++)
		memcpy(image_data + (row_bytes * (temp_height - 1 - i)), row_pointers[i], row_bytes);

	GB_LDEBUG("Loading texture " + (string)name + " done.");

	GLuint temp_texture;
	glGenTextures(1, &temp_texture);
	glBindTexture(GL_TEXTURE_2D, temp_texture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, temp_width, temp_height, 0, GL_RGB, GL_UNSIGNED_BYTE, image_data);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	*texture = temp_texture;

	png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
	free(image_data);
	fclose(file_ptr);
	return GB_Enum::GB_OK;
}

//==================================================================
/**
@fn		GB_Loader::LoadMeshFile(std::string file)
@brief	Fuction to load and *.obj file
**/
//==================================================================
GOOSEBERRY_API GB_Enum::gbResult GB_Loader::LoadMeshFile(std::string file, GB_Mesh * mesh, bool is_quad)
{
	GB_Mesh temp_mesh;

	if (is_quad)
		temp_mesh.is_triangle_ = FALSE;

	GB_LDEBUG("\t--> " + file);
	std::ifstream file_stream;
	file_stream.open(file);

	if (file_stream.is_open())
	{
		temp_mesh.msh_file_ = file;
		temp_mesh.msh_name_ = GB_Func::ExtractName(file);
		temp_mesh.msh_path_ = GB_Func::ExtractPath(file);

		std::string buffer, temp, GB_Array[4];
		while (!file_stream.eof())
		{
			ZeroMemory(&buffer, sizeof(std::string));
			std::getline(file_stream, buffer);
			std::istringstream line(buffer);

			if (strncmp("v ", buffer.c_str(), 2) == 0)
				temp_mesh.num_vertices_++;
			else if (strncmp("vt ", buffer.c_str(), 3) == 0)
				temp_mesh.num_tex_coords_++;
			else if (strncmp("vn ", buffer.c_str(), 3) == 0)
				temp_mesh.num_normals_++;
			else if (strncmp("f ", buffer.c_str(), 2) == 0)
				temp_mesh.num_faces_++;
		}

		file_stream.close();

		temp_mesh.faces_		= new GB_Struct::Face[temp_mesh.num_faces_];
		temp_mesh.vertices_		= new GB_Struct::Vertex[temp_mesh.num_vertices_];
		temp_mesh.normals_		= new GB_Struct::Normal[temp_mesh.num_normals_];
		temp_mesh.tex_coords_	= new GB_Struct::TexCoord[temp_mesh.num_tex_coords_];

		file_stream.open(file);
		file_stream.clear();
		if (file_stream.is_open())
		{
			char * token = "/";
			bool has_mat = false;
			for (int v = 0, n = 0, t = 0, f = 0; !file_stream.eof();)
			{
				ZeroMemory(&buffer, sizeof(std::string));
				std::getline(file_stream, buffer);
				std::istringstream line(buffer);
				temp = GB_Array[0] = GB_Array[1] = GB_Array[2] = GB_Array[3] = "NULL";

				if (strncmp("mtllib ", buffer.c_str(), 7) == 0)
				{
					line >> temp >> GB_Array[0];
					temp_mesh.mtl_lib_ = GB_Array[0];
					has_mat = true;
					continue;
				}
				else if (strncmp("usemtl ", buffer.c_str(), 7) == 0)
				{
					line >> temp >> GB_Array[0];
					temp_mesh.mtl_use_ = GB_Array[0];
					continue;
				}
				else if (strncmp("v ", buffer.c_str(), 2) == 0)
				{
					line >> temp >> GB_Array[0] >> GB_Array[1] >> GB_Array[2];
					temp_mesh.vertices_[v].x = (float)atof(GB_Array[0].c_str());
					temp_mesh.vertices_[v].y = (float)atof(GB_Array[1].c_str());
					temp_mesh.vertices_[v].z = (float)atof(GB_Array[2].c_str());
					v++;
					continue;
				}
				else if (strncmp("vt ", buffer.c_str(), 3) == 0)
				{
					line >> temp >> GB_Array[0] >> GB_Array[1];
					temp_mesh.tex_coords_[t].u = (float)atof(GB_Array[0].c_str());
					temp_mesh.tex_coords_[t].v = (float)atof(GB_Array[1].c_str());
					t++;
					continue;
				}
				else if (strncmp("vn ", buffer.c_str(), 3) == 0)
				{
					line >> temp >> GB_Array[0] >> GB_Array[1] >> GB_Array[2];
					temp_mesh.normals_[n].x = (float)atof(GB_Array[0].c_str());
					temp_mesh.normals_[n].y = (float)atof(GB_Array[1].c_str());
					temp_mesh.normals_[n].z = (float)atof(GB_Array[2].c_str());
					n++;
					continue;
				}
				else if (strncmp("f ", buffer.c_str(), 2) == 0)
				{
					if (temp_mesh.num_tex_coords_ == 0)
						token = "//";

					line >> temp >> GB_Array[0] >> GB_Array[1] >> GB_Array[2] >> GB_Array[3];
					std::vector<std::string> strings;
					GB_Func::SplitString(GB_Array[0], strings, token);

					temp_mesh.faces_[f].vertex[0]	= atoi(strings[0].c_str());
					temp_mesh.faces_[f].texcoord[0] = atoi(strings[1].c_str());
					temp_mesh.faces_[f].normal[0]	= atoi(strings[2].c_str());

					strings.clear();
					GB_Func::SplitString(GB_Array[1], strings, token);
					temp_mesh.faces_[f].vertex[1]	= atoi(strings[0].c_str());
					temp_mesh.faces_[f].texcoord[1] = atoi(strings[1].c_str());
					temp_mesh.faces_[f].normal[1]	= atoi(strings[2].c_str());

					strings.clear();
					GB_Func::SplitString(GB_Array[2], strings, token);
					temp_mesh.faces_[f].vertex[2]	= atoi(strings[0].c_str());
					temp_mesh.faces_[f].texcoord[2] = atoi(strings[1].c_str());
					temp_mesh.faces_[f].normal[2]	= atoi(strings[2].c_str());

					if (strcmp("NULL", GB_Array[3].c_str()) == 0)
						temp_mesh.is_triangle_ = TRUE;
					else
					{
						temp_mesh.is_triangle_ = FALSE;

						strings.clear();
						GB_Func::SplitString(GB_Array[3], strings, token);
						temp_mesh.faces_[f].vertex[3]	= atoi(strings[0].c_str());
						temp_mesh.faces_[f].texcoord[3] = atoi(strings[1].c_str());
						temp_mesh.faces_[f].normal[3]	= atoi(strings[2].c_str());
					}

					f++;
				}
			}

			*mesh	= temp_mesh;

			file_stream.close();
			return GB_OK;
		}
		else // \todo include define error str and id
		{
			GB_LERROR("Error while counting properties of file: " + file, "GB_Loader Error");
			return GB_ERROR;
		}
	}
	else // \todo include define error str and id
	{
		GB_LERROR("Error while open file: " + file, "GB_Loader Error");
		return GB_ERROR;
	}
}

//==================================================================
/**
@fn		GB_Loader::LoadMaterialFile(std::string file)
@brief	Fuction to load and *.mtl file
**/
//==================================================================
GOOSEBERRY_API GB_Enum::gbResult GB_Loader::LoadMaterialFile(std::string file, GB_Material * material)
{
	GB_Material temp_mat(file);
	std::ifstream file_stream;
	file_stream.open(file);

	if (file_stream.is_open())
	{
		std::string buffer, temp, texture_file, array[3];
		while (!file_stream.eof())
		{
			ZeroMemory(&buffer, sizeof(std::string));
			std::getline(file_stream, buffer);
			std::istringstream line(buffer);

			if (strncmp("map_Kd ", buffer.c_str(), 7) == 0)
			{
				line >> temp >> texture_file;
				temp_mat.map_kd_ = texture_file;
				continue;
			}

			if (strncmp("illum ", buffer.c_str(), 6) == 0)
			{
				line >> temp >> array[0];
				temp_mat.illum_ = (float)atof(array[0].c_str());
				continue;
			}

			if (strncmp("Ka ", buffer.c_str(), 3) == 0)
			{
				line >> temp >> array[0] >> array[1] >> array[2];
				temp_mat.ambient_[0]	= (float)atof(array[0].c_str());
				temp_mat.ambient_[1]	= (float)atof(array[1].c_str());
				temp_mat.ambient_[2]	= (float)atof(array[2].c_str());
				temp_mat.has_ambient_	= true;
				continue;
			}

			if (strncmp("Kd ", buffer.c_str(), 3) == 0)
			{
				line >> temp >> array[0] >> array[1] >> array[2];
				temp_mat.diffuse_[0]	= (float)atof(array[0].c_str());
				temp_mat.diffuse_[1]	= (float)atof(array[1].c_str());
				temp_mat.diffuse_[2]	= (float)atof(array[2].c_str());
				temp_mat.has_diffuse_	= true;
				continue;
			}

			if (strncmp("Ks ", buffer.c_str(), 3) == 0)
			{
				line >> temp >> array[0] >> array[1] >> array[2];
				temp_mat.specular_[0]	= (float)atof(array[0].c_str());
				temp_mat.specular_[1]	= (float)atof(array[1].c_str());
				temp_mat.specular_[2]	= (float)atof(array[2].c_str());
				temp_mat.has_specular_	= true;
				continue;
			}

			if (strncmp("Ke ", buffer.c_str(), 3) == 0)
			{
				line >> temp >> array[0] >> array[1] >> array[2];
				temp_mat.emissive_[0]	= (float)atof(array[0].c_str());
				temp_mat.emissive_[1]	= (float)atof(array[1].c_str());
				temp_mat.emissive_[2]	= (float)atof(array[2].c_str());
				temp_mat.has_emissive_	= true;
				continue;
			}

			if (strncmp("Tf ", buffer.c_str(), 3) == 0)
			{
				line >> temp >> array[0] >> array[1] >> array[2];
				temp_mat.transmission_[0]	= (float)atof(array[0].c_str());
				temp_mat.transmission_[1]	= (float)atof(array[1].c_str());
				temp_mat.transmission_[2]	= (float)atof(array[2].c_str());
				temp_mat.has_transmission_	= true;
				continue;
			}

			if (strncmp("Ns ", buffer.c_str(), 3) == 0)
			{
				line >> temp >> array[0];
				temp_mat.shininess_		= (float)atof(array[0].c_str());
				continue;
			}

			if (strncmp("Ni ", buffer.c_str(), 3) == 0)
			{
				line >> temp >> array[0];
				temp_mat.index_reflect_ = (float)atof(array[0].c_str());
				continue;
			}
		}

		*material	= temp_mat;
		file_stream.close();
		return GB_OK;
	}
	else // \todo include define error str and id
	{
		GB_LERROR("Error while open material file: " + file, "GB_Loader Error");
		return GB_ERROR;
	}
}

//==================================================================
/**
@fn		GB_Loader::LoadTextureFile(std::string file)
@brief	Fuction to load a texture file
**/
//==================================================================
GOOSEBERRY_API GB_Enum::gbResult GB_Loader::LoadTextureFile(std::string file, int texture_id)
{
	int tex_width, tex_height, tex_n;
	unsigned char * pixel_data	= stbi_load(file.c_str(), &tex_width, &tex_height, &tex_n, 0);

	if (pixel_data == NULL)
	{
		GB_LERROR("Error while open texture file: " + file, "GB_Loader Error");
		return GB_ERROR;
	}
	else
	{
		if (pixel_data == '\0')
		{
			GB_LERROR("Error while loading texture file: " + file, "GB_Loader Error");
			return GB_ERROR;
		}

		unsigned int tex_id = static_cast<unsigned int>(texture_id);
		glBindTexture(GL_TEXTURE_2D, tex_id);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, tex_width, tex_height, 0, GL_RGB, GL_UNSIGNED_BYTE, pixel_data);
		//int error = gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, tex_width, tex_height, GL_RGB, GL_UNSIGNED_BYTE, &pixel_data);
		GB_LDEBUG("\t--> " + file + "; tex_id: " + NumToStr(texture_id)); 
		stbi_image_free(pixel_data);
		return GB_OK;
	}
}