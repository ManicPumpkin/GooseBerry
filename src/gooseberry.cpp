/**
	@file	glooseberry.cpp
	@brief	Includes all glooseberry class methods
	@author	drubner
	@date	2013-07-16
**/
//==================================================================
//	Include
//==================================================================
#include "gooseberry.h"

//==================================================================
//	Namespace
//==================================================================

//==================================================================
//	Variables
//==================================================================
HINSTANCE	gb_g_hinstance	= NULL;
HWND		gb_g_HWND		= NULL;
HDC			gb_g_HDC		= NULL;
HGLRC		gb_g_HGLRC		= NULL;
LPCSTR		gb_g_wndTitle	= "";
LPCSTR		gb_g_wndName	= "";
int			gb_g_wndWidth	= -1;
int			gb_g_wndHeight  = -1;
int			gb_g_wndX		= -1;
int			gb_g_wndY		= -1;
int			gb_g_bitsColor	= -1;
int			gb_g_bitsDepth	= -1;
int			gb_g_bitsAlpha	= -1;
bool		gb_g_fullscreen = FALSE;
bool		gb_g_init		= FALSE;
bool		gb_g_active		= TRUE;
bool		gb_g_keys[256];

//gbOpenGL *	gb_g_openGL		= NULL;

//==================================================================
/**
	@fn		gooseberry :: ~glooseberry
	@brief	Deconstructor
**/
//==================================================================
GOOSEBERRY_API gbResult gbExit()
{
	gbStopLog();
	return GB_OK;
}

//==================================================================
/**
	@fn		gooseberry :: fInitialize
	@brief	Initialize the game engine
**/
//==================================================================
GOOSEBERRY_API gbResult gbInitialize()
{
	if(!gb_g_init)
	{
		gbInitializeLog();
		GB_LINFO("Initialize GooseBerry");
	}

	gb_g_init = TRUE;
	return GB_OK;
}

//==================================================================
/**
		@fn		gbExtractName(std::string pFile)
		@param	pFile	name of file to extract
		@brief	Extracts object name from file name
		@return std::string tName
**/
//==================================================================
std::string gbExtractName(std::string pFile)
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
std::string gbExtractPath(std::string pFile)
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
VOID gbSplitString(const string& pStr, vector<string>& pToken, const string& pSeperator)
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