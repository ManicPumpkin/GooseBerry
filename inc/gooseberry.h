/**
	@file	GooseBerry.h
	@brief	Includes gooseberry class
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
//	GLOBAL NAMESPACE START
//==================================================================
namespace gbGlobal
{

//==================================================================
//	GLOBALS
//==================================================================
GOOSEBERRY_API extern HINSTANCE		g_hinstance;	//!< instance of program
GOOSEBERRY_API extern HWND			g_HWND;			//!< handle to window
GOOSEBERRY_API extern HDC			g_HDC;			//!< device context
GOOSEBERRY_API extern HGLRC			g_HGLRC;		//!< render context
GOOSEBERRY_API extern LPCSTR		g_wndTitle;		//!< title of window
GOOSEBERRY_API extern LPCSTR		g_wndName;		//!< name of window
GOOSEBERRY_API extern int			g_wndWidth;		//!< window width
GOOSEBERRY_API extern int			g_wndHeight;	//!< window height
GOOSEBERRY_API extern int			g_wndX;			//!< window x
GOOSEBERRY_API extern int			g_wndY;			//!< window y
GOOSEBERRY_API extern int			g_bitsColor;	//!< color bits
GOOSEBERRY_API extern int			g_bitsDepth;	//!< color depth
GOOSEBERRY_API extern int			g_bitsAlpha;	//!< color alpha
GOOSEBERRY_API extern bool			g_fullscreen;	//!< window runs in fullscreen
GOOSEBERRY_API extern bool			g_active;		//!< window is active
GOOSEBERRY_API extern bool			g_init;			//!< gooseberry engine initialized
GOOSEBERRY_API extern bool			g_keys[256];	//!< all keys

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
GOOSEBERRY_API gbResult Initialize();
GOOSEBERRY_API gbResult MessageLoop(gbResult (*typ_render)(float));
GOOSEBERRY_API gbResult Exit();

std::string ExtractName(std::string file);
std::string ExtractPath(std::string file);
std::string IntToStr(int value);
VOID		SplitString(const string& str, vector<string>& token, const string& seperator);

//==================================================================
//	GLOBAL NAMESPACE END
//==================================================================
}

//==================================================================
//	INCLUDE HEADER OF ENGINE
//==================================================================
#include "Exception.h"
#include "Errors.h"
#include "Log.h"
#include "Convert.h"
#include "Array.h"
#include "Matrix.h"
#include "Vector3d.h"
#include "Vector2d.h"
#include "Color.h"
#include "OpenGL.h"
//#include "gbMat.h"
//#include "gbTex.h"
//#include "gbMsh.h"
//#include "gbMshLoader.h"
//#include "gbMshQueue.h"