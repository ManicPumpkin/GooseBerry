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
//	Include
//==================================================================
#include "gooseberry.h"

//==================================================================
//	Functions
//==================================================================
GOOSEBERRY_API gbResult	gbInitializeLog();
GOOSEBERRY_API gbResult	gbStopLog();
GOOSEBERRY_API gbResult	gbLog(std::string pMsg);
GOOSEBERRY_API gbResult	gbLog(std::string pMsg, std::string pSpace);
GOOSEBERRY_API std::string	gbCurrentTime();
GOOSEBERRY_API std::string	gbCurrentDate();

//==================================================================
//	Inline functions
//==================================================================
inline GOOSEBERRY_API VOID GB_LINFO(string pMsg)					{ gbLog("<td class=\"log_info\">" + pMsg + "</td>\n"); }
inline GOOSEBERRY_API VOID GB_LWARNING(string pMsg)					{ gbLog("<td class=\"log_warning\">" + pMsg + "</td>\n"); }
//inline GOOSEBERRY_API VOID GB_LERROR(string pMsg)					{ gbLog("<td class=\"log_error\">" + pMsg + "</td>\n");  }
inline GOOSEBERRY_API VOID GB_LERROR(string pMsg, string pID)		{ gbLog("<td class=\"log_error\">" + pMsg + "<" + pID + "></td>\n"); }
inline GOOSEBERRY_API VOID GB_MSGBOXERR(LPCSTR pMsg, LPCSTR pID)	{ MessageBox(NULL, pMsg, pID, MB_OK | MB_ICONERROR); }