/**
	@file	GB_OpenGL.cpp
	@brief	Initializes and enables GB_OpenGL 
	@author	drubner
	@date	2013-07-16
**/
//==================================================================
//	INCLUDE
//==================================================================
#include "gooseberry.h"
#include "GB_Exception.h"
#include "GB_Errors.h"
#include "GB_Log.h"
#include "GB_OpenGL.h"

//==================================================================
//	NAMESPACE
//==================================================================

//==================================================================
/**
	@fn		GB_OpenGL :: WindowProc
	@brief	Called if window is resized
	@param	wnd_width		width of GB_OpenGL window
	@param	wnd_height		heigh of GB_OpenGL window
**/
//==================================================================
LONG WINAPI WindowProc(HWND hwnd, UINT msg, WPARAM w_param, LPARAM l_param)
{ 
    switch(msg) 
	{
		case WM_CLOSE:
			DestroyWindow(hwnd);
			PostQuitMessage(0);
			return 0;
			break;

		case WM_ACTIVATE:
			if(!HIWORD(w_param))
				GB_Settings::App::g_active		= TRUE;
			else
				GB_Settings::App::g_active		= FALSE;

			return 0;
			break;
		
		case WM_KEYDOWN:
			GB_Settings::Engine::g_keys[w_param]	= TRUE;
			return 0;
			break;

		case WM_KEYUP:
			GB_Settings::Engine::g_keys[w_param]	= FALSE;
			return 0;
			break;
    }

    return DefWindowProc(hwnd, msg, w_param, l_param); 
} 

//==================================================================
//	(De-)Constructor
//==================================================================
/**
	@fn		GB_OpenGL :: GB_OpenGL
	@brief	Initializes model queue, window params, enables and 
			initializes GB_OpenGL
**/
//==================================================================
GB_OpenGL :: GB_OpenGL()
{
	GB_LINFO("GB_OpenGL");
	initialize_	= FALSE;
}

//==================================================================
/**
	@fn		GB_OpenGL :: ~GB_OpenGL
	@brief	Frees memory
**/
//==================================================================
GB_OpenGL :: ~GB_OpenGL()
{
	
}

//==================================================================
//	Functions
//==================================================================
/**
	@fn		GB_OpenGL :: StartWnd
	@brief	Starts this window
**/
//==================================================================
GB_Enum::gbResult GB_OpenGL :: StartWnd()
{
	try
	{
		GB_LDEBUG("Initialize and create GB_OpenGL window");
		if(!initialize_) 
			RegisterWndClass();

		FullscreenWnd();
		CreateGB_OpenGLWnd();
		EnableGB_OpenGL();
		InitializeGB_OpenGL();
		ResizeGB_OpenGLWnd(GB_Settings::Window::g_wnd_width, GB_Settings::Window::g_wnd_height);
	}
	catch(const GB_Exception &tGB_Exception)
	{
		GB_LERROR(tGB_Exception.GetStr(), tGB_Exception.GetId());
		// GB_MSGBOXERR(tGB_Exception.GetStr(), tGB_Exception.GetId());
		return GB_Enum::GB_STOP;
	}

	initialize_	= TRUE;
	return GB_Enum::GB_OK;
}

//==================================================================
/**
	@fn		GB_OpenGL :: ExitWnd
	@brief	Exit window
**/
//==================================================================
GB_Enum::gbResult GB_OpenGL :: ExitWnd()
{
	GB_LDEBUG("Close and destroy GB_OpenGL window");
	wglMakeCurrent(NULL, NULL);
	ReleaseDC(GB_Settings::OpenGL::g_hwnd, GB_Settings::OpenGL::g_hdc);
	wglDeleteContext(GB_Settings::OpenGL::g_hglrc);
	DestroyWindow(GB_Settings::OpenGL::g_hwnd);
	return GB_Enum::GB_OK;
}

//==================================================================
/**
	@fn		GB_OpenGL :: RegisterWndClass
	@brief	Register window class
**/
//==================================================================
GB_Enum::gbResult GB_OpenGL :: RegisterWndClass()
{
	GB_LDEBUG("Register window class");
	GB_Settings::OpenGL::g_hinstance	= GetModuleHandle(NULL);

	WNDCLASS wnd_class		= {};
	wnd_class.style			= CS_OWNDC;
	wnd_class.lpfnWndProc	= (WNDPROC)WindowProc;
	wnd_class.cbClsExtra	= 0;
	wnd_class.cbWndExtra	= 0;
	wnd_class.hInstance		= GB_Settings::OpenGL::g_hinstance;
	wnd_class.hIcon			= LoadIcon(NULL, IDI_WINLOGO);
	wnd_class.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wnd_class.hbrBackground	= NULL;
	wnd_class.lpszMenuName	= NULL;
	wnd_class.lpszClassName = GB_Settings::Window::g_wnd_name;

	if(!RegisterClass(&wnd_class))
		throw GB_Exception(ERR_WIN_CLASS_STR, ERR_WIN_CLASS_ID);

	return GB_Enum::GB_OK;
}

//==================================================================
/**
	@fn		GB_OpenGL :: FullscreenWnd
	@brief	Going fullscreen or not
**/
//==================================================================
GB_Enum::gbResult GB_OpenGL :: FullscreenWnd()
{
	GB_LDEBUG("Seting up screen mode");
	RECT windows_rect;				
	windows_rect.left	= (long)0;			
	windows_rect.right	= (long)GB_Settings::Window::g_wnd_width;		
	windows_rect.top		= (long)0;			
	windows_rect.bottom	= (long)GB_Settings::Window::g_wnd_height;		

	if(GB_Settings::App::g_fullscreen)
	{
		DEVMODE screen_setings;
		memset(&screen_setings, 0, sizeof(screen_setings));
		screen_setings.dmSize			= sizeof(screen_setings);
		screen_setings.dmPelsWidth		= GB_Settings::Window::g_wnd_width;
		screen_setings.dmPelsHeight	= GB_Settings::Window::g_wnd_height;
		screen_setings.dmBitsPerPel	= GB_Settings::App::g_bits_color;
		screen_setings.dmFields		= DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;

		if(ChangeDisplaySettings(&screen_setings, CDS_FULLSCREEN)!=DISP_CHANGE_SUCCESSFUL)
		{
			if(MessageBox(NULL, ERR_GL_FS_STR, ERR_GL_FS_ID, MB_YESNO | MB_ICONEXCLAMATION)==IDYES)
			{
				GB_LWARNING("Fullscreen not supported. Going back to windowed mode.");
				GB_Settings::App::g_fullscreen		= FALSE;
			}
			else
				throw GB_Exception(ERR_GL_FSEX_STR, ERR_GL_FSEX_ID);
		}
		else
			GB_LDEBUG("Fullscreen mode");
	}
	else
		GB_LDEBUG("Windowed mode");

	if(GB_Settings::App::g_fullscreen)
	{
		dw_ex_style_	= WS_EX_APPWINDOW;
		dw_style_	= WS_POPUP;
		ShowCursor(FALSE);
	}
	else
	{
		dw_ex_style_	= WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;
		dw_style_	= WS_OVERLAPPEDWINDOW;
	}

	AdjustWindowRectEx(&windows_rect, dw_style_, FALSE, dw_ex_style_);
	return GB_Enum::GB_OK;
}

//==================================================================
/**
	@fn		GB_OpenGL :: CreateGB_OpenGLWnd
	@brief	Create new GB_OpenGL window
**/
//==================================================================
GB_Enum::gbResult GB_OpenGL :: CreateGB_OpenGLWnd()
{
	GB_LDEBUG("Create window");
	GB_Settings::OpenGL::g_hwnd	= CreateWindowEx( dw_ex_style_, GB_Settings::Window::g_wnd_name, GB_Settings::Window::g_wnd_title, 
		dw_style_ | WS_HSCROLL | WS_VSCROLL | WS_OVERLAPPEDWINDOW,
		GB_Settings::Window::g_wnd_x, GB_Settings::Window::g_wnd_y, GB_Settings::Window::g_wnd_width, GB_Settings::Window::g_wnd_height, 
		NULL, NULL, GB_Settings::OpenGL::g_hinstance, NULL );

	if(GB_Settings::OpenGL::g_hwnd == NULL)
		throw GB_Exception(ERR_WIN_WND_STR, ERR_WIN_WND_ID);

	return GB_Enum::GB_OK;
}

//==================================================================
/**
	@fn		GB_OpenGL :: EnableGB_OpenGL
	@brief	Enables GB_OpenGL for current window
**/
//==================================================================
GB_Enum::gbResult GB_OpenGL :: EnableGB_OpenGL()
{
	GB_LDEBUG("Enable GB_OpenGL for window");
	GB_Settings::OpenGL::g_hdc	= GetDC((HWND)GB_Settings::OpenGL::g_hwnd);
	
	PIXELFORMATDESCRIPTOR pfd;
	ZeroMemory(&pfd, sizeof(PIXELFORMATDESCRIPTOR));
	pfd.nSize		= sizeof(PIXELFORMATDESCRIPTOR);
	pfd.nVersion	= 1;
	pfd.dwFlags		= PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	pfd.iPixelType	= PFD_TYPE_RGBA;
	pfd.cColorBits	= GB_Settings::App::g_bits_color;
	pfd.cDepthBits	= GB_Settings::App::g_bits_depth;
	pfd.cAlphaBits	= GB_Settings::App::g_bits_alpha;
	pfd.iLayerType	= PFD_MAIN_PLANE;
	
	int format		= ChoosePixelFormat(GB_Settings::OpenGL::g_hdc, &pfd);
	if(!SetPixelFormat(GB_Settings::OpenGL::g_hdc, format, &pfd))
		throw GB_Exception(ERR_GL_SPF_STR, ERR_GL_SPF_ID);

	if(!(GB_Settings::OpenGL::g_hglrc = wglCreateContext(GB_Settings::OpenGL::g_hdc)))
		throw GB_Exception(ERR_GL_HRC_STR, ERR_GL_HRC_ID);
	
	if(!wglMakeCurrent(GB_Settings::OpenGL::g_hdc, GB_Settings::OpenGL::g_hglrc))
		throw GB_Exception(ERR_GL_HDRC_STR, ERR_GL_HDRC_ID);

	DescribePixelFormat(GB_Settings::OpenGL::g_hdc, format, sizeof(PIXELFORMATDESCRIPTOR), &pfd);
	ReleaseDC(GB_Settings::OpenGL::g_hwnd, GB_Settings::OpenGL::g_hdc);

	return GB_Enum::GB_OK;
}

//==================================================================
/**
	@fn		GB_OpenGL :: InitializeGB_OpenGL
	@brief	Initialize GB_OpenGL properties
**/
//==================================================================
VOID GB_OpenGL :: InitializeGB_OpenGL()
{
	GB_LDEBUG("Initialize GB_OpenGL");
	glLoadIdentity();
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

//==================================================================
/**
	@fn		GB_OpenGL :: ResizeGB_OpenGLWnd
	@brief	Called if window is resized
	@param	wnd_width		width of GB_OpenGL window
	@param	wnd_height		heigh of GB_OpenGL window
**/
//==================================================================
GB_Enum::gbResult GB_OpenGL :: ResizeGB_OpenGLWnd(int wnd_width, int wnd_height)
{
	if(wnd_height == 0)
		wnd_height = 1;

	glViewport(0, 0, wnd_width, wnd_height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, (GLfloat)wnd_width / (GLfloat)wnd_height, 0.1f, 100.0f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	return GB_Enum::GB_OK;
}

//==================================================================
/**
	@fn		GB_OpenGL :: DrawSimpleLine(GooseBerry::Vector3d start_vec, GooseBerry::Vector3d end_vec)
	@brief	Draw a simple line with vectors
	@param	start_vec		start vector
	@param	end_vec		end vector
**/
//==================================================================
GB_Enum::gbResult GB_OpenGL :: DrawSimpleLine(GB_Vector3 start_vec, GB_Vector3 end_vec)
{
	glBegin(GL_LINES);
	glVertex3f(start_vec.x_, start_vec.y_, start_vec.z_);
	glVertex3f(end_vec.x_, end_vec.y_, end_vec.z_);
	glEnd();

	return GB_Enum::GB_OK;
}

//==================================================================
/**
	@fn		GB_OpenGL :: DrawSimpleLine(GooseBerry::GB_Color GooseBerry::GB_Color, GooseBerry::Vector3d start_vec, GooseBerry::Vector3d end_vec)
	@brief	Draw a simple line with vectors in a specific GooseBerry::GB_Color
	@param	start_vec		start vector
	@param	end_vec		end vector
	@param	GooseBerry::GB_Color		GooseBerry::GB_Color
**/
//==================================================================
GB_Enum::gbResult GB_OpenGL :: DrawSimpleLine(GB_Color color, GB_Vector3 start_vec, GB_Vector3 end_vec)
{
	glBegin(GL_LINES);
	glColor3f(color.red, color.green, color.blue);
	glVertex3f(start_vec.x_, start_vec.y_, start_vec.z_);
	glVertex3f(end_vec.x_, end_vec.y_, end_vec.z_);
	glEnd();

	return GB_Enum::GB_OK;
}