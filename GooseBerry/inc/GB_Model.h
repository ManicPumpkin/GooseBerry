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
//	INCLUDE
//==================================================================
#include "gooseberry.h"
class GB_BB3D;
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
		GB_Mesh		* mesh_;		//!< mesh of model
		GB_Material	* material_;	//!< material of model
		GB_Texture  * texture_;		//!< texture of model
		GB_BB3D     * bb3d_;

		GLuint		texture_nr_;	//!< number of texture

		bool		has_texture_;	//!< flag for texture 
		bool		has_mesh_;		//!< flag of mesh
		bool		has_material_;	//!< flag of meterial

		//	Functions
		void	Draw();

		//	(De-)Constructor
		GB_Model();
		GB_Model(std::string mesh_file, GLuint texture_nr);
};