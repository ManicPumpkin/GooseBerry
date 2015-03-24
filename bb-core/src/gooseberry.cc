/**
	@file	Blueberry.cpp
	@brief	Includes main programm
	@author	drubner
	@date	2013-07-16

	\mainpage Blueberry Game Engine Project

	This project is developed for games and provides all useful
	classes, like BB_Matrix , vector or BB_Object classes, they are
	necessary to build a playable game with full functionality. 
	Blueberry is based on BB_OpenGL and is used in the "Cube" game
	project and its litle sister the world generator project 
	"WorldGen".

	\section Description
	Game Engine based on BB_OpenGL

	\section Autors
	-	RUBNER,		Danny

	� Copyright 2014. All rights reserved by 
	Rubner, Danny.
**/
//==================================================================
//	INCLUDE
//==================================================================
#include "Blueberry.h"

//==================================================================
//	NAMESPACE
//==================================================================
using namespace BB_Enum;

//==================================================================
//	VARIABLES
//==================================================================
HINSTANCE	BB_Settings::OpenGL::g_hinstance			= NULL;
HWND		BB_Settings::OpenGL::g_hwnd					= NULL;
HDC			BB_Settings::OpenGL::g_hdc					= NULL;
HGLRC		BB_Settings::OpenGL::g_hglrc				= NULL;

bool		BB_Settings::Debug::g_debug_mode			= true;
bool		BB_Settings::Debug::g_only_compile			= false;

LPCSTR		BB_Settings::Window::g_wnd_title			= "";
LPCSTR		BB_Settings::Window::g_wnd_name				= "";
int			BB_Settings::Window::g_wnd_width			= -1;
int			BB_Settings::Window::g_wnd_height			= -1;
int			BB_Settings::Window::g_wnd_x				= -1;
int			BB_Settings::Window::g_wnd_y				= -1;

int			BB_Settings::App::g_bits_color				= -1;
int			BB_Settings::App::g_bits_depth				= -1;
int			BB_Settings::App::g_bits_alpha				= -1;
bool		BB_Settings::App::g_fullscreen				= FALSE;
bool		BB_Settings::App::g_active					= TRUE;

bool		BB_Settings::Engine::g_initialized			= FALSE;
bool		BB_Settings::Engine::g_keys[256];

bool		BB_Settings::BoundinBBox::g_show			= TRUE;
float		BB_Settings::BoundinBBox::g_line_width		= 1.0f;
float		BB_Settings::BoundinBBox::g_line_color[]	= {1.0f, 1.0f, 1.0f};

//==================================================================
/**
	@fn		Initialize
	@brief	Initialize the game engine
**/
//==================================================================
Blueberry_API BB_Enum::BBResult BB_Func::Initialize()
{
	BB_Timer timer;
	timer.Start();

	if (BB_Settings::Debug::g_debug_mode)
	{
		InitializeDebugConsole();
		BB_LDEBUG("DebugConsole initialized");
	}

	if(!BB_Settings::Engine::g_initialized)
	{
		InitializeLog();
		BB_LDEBUG("Blueberry initialized");
	}

	BB_Settings::Engine::g_initialized = TRUE;
	timer.Stop();
	timer.Result();
	return BB_OK;
}

//==================================================================
/**
@fn		InitializeDebugConsole();
@brief	Initialize the debug console
**/
//==================================================================
Blueberry_API BB_Enum::BBResult BB_Func::InitializeDebugConsole()
{
	AllocConsole();
	AttachConsole(ATTACH_PARENT_PROCESS);

	HANDLE	handle_out = GetStdHandle(STD_OUTPUT_HANDLE);
	int hCrt = _open_osfhandle((long)handle_out, _O_TEXT);
	FILE* hf_out = _fdopen(hCrt, "w");
	setvbuf(hf_out, NULL, _IONBF, 1);
	*stdout = *hf_out;

	HANDLE handle_in = GetStdHandle(STD_INPUT_HANDLE);
	hCrt = _open_osfhandle((long)handle_in, _O_TEXT);
	FILE* hf_in = _fdopen(hCrt, "r");
	setvbuf(hf_in, NULL, _IONBF, 128);
	*stdin = *hf_in;

	return BB_OK;
}

//==================================================================
/**
	@fn		MessageLoop
	@brief	Enter message loop
**/
//==================================================================
Blueberry_API BB_Enum::BBResult BB_Func::MessageLoop(BB_Enum::BBResult(*Render)(float))
{
	MSG			msg;
	LONGLONG	start_time	= 0.0f;
	LONGLONG	end_time	= 0.0f;
	LONGLONG	init_time	= 0.0f;
	DOUBLE		time		= 0.0f;
	BOOL		quit		= FALSE;

	BB_LDEBUG("Enter message loop");
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

		if(BB_Settings::App::g_active)
		{
			if(BB_Settings::Engine::g_keys[VK_ESCAPE])
				quit	= TRUE;
			else
			{
				Render((float)time);
				SwapBuffers(BB_Settings::OpenGL::g_hdc);
			}
		}

		if(BB_Settings::Engine::g_keys[VK_F1])
		{
			BB_Settings::Engine::g_keys[VK_F1]	= FALSE;
			BB_Settings::App::g_fullscreen	= !BB_Settings::App::g_fullscreen;
			BB_Func::Exit();

			if (BB_Func::Initialize() != BB_OK)
				throw BB_Exception(ERR_WIN_FS_STR, ERR_WIN_FS_ID);
		}

		if(BB_Settings::Debug::g_only_compile)
			quit = TRUE;

		QueryPerformanceCounter((LARGE_INTEGER*)(&end_time));
		if(end_time == start_time) 
			time	= 0.0001;
		else
			time	= (end_time - start_time) / init_time;
	}

	BB_LDEBUG("Exit message loop");
	return BB_OK;
}

//==================================================================
/**
	@fn		Blueberry :: ~glooseberry
	@brief	Deconstructor
**/
//==================================================================
Blueberry_API BB_Enum::BBResult BB_Func::Exit()
{
	BB_LDEBUG("Blueberry stopped");
	StopLog();

	if (BB_Settings::Debug::g_debug_mode)
		FreeConsole();

	return BB_OK;
}

//==================================================================
/**
		@fn		IntToStr(int value);
		@param	value	int to BB_Convert
		@brief	BB_Converts int to string
		@return std::string tString
**/
//==================================================================
std::string BB_Func::IntToStr(int value)
{
	ostringstream BB_Convert;
	BB_Convert << value;
	return BB_Convert.str();
}

//==================================================================
/**
@fn		ExtractFile(std::string file)
@param	file	name of file to extract
@brief	Extracts BB_Object name from file name
@return std::string tName
**/
//==================================================================
std::string BB_Func::ExtractFile(std::string file)
{
	int start_sub_str = 0;
	int end_sub_str = 0;

	if (strncmp("./", file.c_str(), 2) == 0 || strncmp("/", file.c_str(), 1) == 0)
		start_sub_str = file.find_last_of("/") + 1;

	if (strncmp(".\\", file.c_str(), 2) == 0 || strncmp("\\", file.c_str(), 1) == 0)
		start_sub_str = file.find_last_of("\\") + 1;

	end_sub_str = file.find_last_of(".");
	return file.substr(start_sub_str, end_sub_str);
}

//==================================================================
/**
		@fn		ExtractName(std::string file)
		@param	file	name of file to extract
		@brief	Extracts BB_Object name from file name
		@return std::string tName
**/
//==================================================================
std::string BB_Func::ExtractName(std::string file)
{
	int start_sub_str	= 0;
	int end_sub_str		= 0;

	if(	strncmp("./", file.c_str(), 2) == 0 || strncmp("/", file.c_str(), 1) == 0)
		start_sub_str	= file.find_last_of("/") + 1;

	if (strncmp(".\\", file.c_str(), 2) == 0 || strncmp("\\", file.c_str(), 1) == 0)
		start_sub_str	= file.find_last_of("\\") + 1;

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
std::string BB_Func::ExtractPath(std::string file)
{
	int end_sub_str		= 0;

	if(	strncmp("./", file.c_str(), 2) == 0 || strncmp("/", file.c_str(), 1) == 0)
		end_sub_str = file.find_last_of("/") + 1;

	if (strncmp(".\\", file.c_str(), 2) == 0 || strncmp("\\", file.c_str(), 1) == 0)
		end_sub_str = file.find_last_of("\\") + 1;

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
VOID BB_Func::SplitString(const string& str, vector<string>& token, const string& seperator)
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
