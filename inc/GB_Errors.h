/**
	@file	GB_Errors.h
	@brief	Includes all error messages and ids for window and 
			GB_OpenGL
	@author	drubner
	@date	2012-11-10
**/
//==================================================================
#ifndef GB_Errors_H
#define GB_Errors_H

//==================================================================
//	Windows GB_Errors
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
//	GB_OpenGL GB_Errors
//==================================================================
#define ERR_GL_INIT_STR		"Failed to initialize GB_OpenGL."
#define ERR_GL_INIT_ID		"Error 0x0000010"
#define ERR_GL_HWND_STR		"Handle to window not set."
#define ERR_GL_HWND_ID		"Error 0x0000011"
#define ERR_GL_SPF_STR		"Failed to set pixel format."
#define ERR_GL_SPF_ID		"Error 0x0000012"
#define ERR_GL_HRC_STR		"Failed to create rendering context."
#define ERR_GL_HRC_ID		"Error 0x0000013"
#define ERR_GL_HDRC_STR		"Failed to set device and render context."
#define ERR_GL_HDRC_ID		"Error 0x0000014"
#define ERR_GL_SHRC_STR		"Failed to deactivate render context."
#define ERR_GL_SHRC_ID		"Error 0x0000015"
#define ERR_GL_DHRC_STR		"Failed to delete render context."
#define ERR_GL_DHRC_ID		"Error 0x0000016"
#define ERR_GL_RHDC_STR		"Failed to release device context."
#define ERR_GL_RHDC_ID		"Error 0x0000017"
#define ERR_GL_VP_STR		"Window width/height equal or smaller then zero."
#define ERR_GL_VP_ID		"Error 0x0000018"
#define ERR_GL_FS_STR		"Fullscreen not supported of your system. Trying going back to windowed mode?"
#define ERR_GL_FS_ID		"Error 0x0000019"
#define ERR_GL_FSEX_STR		"The program will now stop running."
#define ERR_GL_FSEX_ID		"Error 0x0000020"

//==================================================================
//	Gooseberry GB_Errors
//==================================================================
#define ERR_GB_INIT_STR		"Failed to initialize gooseberry."
#define ERR_GB_INIT_ID		"Error 0x0000050"
#define ERR_GB_EXIT_STR		"Failed to exit gooseberry."
#define ERR_GB_EXIT_ID		"Error 0x0000051"
#define ERR_GB_MSGL_STR		"Error while during message loop."
#define ERR_GB_MSGL_ID		"Error 0x0000052"

//==================================================================
//	Game GB_Errors
//==================================================================
#define ERR_G_LOAD_STR		"Failed to load game."
#define ERR_G_LOAD_ID		"Error 0x0000100"
#define ERR_G_EXIT_STR		"Failed to exit game."
#define ERR_G_EXIT_ID		"Error 0x0000101"

//==================================================================
#endif GB_Errors_H
//==================================================================