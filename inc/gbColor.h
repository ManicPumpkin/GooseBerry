/**
	@file	gbColor.h
	@brief	Includes gbColor class
	@author	drubner
	@date	2013-08-28
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
		@class	gbColor
		@brief	Implements all rendering, initialization and resize
				methods for OpenGL, also variables, getter and 
				setter methods
**/
//==================================================================
class GOOSEBERRY_API gbColor
{
	public:
		//  Variables
		union
		{
			struct
			{
				float mR, mG, mB, mA;
			};

			struct
			{
				float mRed, mGreen, mBlue, mAlpha;
			};

			float mColors[4];
		};

		//	(De-)Constructor
		gbColor();
		gbColor(float pR, float pG, float pB);
		gbColor(float pR, float pG, float pB, float pA);
		gbColor(float * pColors);
		~gbColor(){}
				
	private:
	protected:
};