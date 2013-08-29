/**
	@file	gbVector3d.h
	@brief	Includes gbVector3d class
	@author	drubner
	@date	2013-08-26
**/
//==================================================================
//	PRAGMA
//==================================================================
#pragma once

//==================================================================
//	INCLUDE
//==================================================================
#include "gooseberry.h"

//==================================================================
//	CLASS
//==================================================================
/**
		@class	gbVector3d
		@brief	Implements all rendering, initialization and resize
				methods for OpenGL, also variables, getter and 
				setter methods
**/
//==================================================================
class GOOSEBERRY_API gbVector3d
{
	public:
		//  Variables
		union
		{
			struct
			{
				float mX, mY, mZ;
			};

			struct
			{
				float mU, mV, mW;
			};

			float mCoords[3];
		};

		//	(De-)Constructor
		gbVector3d();
		gbVector3d(float pCoord);
		gbVector3d(float * pCoords);
		gbVector3d(float pX, float pY, float pZ);
		~gbVector3d();

		//	Operators
		gbVector3d operator+(const gbVector3d& pRight);
		gbVector3d operator-(const gbVector3d& pRight);
		gbVector3d operator*(const gbVector3d& pRight);
		gbVector3d operator/(const gbVector3d& pRight);
				
	private:
	protected:
};