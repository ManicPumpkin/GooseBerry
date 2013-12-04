//==================================================================
/**
	@file	Log.h
	@brief	This file includes the log class

	The log class writes errors, warnings and other messages into
	a file.

	@author	drubner
	@date Created at 2012-08-15
**/
//==================================================================
#pragma once 

//==================================================================
//	INCLUDE
//==================================================================
#include "GooseBerry.h"

//==================================================================
//	NAMESPACE
//==================================================================
using namespace gbGlobal;

//==================================================================
//	FUNCTION
//==================================================================
GOOSEBERRY_API gbGlobal::gbResult	InitializeLog();
GOOSEBERRY_API gbGlobal::gbResult	StopLog();
GOOSEBERRY_API gbGlobal::gbResult	Log(std::string msg);
GOOSEBERRY_API gbGlobal::gbResult	Log(std::string msg, std::string space);
GOOSEBERRY_API std::string			CurrentTime();
GOOSEBERRY_API std::string			CurrentDate();

//==================================================================
//	INLINE
//==================================================================
inline GOOSEBERRY_API VOID GB_LDEBUG(string msg)				{ if(DEBUG_MODE) Log("<td class=\"log_debug\">" + msg + "</td>\n"); }
inline GOOSEBERRY_API VOID GB_LINFO(string msg)					{ Log("<td class=\"log_info\">" + msg + "</td>\n"); }
inline GOOSEBERRY_API VOID GB_LWARNING(string msg)				{ Log("<td class=\"log_warning\">" + msg + "</td>\n"); }
inline GOOSEBERRY_API VOID GB_LERROR(string msg, string id)		{ Log("<td class=\"log_error\">" + msg + "<" + id + "></td>\n"); }
inline GOOSEBERRY_API VOID GB_MSGBOXERR(LPCSTR msg, LPCSTR id)	{ MessageBox(NULL, msg, id, MB_OK | MB_ICONERROR); }