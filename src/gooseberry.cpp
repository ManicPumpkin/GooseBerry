/**
	@file	gooseberry.cpp
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

	Copyright 2013. All rights reserved by 
	Rubner, Danny.
**/
//==================================================================
//	INCLUDE
//==================================================================
#include "gooseberry.h"

//==================================================================
//	NAMESPACE
//==================================================================
using namespace gbGlobal;

//==================================================================
//	VARIABLES
//==================================================================
HINSTANCE	gbGlobal::gb_g_hinstance = NULL;
HWND		gbGlobal::gb_g_HWND = NULL;
HDC			gbGlobal::gb_g_HDC = NULL;
HGLRC		gbGlobal::gb_g_HGLRC = NULL;
LPCSTR		gbGlobal::gb_g_wndTitle = "";
LPCSTR		gbGlobal::gb_g_wndName = "";
int			gbGlobal::gb_g_wndWidth = -1;
int			gbGlobal::gb_g_wndHeight = -1;
int			gbGlobal::gb_g_wndX = -1;
int			gbGlobal::gb_g_wndY = -1;
int			gbGlobal::gb_g_bitsColor = -1;
int			gbGlobal::gb_g_bitsDepth = -1;
int			gbGlobal::gb_g_bitsAlpha = -1;
bool		gbGlobal::gb_g_fullscreen = FALSE;
bool		gbGlobal::gb_g_init = FALSE;
bool		gbGlobal::gb_g_active = TRUE;
bool		gbGlobal::gb_g_keys[256];

//==================================================================
/**
	@fn		gbInitialize
	@brief	Initialize the game engine
**/
//==================================================================
GOOSEBERRY_API gbResult gbGlobal::gbInitialize()
{
	if(!gb_g_init)
	{
		gbInitializeLog();
		GB_LDEBUG("GooseBerry initialized");
	}

	gb_g_init = TRUE;
	return GB_OK;
}

//==================================================================
/**
	@fn		gbMessageLoop
	@brief	Enter message loop
**/
//==================================================================
GOOSEBERRY_API gbResult gbGlobal::gbMessageLoop(gbResult(*pRender)(float))
{
	MSG			tMSG;
	LONGLONG	tStartTime	= 0.0f;
	LONGLONG	tEndTime	= 0.0f;
	LONGLONG	tInitTime	= 0.0f;
	DOUBLE		tTime		= 0.0f;
	BOOL		tQuit		= FALSE;

	GB_LDEBUG("Enter message loop");
	QueryPerformanceCounter((LARGE_INTEGER*)(&tInitTime));
	ZeroMemory(&tMSG, sizeof(tMSG));

	while(!tQuit)
	{
		QueryPerformanceCounter((LARGE_INTEGER*)(&tStartTime));

		while(PeekMessage(&tMSG, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&tMSG);
			DispatchMessage(&tMSG);

			if(tMSG.message == WM_QUIT)
				tQuit = TRUE;
		}

		if(gb_g_active)	
		{
			if(gb_g_keys[VK_ESCAPE])
				tQuit	= TRUE;
			else
			{
				pRender((float)tTime);
				SwapBuffers(gb_g_HDC);
			}
		}

		if(gb_g_keys[VK_F1])
		{
			gb_g_keys[VK_F1]	= FALSE;
			gb_g_fullscreen	    = !gb_g_fullscreen;
			gbGlobal::gbExit();

			if (gbGlobal::gbInitialize() != GB_OK)
				throw gbException(ERR_WIN_FS_STR, ERR_WIN_FS_ID);
		}

		if(ONLY_COMPILE)
			tQuit = TRUE;

		QueryPerformanceCounter((LARGE_INTEGER*)(&tEndTime));
		if(tEndTime == tStartTime) 
			tTime	= 0.0001;
		else
			tTime	= (tEndTime - tStartTime) / tInitTime;
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
GOOSEBERRY_API gbResult gbGlobal::gbExit()
{
	GB_LDEBUG("Gooseberry stopped");
	gbStopLog();
	return GB_OK;
}

//==================================================================
/**
		@fn		gbIntToString(int pInt);
		@param	pInt	int to convert
		@brief	Converts int to string
		@return std::string tString
**/
//==================================================================
std::string gbGlobal::gbIntToStr(int pInt)
{
	ostringstream tConvert;
	tConvert << pInt;
	return tConvert.str();
}

//==================================================================
/**
		@fn		gbExtractName(std::string pFile)
		@param	pFile	name of file to extract
		@brief	Extracts object name from file name
		@return std::string tName
**/
//==================================================================
std::string gbGlobal::gbExtractName(std::string pFile)
{
	int tStartSubStr	= 0;
	int tEndSubStr		= 0;

	if(	strncmp("./", pFile.c_str(), 2) == 0 || strncmp("/", pFile.c_str(), 1) == 0)
		tStartSubStr	= pFile.find_last_of("/") + 1;

	tEndSubStr			= pFile.find_last_of(".");
	return pFile.substr(tStartSubStr, tEndSubStr - tStartSubStr);
}

//==================================================================
/**
		@fn		gbExtractPath(std::string pFile)
		@param	pFile	name of file to extract
		@brief	Extracts path of file string
		@return std::string tPath
**/
//==================================================================
std::string gbGlobal::gbExtractPath(std::string pFile)
{
	int tEndSubStr		= 0;

	if(	strncmp("./", pFile.c_str(), 2) == 0 || strncmp("/", pFile.c_str(), 1) == 0)
		tEndSubStr		= pFile.find_last_of("/") + 1;

	return pFile.substr(0, tEndSubStr);
}

//==================================================================
/**
	@fn		gbSplitString
	@brief	Split string into sub string
	@param	pStr		std::string to split
	@param	pToken		vector of tokens (sub strings)
	@param	pSeperator	delemiter
**/
//==================================================================
VOID gbGlobal::gbSplitString(const string& pStr, vector<string>& pToken, const string& pSeperator)
{
	string::size_type tLastPos	= pStr.find_first_not_of(pSeperator, 0);
	string::size_type tPos		= pStr.find_first_of(pSeperator, tLastPos);

	while(string::npos != tPos || string::npos != tLastPos)
	{
		pToken.push_back(pStr.substr(tLastPos, tPos - tLastPos));
		tLastPos	= pStr.find_first_not_of(pSeperator, tPos);
		tPos		= pStr.find_first_of(pSeperator, tLastPos);
	}	
}