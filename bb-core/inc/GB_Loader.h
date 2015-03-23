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
//	CLASS PREDEFINITION
//==================================================================
class GB_Mesh;

//==================================================================
//	FUNCTIONS
//==================================================================
namespace GB_Loader
{
	//GOOSEBERRY_API GB_Enum::gbResult LoadPngFile(char * name, int * width, int * height, GLuint * texture);
	GOOSEBERRY_API GB_Enum::gbResult LoadMeshFile(std::string file, GB_Mesh * mesh, bool is_quad = FALSE);
	GOOSEBERRY_API GB_Enum::gbResult LoadMaterialFile(std::string file, GB_Material * material);
	GOOSEBERRY_API GB_Enum::gbResult LoadTextureFile(std::string file, int texture_id);
}