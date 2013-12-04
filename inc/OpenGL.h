/**
	@file	OpenGL.h
	@brief	Includes OpenGL class
	@author	drubner
	@date	2013-07-06
**/
//==================================================================
//	PRAGMA
//==================================================================
#pragma once

//==================================================================
//	NAMESPACE
//==================================================================
using namespace gbGlobal;

//==================================================================
//	INCLUDE
//==================================================================
#include "GooseBerry.h"

//==================================================================
//	FORWARD DEFINITION
//==================================================================
class Vector3d;
class Color;

//==================================================================
//	CLASS
//==================================================================
/**
		@class	OpenGL
		@brief	Implements all rendering, initialization and resize
				methods for OpenGL, also variables, getter and 
				setter methods
**/
//==================================================================
class GOOSEBERRY_API OpenGL 
{
	public:
		//  Variables

		//	(De-)Constructor
		OpenGL();
		~OpenGL();

		//	Functions
		VOID InitializeOpenGL();
		//VOID InitializeScene();
		//VOID RenderScene();
		gbResult StartWnd();
		gbResult ExitWnd();
		gbResult RegisterWndClass();
		gbResult FullscreenWnd();
		gbResult CreateOpenGLWnd();
		gbResult EnableOpenGL();
		gbResult ResizeOpenGLWnd(int wnd_width, int wnd_height);
		//VOID DrawBitmapText(char *, float, float, float);
		gbResult DrawSimpleLine(Vector3d start_vec, Vector3d end_vec);
		gbResult DrawSimpleLine(Color color, Vector3d start_vec, Vector3d end_vec);
				
	private:
		//	Variables
		DWORD	dw_ex_style_;		//!<	extended style of window
		DWORD	dw_style_;			//!<	style of window
		bool	initialize_;		//!<	if OpenGL is initialized

	protected:
};