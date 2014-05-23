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
	bb3d_		= NULL;
	texture_nr_ = -1;
}

//==================================================================
/**
@fn		GB_Model(std::string mat_file, GB_Mesh target_mesh)
@brief	Enhanced constructor
**/
//==================================================================
GB_Model :: GB_Model(std::string mat_file, GB_Mesh target_mesh)
{
	/*al_	= new GB_Material();
	texture_	= new GB_Texture();
	texture_nr_ = texture_nr;

	GB_Loader::LoadMeshFile(mesh_file, mesh_);
	GB_Loader::LoadMaterialFile(mesh_->msh_path_ + mesh_->mtl_lib_, material_);
	GB_Loader::LoadTextureFile(material_->mat_path_ + material_->map_kd_, texture_, &texture_nr_);
	*/
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
 	//GB_Loader::LoadTextureFile(material_->mat_path_ + material_->map_kd_, texture_, &texture_nr_);

	// \todo add getter&setter for meshes
	bb3d_			= new GB_BB3D(mesh_->GetVertices(), (int)mesh_->num_vertices_);
}

//==================================================================
/**
@fn		GB_Model::Draw()
@brief	Draw model with mesh, textures and material
**/
//==================================================================
void GB_Model :: Draw()
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture_nr_);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	mesh_->Draw();
	glDisable(GL_TEXTURE_2D);

	if (GB_Settings::BoundingBox::g_show)
		bb3d_->Draw();
}