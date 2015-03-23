//==================================================================
/**
@file	GB_Model.h
@brief	This file includes the Model class
@author	drubner
@date	2014-04-29
**/
//==================================================================
#pragma once

//==================================================================
//	CLASS
//==================================================================
/**
@class	GB_Model
@brief	Contains information about model files
**/
//==================================================================
class GOOSEBERRY_API GB_Model
{
	protected:

	private:

	public:
		GB_Mesh		*		mesh_;			//!< mesh of model
		GB_Material	*		material_;		//!< material of model
		GB_BB3D     *		bb3d_;

		int					texture_nr_;	//!< number of texture to use

		bool				has_texture_;	//!< flag for texture 
		bool				has_mesh_;		//!< flag of mesh
		bool				has_material_;	//!< flag of meterial

		//	Functions
		GB_Enum::gbResult	Draw();

		//	(De-)Constructor
		GB_Model();
		GB_Model(std::string mat_file, GB_Mesh target_mesh);
		GB_Model(std::string mesh_file, int texture_nr = -1);
		GB_Model(GB_Mesh * mesh, int texture_nr);
		GB_Model(int texture_nr, const char * mesh_name = "cube");
};