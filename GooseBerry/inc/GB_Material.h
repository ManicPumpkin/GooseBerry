//==================================================================
/**
	@file	Material.h
	@brief	This file includes the Material class
	@author	drubner
	@date	2012-12-02
**/
//==================================================================
#pragma once

//==================================================================
//	INCLUDE
//==================================================================
#include "GooseBerry.h"

//==================================================================
//	CLASS
//==================================================================
/**
	@class	Material
	@brief	Contains information about material files
**/
//==================================================================
class Material
{
	protected:

	private:

	public:
		string	mat_file_;		//!< full material file name
		string	mat_name_;		//!< material name
		string	mat_path_;		//!< material file path
		string	tex_file_;		//!< texture file
		GLuint	texture_;		//!< textures not implemented yet

		float	ambient_[4];	//!< ambient material properties
		float	diffuse_[4];	//!< diffuse material properties
		float	specular_[4];	//!< specular material properties
		float 	emissive_[4];	//!< emissive material properties
		float	shininess_;		//!< shniness of material

		bool	has_ambient_;	//!< flag for ambient material
		bool	has_diffuse_;	//!< flag for diffuse material
		bool	has_specular_;	//!< flag for specular material
		bool	has_emissive_;	//!< flag for emissive material

		//	(De-)Constructor
		Material():shininess_(-1),has_ambient_(false),has_diffuse_(false),has_specular_(false), has_emissive_(false){};
		
		/**
			@fn		Material(string file)
			@brief	Extended constructor
			@param	file		file name and path
		**/
		Material(string file):shininess_(-1),has_ambient_(false),has_diffuse_(false),has_specular_(false), has_emissive_(false)
		{
			this->mat_name_	= GB_Func::ExtractName(file);
			this->mat_path_ = GB_Func::ExtractPath(file);
		}
};