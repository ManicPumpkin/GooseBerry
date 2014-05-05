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
		string	mat_file_;			//!< full material file name
		string	mat_name_;			//!< material name
		string  mat_path_;			//!< path of file
		string	map_kd_;			//!< texture file

		float	ambient_[3];		//!< ambient material properties
		float	diffuse_[3];		//!< diffuse material properties
		float	specular_[3];		//!< specular material properties
		float 	emissive_[3];		//!< emissive material properties
		float	transmission_[3];	//!< transmission color (only specified color is able to pass through the object)
		float	shininess_;			//!< shininess of material (specular exponent)
		float   illum_;				//!< illumination of material
		float   index_reflect_;		//!< index of reflection

		bool	has_ambient_;		//!< flag for ambient material
		bool	has_diffuse_;		//!< flag for diffuse material
		bool	has_specular_;		//!< flag for specular material
		bool	has_emissive_;		//!< flag for emissive material
		bool	has_transmission_;	//!< flag for transmission material

		//	(De-)Constructor
		GB_Material() :shininess_(-1), has_ambient_(false), has_diffuse_(false), has_specular_(false), has_emissive_(false), has_transmission_(false) {};
		
		/**
			@fn		Material(string file)
			@brief	Extended constructor
			@param	file		file name and path
		**/
		GB_Material(string file) :shininess_(-1), has_ambient_(false), has_diffuse_(false), has_specular_(false), has_emissive_(false), has_transmission_(false)
		{
			this->mat_name_	= GB_Func::ExtractName(file);
			this->mat_file_ = GB_Func::ExtractFile(file);
			this->mat_path_ = GB_Func::ExtractPath(file);
		}

		/**
		@fn		operator= (GB_Material const& right)
		@brief	Overload operator=
		@param	right	right term of equation
		@param  this	GB_Material object with copied values
		**/
		GB_Material operator= (GB_Material const& right)
		{
			this->mat_file_			= right.mat_file_;
			this->mat_name_			= right.mat_name_;
			this->mat_path_			= right.mat_path_;
			this->map_kd_			= right.map_kd_;
			this->shininess_		= right.shininess_;
			this->illum_			= right.illum_;
			this->index_reflect_	= right.index_reflect_;

			for (int i = 0; i < sizeof(right.ambient_); i++)
				ambient_[i] = right.ambient_[i];

			for (int i = 0; i < sizeof(right.diffuse_); i++)
				diffuse_[i] = right.diffuse_[i];

			for (int i = 0; i < sizeof(right.specular_); i++)
				specular_[i] = right.specular_[i];

			for (int i = 0; i < sizeof(right.emissive_); i++)
				emissive_[i] = right.emissive_[i];

			for (int i = 0; i < sizeof(right.transmission_); i++)
				transmission_[i] = right.transmission_[i];

			this->has_ambient_		= right.has_ambient_;
			this->has_diffuse_		= right.has_diffuse_;
			this->has_emissive_		= right.has_emissive_;
			this->has_specular_		= right.has_specular_;
			this->has_transmission_	= right.has_transmission_;

			return *this;
		}

		//	Set&Get
		void SetMatName(string mat_name)
		{
			if (strncmp("./", mat_name.c_str(), 2) == 0		||
				strncmp(".\\", mat_name.c_str(), 2) == 0	||
				strncmp("/", mat_name.c_str(), 1) == 0		||
				strncmp("\\", mat_name.c_str(), 1) == 0	)
				this->mat_name_ = GB_Func::ExtractName(mat_name);
			else
				this->mat_name_ = mat_name;
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
		string GetMatFile()		{ return this->mat_file_; }
};