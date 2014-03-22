/**
@file	GB_PngLoader.h
@brief	Includes png loader
@author	drubner
@date	2014-01-19
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
GOOSEBERRY_API GB_Enum::gbResult LoadPngImage(char * name, int * width, int * height, GLuint * texture);