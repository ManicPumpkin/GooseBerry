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
bool		gb_g_fullscreen = FALSE;
bool		gb_g_init		= FALSE;
bool		gb_g_active		= TRUE;
bool		gb_g_keys[256];

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
	{
		gb_g_openGL->fExitWnd();
		delete gb_g_openGL;
	}

	return GB_OK;
}

//==================================================================
/**
	@fn		gooseberry :: fInitialize
	@brief	Initialize the game engine
**/
//==================================================================
GOOSEBERRY_API gbResult gbInitialize()
{
	if(!gb_g_init)
	{
		gbInitializeLog();
		gbLog("Initialize GooseBerry");
	}

	gb_g_openGL		= new gbOpenGL();
	if(gb_g_openGL->fStartWnd()) return GB_STOP;

	gb_g_init = TRUE;
	return GB_OK;
}
