/**
	@file	Vector2d.h
	@brief	Includes Vector2d class
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
		@class	Vector2d
		@brief	Implements all rendering, initialization and resize
				methods for OpenGL, also variables, getter and 
				setter methods
**/
//==================================================================
class GOOSEBERRY_API Vector2d
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
		Vector2d();
		Vector2d(float coord);
		Vector2d(float * coords);
		Vector2d(float x, float y);
		~Vector2d();

		//	Operators
		Vector2d operator+(const Vector2d& right);
		Vector2d operator-(const Vector2d& right);
		Vector2d operator*(const Vector2d& right);
		Vector2d operator/(const Vector2d& right);
				
	private:
	protected:
};