/**
	@file	Color.h
	@brief	Includes Color class
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
#include "GooseBerry.h"

//==================================================================
//	CLASS
//==================================================================
/**
		@class	Color
		@brief	Implements all rendering, initialization and resize
				methods for OpenGL, also variables, getter and 
				setter methods
**/
//==================================================================
class GOOSEBERRY_API Color
{
	public:
		//  Variables
		union
		{
			struct
			{
				float r, g, b, a;
			};

			struct
			{
				float red, green, blue, alpha;
			};

			float colors[4];
		};

		//	(De-)Constructor
		Color();
		Color(float r, float g, float b);
		Color(float r, float g, float b, float a);
		Color(float * colors);
		~Color(){}
				
	private:
	protected:
};