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
#include "GooseBerry.h"

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
		Vector3d	mAxisX;		//!< x axis
		Vector3d	mAxisY;		//!< y axis
		Vector3d	mAxisZ;		//!< z axis
		Vector3d	mPosition;	//!< position
		Vector3d	mScale;		//!< scaling
		Vector3d	mRotation;	//!< rotation
		Vector3d	v_elocity;	//!< velocity
		Matrix	mMatrix;	//!< transform matrix
		Matrix	mInvMatrix;	//!< inverse transform matrix

		//	Functions
		VOID fReset();
		VOID fUpdate();
		VOID fMove(const float pTime);
		
	public:
		//	Variables
		//	(De-)Constructor & Coy
		~gbObj();
		gbObj();
		gbObj(Vector3d pPosition);
		gbObj(float x, float y, float z);
};