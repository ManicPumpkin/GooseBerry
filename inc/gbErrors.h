/**
	@file	hErrors.h
	@brief	Includes all error messages and ids for window and 
			OpenGL
	@author	drubner
	@date	2012-11-10
**/
//==================================================================
#ifndef CERRORS_H
#define CERRORS_H
//==================================================================
//	Windows Errors
//==================================================================
#define ERR_WIN_UNKNOWN_STR	"Unknown error occoured."
#define ERR_WIN_UNKNOWN_ID	"Error 0x0000000"
#define ERR_WIN_CLASS_STR	"Failed to register class."
#define ERR_WIN_CLASS_ID	"Error 0x0000001"
#define ERR_WIN_WND_STR		"Failed to create window."
#define ERR_WIN_WND_ID		"Error 0x0000002"
#define ERR_WIN_DWND_STR	"Failed to destroy window."
#define ERR_WIN_DWND_ID		"Error 0x0000003"
#define ERR_WIN_FS_STR		"Failed to switch to fullscreen mode."
#define ERR_WIN_FS_ID		"Error 0x0000004"
#define ERR_WIN_EXWS_STR	"Extended window style not set."
#define ERR_WIN_EXWS_ID		"Error 0x0000005"
#define ERR_WIN_WS_STR		"Window style not set."
#define ERR_WIN_WS_ID		"Error 0x0000006"
//==================================================================
//	OpenGL Errors
//==================================================================
#define ERR_GL_HWND_STR		"Handle to window not set."
#define ERR_GL_HWND_ID		"Error 0x0000010"
#define ERR_GL_SPF_STR		"Failed to set pixel format."
#define ERR_GL_SPF_ID		"Error 0x0000011"
#define ERR_GL_HRC_STR		"Failed to create rendering context."
#define ERR_GL_HRC_ID		"Error 0x0000012"
#define ERR_GL_HDRC_STR		"Failed to set device and render context."
#define ERR_GL_HDRC_ID		"Error 0x0000013"
#define ERR_GL_SHRC_STR		"Failed to deactivate render context."
#define ERR_GL_SHRC_ID		"Error 0x0000014"
#define ERR_GL_DHRC_STR		"Failed to delete render context."
#define ERR_GL_DHRC_ID		"Error 0x0000015"
#define ERR_GL_RHDC_STR		"Failed to release device context."
#define ERR_GL_RHDC_ID		"Error 0x0000016"
#define ERR_GL_VP_STR		"Window width/height equal or smaller then zero."
#define ERR_GL_VP_ID		"Error 0x0000017"
//==================================================================
//	Gooseberry Errors
//==================================================================

//==================================================================
#endif CERRORS_H
//==================================================================