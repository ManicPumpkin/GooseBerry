/**
	@file	gbVector3f.h
	@brief	Includes gbVector3f class
	@author	drubner
	@date	2013-08-22
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
//	Structs
//==================================================================
struct gb_g_position				//! Position struct with coordinates
{
	float	x,						//!< x-coordinate
			y,						//!< y-coordinate
			z;						//!< z-coordinate
};	

//==================================================================
//	CLASS
//==================================================================
/**
		@class	gbVector3f
		@brief	Implements all rendering, initialization and resize
				methods for OpenGL, also variables, getter and 
				setter methods
**/
//==================================================================
class GOOSEBERRY_API gbVector3f 
{
	public:
		//  Variables

		//	(De-)Constructor
		gbVector3f();
		gbVector3f(gb_g_position pPosition);
		gbVector3f(float pX, float pY, float pZ);
		~gbVector3f();

		//	Operators
		gbVector3f operator+(const gbVector3f& pRight);
		gbVector3f operator-(const gbVector3f& pRight);
		gbVector3f operator*(const gbVector3f& pRight);
		gbVector3f operator/(const gbVector3f& pRight);
				
	private:
		//	Variables
		gb_g_position	mPosition;

	protected:
};