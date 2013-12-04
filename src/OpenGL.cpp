/**
	@file	OpenGL.cpp
	@brief	Initializes and enables OpenGL 
	@author	drubner
	@date	2013-07-16
**/
//==================================================================
//	Include
//==================================================================
#include "GooseBerry.h"
#include "gbException.h"
#include "gbErrors.h"
#include "Log.h"
#include "OpenGL.h"

//==================================================================
/**
	@fn		OpenGL :: WindowProc
	@brief	Called if window is resized
	@param	wnd_width		width of OpenGL window
	@param	wnd_height		heigh of OpenGL window
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
				g_active		= TRUE;
			else
				g_active		= FALSE;

			return 0;
			break;
		
		case WM_KEYDOWN:
			g_keys[w_param]	= TRUE;
			return 0;
			break;

		case WM_KEYUP:
			g_keys[w_param]	= FALSE;
			return 0;
			break;
    }

    return DefWindowProc(hwnd, msg, w_param, l_param); 
} 

//==================================================================
//	(De-)Constructor
//==================================================================
/**
	@fn		OpenGL :: OpenGL
	@brief	Initializes model queue, window params, enables and 
			initializes OpenGL
**/
//==================================================================
OpenGL :: OpenGL()
{
	GB_LINFO("OpenGL");
	initialize_	= FALSE;
}

//==================================================================
/**
	@fn		OpenGL :: ~OpenGL
	@brief	Frees memory
**/
//==================================================================
OpenGL :: ~OpenGL()
{
	
}

//==================================================================
//	Functions
//==================================================================
/**
	@fn		OpenGL :: StartWnd
	@brief	Starts this window
**/
//==================================================================
gbResult OpenGL :: StartWnd()
{
	try
	{
		GB_LDEBUG("Initialize and create OpenGL window");
		if(!initialize_) 
			RegisterWndClass();

		FullscreenWnd();
		CreateOpenGLWnd();
		EnableOpenGL();
		InitializeOpenGL();
		ResizeOpenGLWnd(g_wndWidth, g_wndHeight);
	}
	catch(const gbException &tException)
	{
		GB_LERROR(tException.GetStr(), tException.GetId());
		GB_MSGBOXERR(tException.GetStr(), tException.GetId());
		return GB_STOP;
	}

	initialize_	= TRUE;
	return GB_OK;
}

//==================================================================
/**
	@fn		OpenGL :: ExitWnd
	@brief	Exit window
**/
//==================================================================
gbResult OpenGL :: ExitWnd()
{
	GB_LDEBUG("Close and destroy OpenGL window");
	wglMakeCurrent(NULL, NULL);
	ReleaseDC(g_HWND, g_HDC);
	wglDeleteContext(g_HGLRC);
	DestroyWindow(g_HWND);
	return GB_OK;
}

//==================================================================
/**
	@fn		OpenGL :: RegisterWndClass
	@brief	Register window class
**/
//==================================================================
gbResult OpenGL :: RegisterWndClass()
{
	GB_LDEBUG("Register window class");
	g_hinstance	= GetModuleHandle(NULL);

	WNDCLASS wnd_class		= {};
	wnd_class.style			= CS_OWNDC;
	wnd_class.lpfnWndProc	= (WNDPROC)WindowProc;
	wnd_class.cbClsExtra	= 0;
	wnd_class.cbWndExtra	= 0;
	wnd_class.hInstance		= g_hinstance;
	wnd_class.hIcon			= LoadIcon(NULL, IDI_WINLOGO);
	wnd_class.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wnd_class.hbrBackground	= NULL;
	wnd_class.lpszMenuName	= NULL;
	wnd_class.lpszClassName = g_wndName;

	if(!RegisterClass(&wnd_class))
		throw gbException(ERR_WIN_CLASS_STR, ERR_WIN_CLASS_ID);

	return GB_OK;
}

//==================================================================
/**
	@fn		OpenGL :: FullscreenWnd
	@brief	Going fullscreen or not
**/
//==================================================================
gbResult OpenGL :: FullscreenWnd()
{
	GB_LDEBUG("Setting up screen mode");
	RECT windows_rect;				
	windows_rect.left	= (long)0;			
	windows_rect.right	= (long)g_wndWidth;		
	windows_rect.top		= (long)0;			
	windows_rect.bottom	= (long)g_wndHeight;		

	if(g_fullscreen)
	{
		DEVMODE screen_settings;
		memset(&screen_settings, 0, sizeof(screen_settings));
		screen_settings.dmSize			= sizeof(screen_settings);
		screen_settings.dmPelsWidth		= g_wndWidth;
		screen_settings.dmPelsHeight	= g_wndHeight;
		screen_settings.dmBitsPerPel	= g_bitsColor;
		screen_settings.dmFields		= DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;

		if(ChangeDisplaySettings(&screen_settings, CDS_FULLSCREEN)!=DISP_CHANGE_SUCCESSFUL)
		{
			if(MessageBox(NULL, ERR_GL_FS_STR, ERR_GL_FS_ID, MB_YESNO | MB_ICONEXCLAMATION)==IDYES)
			{
				GB_LWARNING("Fullscreen not supported. Going back to windowed mode.");
				g_fullscreen		= FALSE;
			}
			else
				throw gbException(ERR_GL_FSEX_STR, ERR_GL_FSEX_ID);
		}
		else
			GB_LDEBUG("Fullscreen mode");
	}
	else
		GB_LDEBUG("Windowed mode");

	if(g_fullscreen)
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
	return GB_OK;
}

//==================================================================
/**
	@fn		OpenGL :: CreateOpenGLWnd
	@brief	Create new OpenGL window
**/
//==================================================================
gbResult OpenGL :: CreateOpenGLWnd()
{
	GB_LDEBUG("Create window");
	g_HWND	= CreateWindowEx( dw_ex_style_, g_wndName, g_wndTitle, 
		dw_style_ | WS_HSCROLL | WS_VSCROLL | WS_OVERLAPPEDWINDOW,
		g_wndX, g_wndY, g_wndWidth, g_wndHeight, 
		NULL, NULL, g_hinstance, NULL );

	if(g_HWND == NULL)
		throw gbException(ERR_WIN_WND_STR, ERR_WIN_WND_ID);

	return GB_OK;
}

//==================================================================
/**
	@fn		OpenGL :: EnableOpenGL
	@brief	Enables OpenGL for current window
**/
//==================================================================
gbResult OpenGL :: EnableOpenGL()
{
	GB_LDEBUG("Enable OpenGL for window");
	g_HDC	= GetDC((HWND)g_HWND);
	
	PIXELFORMATDESCRIPTOR pfd;
	ZeroMemory(&pfd, sizeof(PIXELFORMATDESCRIPTOR));
	pfd.nSize		= sizeof(PIXELFORMATDESCRIPTOR);
	pfd.nVersion	= 1;
	pfd.dwFlags		= PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	pfd.iPixelType	= PFD_TYPE_RGBA;
	pfd.cColorBits	= g_bitsColor;
	pfd.cDepthBits	= g_bitsDepth;
	pfd.cAlphaBits	= g_bitsAlpha;
	pfd.iLayerType	= PFD_MAIN_PLANE;
	
	int format		= ChoosePixelFormat(g_HDC, &pfd);
	if(!SetPixelFormat(g_HDC, format, &pfd))
		throw gbException(ERR_GL_SPF_STR, ERR_GL_SPF_ID);

	if(!(g_HGLRC = wglCreateContext(g_HDC)))
		throw gbException(ERR_GL_HRC_STR, ERR_GL_HRC_ID);
	
	if(!wglMakeCurrent(g_HDC, g_HGLRC))
		throw gbException(ERR_GL_HDRC_STR, ERR_GL_HDRC_ID);

	DescribePixelFormat(g_HDC, format, sizeof(PIXELFORMATDESCRIPTOR), &pfd);
	ReleaseDC(g_HWND, g_HDC);

	return GB_OK;
}

//==================================================================
/**
	@fn		OpenGL :: InitializeOpenGL
	@brief	Initialize OpenGL properties
**/
//==================================================================
VOID OpenGL :: InitializeOpenGL()
{
	GB_LDEBUG("Initialize OpenGL");
	glLoadIdentity();
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

//==================================================================
/**
	@fn		OpenGL :: ResizeOpenGLWnd
	@brief	Called if window is resized
	@param	wnd_width		width of OpenGL window
	@param	wnd_height		heigh of OpenGL window
**/
//==================================================================
gbResult OpenGL :: ResizeOpenGLWnd(int wnd_width, int wnd_height)
{
	if(wnd_height == 0)
		wnd_height = 1;

	glViewport(0, 0, wnd_width, wnd_height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, (GLfloat)wnd_width / (GLfloat)wnd_height, 0.1f, 100.0f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	return GB_OK;
}

//==================================================================
/**
	@fn		OpenGL :: DrawSimpleLine(Vector3d start_vec, Vector3d end_vec)
	@brief	Draw a simple line with vectors
	@param	start_vec		start vector
	@param	end_vec		end vector
**/
//==================================================================
gbResult OpenGL :: DrawSimpleLine(Vector3d start_vec, Vector3d end_vec)
{
	glBegin(GL_LINES);
	glVertex3f(start_vec.x_, start_vec.y_, start_vec.z_);
	glVertex3f(end_vec.x_, end_vec.y_, end_vec.z_);
	glEnd();

	return GB_OK;
}

//==================================================================
/**
	@fn		OpenGL :: DrawSimpleLine(Color color, Vector3d start_vec, Vector3d end_vec)
	@brief	Draw a simple line with vectors in a specific color
	@param	start_vec		start vector
	@param	end_vec		end vector
	@param	color		color
**/
//==================================================================
gbResult OpenGL :: DrawSimpleLine(Color color, Vector3d start_vec, Vector3d end_vec)
{
	glBegin(GL_LINES);
	glColor3f(color.red, color.green, color.blue);
	glVertex3f(start_vec.x, start_vec.y, start_vec.z);
	glVertex3f(end_vec.x, end_vec.y, end_vec.z

	return GB_OK;
}