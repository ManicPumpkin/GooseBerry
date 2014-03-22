/**
	@file	GB_Vector2.h
	@brief	Includes GB_Vector2 class
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
#include "GooseBerry.h"

//==================================================================
//	CLASS
//==================================================================
/**
		@class	GB_Vector2
		@brief	Implements all rendering, initialization and resize
				methods for GB_OpenGL, also variables, geter and 
				seter methods
**/
//==================================================================
class GOOSEBERRY_API GB_Vector2
{
	public:
		//  Variables
		union
		{
			struct
			{
				float x_, y_;
			};

			struct
			{
				float u_, v_;
			};

			float coords_[2];
		};

		//	(De-)Constructor
		GB_Vector2();
		GB_Vector2(float coord);
		GB_Vector2(float * coords);
		GB_Vector2(float x, float y);
		~GB_Vector2();

		//	Operators
		GB_Vector2 operator+(const GB_Vector2& right);
		GB_Vector2 operator-(const GB_Vector2& right);
		GB_Vector2 operator*(const GB_Vector2& right);
		GB_Vector2 operator/(const GB_Vector2& right);
				
	private:
	protected:
};