//==================================================================
/**
	@file	cMdl.h
	@brief	This file includes the object which been loaded from
			cMdlLoader

	Includes the model class. Contains all variables needed to
	hold loaded information of object/model files.

	@author	drubner
	@date	2012-11-24
**/
//==================================================================
#ifndef CMDL_H
#define CMDL_H
//==================================================================
//	Includes
//==================================================================
#include "hLibraries.h"
#include "hStructs.h"
//==================================================================
#include "cMat.h"
//==================================================================
//	Class
//==================================================================
/**
	@class	cMdl
	@brief	Contains information about object/model files
**/
//==================================================================
class cMdl
{
	protected:
	private:
		//	Variables
		//	Functions
		VOID fFreeMdl();
		
	public:
		//	Variables
		std::string		mObjName;		//!< object name
		std::string		mObjFile;		//!< object file
		std::string		mMatPath;		//!< material file path
		std::string		mMtllib;		//!< material lib to use
		std::string		mUsemtl;		//!< material to use
		cMat 			mMaterial;		//!< material

		bool			mIsTriangle;	//!< if object is made of triangles, else quads 

		unsigned int	mNumFaces,		//!< number of faces
						mNumVertices,	//!< number of vertices
						mNumNormals,	//!< number of normals
						mNumTexCoords;	//!< number of texture coordinates
		
		grFace *		mFaces;			//!< list of faces
		grVertex *		mVertices;		//!< list of vetices
		grNormal *		mNormals;		//!< list of normals
		grTexCoord *	mTexCoords;		//!< list of texture coordiantes

		//	(De-)Constructor & Copy
		~cMdl();
		cMdl();
		cMdl(const cMdl& tRHS);

		//	Functions
		VOID fDraw();

		//	Get
		//	Set
};
//==================================================================
#endif CMDL_H
//==================================================================