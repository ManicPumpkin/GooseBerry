//==================================================================
/**
	@file	GB_Log.h
	@brief	This file includes the GB_Log class

	The GB_Log class writes GB_LERRORs, warnings and other messages into
	a file.

	@author	drubner
	@date Created at 2012-08-15
**/
//==================================================================
#pragma once 

//==================================================================
//	FUNCTION
//==================================================================
GOOSEBERRY_API GB_Enum::gbResult	InitializeLog();
GOOSEBERRY_API GB_Enum::gbResult	StopLog();
GOOSEBERRY_API GB_Enum::gbResult	Log(std::string msg);
GOOSEBERRY_API std::string			CurrentTime();
GOOSEBERRY_API std::string			CurrentDate();

//==================================================================
//	INLINE
//==================================================================
inline GOOSEBERRY_API VOID GB_LCONSOLE(string msg)				{ if (GB_Settings::Debug::g_debug_mode) printf((msg + "\n").c_str()); }
inline GOOSEBERRY_API VOID GB_LDEBUG(string msg)				{ GB_LCONSOLE(msg); if (GB_Settings::Debug::g_debug_mode) Log("<td class=\"log_debug\">" + msg + "</td>\n"); }
inline GOOSEBERRY_API VOID GB_LINFO(string msg)					{ GB_LCONSOLE(msg); Log("<td class=\"log_info\">" + msg + "</td>\n"); }
inline GOOSEBERRY_API VOID GB_LWARNING(string msg)				{ GB_LCONSOLE(msg); Log("<td class=\"log_warning\">" + msg + "</td>\n"); }
inline GOOSEBERRY_API VOID GB_LERROR(string msg, string id)		{ GB_LCONSOLE(msg); Log("<td class=\"log_error\">" + msg + "<" + id + "></td>\n"); }
inline GOOSEBERRY_API VOID GB_MSGBOXERR(LPCSTR msg, LPCSTR id)	{ MessageBox(NULL, msg, id, MB_OK | MB_ICONERROR); }