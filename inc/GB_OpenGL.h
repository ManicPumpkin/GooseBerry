/**
	@file	GB_OpenGL.h
	@brief	Includes GB_OpenGL class
	@author	drubner
	@date	2013-07-06
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
//	NAMESPACE
//==================================================================
using namespace GB_Enum;

//==================================================================
//	FORWARD DEFINITION
//==================================================================
//class GB_Vector3;
class GB_Color;

//==================================================================
//	CLASS
//==================================================================
/**
		@class	GB_OpenGL
		@brief	Implements all rendering, initialization and resize
				methods for GB_OpenGL, also variables, geter and 
				seter methods
**/
//==================================================================
class GOOSEBERRY_API GB_OpenGL 
{
	public:
		//  Variables

		//	(De-)Constructor
		GB_OpenGL();
		~GB_OpenGL();

		//	Functions
		VOID InitializeGB_OpenGL();
		//VOID InitializeScene();
		//VOID RenderScene();
		gbResult StartWnd();
		gbResult ExitWnd();
		gbResult RegisterWndClass();
		gbResult FullscreenWnd();
		gbResult CreateGB_OpenGLWnd();
		gbResult EnableGB_OpenGL();
		gbResult ResizeGB_OpenGLWnd(int wnd_width, int wnd_height);
		//VOID DrawBitmapText(char *, float, float, float);
		gbResult DrawSimpleLine(GB_Vector3 start_vec, GB_Vector3 end_vec);
		gbResult DrawSimpleLine(GB_Color color, GB_Vector3 start_vec, GB_Vector3 end_vec);
				
	private:
		//	Variables
		DWORD	dw_ex_style_;		//!<	extended style of window
		DWORD	dw_style_;			//!<	style of window
		bool	initialize_;		//!<	if GB_OpenGL is initialized

	protected:
};