/**
	@file	glooseberry.h
	@brief	Includes glooseberry class
	@author	drubner
	@date	2013-07-16
**/
//==================================================================
//	PRAGMA ONCE
//==================================================================
#pragma once

#ifdef GOOSEBERRY_EXPORTS
	#define GOOSEBERRY_API __declspec(dllexport)
#else
	#define GOOSEBERRY_API __declspec(dllimport)
#endif

#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glut32.lib")
#pragma comment(lib, "glu32.lib")

//==================================================================
//	INCLUDE
//==================================================================
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <gl/GLU.h>
#include <gl/GL.h>

#include "glut.h"

//==================================================================
//	NAMESPACES
//==================================================================
using namespace std;

//==================================================================
//	FORWARD DECLARATIONS
//==================================================================

//==================================================================
//	DEFINES
//==================================================================
#define DEBUG_MODE				TRUE
#define ONLY_COMPILE			FALSE
#define LOG_ONCE				FALSE
#define LOG_FILE				"logfile.html"
#define LOG_PATH				".\\log\\"
#define LOG_FILEPATH			LOG_PATH LOG_FILE

//==================================================================
//	GLOBALS
//==================================================================
GOOSEBERRY_API extern HINSTANCE		gb_g_hinstance;		//!< instance of program
GOOSEBERRY_API extern HWND			gb_g_HWND;			//!< handle to window
GOOSEBERRY_API extern HDC			gb_g_HDC;			//!< device context
GOOSEBERRY_API extern HGLRC			gb_g_HGLRC;			//!< 
GOOSEBERRY_API extern LPCSTR		gb_g_wndTitle;		//!< title of window
GOOSEBERRY_API extern LPCSTR		gb_g_wndName;		//!< name of window
GOOSEBERRY_API extern int			gb_g_wndWidth;		//!< window width
GOOSEBERRY_API extern int			gb_g_wndHeight;		//!< window height
GOOSEBERRY_API extern int			gb_g_wndX;			//!< window x
GOOSEBERRY_API extern int			gb_g_wndY;			//!< window y
GOOSEBERRY_API extern int			gb_g_bitsColor;		//!< color bits
GOOSEBERRY_API extern int			gb_g_bitsDepth;		//!< color depth
GOOSEBERRY_API extern int			gb_g_bitsAlpha;		//!< color alpha
GOOSEBERRY_API extern bool			gb_g_fullscreen;	//!< window runs in fullscreen
GOOSEBERRY_API extern bool			gb_g_active;		//!< window is active
GOOSEBERRY_API extern bool			gb_g_init;			//!< gooseberry engine initialized
GOOSEBERRY_API extern bool			gb_g_keys[256];		//!< all keys

//==================================================================
//	ENUM & STRUCTS
//==================================================================
enum gbResult
{
	GB_OK			= 0,
	GB_ERROR		= 1,
	GB_STOP			= 2,
	GB_NOTFOUND		= 3
};

//==================================================================
//	FUNCTION DECLARATION
//==================================================================
GOOSEBERRY_API gbResult gbInitialize();
GOOSEBERRY_API gbResult gbMessageLoop(gbResult (*typRender)(float));
GOOSEBERRY_API gbResult gbExit();

std::string gbExtractName(std::string pFile);
std::string gbExtractPath(std::string pFile);
VOID		gbSplitString(const string& pStr, vector<string>& pToken, const string& pSeperator);

//==================================================================
//	INCLUDE HEADER OF ENGINE
//==================================================================
#include "gbException.h"
#include "gbErrors.h"
#include "gbLog.h"
#include "gbConvert.h"
#include "gbArray.h"
#include "gbMatrix.h"
#include "gbVector3d.h"
#include "gbVector2d.h"
#include "gbColor.h"
#include "gbOpenGL.h"
#include "gbMdl.h"
#include "gbMdlLoader.h"
#include "gbMdlQueue.h"