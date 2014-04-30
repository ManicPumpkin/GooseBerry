//==================================================================
/**
@file	GB_Model.cpp
@brief	This file includes all functions of GB_Model class
@author	drubner
@date	2014-04-29
**/
//==================================================================
//	INCLUDE
//==================================================================
#include "gooseberry.h"

//==================================================================
//	FUNCTIONS
//==================================================================
/**
@fn		GB_Model::GB_Model()
@brief	Standardconstructor
**/
//==================================================================
GB_Model::GB_Model()
{
	mesh_		= NULL;
	material_	= NULL;
	texture_	= NULL;
}

//==================================================================
/**
@fn		GB_Model::GB_Model()
@brief	Standardconstructor
**/
//==================================================================
GB_Model :: GB_Model(std::string mesh_file, std::string material_file, std::string texture_file)
{
	mesh_ = &GB_Loader::LoadMeshFile(mesh_file);
	/*material_ =*/ GB_Loader::LoadMaterialFile(material_file);
	/*texture_ = GB_Loader::LoadTextureFile(texture_File);*/
}