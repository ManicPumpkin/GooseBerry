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
#include "gooseberry.h"

//==================================================================
//	FUNCTIONS
//==================================================================
namespace GB_Loader
{
	GOOSEBERRY_API GB_Enum::gbResult LoadPngImage(char * name, int * width, int * height, GLuint * texture);
	GOOSEBERRY_API GB_Mesh LoadMeshFile(std::string file, bool is_quad = FALSE);
}