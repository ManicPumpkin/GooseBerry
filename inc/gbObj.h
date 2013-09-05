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
		gbMsh		mMdl;		//!< model of object
		gbVector3d	mAxisX;		//!< x axis
		gbVector3d	mAxisY;		//!< y axis
		gbVector3d	mAxisZ;		//!< z axis
		gbVector3d	mPosition;	//!< position
		gbVector3d	mScale;		//!< scaling
		gbVector3d	mRotation;	//!< rotation
		gbVector3d	mVelocity;	//!< velocity
		gbMatrix	mMatrix;	//!< transform matrix
		gbMatrix	mInvMatrix;	//!< inverse transform matrix

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