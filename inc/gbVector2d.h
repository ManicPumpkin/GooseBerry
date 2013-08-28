/**
	@file	gbVector2d.h
	@brief	Includes gbVector2d class
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
		@class	gbVector2d
		@brief	Implements all rendering, initialization and resize
				methods for OpenGL, also variables, getter and 
				setter methods
**/
//==================================================================
class GOOSEBERRY_API gbVector2d
{
	public:
		//  Variables
		union
		{
			struct
			{
				float mX, mY;
			};

			struct
			{
				float mU, mV;
			};

			float mCoords[2];
		};

		//	(De-)Constructor
		gbVector2d();
		gbVector2d(float * pCoords);
		gbVector2d(float pX, float pY);
		~gbVector2d();

		//	Operators
		gbVector2d operator+(const gbVector2d& pRight);
		gbVector2d operator-(const gbVector2d& pRight);
		gbVector2d operator*(const gbVector2d& pRight);
		gbVector2d operator/(const gbVector2d& pRight);
				
	private:
	protected:
};