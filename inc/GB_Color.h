/**
	@file	GB_Color.h
	@brief	Includes GB_Color class
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
		@class	GB_Color
		@brief	Implements all rendering, initialization and resize
				methods for GB_OpenGL, also variables, geter and 
				seter methods
**/
//==================================================================
class GOOSEBERRY_API GB_Color
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
		GB_Color();
		GB_Color(float r, float g, float b);
		GB_Color(float r, float g, float b, float a);
		GB_Color(float * colors);
		~GB_Color(){}
				
	private:
	protected:
};