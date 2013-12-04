/**
	@file	Vector3d.h
	@brief	Includes Vector3d class
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
		@class	Vector3d
		@brief	Implements all rendering, initialization and resize
				methods for OpenGL, also variables, getter and 
				setter methods
**/
//==================================================================
class GOOSEBERRY_API Vector3d
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
		Vector3d();
		Vector3d(float coord);
		Vector3d(float * coords);
		Vector3d(float x, float y, float z);
		~Vector3d();

		//	Operators
		Vector3d operator+(const Vector3d& right);
		Vector3d operator-(const Vector3d& right);
		Vector3d operator*(const Vector3d& right);
		Vector3d operator/(const Vector3d& right);
				
	private:
	protected:
};