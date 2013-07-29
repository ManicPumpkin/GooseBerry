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
//	INCLUDE
//==================================================================
#include "gooseberry.h"

//==================================================================
//	NAMESPACES
//==================================================================

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
class gbOpenGL 
{
	public:
		//  Variables

		//	(De-)Constructor
		gbOpenGL(){}
		gbOpenGL(HINSTANCE pHinstance, HWND pHWND, LPCSTR pWndName, LPCSTR pWndTitle, int pWidth, int pHeight, int pX, int pY, int pBitsColor, int pBitsDepth, int pBitsAlpha, bool pFullscreen);
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
		VOID fCreateParams();
		VOID fOnResize(int pWidth, int pHeight);
		//VOID fDrawBitmapText(char *, float, float, float);
		//VOID fDrawSimpleLine(cVector3f pStart, cVector3f pEnd);
				
	private:
		//	Variables
		DWORD mDwExStyle;
		DWORD mDwStyle;

	protected:
};