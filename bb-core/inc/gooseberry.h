/**
	@file	Blueberry.h
	@brief	Includes Blueberry class
	@author	drubner
	@date	2013-07-16
**/
//==================================================================
//	PRAGMA ONCE
//==================================================================
#pragma once

#ifdef Blueberry_EXPORTS
	#define Blueberry_API __declspec(dllexport)
#else
	#define Blueberry_API __declspec(dllimport)
#endif

#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glut32.lib")
#pragma comment(lib, "glu32.lib")
#pragma comment(lib, "zlib.lib")
//#pragma comment(lib, "libpng16.lib")

//==================================================================
//	INCLUDE
//==================================================================
#ifdef _WIN32 || _WIN64
	#include <Windows.h>
	#include <iostream>
	#include <fstream>
	#include <sstream>
	#include <stdarg.h>
	#include <stdlib.h>
	#include <stdio.h>
	#include <string>
	#include <time.h>
	#include <vector>
	#include <io.h>
	#include <fcntl.h>
	#include <gl/GLU.h>
	#include <gl/GL.h>

	//	EXTERN LIBRARIES
	#include "..\ext\glut-3.7.6\glut.h"
	//#include "..\ext\libpng-1.6.8\png.h"
	#include "..\ext\stb_image\stb_image.h"

#error Can not compile on Windows yet
#endif

#ifdef __linux__
	#include <iostream>
	#include <fstream>
	#include <sstream>
#error Can not compile on Linux yet
#endif

//==================================================================
//	NAMESPACES
//==================================================================
using namespace std;

//==================================================================
//	PRAGMA
//==================================================================
#pragma warning(disable: 4251)
#pragma warning(disable: 4996)

//==================================================================
//	DEFINES
//==================================================================
#define LOG_ONCE				FALSE
#define LOG_FILE				"BB_log.html"
#define LOG_PATH				".\\log\\"
#define LOG_FILEPATH			LOG_PATH LOG_FILE

//==================================================================
//	GLOBALS
//==================================================================
namespace BB_Settings
{
	namespace Engine
	{
		Blueberry_API extern bool			g_initialized;		//!< Blueberry engine initialized
		Blueberry_API extern bool			g_keys[256];		//!< all keys
	}

	namespace Debug
	{
		Blueberry_API extern bool			g_debug_mode;		//!< debug mode active
		Blueberry_API extern bool			g_only_compile;		//!< only compile app
	}

	namespace OpenGL
	{
		Blueberry_API extern HINSTANCE		g_hinstance;		//!< instance of program
		Blueberry_API extern HWND			g_hwnd;				//!< handle to window
		Blueberry_API extern HDC			g_hdc;				//!< device context
		Blueberry_API extern HGLRC			g_hglrc;			//!< render context
	}

	namespace Window
	{
		Blueberry_API extern LPCSTR			g_wnd_title;		//!< title of window
		Blueberry_API extern LPCSTR			g_wnd_name;			//!< name of window
		Blueberry_API extern int			g_wnd_width;		//!< window width
		Blueberry_API extern int			g_wnd_height;		//!< window height
		Blueberry_API extern int			g_wnd_x;			//!< window x
		Blueberry_API extern int			g_wnd_y;			//!< window y
	}

	namespace App
	{
		Blueberry_API extern int			g_bits_color;		//!< BB_Color bits
		Blueberry_API extern int			g_bits_depth;		//!< BB_Color depth
		Blueberry_API extern int			g_bits_alpha;		//!< BB_Color alpha
		Blueberry_API extern bool			g_fullscreen;		//!< window runs in fullscreen
		Blueberry_API extern bool			g_active;			//!< window is active
	}

	namespace BoundingBox
	{
		Blueberry_API extern bool			g_show;				//!< show bounding box
		Blueberry_API extern float			g_line_width;		//!< line width of bounding box
		Blueberry_API extern float			g_line_color[3];	//!< line color of bounding box
	}
}

//==================================================================
//	ENUM & STRUCTS
//==================================================================
namespace BB_Enum
{
	enum gbResult
	{
		BB_OK = 0,
		BB_ERROR = 1,
		BB_STOP = 2,
		BB_NOTFOUND = 3
	};
}

namespace BB_Struct
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
namespace BB_Func
{
	Blueberry_API BB_Enum::gbResult Initialize();
	Blueberry_API BB_Enum::gbResult InitializeDebugConsole();
	Blueberry_API BB_Enum::gbResult MessageLoop(BB_Enum::gbResult(*func_render)(float));
	Blueberry_API BB_Enum::gbResult Exit();

	std::string ExtractFile(std::string file);
	std::string ExtractName(std::string file);
	std::string ExtractPath(std::string file);
	std::string IntToStr(int value);
	VOID		SplitString(const string& str, vector<string>& token, const string& seperator);
}

//==================================================================
//	INCLUDE HEADER OF ENGINE
//==================================================================
/*
#include "BB_Exception.h"
#include "BB_Errors.h"
#include "BB_Log.h"
#include "BB_Timer.h"
#include "BB_Convert.h"
#include "BB_Array.h"
#include "BB_Matrix.h"
#include "BB_Vector3.h"
#include "BB_Vector2.h"
#include "BB_Color.h"
#include "BB_OpenGL.h"
#include "BB_BB3D.h"
#include "BB_Material.h"
#include "BB_Texture.h"
#include "BB_TextureManager.h"
#include "BB_Loader.h"
#include "BB_Mesh.h"
#include "BB_MeshManager.h"
#include "BB_MeshQueue.h"
#include "BB_Model.h"
#include "BB_Object.h"
*/
