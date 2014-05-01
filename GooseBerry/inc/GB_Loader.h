/**
@file	GB_Loader.h
@brief	Includes loader functions
@author	drubner
@date	2014-03-31
**/
//==================================================================
//	PRAGMA ONCE
//==================================================================
#pragma once

//==================================================================
//	INCLUDE
//==================================================================
#include "..\ext\libpng-1.6.8\png.h"
#include "..\ext\stb_image\stb_image.h"
//#include "stb_image.h"
#include "gooseberry.h"

//==================================================================
//	CLASS PREDEFINITION
//==================================================================
class GB_Mesh;

//==================================================================
//	FUNCTIONS
//==================================================================
namespace GB_Loader
{
	GOOSEBERRY_API GB_Enum::gbResult LoadPngFile(char * name, int * width, int * height, GLuint * texture);
	GOOSEBERRY_API GB_Enum::gbResult LoadMeshFile(std::string file, GB_Mesh * mesh, bool is_quad = FALSE);
	GOOSEBERRY_API GB_Enum::gbResult LoadMaterialFile(std::string file);
	GOOSEBERRY_API GB_Enum::gbResult LoadTextureFile(std::string file, GB_Texture * texture_para, GLuint * texture_nr);
}