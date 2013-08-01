/**
	@file	gbOpenGL.cpp
	@brief	Initializes and enables OpenGL 
	@author	drubner
	@date	2013-07-16
**/
//==================================================================
//	Include
//==================================================================
#include "gooseberry.h"
#include "gbException.h"
#include "gbErrors.h"
#include "gbLog.h"
#include "gbOpenGL.h"

//==================================================================
/**
	@fn		gbOpenGL :: WindowProc
	@brief	Called if window is resized
	@param	pWidth		width of OpenGL window
	@param	pHeight		heigh of OpenGL window
**/
//==================================================================
LONG WINAPI fWindowProc(HWND pHWND, UINT pMsg, WPARAM pWParam, LPARAM pLParam)
{ 
    switch(pMsg) 
	{
		case WM_CLOSE:
			DestroyWindow(pHWND);
			PostQuitMessage(0);
			return 0;
			break;

		case WM_ACTIVATE:
			if(!HIWORD(pWParam))
				gb_g_active		= TRUE;
			else
				gb_g_active		= FALSE;

			return 0;
			break;
		
		case WM_KEYDOWN:
			gb_g_keys[pWParam]	= TRUE;
			return 0;
			break;

		case WM_KEYUP:
			gb_g_keys[pWParam]	= FALSE;
			return 0;
			break;
    }

    return DefWindowProc(pHWND, pMsg, pWParam, pLParam); 
} 

//==================================================================
//	(De-)Constructor
//==================================================================
/**
	@fn		cOpenGL :: cOpenGL
	@brief	Initializes model queue, window params, enables and 
			initializes OpenGL
	@param	pParentForm	handle to parent form
	@param	pWidth		width of OpenGL window
	@param	pHeight		height of OpenGL window
	@param	pX			x position of OpenGL window on form
	@param	pY			y position of OpenGL window on form
	@param	pWndID		id of OpenGL window
**/
//==================================================================
gbOpenGL :: gbOpenGL()
{
	mInit	= FALSE;
}

//==================================================================
/**
	@fn		cOpenGL :: ~cOpenGL
	@brief	Frees memory
**/
//==================================================================
gbOpenGL :: ~gbOpenGL()
{
	
}

//==================================================================
//	Functions
//==================================================================
/**
	@fn		gbOpenGL :: fStartWnd
	@brief	Starts this window
**/
//==================================================================
gbResult gbOpenGL :: fStartWnd()
{
	try
	{
		GB_LINFO("Initialize and create OpenGL window");
		if(!mInit) 
			fRegisterWndClass();

		fFullscreenWnd();
		fCreateOpenGLWnd();
		fEnableOpenGL();
	}
	catch(const gbException &tException)
	{
		GB_LERROR(tException.fGetStr(), tException.fGetId());
		GB_MSGBOXERR(tException.fGetStr(), tException.fGetId());
		return GB_STOP;
	}

	mInit	= TRUE;
	return GB_OK;
}

//==================================================================
/**
	@fn		gbOpenGL :: fExitWnd
	@brief	Exit window
**/
//==================================================================
gbResult gbOpenGL :: fExitWnd()
{
	GB_LINFO("Close and destroy OpenGL window");
	wglMakeCurrent(NULL, NULL);
	ReleaseDC(gb_g_HWND, gb_g_HDC);
	wglDeleteContext(gb_g_HGLRC);
	DestroyWindow(gb_g_HWND);
	return GB_OK;
}

//==================================================================
/**
	@fn		gbOpenGL :: fRegisterWndClass
	@brief	Register window class
**/
//==================================================================
gbResult gbOpenGL :: fRegisterWndClass()
{
	GB_LINFO("Register window class");
	gb_g_hinstance	= GetModuleHandle(NULL);

	WNDCLASS tWndClass		= {};
	tWndClass.style			= CS_OWNDC;
	tWndClass.lpfnWndProc	= (WNDPROC)fWindowProc;
	tWndClass.cbClsExtra	= 0;
	tWndClass.cbWndExtra	= 0;
	tWndClass.hInstance		= gb_g_hinstance;
	tWndClass.hIcon			= LoadIcon(NULL, IDI_WINLOGO);
	tWndClass.hCursor		= LoadCursor(NULL, IDC_ARROW);
	tWndClass.hbrBackground	= NULL;
	tWndClass.lpszMenuName	= NULL;
	tWndClass.lpszClassName = gb_g_wndName;

	if(!RegisterClass(&tWndClass))
		throw gbException(ERR_WIN_CLASS_STR, ERR_WIN_CLASS_ID);

	return GB_OK;
}

//==================================================================
/**
	@fn		gbOpenGL :: fFullscreenWnd
	@brief	Going fullscreen or not
**/
//==================================================================
gbResult gbOpenGL :: fFullscreenWnd()
{
	GB_LINFO("Setting up screen mode");
	RECT tWindowRect;				
	tWindowRect.left	=(long)0;			
	tWindowRect.right	=(long)gb_g_wndWidth;		
	tWindowRect.top		=(long)0;			
	tWindowRect.bottom	=(long)gb_g_wndHeight;		

	if(gb_g_fullscreen)
	{
		DEVMODE tDmScreenSettings;
		memset(&tDmScreenSettings, 0, sizeof(tDmScreenSettings));
		tDmScreenSettings.dmSize		= sizeof(tDmScreenSettings);
		tDmScreenSettings.dmPelsWidth	= gb_g_wndWidth;
		tDmScreenSettings.dmPelsHeight	= gb_g_wndHeight;
		tDmScreenSettings.dmBitsPerPel	= gb_g_bitsColor;
		tDmScreenSettings.dmFields		= DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;

		if(ChangeDisplaySettings(&tDmScreenSettings, CDS_FULLSCREEN)!=DISP_CHANGE_SUCCESSFUL)
		{
			if(MessageBox(NULL, ERR_GL_FS_STR, ERR_GL_FS_ID, MB_YESNO | MB_ICONEXCLAMATION)==IDYES)
			{
				GB_LWARNING("Fullscreen not supported. Going back to windowed mode.");
				gb_g_fullscreen		= FALSE;
			}
			else
				throw gbException(ERR_GL_FSEX_STR, ERR_GL_FSEX_ID);
		}
		else
			GB_LINFO("Fullscreen mode");
	}
	else
		GB_LINFO("Windowed mode");

	if(gb_g_fullscreen)
	{
		mDwExStyle	= WS_EX_APPWINDOW;
		mDwStyle	= WS_POPUP;
		ShowCursor(FALSE);
	}
	else
	{
		mDwExStyle	= WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;
		mDwStyle	= WS_OVERLAPPEDWINDOW;
	}

	AdjustWindowRectEx(&tWindowRect, mDwStyle, FALSE, mDwExStyle);
	return GB_OK;
}

//==================================================================
/**
	@fn		gbOpenGL :: fCreateOpenGLWnd
	@brief	Create new OpenGL window
**/
//==================================================================
gbResult gbOpenGL :: fCreateOpenGLWnd()
{
	GB_LINFO("Create window");
	gb_g_HWND	= CreateWindowEx( mDwExStyle, gb_g_wndName, gb_g_wndTitle, 
		mDwStyle | WS_HSCROLL | WS_VSCROLL | WS_OVERLAPPEDWINDOW,
		gb_g_wndX, gb_g_wndY, gb_g_wndWidth, gb_g_wndHeight, 
		NULL, NULL, gb_g_hinstance, NULL );

	if(gb_g_HWND == NULL)
		throw gbException(ERR_WIN_WND_STR, ERR_WIN_WND_ID);

	return GB_OK;
}

//==================================================================
/**
	@fn		gbOpenGL :: fEnableOpenGL
	@brief	Enables OpenGL for current window
**/
//==================================================================
gbResult gbOpenGL :: fEnableOpenGL()
{
	GB_LINFO("Enable OpenGL for window");
	gb_g_HDC	= GetDC((HWND)gb_g_HWND);
	
	PIXELFORMATDESCRIPTOR tPfd;
	ZeroMemory(&tPfd, sizeof(PIXELFORMATDESCRIPTOR));
	tPfd.nSize		= sizeof(PIXELFORMATDESCRIPTOR);
	tPfd.nVersion	= 1;
	tPfd.dwFlags	= PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	tPfd.iPixelType	= PFD_TYPE_RGBA;
	tPfd.cColorBits = gb_g_bitsColor;
	tPfd.cDepthBits = gb_g_bitsDepth;
	tPfd.cAlphaBits	= gb_g_bitsAlpha;
	tPfd.iLayerType = PFD_MAIN_PLANE;
	
	int tFormat		= ChoosePixelFormat(gb_g_HDC, &tPfd);
	if(!SetPixelFormat(gb_g_HDC, tFormat, &tPfd))
		throw gbException(ERR_GL_SPF_STR, ERR_GL_SPF_ID);

	if(!(gb_g_HGLRC = wglCreateContext(gb_g_HDC)))
		throw gbException(ERR_GL_HRC_STR, ERR_GL_HRC_ID);
	
	if(!wglMakeCurrent(gb_g_HDC, gb_g_HGLRC))
		throw gbException(ERR_GL_HDRC_STR, ERR_GL_HDRC_ID);

	DescribePixelFormat(gb_g_HDC, tFormat, sizeof(PIXELFORMATDESCRIPTOR), &tPfd);
	ReleaseDC(gb_g_HWND, gb_g_HDC);

	return GB_OK;
}

//==================================================================
/**
	@fn		gbOpenGL :: fInitializeOpenGL
	@brief	Initialize OpenGL properties
**/
//==================================================================
VOID gbOpenGL :: fInitializeOpenGL()
{
	GB_LINFO("Initialize OpenGL");
	glLoadIdentity();
	glEnable(GL_DEPTH_TEST);
}

//==================================================================
/**
	@fn		gbOpenGL :: fOnResize
	@brief	Called if window is resized
	@param	pWidth		width of OpenGL window
	@param	pHeight		heigh of OpenGL window
**/
//==================================================================
VOID gbOpenGL :: fOnResize(int pWidth, int pHeight)
{

}
