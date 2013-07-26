//==================================================================
/**
	@file	cMat.h
	@brief	This file includes the cMat class
	@author	drubner
	@date	2012-12-02
**/
//==================================================================
#ifndef CMAT_H
#define CMAT_H
//==================================================================
//	Includes
//==================================================================
#include "hLibraries.h"
#include "hGlobal.h"
//==================================================================
//	Class
//==================================================================
/**
	@class	cMat
	@brief	Contains information about material files
**/
//==================================================================
class cMat
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
		cMat():mShininess(-1),mHasAmbient(false),mHasDiffuse(false),mHasSpecular(false), mHasEmissive(false){};
		cMat(string pFile):mShininess(-1),mHasAmbient(false),mHasDiffuse(false),mHasSpecular(false), mHasEmissive(false)
		{
			this->mMatName	= cGlobal::gExtractName(pFile);
			this->mMatPath	= cGlobal::gExtractPath(pFile);
		}
};
//==================================================================
#endif CMAT_H
//==================================================================