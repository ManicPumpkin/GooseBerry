/**
	@file	GooseBerry.cpp
	@brief	Includes main programm
	@author	drubner
	@date	2013-07-16

	\mainpage GooseBerry Game Engine Project

	This project is developed for games and provides all useful
	classes, like GB_Matrix , vector or GB_Object classes, they are 
	necessary to build a playable game with full functionality. 
	Gooseberry is based on GB_OpenGL and is used in the "Cube" game 
	project and its litle sister the world generator project 
	"WorldGen".

	\section Description
	Game Engine based on GB_OpenGL

	\section Autors
	-	RUBNER,		Danny

	© Copyright 2014. All rights reserved by 
	Rubner, Danny.
**/
//==================================================================
//	INCLUDE
//==================================================================
#include "gooseberry.h"

//==================================================================
//	NAMESPACE
//==================================================================
using namespace GB_Enum;

//==================================================================
//	VARIABLES
//==================================================================
HINSTANCE	GB_Settings::OpenGL::g_hinstance			= NULL;
HWND		GB_Settings::OpenGL::g_hwnd					= NULL;
HDC			GB_Settings::OpenGL::g_hdc					= NULL;
HGLRC		GB_Settings::OpenGL::g_hglrc				= NULL;

LPCSTR		GB_Settings::Window::g_wnd_title			= "";
LPCSTR		GB_Settings::Window::g_wnd_name				= "";
int			GB_Settings::Window::g_wnd_width			= -1;
int			GB_Settings::Window::g_wnd_height			= -1;
int			GB_Settings::Window::g_wnd_x				= -1;
int			GB_Settings::Window::g_wnd_y				= -1;

int			GB_Settings::App::g_bits_color				= -1;
int			GB_Settings::App::g_bits_depth				= -1;
int			GB_Settings::App::g_bits_alpha				= -1;
bool		GB_Settings::App::g_fullscreen				= FALSE;
bool		GB_Settings::App::g_active					= TRUE;

bool		GB_Settings::Engine::g_initialized			= FALSE;
bool		GB_Settings::Engine::g_keys[256];

bool		GB_Settings::BoundingBox::g_show			= TRUE;			
float		GB_Settings::BoundingBox::g_line_width		= 1.0f;		
float		GB_Settings::BoundingBox::g_line_color[]	= {1.0f, 1.0f, 1.0f};

//==================================================================
/**
	@fn		Initialize
	@brief	Initialize the game engine
**/
//==================================================================
GOOSEBERRY_API GB_Enum::gbResult GB_Func::Initialize()
{
	if(!GB_Settings::Engine::g_initialized)
	{
		InitializeLog();
		GB_LDEBUG("GooseBerry initialized");
	}

	//GB_SimpleMeshes::gbCube = GB_MeshLoader::GetInstance()->LoadObj(".//dta//cube.obj");
	GB_Loader::LoadMeshFile(".//dta//cube.obj", &GB_SimpleMeshes::gbCube);

	GB_Settings::Engine::g_initialized = TRUE;
	return GB_OK;
}

//==================================================================
/**
	@fn		MessageLoop
	@brief	Enter message loop
**/
//==================================================================
GOOSEBERRY_API GB_Enum::gbResult GB_Func::MessageLoop(GB_Enum::gbResult(*Render)(float))
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

		if(GB_Settings::App::g_active)	
		{
			if(GB_Settings::Engine::g_keys[VK_ESCAPE])
				quit	= TRUE;
			else
			{
				Render((float)time);
				SwapBuffers(GB_Settings::OpenGL::g_hdc);
			}
		}

		if(GB_Settings::Engine::g_keys[VK_F1])
		{
			GB_Settings::Engine::g_keys[VK_F1]	= FALSE;
			GB_Settings::App::g_fullscreen	= !GB_Settings::App::g_fullscreen;
			GB_Func::Exit();

			if (GB_Func::Initialize() != GB_OK)
				throw GB_Exception(ERR_WIN_FS_STR, ERR_WIN_FS_ID);
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
GOOSEBERRY_API GB_Enum::gbResult GB_Func::Exit()
{
	GB_LDEBUG("Gooseberry stopped");
	StopLog();
	return GB_OK;
}

//==================================================================
/**
		@fn		IntToStr(int value);
		@param	value	int to GB_Convert
		@brief	GB_Converts int to string
		@return std::string tString
**/
//==================================================================
std::string IntToStr(int value)
{
	ostringstream GB_Convert;
	GB_Convert << value;
	return GB_Convert.str();
}

//==================================================================
/**
@fn		ExtractFile(std::string file)
@param	file	name of file to extract
@brief	Extracts GB_Object name from file name
@return std::string tName
**/
//==================================================================
std::string GB_Func::ExtractFile(std::string file)
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
		@brief	Extracts GB_Object name from file name
		@return std::string tName
**/
//==================================================================
std::string GB_Func::ExtractName(std::string file)
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
std::string GB_Func::ExtractPath(std::string file)
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
VOID GB_Func::SplitString(const string& str, vector<string>& token, const string& seperator)
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