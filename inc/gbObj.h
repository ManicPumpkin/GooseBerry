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
		gbMdl		mMdl;
		gbVector3d	mPosition;

		//	Functions
		
	public:
		//	Variables
		//	(De-)Constructor & Copy
		~gbObj();
		gbObj();
		gbObj(gbVector3d pPosition);
		gbObj(float pX, float pY, float pZ);
};