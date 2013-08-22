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
		gbMdl			mMdl;
		gb_g_position	mPosition;

		//	Functions
		
	public:
		//	Variables
		//	(De-)Constructor & Copy
		~gbObj();
		gbObj();
		gbObj(gb_g_position pPosition);
		gbObj(float pX, float pY, float pZ);

		//	Functions
		//	Get
		//	Set
};