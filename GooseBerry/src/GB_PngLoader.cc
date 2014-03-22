/**
@file	GB_PngLoader.h
@brief	Includes png loader
@author	drubner
@date	2014-01-19
**/
//==================================================================

//==================================================================
//	INCLUDE
//==================================================================
#include "GB_PngLoader.h"

//	Some helpful references:
//	http://blog.nobel-joergensen.com/2010/11/07/loading-a-png-as-texture-in-opengl-using-libpng/
//	http://examples.oreilly.de/english_examples/gff/CDROM/SOFTWARE/SOURCE/LIBPNG/EXAMPLE.C

//==================================================================
//	FUNCTIONS
//==================================================================
GOOSEBERRY_API GB_Enum::gbResult LoadPngImage(char * name, int * width, int * height, GLuint * texture)
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