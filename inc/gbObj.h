//==================================================================
/**
	@file	gbObj.h
	@brief	This file includes the object 

	Includes the object class. Contains all variables needed to
	hold information of the object and contains variables such
	as model, position etc.

	@author	drubner
	@date	2013-08-22
**/
//==================================================================
#pragma once

//==================================================================
//	Includes
//==================================================================
#include "gooseberry.h"

//==================================================================
//	Class
//==================================================================
/**
	@class	gbObj
	@brief	Contains information about object/model files
**/
//==================================================================
class GOOSEBERRY_API gbObj
{
	protected:
	private:
		//	Variables
		gbMsh		mMdl;
		gbVector3d	mAxisX;
		gbVector3d	mAxisY;
		gbVector3d	mAxisZ;
		gbVector3d	mPosition;
		gbVector3d	mScale;
		gbVector3d	mRotation;
		gbVector3d	mVelocity;
		gbMatrix	mMatrix;
		gbMatrix	mInvMatrix;

		//	Functions
		VOID fReset();
		VOID fUpdate();
		VOID fMove(const float pTime);
		
	public:
		//	Variables
		//	(De-)Constructor & Copy
		~gbObj();
		gbObj();
		gbObj(gbVector3d pPosition);
		gbObj(float pX, float pY, float pZ);
};