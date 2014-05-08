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
#pragma comment(lib, "zlib.lib")
#pragma comment(lib, "libpng16.lib")

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

//	EXTERN LIBRARIES
#include "..\ext\glut-3.7.6\glut.h"

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
#define LOG_FILE				"gb_log.html"
#define LOG_PATH				".\\log\\"
#define LOG_FILEPATH			LOG_PATH LOG_FILE

#define BB3D_SHOW				TRUE
#define BB3D_LINE_WIDTH			2.5f
#define BB3D_LINE_COLOR			1.0f, 1.0f, 1.0f

//==================================================================
//	GLOBALS
//==================================================================
namespace GB_Settings
{
	namespace Engine
	{
		GOOSEBERRY_API extern bool			g_initialized;		//!< gooseberry engine initialized
		GOOSEBERRY_API extern bool			g_keys[256];		//!< all keys
	}

	namespace OpenGL
	{
		GOOSEBERRY_API extern HINSTANCE		g_hinstance;		//!< instance of program
		GOOSEBERRY_API extern HWND			g_hwnd;				//!< handle to window
		GOOSEBERRY_API extern HDC			g_hdc;				//!< device context
		GOOSEBERRY_API extern HGLRC			g_hglrc;			//!< render context
	}

	namespace Window
	{
		GOOSEBERRY_API extern LPCSTR		g_wnd_title;		//!< title of window
		GOOSEBERRY_API extern LPCSTR		g_wnd_name;			//!< name of window
		GOOSEBERRY_API extern int			g_wnd_width;		//!< window width
		GOOSEBERRY_API extern int			g_wnd_height;		//!< window height
		GOOSEBERRY_API extern int			g_wnd_x;			//!< window x
		GOOSEBERRY_API extern int			g_wnd_y;			//!< window y
	}

	namespace App
	{
		GOOSEBERRY_API extern int			g_bits_color;		//!< GB_Color bits
		GOOSEBERRY_API extern int			g_bits_depth;		//!< GB_Color depth
		GOOSEBERRY_API extern int			g_bits_alpha;		//!< GB_Color alpha
		GOOSEBERRY_API extern bool			g_fullscreen;		//!< window runs in fullscreen
		GOOSEBERRY_API extern bool			g_active;			//!< window is active
	}

	namespace BoundingBox
	{
		GOOSEBERRY_API extern bool			g_show;				//!< show bounding box
		GOOSEBERRY_API extern float			g_line_width;		//!< line width of bounding box
		GOOSEBERRY_API extern float			g_line_color[3];	//!< line color of bounding box
	}
}

//==================================================================
//	ENUM & STRUCTS
//==================================================================
namespace GB_Enum
{
	enum gbResult
	{
		GB_OK = 0,
		GB_ERROR = 1,
		GB_STOP = 2,
		GB_NOTFOUND = 3
	};
}

namespace GB_Struct
{
	struct Vertex						//! Vertex struct with coordinates
	{
		float	x,						//!< x-coordinate
		y,								//!< y-coordinate
		z;								//!< z-coordinate
	};

	typedef Vertex Normal;				//! Normal struct with coordiantes

	struct TexCoord						//! Texture struct with coordinates
	{
		float	u,						//!< u-coordinate
				v;						//!< v-coordinate
	};

	struct Face							//! Face struct
	{
		unsigned int	vertex[4],		//!< vertex indices of face
						normal[4],		//!< normal indices of face
						texcoord[4];	//!< texture indices of face
	};
}

//==================================================================
//	FUNCTION DECLARATION
//==================================================================
namespace GB_Func
{
	GOOSEBERRY_API GB_Enum::gbResult Initialize();
	GOOSEBERRY_API GB_Enum::gbResult MessageLoop(GB_Enum::gbResult(*func_render)(float));
	GOOSEBERRY_API GB_Enum::gbResult Exit();

	std::string ExtractFile(std::string file);
	std::string ExtractName(std::string file);
	std::string ExtractPath(std::string file);
	std::string IntToStr(int value);
	VOID		SplitString(const string& str, vector<string>& token, const string& seperator);
}

//==================================================================
//	INCLUDE HEADER OF ENGINE
//==================================================================
#include "GB_Exception.h"
#include "GB_Errors.h"
#include "GB_Log.h"	
#include "GB_Convert.h"
#include "GB_Array.h"
#include "GB_Matrix.h"
#include "GB_Vector3.h"
#include "GB_Vector2.h"
#include "GB_Color.h"
#include "GB_OpenGL.h"
#include "GB_BB3D.h"
#include "GB_Material.h"
#include "GB_Texture.h"
#include "GB_Loader.h"
#include "GB_Mesh.h"
#include "GB_MeshQueue.h"
#include "GB_Model.h"
