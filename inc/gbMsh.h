//==================================================================
/**
	@file	gbMsh.h
	@brief	This file includes the object which been loaded from
			gbMshLoader

	Includes the model class. Contains all variables needed to
	hold loaded information of object/model files.

	@author	drubner
	@date	2013-07-31
**/
//==================================================================
#pragma once
#pragma warning(disable: 4251)

//==================================================================
//	Includes
//==================================================================
#include "GooseBerry.h"
//#include "gbMat.h"

//==================================================================
//	Structs
//==================================================================
struct gb_g_vertex					//! Vertex struct with coordinates
{
	float	x,						//!< x-coordinate
			y,						//!< y-coordinate
			z;						//!< z-coordinate
};	

typedef gb_g_vertex gb_g_normal;	//! Normal struct with coordiantes

struct gb_g_texCoord				//! Texture struct with coordinates
{
	float	u,						//!< u-coordinate
			v;						//!< v-coordinate
};

struct gb_g_face					//! Face struct
{
	unsigned int	vertex[4],		//!< vertex indices of face
					normal[4],		//!< normal indices of face
					texcoord[4];	//!< texture indices of face
};

//==================================================================
//	Class
//==================================================================
/**
	@class	gbMsh
	@brief	Contains information about object/model files
**/
//==================================================================
class GOOSEBERRY_API gbMsh
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
		std::string		u_semtl;		//!< material to use
		gbMat 			mMaterial;		//!< material

		bool			mIsTriangle;	//!< if object is made of triangles, else quads 

		unsigned int	mNumFaces,		//!< number of faces
						mNuv_ertices,	//!< number of vertices
						mNumNormals,	//!< number of normals
						mNumTexCoords;	//!< number of texture coordinates
		
		gb_g_face *		mFaces;			//!< list of faces
		gb_g_vertex *	v_ertices;		//!< list of vetices
		gb_g_normal *	mNormals;		//!< list of normals
		gb_g_texCoord *	mTexCoords;		//!< list of texture coordiantes

		//	(De-)Constructor & Coy
		~gbMsh();
		gbMsh();
		gbMsh(const gbMsh& tRHS);

		//	Functions
		VOID fDraw();

		//	Get
		//	Set
};