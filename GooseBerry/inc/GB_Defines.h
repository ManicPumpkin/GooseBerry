/**
	@file	Defines.h
	@brief	Includes all programm macros
	@author	drubner
	@date	2013-07-16
**/
//==================================================================
#pragma once

//==================================================================
//	DEFINES
//==================================================================
#define WND_WIDTH			WND_PADDING * 2 + GL_WIDTH_R	//!< main window width
#define WND_HEIGHT			665								//!< main window height
#define WND_BITS_Color		32								//!< Color bits
#define WND_BITS_DEPTH		16								//!< Color depth
#define WND_PADDING			10								//!< window padding
#define WND_X_POS			DI_X_POS + DI_WIDTH				//!< main window x position
#define WND_Y_POS			DI_Y_POS						//!< main window y position
#define WND_FOV				45.0f							//!< field of view
#define WND_NEAR_DIST		0.1f							//!< near distance 
#define WND_FAR_DIST		100.0f							//!< far distance
//==================================================================
#define LOG_FILE			"GB_Log.txt"						//!< GB_Log file name
#define LOG_PATH			".\\out\\"						//!< GB_Log file path
#define DEBUG_MODE			TRUE							//!< debug mode option (not used)
//==================================================================
#define ERR_BTN_STYLE		MB_OK | MB_ICONERROR

//==================================================================
//	MACROS
//==================================================================

//==================================================================
//	EXTERN
//==================================================================