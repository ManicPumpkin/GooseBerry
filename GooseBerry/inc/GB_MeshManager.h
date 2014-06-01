//==================================================================
/**
@file	GB_MeshManager.h
@brief	This file includes the GB_MeshManager class
@author	drubner
@date	2014-06-01
**/
//==================================================================
#pragma once

//==================================================================
//	INCLUDE
//==================================================================
#include "gooseberry.h"

//==================================================================
//	DEFINE
//==================================================================
#define MSHMANAGER				GB_MeshManager::GetInstance()
#define MSHMANAGER_INIT_SIZE	16
#define MSHMANAGER_STEP			8

//==================================================================
//	STRUCT
//==================================================================
struct MeMaProperty		//!< stands for mesh manager property
{
	GB_Mesh 	mesh;	//!< mesh object
	int			id;		//!< unique id of mesh
	std::string name;	//!< name of mesh
};

//==================================================================
//	CLASS
//==================================================================
/**
@class	GB_MeshManager
@brief	Contains information about meshes and manage them
**/
//==================================================================
class GOOSEBERRY_API GB_MeshManager
{
protected:
private:
	//	Variables
	static			GB_MeshManager* instance_;
	int				num_meshes_;
	int				ids_;
	int				available_space_;
	MeMaProperty*	meshes_;

	//	Functions
	static void Initialize();
	static void Destroy();
	void Resort();
	void Extend();
	void Reduce();
	
	//	(Standard-/Copy-/De-)Constructor
	GB_MeshManager();
	GB_MeshManager(const GB_MeshManager&){}
	~GB_MeshManager(){}

public:
	//	Funtctions
	GB_Enum::gbResult	LoadMesh(const char *filename, int * mesh_id = NULL, std::string * mesh_name = NULL);
	int					AddMesh(GB_Mesh);
	GB_Enum::gbResult	RemoveMeshByIndex(int index);
	GB_Enum::gbResult	RemoveMeshById(int id);
	GB_Enum::gbResult	RemoveMeshByName(std::string name);
	GB_Enum::gbResult	RemoveAllMeshes();

	//	Get&Set
	static GB_MeshManager* GetInstance()
	{
		if (instance_ == NULL)
		{
			instance_ = new GB_MeshManager();
			Initialize();
		}

		return instance_;
	}

	int GetNumMeshes()							{ return num_meshes_;		}
	int GetAvailableSpace()						{ return available_space_;	}
	int GetNewId()								{ return ids_++;			}
	MeMaProperty GetMshById(int id);
	MeMaProperty GetMshByIndex(int index);
	MeMaProperty GetMshByName(std::string msh_name);
};
