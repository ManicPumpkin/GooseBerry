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
	texture_nr_ = -1;
}

//==================================================================
/**
@fn		GB_Model::GB_Model(std::string mesh_file, GLuint texture_nr)
@brief	Enhanced constructor
**/
//==================================================================
GB_Model :: GB_Model(std::string mesh_file, GLuint texture_nr)
{
	mesh_			= new GB_Mesh();
	material_		= new GB_Material();
	texture_		= new GB_Texture();
	texture_nr_		= texture_nr;

	GB_Loader::LoadMeshFile(mesh_file, mesh_);
	GB_Loader::LoadMaterialFile(mesh_->msh_path_ + mesh_->mtl_lib_, material_);
 	GB_Loader::LoadTextureFile(material_->mat_path_ + material_->map_kd_, texture_, &texture_nr_);
}