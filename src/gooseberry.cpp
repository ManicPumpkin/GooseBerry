/**
	@file	GooseBerry.cpp
	@brief	Includes main programm
	@author	drubner
	@date	2013-07-16

	\mainpage GooseBerry Game Engine Project

	This project is developed for games and provides all useful
	classes, like matrix, vector or object classes, they are 
	necessary to build a playable game with full functionality. 
	Gooseberry is based on OpenGL and is used in the "Cube" game 
	project and its little sister the world generator project 
	"WorldGen".

	\section Description
	Game Engine based on OpenGL

	\section Autors
	-	RUBNER,		Danny

	Coyright 2013. All rights reserved by 
	Rubner, Danny.
**/
//==================================================================
//	INCLUDE
//==================================================================
#include "GooseBerry.h"

//==================================================================
//	NAMESPACE
//==================================================================
using namespace gbGlobal;

//==================================================================
//	VARIABLES
//==================================================================
HINSTANCE	gbGlobal::g_hinstance = NULL;
HWND		gbGlobal::g_HWND = NULL;
HDC			gbGlobal::g_HDC = NULL;
HGLRC		gbGlobal::g_HGLRC = NULL;
LPCSTR		gbGlobal::g_wndTitle = "";
LPCSTR		gbGlobal::g_wndName = "";
int			gbGlobal::g_wndWidth = -1;
int			gbGlobal::g_wndHeight = -1;
int			gbGlobal::g_wndX = -1;
int			gbGlobal::g_wndY = -1;
int			gbGlobal::g_bitsColor = -1;
int			gbGlobal::g_bitsDepth = -1;
int			gbGlobal::g_bitsAlpha = -1;
bool		gbGlobal::g_fullscreen = FALSE;
bool		gbGlobal::g_init = FALSE;
bool		gbGlobal::g_active = TRUE;
bool		gbGlobal::g_keys[256];

//==================================================================
/**
	@fn		Initialize
	@brief	Initialize the game engine
**/
//==================================================================
GOOSEBERRY_API gbResult gbGlobal::Initialize()
{
	if(!g_init)
	{
		InitializeLog();
		GB_LDEBUG("GooseBerry initialized");
	}

	g_init = TRUE;
	return GB_OK;
}

//==================================================================
/**
	@fn		MessageLoop
	@brief	Enter message loop
**/
//==================================================================
GOOSEBERRY_API gbResult gbGlobal::MessageLoop(gbResult(*pRender)(float))
{
	MSG			msg;
	LONGLONG	start_time	= 0.0f;
	LONGLONG	end_time	= 0.0f;
	LONGLONG	init_time	= 0.0f;
	DOUBLE		time		= 0.0f;
	BOOL		quit		= FALSE;

	GB_LDEBUG("Enter message loop");
	QueryPerformanceCounter((LARGE_INTEGER*)(&init_time));
	ZeroMemory(&msg, sizeof(msg));

	while(!quit)
	{
		QueryPerformanceCounter((LARGE_INTEGER*)(&start_time));

		while(PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);

			if(msg.message == WM_QUIT)
				quit = TRUE;
		}

		if(g_active)	
		{
			if(g_keys[VK_ESCAPE])
				quit	= TRUE;
			else
			{
				pRender((float)time);
				SwapBuffers(g_HDC);
			}
		}

		if(g_keys[VK_F1])
		{
			g_keys[VK_F1]	= FALSE;
			g_fullscreen	    = !g_fullscreen;
			gbGlobal::Exit();

			if (gbGlobal::Initialize() != GB_OK)
				throw gbException(ERR_WIN_FS_STR, ERR_WIN_FS_ID);
		}

		if(ONLY_COMPILE)
			quit = TRUE;

		QueryPerformanceCounter((LARGE_INTEGER*)(&end_time));
		if(end_time == start_time) 
			time	= 0.0001;
		else
			time	= (end_time - start_time) / init_time;
	}

	GB_LDEBUG("Exit message loop");
	return GB_OK;
}

//==================================================================
/**
	@fn		gooseberry :: ~glooseberry
	@brief	Deconstructor
**/
//==================================================================
GOOSEBERRY_API gbResult gbGlobal::Exit()
{
	GB_LDEBUG("Gooseberry stopped");
	StopLog();
	return GB_OK;
}

//==================================================================
/**
		@fn		IntToString(int value);
		@param	value	int to convert
		@brief	Converts int to string
		@return std::string tString
**/
//==================================================================
std::string gbGlobal::IntToStr(int value)
{
	ostringstream convert;
	convert << value;
	return convert.str();
}

//==================================================================
/**
		@fn		ExtractName(std::string file)
		@param	file	name of file to extract
		@brief	Extracts object name from file name
		@return std::string tName
**/
//==================================================================
std::string gbGlobal::ExtractName(std::string file)
{
	int start_sub_str	= 0;
	int end_sub_str		= 0;

	if(	strncmp("./", file.c_str(), 2) == 0 || strncmp("/", file.c_str(), 1) == 0)
		start_sub_str	= file.find_last_of("/") + 1;

	end_sub_str			= file.find_last_of(".");
	return file.substr(start_sub_str, end_sub_str - start_sub_str);
}

//==================================================================
/**
		@fn		ExtractPath(std::string file)
		@param	file	name of file to extract
		@brief	Extracts path of file string
		@return std::string tPath
**/
//==================================================================
std::string gbGlobal::ExtractPath(std::string file)
{
	int end_sub_str		= 0;

	if(	strncmp("./", file.c_str(), 2) == 0 || strncmp("/", file.c_str(), 1) == 0)
		end_sub_str		= file.find_last_of("/") + 1;

	return file.substr(0, end_sub_str);
}

//==================================================================
/**
	@fn		SplitString
	@brief	Split string into sub string
	@param	str		std::string to split
	@param	token		vector of tokens (sub strings)
	@param	seperator	delemiter
**/
//==================================================================
VOID gbGlobal::SplitString(const string& str, vector<string>& token, const string& seperator)
{
	string::size_type last_pos	= str.find_first_not_of(seperator, 0);
	string::size_type pos		= str.find_first_of(seperator, last_pos);

	while(string::npos != pos || string::npos != last_pos)
	{
		token.push_back(str.substr(last_pos, pos - last_pos));
		last_pos	= str.find_first_not_of(seperator, pos);
		pos		= str.find_first_of(seperator, last_pos);
	}	
}