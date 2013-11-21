//==================================================================
/**
	@file	gbLog.h
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
#include "gooseberry.h"

//==================================================================
//	NAMESPACE
//==================================================================
using namespace gbGlobal;

//==================================================================
//	FUNCTION
//==================================================================
GOOSEBERRY_API gbGlobal::gbResult	gbInitializeLog();
GOOSEBERRY_API gbGlobal::gbResult	gbStopLog();
GOOSEBERRY_API gbGlobal::gbResult	gbLog(std::string pMsg);
GOOSEBERRY_API gbGlobal::gbResult	gbLog(std::string pMsg, std::string pSpace);
GOOSEBERRY_API std::string			gbCurrentTime();
GOOSEBERRY_API std::string			gbCurrentDate();

//==================================================================
//	INLINE
//==================================================================
inline GOOSEBERRY_API VOID GB_LDEBUG(string pMsg)					{ if(DEBUG_MODE) gbLog("<td class=\"log_debug\">" + pMsg + "</td>\n"); }
inline GOOSEBERRY_API VOID GB_LINFO(string pMsg)					{ gbLog("<td class=\"log_info\">" + pMsg + "</td>\n"); }
inline GOOSEBERRY_API VOID GB_LWARNING(string pMsg)					{ gbLog("<td class=\"log_warning\">" + pMsg + "</td>\n"); }
inline GOOSEBERRY_API VOID GB_LERROR(string pMsg, string pID)		{ gbLog("<td class=\"log_error\">" + pMsg + "<" + pID + "></td>\n"); }
inline GOOSEBERRY_API VOID GB_MSGBOXERR(LPCSTR pMsg, LPCSTR pID)	{ MessageBox(NULL, pMsg, pID, MB_OK | MB_ICONERROR); }