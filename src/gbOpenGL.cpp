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
LONG WINAPI fWindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{ 
    switch(uMsg) 
	{
		case WM_CLOSE:
		PostQuitMessage(0);
		return 0;
    }

    return DefWindowProc(hWnd, uMsg, wParam, lParam); 
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
gbOpenGL :: gbOpenGL(HINSTANCE pHinstance, HWND pHWND, LPCSTR pWndName, LPCSTR pWndTitle, int pWidth, int pHeight, int pX, int pY, int pBitsColor, int pBitsDepth, int pBitsAlpha)
{
	mHinstance	= pHinstance;
	mHWND		= pHWND;
	mWndName	= pWndName;
	mWndTitle	= pWndTitle;
	mWndWidth	= pWidth;
	mWndHeight	= pHeight;
	mWndX		= pX;
	mWndY		= pY;
	mBitsColor	= pBitsColor;
	mBitsAlpha	= pBitsAlpha;
	mBitsDepth	= pBitsDepth;

	gbLog("Initialize and create OpenGL window");
	//mMdlQueue	= new cMdlQueue();
	//fCreateParams();
	fRegisterWndClass();
	fCreateOpenGLWnd();
	fEnableOpenGL();
	fInitializeOpenGL();
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
	@fn		gbOpenGL :: fCreateParams
	@brief	Creates parameter of OpenGL window, like window position 
			or window size
	@param	pParentForm	form where the OpenGL window is rooted in
**/
//==================================================================
VOID gbOpenGL :: fCreateParams()
{
	/*
	gbLog("Set parameters for OpenGL window", "\t");
	CreateParams^ tCParam	= gcnew CreateParams;
	tCParam->X		= mX;
	tCParam->Y		= mY;
	tCParam->Height	= mHeight;
	tCParam->Width	= mWidth;
	tCParam->Parent	= pParentForm->Handle;
	tCParam->Style	= WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN;
	this->CreateHandle(tCParam);

	mHDC	= GetDC((HWND)this);
	if(mHDC)
	{
		fEnableOpenGL();
		//fOnResize(mWidth, mHeight);
		fInitializeOpenGL();
	}
	else
		throw gbException(ERR_GL_HWND_STR, ERR_GL_HWND_ID);
	*/
}

//==================================================================
/**
	@fn		gbOpenGL :: fStartWnd
	@brief	Starts this window
**/
//==================================================================
gbResult gbOpenGL :: fStartWnd()
{
	fRegisterWndClass();
	fCreateOpenGLWnd();
	fEnableOpenGL();
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
	wglMakeCurrent(NULL, NULL);
	ReleaseDC(mHWND, mHDC);
	wglDeleteContext(mHGLRC);
	DestroyWindow(mHWND);
	return GB_OK;
}

//==================================================================
/**
	@fn		gbOpenGL :: fRegisterWndClass
	@brief	Register window class
**/
//==================================================================
VOID gbOpenGL :: fRegisterWndClass()
{
	gbLog("Register window class", "\t");
	mHinstance	= GetModuleHandle(NULL);

	WNDCLASS tWndClass		= {};
	tWndClass.style			= CS_OWNDC;
	tWndClass.lpfnWndProc	= (WNDPROC)fWindowProc;
	tWndClass.cbClsExtra	= 0;
	tWndClass.cbWndExtra	= 0;
	tWndClass.hInstance		= mHinstance;
	tWndClass.hIcon			= LoadIcon(NULL, IDI_WINLOGO);
	tWndClass.hCursor		= LoadCursor(NULL, IDC_ARROW);
	tWndClass.hbrBackground	= NULL;
	tWndClass.lpszMenuName	= NULL;
	tWndClass.lpszClassName = mWndName;

	if(!RegisterClass(&tWndClass))
		throw gbException(ERR_WIN_CLASS_STR, ERR_WIN_CLASS_ID);
}

//==================================================================
/**
	@fn		gbOpenGL :: fCreateOpenGLWnd
	@brief	Create new OpenGL window
**/
//==================================================================
VOID gbOpenGL :: fCreateOpenGLWnd()
{
	gbLog("Create window", "\t");
	mHWND	= CreateWindow( mWndName, mWndTitle, 
		WS_HSCROLL | WS_VSCROLL | WS_OVERLAPPEDWINDOW,
		mWndX, mWndY, mWndWidth, mWndHeight, 
		NULL, NULL, mHinstance, NULL);

	if(mHWND == NULL)
		throw gbException(ERR_WIN_WND_STR, ERR_WIN_WND_ID);
}

//==================================================================
/**
	@fn		gbOpenGL :: fEnableOpenGL
	@brief	Enables OpenGL for current window
**/
//==================================================================
VOID gbOpenGL :: fEnableOpenGL()
{
	gbLog("Enable OpenGL for window", "\t");
	mHDC	= GetDC((HWND)mHWND);
	
	PIXELFORMATDESCRIPTOR tPfd;
	ZeroMemory(&tPfd, sizeof(PIXELFORMATDESCRIPTOR));
	tPfd.nSize		= sizeof(PIXELFORMATDESCRIPTOR);
	tPfd.nVersion	= 1;
	tPfd.dwFlags	= PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	tPfd.iPixelType	= PFD_TYPE_RGBA;
	tPfd.cColorBits = mBitsColor;
	tPfd.cDepthBits = mBitsDepth;
	tPfd.cAlphaBits	= mBitsAlpha;
	tPfd.iLayerType = PFD_MAIN_PLANE;
	
	int tFormat		= ChoosePixelFormat(mHDC, &tPfd);
	if(!SetPixelFormat(mHDC, tFormat, &tPfd))
		throw gbException(ERR_GL_SPF_STR, ERR_GL_SPF_ID);

	if(!(mHGLRC = wglCreateContext(mHDC)))
		throw gbException(ERR_GL_HRC_STR, ERR_GL_HRC_ID);
	
	if(!wglMakeCurrent(mHDC, mHGLRC))
		throw gbException(ERR_GL_HDRC_STR, ERR_GL_HDRC_ID);

	DescribePixelFormat(mHDC, tFormat, sizeof(PIXELFORMATDESCRIPTOR), &tPfd);
	ReleaseDC(mHWND, mHDC);
}

//==================================================================
/**
	@fn		gbOpenGL :: fInitializeOpenGL
	@brief	Initialize OpenGL properties
**/
//==================================================================
VOID gbOpenGL :: fInitializeOpenGL()
{
	gbLog("Initialize OpenGL", "\t");
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
	/*
	gbLog("Set (re-)size window properties and view options", "\t");
	if(pWidth <= 0 || pHeight <= 0)
		throw gbException(ERR_GL_VP_STR, ERR_GL_VP_ID);

	gbLog("Set viewport", "\t\t");
	glViewport(0, 0, pWidth, pHeight);

	gbLog("Set persperctive", "\t\t");
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(WND_FOV, (GLfloat)pWidth/(GLfloat)pHeight, WND_NEAR_DIST, WND_FAR_DIST);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	*/
}
