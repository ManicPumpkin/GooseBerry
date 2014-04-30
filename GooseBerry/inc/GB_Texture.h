//==================================================================
/**
@file	GB_Texture.h
@brief	This file includes the Texture class
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
@class	GB_Texture
@brief	Contains information about texture files
**/
//==================================================================
class GB_Texture
{
	protected:

	private:

	public:
		string	tex_file_;		//!< texture file
		string	tex_name_;		//!< name of texture
		string  tex_path_;		//!< path to texture
		void *	texture_;		//!< textures not implemented yet

		bool	has_texture_;	//!< flag for texture 

		//	(De-)Constructor
		GB_Texture() : has_texture_(false) {};

		/**
		@fn		Material(string file)
		@brief	Extended constructor
		@param	file		file name and path
		**/
		GB_Texture(string file) : has_texture_(false)
		{
			this->tex_name_ = GB_Func::ExtractName(file);
			this->tex_path_ = GB_Func::ExtractPath(file);
		}
};