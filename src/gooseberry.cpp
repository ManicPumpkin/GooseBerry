/**
	@file	glooseberry.cpp
	@brief	Includes all glooseberry class methods
	@author	drubner
	@date	2013-07-16
**/
//==================================================================
//	Include
//==================================================================
#include "gooseberry.h"

//==================================================================
//	Namespace
//==================================================================

//==================================================================
//	Variables
//==================================================================
HINSTANCE	gb_g_hinstance	= NULL;
HWND		gb_g_HWND		= NULL;
HDC			gb_g_HDC		= NULL;
HGLRC		gb_g_HGLRC		= NULL;
LPCSTR		gb_g_wndTitle	= "";
LPCSTR		gb_g_wndName	= "";
int			gb_g_wndWidth	= -1;
int			gb_g_wndHeight  = -1;
int			gb_g_wndX		= -1;
int			gb_g_wndY		= -1;
int			gb_g_bitsColor	= -1;
int			gb_g_bitsDepth	= -1;
int			gb_g_bitsAlpha	= -1;

gbOpenGL *	gb_g_openGL		= NULL;

//==================================================================
/**
	@fn		gooseberry :: ~glooseberry
	@brief	Deconstructor
**/
//==================================================================
GOOSEBERRY_API gbResult gbExit()
{
	if(gb_g_openGL)	
		delete gb_g_openGL;

	return GB_OK;
}

//==================================================================
/**
	@fn		gooseberry :: fInitialize
	@brief	Initialize the game engine
**/
//==================================================================
GOOSEBERRY_API gbResult gbInitialize(HINSTANCE * pHinstance, HWND * pHWND, LPCSTR pWndTitle, LPCSTR pWndName, int pWndWidth, int pWndHeight, int pWndX, int pWndY, int pBitsColor, int pBitsDepth, int pBitsAlpha)
{
	gb_g_hinstance		= *pHinstance;
	gb_g_HWND			= *pHWND;
	gb_g_wndTitle		= pWndTitle;
	gb_g_wndName		= pWndName;
	gb_g_wndWidth		= pWndWidth;
	gb_g_wndHeight		= pWndHeight;
	gb_g_wndX			= pWndX;
	gb_g_wndY			= pWndY;
	gb_g_bitsColor		= pBitsColor;
	gb_g_bitsDepth		= pBitsDepth;
	gb_g_bitsAlpha		= pBitsAlpha;
	gbInitializeLog();
	
	gbLog("Initialize GlooseBerry");
	gb_g_openGL = new gbOpenGL(gb_g_hinstance, gb_g_HWND, gb_g_wndName, gb_g_wndTitle, 
		gb_g_wndWidth, gb_g_wndHeight, gb_g_wndX, gb_g_wndY,
		gb_g_bitsColor, gb_g_bitsDepth, gb_g_bitsAlpha);

	//gb_g_openGL->fStartWnd(&gb_g_HWND);
	*pHWND	= gb_g_openGL->fGetHWND();

	return GB_OK;
}
