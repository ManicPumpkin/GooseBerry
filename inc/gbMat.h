//==================================================================
/**
	@file	gbMat.h
	@brief	This file includes the gbMat class
	@author	drubner
	@date	2012-12-02
**/
//==================================================================
#pragma once

//==================================================================
//	Includes
//==================================================================
#include "GooseBerry.h"

//==================================================================
//	Class
//==================================================================
/**
	@class	gbMat
	@brief	Contains information about material files
**/
//==================================================================
class gbMat
{
	protected:

	private:

	public:
		string	mMatFile;		//!< full material file name
		string	mMatName;		//!< material name
		string	mMatPath;		//!< material file path
		string	mTexFile;		//!< texture file
		GLuint	mTexture;		//!< textures not implemented yet

		float	mAmbient[4];	//!< ambient material properties
		float	mDiffuse[4];	//!< diffuse material properties
		float	mSpecular[4];	//!< specular material properties
		float 	mEmissive[4];	//!< emissive material properties
		float	mShininess;		//!< shniness of material

		bool	mHasAmbient;	//!< flag for ambient material
		bool	mHasDiffuse;	//!< flag for diffuse material
		bool	mHasSpecular;	//!< flag for specular material
		bool	mHasEmissive;	//!< flag for emissive material

		//	(De-)Constructor
		gbMat():mShininess(-1),mHasAmbient(false),mHasDiffuse(false),mHasSpecular(false), mHasEmissive(false){};
		
		/**
			@fn		gbMat(string pFile)
			@brief	Extended constructor
			@param	pFile		file name and path
		**/
		gbMat(string pFile):mShininess(-1),mHasAmbient(false),mHasDiffuse(false),mHasSpecular(false), mHasEmissive(false)
		{
			this->mMatName	= gbGlobal::ExtractName(pFile);
			this->mMatPath	= gbGlobal::ExtractPath(pFile);
		}
};