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
//	Class
//==================================================================
/**
	@class	gbLog
	@brief	The log class writes errors, warnings and other messages 
			into a file
**/
//==================================================================
GOOSEBERRY_API gbResult	gbInitializeLog();
GOOSEBERRY_API gbResult	gbStopLog();
GOOSEBERRY_API gbResult	gbLogProgramData(std::ofstream & pFileStream);
GOOSEBERRY_API gbResult	gbLog(std::string pMsg);
GOOSEBERRY_API gbResult	gbLog(std::string pMsg, std::string pSpace);
GOOSEBERRY_API std::string	gbCurrentTime();
GOOSEBERRY_API std::string	gbCurrentDate();
