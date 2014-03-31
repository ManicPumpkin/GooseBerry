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

	/*
	png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
	if (png_ptr == NULL)
	{
	fclose(file_ptr);
	return GB_Enum::GB_ERROR;
	}

	info_ptr = png_create_info_struct(png_ptr);
	if (info_ptr == NULL)
	{
	fclose(file_ptr);
	return GB_Enum::GB_ERROR;
	}

	if (setjmp(png_jmpbuf(png_ptr)))
	{
	png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
	fclose(file_ptr);
	return GB_Enum::GB_ERROR;
	}

	png_init_io(png_ptr, file_ptr);
	png_set_sig_bytes(png_ptr, sig_read);

	png_read_png(png_ptr, info_ptr, PNG_TRANSFORM_STRIP_16 | PNG_TRANSFORM_PACKING | PNG_TRANSFORM_EXPAND, NULL);
	png_uint_32 width, height;
	int bit_depth;
	png_get_IHDR(png_ptr, info_ptr, &width, &height, &bit_depth, &color_type, &interlace_type, NULL, NULL);
	outer_width = width;
	outer_height = height;
	unsigned int row_bytes = png_get_rowbytes(png_ptr, info_ptr);
	*out_data = (unsigned char*)malloc(row_bytes * outer_height);
	png_bytepp row_ptrs = png_get_rows(png_ptr, info_ptr);

	for (int i = 0; i < outer_height; i++)
	memcpy(*out_data + (row_bytes * (outer_height - 1 - i)), row_ptrs[i], row_bytes);

	png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
	fclose(file_ptr);

	return GB_Enum::GB_OK;
	*/
}

//==================================================================
/**
@fn		GB_Loader::LoadMeshFile(std::string file)
@brief	Fuction to load and *.obj file
**/
//==================================================================
GOOSEBERRY_API GB_Mesh GB_Loader::LoadMeshFile(std::string file, bool is_quad)
{
	GB_Mesh model;

	if (is_quad)
		model.is_triangle_ = FALSE;

	std::ifstream file_stream;
	file_stream.open(file);

	if (file_stream.is_open())
	{
		GB_LINFO("Count properties of GB_Object file: " + file);

		model.obj_file_ = file;
		model.obj_name_ = GB_Func::ExtractName(file);
		model.mat_path_ = GB_Func::ExtractName(file);

		std::string buffer, temp, GB_Array[4];
		while (!file_stream.eof())
		{
			ZeroMemory(&buffer, sizeof(std::string));
			std::getline(file_stream, buffer);
			std::istringstream line(buffer);

			if (strncmp("v ", buffer.c_str(), 2) == 0)
				model.num_vertices_++;
			else if (strncmp("vt ", buffer.c_str(), 3) == 0)
				model.num_tex_coords_++;
			else if (strncmp("n ", buffer.c_str(), 3) == 0)
				model.num_normals_++;
			else if (strncmp("f ", buffer.c_str(), 2) == 0)
				model.num_faces_++;
		}

		file_stream.close();

		model.faces_ = new GB_Struct::Face[model.num_faces_];
		model.vertices_ = new GB_Struct::Vertex[model.num_vertices_];
		model.normals_ = new GB_Struct::Normal[model.num_normals_];
		model.tex_coords_ = new GB_Struct::TexCoord[model.num_tex_coords_];

		file_stream.open(file);
		file_stream.clear();
		if (file_stream.is_open())
		{
			GB_LINFO("Parse GB_Object file: " + file);

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
					model.mtl_lib_ = GB_Array[0];
					has_mat = true;
					continue;
				}
				else if (strncmp("usemtl ", buffer.c_str(), 7) == 0)
				{
					line >> temp >> GB_Array[0];
					model.mtl_use_ = GB_Array[0];
					continue;
				}
				else if (strncmp("v ", buffer.c_str(), 2) == 0)
				{
					line >> temp >> GB_Array[0] >> GB_Array[1] >> GB_Array[2];
					model.vertices_[v].x = (float)atof(GB_Array[0].c_str());
					model.vertices_[v].y = (float)atof(GB_Array[1].c_str());
					model.vertices_[v].z = (float)atof(GB_Array[2].c_str());
					v++;
					continue;
				}
				else if (strncmp("vt ", buffer.c_str(), 3) == 0)
				{
					line >> temp >> GB_Array[0] >> GB_Array[1];
					model.tex_coords_[t].u = (float)atof(GB_Array[0].c_str());
					model.tex_coords_[t].v = (float)atof(GB_Array[1].c_str());
					t++;
					continue;
				}
				else if (strncmp("n ", buffer.c_str(), 3) == 0)
				{
					line >> temp >> GB_Array[0] >> GB_Array[1] >> GB_Array[2];
					model.normals_[n].x = (float)atof(GB_Array[0].c_str());
					model.normals_[n].y = (float)atof(GB_Array[1].c_str());
					model.normals_[n].z = (float)atof(GB_Array[2].c_str());
					n++;
					continue;
				}
				else if (strncmp("f ", buffer.c_str(), 2) == 0)
				{
					if (model.num_tex_coords_ == 0)
						token = "//";

					line >> temp >> GB_Array[0] >> GB_Array[1] >> GB_Array[2] >> GB_Array[3];
					std::vector<std::string> strings;
					GB_Func::SplitString(GB_Array[0], strings, token);

					model.faces_[f].vertex[0] = atoi(strings[0].c_str());
					model.faces_[f].texcoord[0] = atoi(strings[1].c_str());
					model.faces_[f].normal[0] = atoi(strings[2].c_str());

					strings.clear();
					GB_Func::SplitString(GB_Array[1], strings, token);
					model.faces_[f].vertex[1] = atoi(strings[0].c_str());
					model.faces_[f].texcoord[1] = atoi(strings[1].c_str());
					model.faces_[f].normal[1] = atoi(strings[2].c_str());

					strings.clear();
					GB_Func::SplitString(GB_Array[2], strings, token);
					model.faces_[f].vertex[2] = atoi(strings[0].c_str());
					model.faces_[f].texcoord[2] = atoi(strings[1].c_str());
					model.faces_[f].normal[2] = atoi(strings[2].c_str());

					if (strcmp("NULL", GB_Array[3].c_str()) == 0)
						model.is_triangle_ = TRUE;
					else
					{
						model.is_triangle_ = FALSE;

						strings.clear();
						GB_Func::SplitString(GB_Array[3], strings, token);
						model.faces_[f].vertex[3] = atoi(strings[0].c_str());
						model.faces_[f].texcoord[3] = atoi(strings[1].c_str());
						model.faces_[f].normal[3] = atoi(strings[2].c_str());
					}

					f++;
				}
			}

			file_stream.close();

			/*
			if(has_mat)
			{
			MaterialLoader tMatLoader;
			model.material_ = tMatLoader.fLoadMat(model.mat_path_ + model.mtl_lib_);
			}
			*/
			/*
			glGenBuffers(1, &model.v_ertexID);
			glBindBuffer(GL_GB_Array_BUFFER, model.v_ertexID);
			glBufferData(GL_GB_Array_BUFFER, model.num_vertices_ * sizeof(grVertex), model.vertices_, GL_STATIC_DRAW);

			glGenBuffers(1, &model.mIndexID);
			glBindBuffer(GL_ELEMENT_GB_Array_BUFFER, model.mIndexID);
			glBufferData(GL_ELEMENT_GB_Array_BUFFER, model.num_faces_ * sizeof(grFace), model.faces_, GL_STATIC_DRAW);
			*/
		}
		else // \todo include define error str and id
			GB_LERROR("Error while counting properties of file: " + file, "GB_MeshLoader Error");
	}
	else // \todo include define error str and id
		GB_LERROR("Error while open file: " + file, "GB_MeshLoader Error");

	return model;
}
