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
#define DEBUG_MODE		TRUE
#define LOG_ONCE		TRUE
#define LOG_FILE		"logfile.txt"
#define LOG_PATH		".\\out\\"
#define LOG_FILEPATH	LOG_PATH LOG_FILE

//==================================================================
//	GLOBALS
//==================================================================
extern HINSTANCE	gb_g_hinstance;
extern HWND			gb_g_HWND;
extern HDC			gb_g_HDC;
extern HGLRC		gb_g_HGLRC;
extern LPCSTR		gb_g_wndTitle;
extern LPCSTR		gb_g_wndName;
extern int			gb_g_wndWidth;
extern int			gb_g_wndHeight;
extern int			gb_g_wndX;
extern int			gb_g_wndY;
extern int			gb_g_bitsColor;
extern int			gb_g_bitsDepth;
extern int			gb_g_bitsAlpha;

//==================================================================
//	ENUM & STRUCTS
//==================================================================
enum gbResult
{
	GB_OK			= 0,
	GB_ERROR		= 1
};

//==================================================================
//	FUNCTIONS
//==================================================================
GOOSEBERRY_API gbResult gbInitialize(HINSTANCE * pHinstance, HWND * pHWND, LPCSTR pWndTitle,
										LPCSTR pWndName, int pWndWidth, int pWndHeight,
										int pWndX, int pWndY, int pBitsColor, 
										int pBitsDepth, int pBitsAlpha);
GOOSEBERRY_API gbResult gbExit();

//==================================================================
//	INCLUDE HEADER OF ENGINE
//==================================================================
#include "gbException.h"
#include "gbErrors.h"
#include "gbLog.h"
#include "gbOpenGL.h"
