/**
@file	GooseBerryTestingApplication.cc
@brief	Includes main program
@author	drubner
@date	2013-12-17
**/
//==================================================================
//	PRAGMA
//==================================================================
#pragma comment(lib, "GooseBerry.lib")

//==================================================================
//	INCLUDE
//==================================================================
#include <iostream>
#include <stdio.h>
#include <tchar.h>
#include <Windows.h>

//#include "..\..\Log\inc\Log.h"
#include ".\..\..\GooseBerry\inc\gooseberry.h"

//==================================================================
//	NAMESPACE
//==================================================================
using namespace std;

//==================================================================
//	GLOBALS
//==================================================================
GB_OpenGL	g_open_gl;
bool		g_render_init = FALSE;

//==================================================================
//	PREDEFINITION
//==================================================================
GB_Enum::gbResult Initialize();
GB_Enum::gbResult Exit();
GB_Enum::gbResult Load();
GB_Enum::gbResult Unload();
GB_Enum::gbResult Show(HWND hwnd);
GB_Enum::gbResult Run();
GB_Enum::gbResult Render(float time);

//==================================================================
//	MAIN
//==================================================================
int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE h_prev_instance, PSTR cmd_line, int cmd_show)
{
	GB_Settings::OpenGL::g_hinstance		= hinstance;
	GB_Settings::OpenGL::g_hwnd				= NULL;
	GB_Settings::Window::g_wnd_title		= "GooseBerryTestApplication";
	GB_Settings::Window::g_wnd_name			= "GooseBerryTestApplication";
	GB_Settings::Window::g_wnd_width		= 800;
	GB_Settings::Window::g_wnd_height		= 600;
	GB_Settings::Window::g_wnd_x			= 0;
	GB_Settings::Window::g_wnd_y			= 0;
	GB_Settings::App::g_bits_color			= 32;
	GB_Settings::App::g_bits_depth			= 32;
	GB_Settings::App::g_bits_alpha			= 32;
	GB_Settings::App::g_fullscreen			= FALSE;
	GB_Settings::App::g_active				= TRUE;

	//Log::getInstance()->set_file_path_and_name(string("log"), string("log.html"));
	//Log::getInstance()->debug_mode_ = true;
	GB_LDEBUG("GooseBerryTestingApplication started");
	GB_LDEBUG("Log system initialized succesfully");

	//	Start code here
	try
	{
		GB_Func::Initialize();

		//	initialize, show, run, exit
		Initialize();
		Show(GB_Settings::OpenGL::g_hwnd);
		Run();
		Exit();

	}
	catch (const GB_Exception &exception)
	{
		GB_LERROR(exception.GetStr(), exception.GetId());
		GB_MSGBOXERR(exception.GetStr(), exception.GetId());
	}

	GB_LDEBUG("GooseBerryTestingApplication finished");
	if (GB_Func::Exit())
		throw GB_Exception(ERR_GB_EXIT_STR, ERR_GB_EXIT_ID);

	return 0;
}

GB_Enum::gbResult Initialize()
{
	GB_LINFO("Initialize application");
	g_open_gl.StartWnd();

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	//glEnable(GL_BLEND);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_LIGHTING);
	//glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	//	GB Settings
	//GB_Settings::BoundingBox::g_show	= false;

	if (Load())
		throw GB_Exception(ERR_G_LOAD_STR, ERR_G_LOAD_ID);

	return GB_Enum::GB_OK;
}

GB_Enum::gbResult Exit()
{
	GB_LINFO("Exit application");

	if (Unload())
		throw GB_Exception(ERR_G_EXIT_STR, ERR_G_EXIT_ID);

	return GB_Enum::GB_OK;
}

GLuint texture_nr = 0;
GB_Model * test_model_1;
GB_Model * test_model_2;
GB_Model * test_model_3;
GB_Model * test_model_4;

GB_Enum::gbResult Load()
{
	GB_LDEBUG("Load application");

	//	load some stuff starts here ...
	int t1, t2, t3;
	TEXMANAGER->LoadTexture(".\\dta\\pumpkin_64x64_black.jpg", &t1);
	TEXMANAGER->LoadTexture(".\\dta\\pumpkin_64x64_white.jpg", &t2);
	TEXMANAGER->LoadTexture(".\\dta\\pumpkin_64x64_grey.jpg", &t3);

	GB_LDEBUG("Loading models");
	test_model_1	= new GB_Model(".\\dta\\cube_pumpkin_black.obj", t1);
	test_model_2	= new GB_Model(".\\dta\\cube_pumpkin_white.obj", t1);
	test_model_3	= new GB_Model(".\\dta\\cube_pumpkin_white.obj");
	test_model_4	= new GB_Model(test_model_3->mesh_, t3);

	return GB_Enum::GB_OK;
}

GB_Enum::gbResult Unload()
{
	GB_LDEBUG("Unload application");

	//	unload some stuff starts here ...
	//	... and ends up here.

	return GB_Enum::GB_OK;
}

GB_Enum::gbResult Show(HWND hwnd)
{
	GB_LDEBUG("Showing window");
	ShowWindow(hwnd, SW_SHOW);
	SetForegroundWindow(hwnd);
	SetFocus(hwnd);
	
	return GB_Enum::GB_OK;
}

GB_Enum::gbResult Run()
{
	GB_LINFO("Run application");

	if (GB_Func::MessageLoop(Render))
		GB_LERROR(ERR_GB_MSGL_STR, ERR_GB_MSGL_ID);

	return GB_Enum::GB_OK;
}

float rotatef = 0.0f;

GB_Enum::gbResult Render(float time)
{
	if (!g_render_init)
	{
		g_render_init = TRUE;
		GB_LDEBUG("Start render process");
	}

	//	Render stuff starts here ...
	Sleep(1 / 50.0f);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, 1, 1, 10);
	gluLookAt(0, 4, 4, 0, 0, 0, 0, 1, 0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	if (rotatef > 360.0f)
		rotatef = 0.0f;

	rotatef += 0.5f;
	glRotatef(rotatef, 0.0f, 1.0f, 0.0f);
	glPushMatrix();
	glTranslatef(0.75f, 0.0f, 0.75f);
	test_model_1->Draw();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-0.75f, 0.0f, 0.75f);
	test_model_2->Draw();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.75f, 0.0f, -0.75f);
	test_model_3->Draw();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-0.75f, 0.0f, -0.75f);
	test_model_4->Draw();
	glPopMatrix();

	glFlush();
	//glutSwapBuffers();

	//	... and ends here.

	return GB_Enum::GB_OK;
}