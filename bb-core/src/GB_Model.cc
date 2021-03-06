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
GB_Model :: GB_Model(std::string mesh_file, int texture_nr)
{
	mesh_				= new GB_Mesh();
	material_			= new GB_Material();
	texture_nr_			= texture_nr;

	has_mesh_			= (GB_OK != GB_Loader::LoadMeshFile(mesh_file, mesh_)) ? false : true;
	if (!has_mesh_)
		return;

	has_material_		= (GB_OK != GB_Loader::LoadMaterialFile(mesh_->msh_path_ + mesh_->mtl_lib_, material_)) ? false : true;
	if (has_material_ && texture_nr_ == -1)
		TEXMANAGER->LoadTexture((material_->mat_path_ + material_->map_kd_).c_str(), &texture_nr_);

	has_texture_ = (texture_nr_ != -1) ? true : false;

	// \todo add getter&setter for meshes
	if (has_mesh_)
		bb3d_		= new GB_BB3D(mesh_->GetVertices(), (int)mesh_->num_vertices_);
}

//==================================================================
/**
@fn		GB_Model::GB_Model(int texture_nr, GB_Mesh mesh)
@brief	Enhanced constructor
**/
//==================================================================
GB_Model::GB_Model(GB_Mesh * mesh, int texture_nr)
{
	mesh_			= mesh;
	material_		= NULL;				// \todo add material
	texture_nr_		= texture_nr;
	has_mesh_		= true;
	has_texture_	= true;
	has_material_	= false;			// \todo add material
	
	bb3d_ = new GB_BB3D(mesh_->GetVertices(), (int)mesh_->num_vertices_);
}

//==================================================================
/**
@fn		GB_Model::GB_Model(int texture_nr, const char * mesh_name)
@brief	Enhanced constructor
**/
//==================================================================
GB_Model::GB_Model(int texture_nr, const char * mesh_name)
{
	// \todo add constructor
	return;
}

//==================================================================
/**
@fn		GB_Model::Draw()
@brief	Draw model with mesh, textures and material
**/
//==================================================================
GB_Enum::gbResult GB_Model :: Draw()
{
	if (!has_mesh_)
		return GB_ERROR;

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

	return GB_OK;
}