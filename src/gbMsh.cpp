//==================================================================
/**
		@file	gbMsh.cpp
		@brief	This file includes all functions of gbMsh class
		@author	drubner
		@date	2013-07-31
**/
//==================================================================
//	Include
//==================================================================
#include "gbMsh.h"

//==================================================================
//	Functions
//==================================================================
/**
		@fn		gbMsh::gbMsh()
		@brief	Standardconstructor
**/
//==================================================================
gbMsh::gbMsh()
{
	mNuv_ertices	= 0;
	mNumNormals		= 0;
	mNumTexCoords	= 0;
	mNumFaces		= 0;
	mIsTriangle		= TRUE;
	mFaces			= NULL;
	v_ertices		= NULL;
	mNormals		= NULL;
	mTexCoords		= NULL;
}

//==================================================================
/**
		@fn		gbMsh::gbMsh(const gbMsh& tRHS)
		@brief	coy constructor for deep coy

				Deep coy an gbMsh object with another.
**/
//==================================================================
gbMsh::gbMsh(const gbMsh& tRHS)
{
	this->mObjName		= tRHS.mObjName;
	this->mObjFile		= tRHS.mObjFile;
	this->mMtllib		= tRHS.mMtllib;
	this->u_semtl		= tRHS.u_semtl;
	this->mIsTriangle	= tRHS.mIsTriangle;
	this->mNumFaces		= tRHS.mNumFaces;
	this->mNuv_ertices	= tRHS.mNuv_ertices;
	this->mNumNormals	= tRHS.mNumNormals;
	this->mNumTexCoords	= tRHS.mNumTexCoords;
	//this->mMaterial		= tRHS.mMaterial;

	mFaces		= new gb_g_face[mNumFaces];
	v_ertices	= new gb_g_vertex[mNuv_ertices];
	mNormals	= new gb_g_normal[mNumNormals];
	mTexCoords	= new gb_g_texCoord[mNumTexCoords];

	for(unsigned int tI = 0; tI < mNumFaces; tI++)
	{
		for(int tJ = 0; tJ < 4; tJ++)
		{
			mFaces[tI].vertex[tJ]	= tRHS.mFaces[tI].vertex[tJ];
			mFaces[tI].normal[tJ]	= tRHS.mFaces[tI].normal[tJ];
			mFaces[tI].texcoord[tJ]	= tRHS.mFaces[tI].texcoord[tJ];
		}
	}

	for(unsigned int tI = 0; tI < mNuv_ertices; tI++)
	{
		v_ertices[tI].x	= tRHS.v_ertices[tI].x;
		v_ertices[tI].y	= tRHS.v_ertices[tI].y;
		v_ertices[tI].z	= tRHS.v_ertices[tI].z;
	}

	for(unsigned int tI = 0; tI < mNumNormals; tI++)
	{
		mNormals[tI].x	= tRHS.mNormals[tI].x;
		mNormals[tI].y	= tRHS.mNormals[tI].y;
		mNormals[tI].z	= tRHS.mNormals[tI].z;
	}

	for(unsigned int tI = 0; tI < mNumTexCoords; tI++)
	{
		mTexCoords[tI].u	= tRHS.mTexCoords[tI].u;
		mTexCoords[tI].v	= tRHS.mTexCoords[tI].v;
	}
}

//==================================================================
/**
		@fn		gbMsh :: ~gbMsh
		@brief	Deconstructor calls fFreeMdl method
**/
//==================================================================
gbMsh::~gbMsh()
{
	fFreeMdl();
}

//==================================================================
/**
		@fn		gbMsh::fFreeMdl()
		@brief	Frees space of pointer arrays and set it to NULL
		@return	VOID
**/
//==================================================================
VOID gbMsh::fFreeMdl()
{
	if(mFaces)		delete[] mFaces;
	if(v_ertices)	delete[] v_ertices;
	if(mNormals)	delete[] mNormals;
	if(mTexCoords)	delete[] mTexCoords;

	mFaces			= NULL;
	v_ertices		= NULL;
	mNormals		= NULL;
	mTexCoords		= NULL;
}

//==================================================================
/**
		@fn		gbMsh::fDraw()
		@brief	Draw object and material

				Initialize different materials and draw the triangle
				with its normals and vertices.
**/
//==================================================================
VOID gbMsh::fDraw()
{
	/*
	\todo Enable Material
	glDisable(GL_COLOR_MATERIAL);
	if(mMaterial.mHasAmbient)
		glMaterialfv(GL_FRONT, GL_AMBIENT, mMaterial.mAmbient);
	
	if(mMaterial.mHasDiffuse)
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mMaterial.mDiffuse);

	if(mMaterial.mHasSpecular)
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mMaterial.mSpecular);

	if(mMaterial.mHasEmissive)
		glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, mMaterial.mEmissive);

	if(mMaterial.mShininess >= 0)
		glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, mMaterial.mShininess);
	*/

	glBegin(GL_TRIANGLES);
	for(unsigned int i = 0; i < this->mNumFaces; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			glNormal3f
			(
				this->mNormals[this->mFaces[i].normal[j] - 1].x, 
				this->mNormals[this->mFaces[i].normal[j] - 1].y, 
				this->mNormals[this->mFaces[i].normal[j] - 1].z
			);
			glVertex3f
			(
				this->v_ertices[this->mFaces[i].vertex[j] - 1].x, 
				this->v_ertices[this->mFaces[i].vertex[j] - 1].y, 
				this->v_ertices[this->mFaces[i].vertex[j] - 1].z
			);
			/*
			\todo Enable Texture
			glTexCoord2f(	this->mTexCoords[this->mFaces[i].texcoord[j] - 1].u,
							this->mTexCoords[this->mFaces[i].texcoord[j] - 1].v		);
			*/
		}
	}
	glEnd();
	glEnable(GL_COLOR_MATERIAL);
}
//==================================================================