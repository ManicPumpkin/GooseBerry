//==================================================================
/**
	@file	GB_Material.h
	@brief	This file includes the Material class
	@author	drubner
	@date	2012-12-02
**/
//==================================================================
#pragma once

//==================================================================
//	INCLUDE
//==================================================================
#include "gooseberry.h"

//==================================================================
//	CLASS
//==================================================================
/**
	@class	GB_Material
	@brief	Contains information about material files
**/
//==================================================================
class GB_Material
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
		GB_Material() :shininess_(-1), has_ambient_(false), has_diffuse_(false), has_specular_(false), has_emissive_(false){};
		
		/**
			@fn		Material(string file)
			@brief	Extended constructor
			@param	file		file name and path
		**/
		GB_Material(string file) :shininess_(-1), has_ambient_(false), has_diffuse_(false), has_specular_(false), has_emissive_(false)
		{
			this->mat_name_	= GB_Func::ExtractName(file);
			this->mat_path_ = GB_Func::ExtractPath(file);
			this->mat_file_ = GB_Func::ExtractFile(file);
		}

		//	Set&Get
		void SetMatName(string mat_name)
		{
			if (strncmp("./", mat_name.c_str(), 2) == 0	||
				strncmp(".\\", mat_name.c_str(), 2) == 0	||
				strncmp("/", mat_name.c_str(), 1) == 0		||
				strncmp("\\", mat_name.c_str(), 1) == 0	)
				this->mat_name_ = GB_Func::ExtractName(mat_name);
			else
				this->mat_name_ = mat_name;
		}

		void SetMatPath(string mat_path)
		{
			if (strncmp("./", mat_path.c_str(), 2) == 0		||
				strncmp(".\\", mat_path.c_str(), 2) == 0	||
				strncmp("/", mat_path.c_str(), 1) == 0		||
				strncmp("\\", mat_path.c_str(), 1) == 0		)
				this->mat_path_ = GB_Func::ExtractPath(mat_path);
			else
				this->mat_path_ = mat_path;
		}

		void SetMatFile(string mat_file)
		{
			if (strncmp("./", mat_file.c_str(), 2) == 0		||
				strncmp(".\\", mat_file.c_str(), 2) == 0	||
				strncmp("/", mat_file.c_str(), 1) == 0		||
				strncmp("\\", mat_file.c_str(), 1) == 0		)
				this->mat_file_ = GB_Func::ExtractFile(mat_file);
			else
				this->mat_file_ = mat_file;
		}

		string GetMatName()		{ return this->mat_name_;  }
		string GetMatPath()		{ return this->mat_path_; }
		string GetMatFile()		{ return this->mat_file_; }
};