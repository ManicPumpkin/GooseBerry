/**
	@file	GB_Vector3.h
	@brief	Includes GB_Vector3 class
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
		@class	GB_Vector3
		@brief	Implements all rendering, initialization and resize
				methods for GB_OpenGL, also variables, geter and 
				seter methods
**/
//==================================================================
class GOOSEBERRY_API GB_Vector3
{
	public:
		//  Variables
		union
		{
			struct
			{
				float x_, y_, z_;
			};

			struct
			{
				float u_, v_, w_;
			};

			float coords_[3];
		};

		//	(De-)Constructor
		GB_Vector3();
		GB_Vector3(float coord);
		GB_Vector3(float * coords);
		GB_Vector3(float x, float y, float z);
		~GB_Vector3();
		
		//	Operators
		GB_Vector3 operator+(const GB_Vector3& right);
		GB_Vector3 operator-(const GB_Vector3& right);
		GB_Vector3 operator*(const GB_Vector3& right);
		GB_Vector3 operator/(const GB_Vector3& right);
				
	private:
	protected:
};