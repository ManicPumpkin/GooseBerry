/**
	@file	openGL.h
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
#include "gooseberry.h"

//==================================================================
//	FORWARD DEFINITION
//==================================================================
class gbVector3d;
class gbColor;

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
class GOOSEBERRY_API gbOpenGL 
{
	public:
		//  Variables

		//	(De-)Constructor
		gbOpenGL();
		~gbOpenGL();

		//	Functions
		VOID fInitializeOpenGL();
		//VOID fInitializeScene();
		//VOID fRenderScene();
		gbResult fStartWnd();
		gbResult fExitWnd();
		gbResult fRegisterWndClass();
		gbResult fFullscreenWnd();
		gbResult fCreateOpenGLWnd();
		gbResult fEnableOpenGL();
		gbResult fResizeOpenGLWnd(int pWidth, int pHeight);
		//VOID fDrawBitmapText(char *, float, float, float);
		gbResult fDrawSimpleLine(gbVector3d pStart, gbVector3d pEnd);
		gbResult fDrawSimpleLine(gbColor pColor, gbVector3d pStart, gbVector3d pEnd);
				
	private:
		//	Variables
		DWORD	mDwExStyle;		//!<	extended style of window
		DWORD	mDwStyle;		//!<	style of window
		bool	mInit;			//!<	if OpenGL is initialized

	protected:
};