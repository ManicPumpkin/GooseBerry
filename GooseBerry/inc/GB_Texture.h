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
		string	tex_file_;			//!< texture file
		string	tex_name_;			//!< name of texture
		string  tex_path_;			//!< path to texture
		int		tex_number_;		//!< number of texture (GL)
		//unsigned char * texture_;	//!< textures not implemented yet

		//	(De-)Constructor
		GB_Texture(){};

		/**
		@fn		GB_Texture(string file, int number)
		@brief	Extended constructor
		@param	file		file name and path
		@param  number		number of texture
		**/
		GB_Texture(string file, int number)
		{
			this->tex_file_ = GB_Func::ExtractFile(file);
			this->tex_name_ = GB_Func::ExtractName(file);
			this->tex_path_ = GB_Func::ExtractPath(file);
			tex_number_		= number;
		}

		/**
		@fn		operator= (GB_Texture const& right)
		@brief	Overloader operator=
		@param	right	right term of equation
		@param  this	GB_Texture object with copied values
		**/
		GB_Texture operator= (GB_Texture const& right)
		{
			this->tex_file_		= right.tex_file_;
			this->tex_name_		= right.tex_name_;
			this->tex_path_		= right.tex_path_;
			this->tex_number_	= right.tex_number_;

			return *this;
		}
};