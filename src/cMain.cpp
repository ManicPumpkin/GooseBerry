/**
	@file	cMain.cpp
	@brief	Includes main programm
	@author	drubner
	@date	2012-11-15

	\mainpage GooseBerry Game Engine Project

	This project is developed for simple games like "Cube" and its functions based
	OpenGL 4.3.

	\section Description
	Game Engine based on OpenGL 4.3

	\section Autors
	-	RUBNER,		Danny

	Copyright 2013. All rights reserved by 
	Rubner, Danny.
**/
//==================================================================
//	INCLUDE
//==================================================================
#include "hLibraries.h"
//==================================================================
#include "cRayTracing.h"
//==================================================================
/**
	@fn		WinMain
	@brief	WinMain methods starts application and win form
	@param	pHinst		handle instance of current window
	@param	pPrevHinst	handle of previous window
	@param	lLpCmdLine	command line for the application
	@param	pCmdShow	controls how the window is to be shown
**/
//==================================================================
int APIENTRY WinMain(HINSTANCE pHinst, HINSTANCE pPrevHinst, LPSTR pLpCmdLine, int pCmdShow)
{
	Application::Run(gcnew cRayTracing());
	return TRUE;
}
//==================================================================