//==================================================================
/**
@file	GB_MeshManager.cc
@brief	This file includes all functions of GB_MeshManager class
@author	drubner
@date	2014-06-01
**/
//==================================================================
//	INCLUDE
//==================================================================
#include "GB_MeshManager.h"

//==================================================================
//	INITIALIZE
//==================================================================
GB_MeshManager* GB_MeshManager::instance_ = 0;

//==================================================================
//	FUNCTIONS
//==================================================================
/**
@fn		GB_MeshManager::GB_MeshManager()
@brief	Standardconstructor
**/
//==================================================================
GB_MeshManager::GB_MeshManager()
{
	num_meshes_			= 0;
	available_space_	= 0;
	meshes_				= 0;
	ids_				= 0;
}

//==================================================================
/**
@fn		GB_MeshManager::Initialize()
@brief	Initialize mesh manager
**/
//==================================================================
void GB_MeshManager::Initialize()
{
	GB_LDEBUG("Mesh manager initialized");

	instance_->num_meshes_		= 0;
	instance_->ids_				= 0;
	instance_->available_space_ = MSHMANAGER_INIT_SIZE;
	instance_->meshes_			= new MeMaProperty[MSHMANAGER_INIT_SIZE];

	for (int i = 0; i < MSHMANAGER_INIT_SIZE; i++)
		instance_->meshes_[i].id	= -1;
}

//==================================================================
/**
@fn		GB_MeshManager::Destroy()
@brief	Destroy mesh manager
**/
//==================================================================
void GB_MeshManager::Destroy()
{
	GB_LDEBUG("Mesh manager destroyed");

	if (instance_)
	{
		delete[] instance_->meshes_;
		instance_->meshes_ = NULL;

		delete instance_;
		instance_ = NULL;
	}
}

//==================================================================
/**
@fn		GB_MeshManager::Resort()
@brief	Reorganize queue after removing meshes from queue
**/
//==================================================================
void GB_MeshManager::Resort()
{
	MeMaProperty * meshes	= new MeMaProperty[instance_->available_space_];

	for (int i = 0, index = 0; i < instance_->available_space_; i++)
		if (instance_->meshes_[i].id != -1)
			meshes[index++] = instance_->meshes_[i];

	delete[] instance_->meshes_;
	instance_->meshes_	= meshes;
}

//==================================================================
/**
@fn		GB_MeshManager::Extend()
@brief	Extend queue
**/
//==================================================================
void GB_MeshManager::Extend()
{
	MeMaProperty * meshes = new MeMaProperty[instance_->available_space_ + MSHMANAGER_STEP];

	for (int i = 0, index = 0; i < instance_->available_space_; i++)
		if (instance_->meshes_[i].id != -1)
			meshes[index++] = instance_->meshes_[i];

	instance_->available_space_ += MSHMANAGER_STEP;
	delete[] instance_->meshes_;
	instance_->meshes_	= meshes;
}

//==================================================================
/**
@fn		GB_MeshManager::Reduce()
@brief	Reduce queue
**/
//==================================================================
void GB_MeshManager::Reduce()
{

}

//==================================================================
/**
@fn		GB_MeshManager::LoadMesh(const char *filename, int * mesh_id = NULL, std::string * mesh_name = NULL)
@brief	Load new mesh and add it to queue
**/
//==================================================================
GB_Enum::gbResult GB_MeshManager::LoadMesh(const char *filename, int * mesh_id, std::string * mesh_name)
{
	GB_Mesh temp_mesh;
	bool result		= (GB_OK != GB_Loader::LoadMeshFile(filename, &temp_mesh)) ? false : true;
	if (!result)
		return GB_ERROR;
			
	AddMesh(temp_mesh);
	return GB_OK;
}

//==================================================================
/**
@fn		GB_MeshManager::AddMesh(GB_Mesh)
@brief	Add mesh to queue
**/
//==================================================================
int GB_MeshManager::AddMesh(GB_Mesh mesh)
{
	Resort();
	if (instance_->num_meshes_ + 1 >= instance_->available_space_)
		Extend();

	int index = 0;
	while (instance_->meshes_[index].id == -1)
		index++;

	int id							= GetNewId();
	instance_->meshes_[index].id	= id;
	instance_->meshes_[index].name	= mesh.msh_name_;
	instance_->meshes_[index].mesh	= mesh;
	instance_->num_meshes_++;

	return id;
}

//==================================================================
/**
@fn		GB_MeshManager::RemoveMeshByIndex(int index);
@brief	Remove mesh by index from queue
**/
//==================================================================
GB_Enum::gbResult GB_MeshManager::RemoveMeshByIndex(int index)
{
	if (index >= instance_->available_space_ || index <= -1)
		return GB_ERROR;

	GB_Mesh	override_mesh;
	instance_->meshes_[index].mesh = override_mesh;
	instance_->meshes_[index].id = -1;
	instance_->meshes_[index].name = "";
	instance_->num_meshes_--;
	Resort();
	return GB_OK;
}

//==================================================================
/**
@fn		GB_MeshManager::RemoveMeshById(int id)
@brief	Remove mesh by id from queue
**/
//==================================================================
GB_Enum::gbResult GB_MeshManager::RemoveMeshById(int id)
{
	for (int i = 0; i < instance_->available_space_; i++)
	{
		if (instance_->meshes_[i].id == id)
		{
			GB_Mesh	override_mesh;
			instance_->meshes_[i].id	= -1;
			instance_->meshes_[i].name	= "";
			instance_->meshes_[i].mesh	= override_mesh;
			instance_->num_meshes_--;
			Resort();
			return GB_OK;
		}
	}

	return GB_NOTFOUND;
}


//==================================================================
/**
@fn		GB_MeshManager::RemoveMeshByName(std::string name)
@brief	Remove mesh by name from queue
**/
//==================================================================
GB_Enum::gbResult GB_MeshManager::RemoveMeshByName(std::string name)
{
	for (int i = 0; i < instance_->available_space_; i++)
	{
		if (instance_->meshes_[i].name == name)
		{
			GB_Mesh	override_mesh;
			instance_->meshes_[i].id = -1;
			instance_->meshes_[i].name = "";
			instance_->meshes_[i].mesh = override_mesh;
			instance_->num_meshes_--;
			Resort();
			return GB_OK;
		}
	}

	return GB_NOTFOUND;
}

//==================================================================
/**
@fn		GB_MeshManager::RemoveAllMeshes()
@brief	Remove all meshes from queue
**/
//==================================================================
GB_Enum::gbResult GB_MeshManager::RemoveAllMeshes()
{
	delete[] instance_->meshes_;

	instance_->meshes_			= new MeMaProperty[MSHMANAGER_INIT_SIZE];
	instance_->available_space_	= MSHMANAGER_INIT_SIZE;
	instance_->num_meshes_		= 0;
	instance_->ids_				= 0;

	for (int i = 0; i < MSHMANAGER_INIT_SIZE; i++)
	{
		instance_->meshes_[i].id	= -1;
		instance_->meshes_[i].name	= "";
	}

	return GB_OK;
}

//==================================================================
/**
@fn		MeMaProperty GetMshById(int id)
@brief	Get mesh mananger property by id
**/
//==================================================================
MeMaProperty GB_MeshManager::GetMshById(int id)
{
	for (int i = 0; i < instance_->available_space_; i++)
		if (instance_->meshes_[i].id == id)
			return instance_->meshes_[i];

	MeMaProperty return_value;
	return return_value;
}

//==================================================================
/**
@fn		MeMaProperty GetMshByIndex(int index)
@brief	Get mesh mananger property by id
**/
//==================================================================
MeMaProperty GB_MeshManager::GetMshByIndex(int index)
{
	MeMaProperty return_value;
	if (index >= instance_->available_space_ || index <= -1)
		return return_value;
	
	return instance_->meshes_[index];
}

//==================================================================
/**
@fn		MeMaProperty GetMshByName(std::string msh_name)
@brief	Get mesh mananger property by id
**/
//==================================================================
MeMaProperty GB_MeshManager::GetMshByName(std::string msh_name)
{
	for (int i = 0; i < instance_->available_space_; i++)
	if (instance_->meshes_[i].name == msh_name)
		return instance_->meshes_[i];

	MeMaProperty return_value;
	return return_value;
}