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
//	Include
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
#define DEBUG_MODE					TRUE
#define LOG_ONCE					FALSE
#define LOG_FILE					"logfile.html"
#define LOG_PATH					".\\log\\"
#define LOG_FILEPATH				LOG_PATH LOG_FILE

//==================================================================
//	GLOBALS
//==================================================================
GOOSEBERRY_API extern HINSTANCE		gb_g_hinstance;
GOOSEBERRY_API extern HWND			gb_g_HWND;
GOOSEBERRY_API extern HDC			gb_g_HDC;
GOOSEBERRY_API extern HGLRC			gb_g_HGLRC;
GOOSEBERRY_API extern LPCSTR		gb_g_wndTitle;
GOOSEBERRY_API extern LPCSTR		gb_g_wndName;
GOOSEBERRY_API extern int			gb_g_wndWidth;
GOOSEBERRY_API extern int			gb_g_wndHeight;
GOOSEBERRY_API extern int			gb_g_wndX;
GOOSEBERRY_API extern int			gb_g_wndY;
GOOSEBERRY_API extern int			gb_g_bitsColor;
GOOSEBERRY_API extern int			gb_g_bitsDepth;
GOOSEBERRY_API extern int			gb_g_bitsAlpha;
GOOSEBERRY_API extern bool			gb_g_fullscreen;
GOOSEBERRY_API extern bool			gb_g_active;
GOOSEBERRY_API extern bool			gb_g_init;
GOOSEBERRY_API extern bool			gb_g_keys[256];

//==================================================================
//	ENUM & STRUCTS
//==================================================================
enum gbResult
{
	GB_OK			= 0,
	GB_ERROR		= 1,
	GB_STOP			= 2
};

//==================================================================
//	FUNCTIONS
//==================================================================
GOOSEBERRY_API gbResult gbInitialize();
GOOSEBERRY_API gbResult gbExit();

//==================================================================
//	INCLUDE HEADER OF ENGINE
//==================================================================
#include "gbException.h"
#include "gbErrors.h"
#include "gbLog.h"
#include "gbOpenGL.h"
