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
		gbOpenGL(HINSTANCE pHinstance, HWND pHWND, LPCSTR pWndName, LPCSTR pWndTitle, int pWidth, int pHeight, int pX, int pY, int pBitsColor, int pBitsDepth, int pBitsAlpha);
		~gbOpenGL();

		//	Functions
		VOID fEnableOpenGL();
		VOID fInitializeOpenGL();
		//VOID fInitializeScene();
		//VOID fRenderScene();
		gbResult fStartWnd();
		gbResult fExitWnd();
		VOID fCreateOpenGLWnd();
		VOID fRegisterWndClass();
		VOID fCreateParams();
		VOID fOnResize(int pWidth, int pHeight);
		//VOID fDrawBitmapText(char *, float, float, float);
		//VOID fDrawSimpleLine(cVector3f pStart, cVector3f pEnd);
		
		//	Set, Get
		VOID	fSetHWND(HWND pHWND)			{	mHWND = pHWND;				}
		VOID	fSetHinst(HINSTANCE pHinstance)	{	mHinstance = pHinstance;	}

		HINSTANCE	fGetHinstance() { return mHinstance;	}	//!< Get current window instance
		HWND		fGetHWND()		{ return mHWND;			}	//!< Get current handle to window
		HDC			fGetHDC()		{ return mHDC;			}	//!< Get handle to device context
		HGLRC		fGetHGLRC()		{ return mHGLRC;		}	//!< Get handle to rendering context
		
	private:
		//	Variables
		HINSTANCE	mHinstance;		//!< Instance
		HWND		mHWND;			//!< Handle to current window
		HDC			mHDC;			//!< Handle device context
		HGLRC		mHGLRC;			//!< Handle rendering context
		LPCSTR		mWndTitle;		//!< Window title
		LPCSTR		mWndName;		//!< Window name
		int			mBitsColor;		//!< Bits color
		int			mBitsDepth;		//!< Bits depth
		int			mBitsAlpha;		//!< Bits alpha
		int			mWndWidth;		//!< OpenGL window width
		int			mWndHeight;		//!< OpenGL window height
		int			mWndX;			//!< OpenGL window x position
		int			mWndY;			//!< OpenGL window y position

	protected:
};