//==================================================================
/**
		@file	cMdl.cpp
		@brief	This file includes all functions of cMdl class
		@author	drubner
		@date	2012-08-20
**/
//==================================================================
//	Include
//==================================================================
#include "cMdl.h"
//==================================================================
//	Functions
//==================================================================
/**
		@fn		cMdl::cMdl()
		@brief	Standard constructor
**/
//==================================================================
cMdl::cMdl()
{
	mNumVertices	= 0;
	mNumNormals		= 0;
	mNumTexCoords	= 0;
	mNumFaces		= 0;
	mIsTriangle		= TRUE;
	mFaces			= NULL;
	mVertices		= NULL;
	mNormals		= NULL;
	mTexCoords		= NULL;
}
//==================================================================
/**
		@fn		cMdl::cMdl(const cMdl& tRHS)
		@brief	copy constructor for deep copy

				Deep copy an cMdl object with another.
**/
//==================================================================
cMdl::cMdl(const cMdl& tRHS)
{
	this->mObjName		= tRHS.mObjName;
	this->mObjFile		= tRHS.mObjFile;
	this->mMtllib		= tRHS.mMtllib;
	this->mUsemtl		= tRHS.mUsemtl;
	this->mIsTriangle	= tRHS.mIsTriangle;
	this->mNumFaces		= tRHS.mNumFaces;
	this->mNumVertices	= tRHS.mNumVertices;
	this->mNumNormals	= tRHS.mNumNormals;
	this->mNumTexCoords	= tRHS.mNumTexCoords;
	this->mMaterial		= tRHS.mMaterial;

	mFaces		= new grFace[mNumFaces];
	mVertices	= new grVertex[mNumVertices];
	mNormals	= new grNormal[mNumNormals];
	mTexCoords	= new grTexCoord[mNumTexCoords];

	for(unsigned int tI = 0; tI < mNumFaces; tI++)
	{
		for(int tJ = 0; tJ < 4; tJ++)
		{
			mFaces[tI].vertex[tJ]	= tRHS.mFaces[tI].vertex[tJ];
			mFaces[tI].normal[tJ]	= tRHS.mFaces[tI].normal[tJ];
			mFaces[tI].texcoord[tJ]	= tRHS.mFaces[tI].texcoord[tJ];
		}
	}

	for(unsigned int tI = 0; tI < mNumVertices; tI++)
	{
		mVertices[tI].x	= tRHS.mVertices[tI].x;
		mVertices[tI].y	= tRHS.mVertices[tI].y;
		mVertices[tI].z	= tRHS.mVertices[tI].z;
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
cMdl::~cMdl()
{
	fFreeMdl();
}
//==================================================================
/**
		@fn		cMdl::fFreeMdl()
		@brief	Frees space of pointer arrays and set it to NULL
		@return	VOID
**/
//==================================================================
VOID cMdl::fFreeMdl()
{
	if(mFaces)		delete[] mFaces;
	if(mVertices)	delete[] mVertices;
	if(mNormals)	delete[] mNormals;
	if(mTexCoords)	delete[] mTexCoords;

	mFaces			= NULL;
	mVertices		= NULL;
	mNormals		= NULL;
	mTexCoords		= NULL;
}
//==================================================================
/**
		@fn		cMdl::fDraw()
		@brief	Draw object and material

				Initialize different materials and draw the triangle
				with its normals and vertices.
**/
//==================================================================
VOID cMdl::fDraw()
{
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
			glVertex3f(
				this->mVertices[this->mFaces[i].vertex[j] - 1].x, 
				this->mVertices[this->mFaces[i].vertex[j] - 1].y, 
				this->mVertices[this->mFaces[i].vertex[j] - 1].z
			);
			/*
			glTexCoord2f(	this->mTexCoords[this->mFaces[i].texcoord[j] - 1].u,
							this->mTexCoords[this->mFaces[i].texcoord[j] - 1].v		);
			*/
			//cGlobal::gLog("face: " + cGlobal::gNumToStr<int>(i) + " vertex x:" + cGlobal::gNumToStr<float>(this->mVertices[this->mFaces[i].vertex[j] - 1].x) + " vertex y " + cGlobal::gNumToStr<float>(this->mVertices[this->mFaces[i].vertex[j] - 1].y) + " vertex z " + cGlobal::gNumToStr<float>(this->mVertices[this->mFaces[i].vertex[j] - 1].z));
			//cGlobal::gLog("normal: " + cGlobal::gNumToStr<int>(i) + " normal x:" + cGlobal::gNumToStr<float>(this->mNormals[this->mFaces[i].normal[j] - 1].x) + " normal y " + cGlobal::gNumToStr<float>(this->mNormals[this->mFaces[i].normal[j] - 1].y) + " normal z " + cGlobal::gNumToStr<float>(this->mNormals[this->mFaces[i].normal[j] - 1].z));
		}
	}
	glEnd();
	glEnable(GL_COLOR_MATERIAL);
}
//==================================================================