//==================================================================
/**
		@file	gbLog.cpp
		@brief	This file includes all functions of cLog class
		@author	drubner
		@date	Created 2012-08-14
**/
//==================================================================
//	Include
//==================================================================
#include <sstream>
#include <time.h>

#include "gbLog.h"

//==================================================================
//	Functions
//==================================================================
/**
		@fn		gbStopLog()
		@brief	Stop logging
		@return	gbResult
**/
//==================================================================
GOOSEBERRY_API gbResult gbStopLog()
{
	return GB_OK;
}

//==================================================================
/**
		@fn		gbLog()
		@brief	Log a message into the mFile file
		@param	pMsg	Message to log
		@return	VOID
**/
//==================================================================
GOOSEBERRY_API gbResult gbLog(std::string pMsg)
{
	std::ofstream tFileStream;
	tFileStream.open(LOG_FILEPATH, std::fstream::in | std::fstream::app);

	if(tFileStream.is_open())
		tFileStream << gbCurrentDate() << " " << gbCurrentTime() << "\t> " << pMsg << "\n";
	
	tFileStream.close();
	return GB_OK;
}

//==================================================================
/**
		@fn		gbLog()
		@brief	Log a message into the mFile file
		@param	pMsg	Message to log
		@param  pSpace	Space in log file 
		@return	VOID
**/
//==================================================================
GOOSEBERRY_API gbResult gbLog(std::string pMsg, std::string pSpace)
{
	std::ofstream tFileStream;
	tFileStream.open(LOG_FILEPATH, std::fstream::in | std::fstream::app);

	if(tFileStream.is_open())
		tFileStream << gbCurrentDate() << " " << gbCurrentTime() << pSpace << "\t> " << pMsg << "\n";
	
	tFileStream.close();
	return GB_OK;
}

//==================================================================
/**
		@fn		gbInitializeLog()
		@brief	Makes log file ready for logging operations
		@return	VOID
**/
//==================================================================
GOOSEBERRY_API gbResult gbInitializeLog()
{
	std::ofstream tFileStream;
	CreateDirectory(LOG_PATH, NULL);
	tFileStream.open(LOG_FILEPATH, std::fstream::trunc);
	
	if(tFileStream.is_open())
	{
		tFileStream << "**************************************************************************************************\n\n";
		tFileStream << " " << gb_g_wndTitle << " - Logfile\n";
		tFileStream << " ------------------------------------------------------------------------------------------------\n";
		if(DEBUG_MODE)	gbLogProgramData(tFileStream);
		tFileStream << " Time\t\t\t: " << gbCurrentTime() << "\n";
		tFileStream << " Date\t\t\t: " << gbCurrentDate() << "\n\n";
		tFileStream << "**************************************************************************************************\n\n";
	}

	tFileStream.close();
	return GB_OK;
}

//==================================================================
/**
		@fn		gbLogProgramData(std::ofstream & pFileStream)
		@brief	Logs program data if debug mode is true
		@return	VOID
**/
//==================================================================
GOOSEBERRY_API gbResult gbLogProgramData(std::ofstream & pFileStream)
{
	pFileStream << " Window class name\t: " << gb_g_wndName << "\n";
	pFileStream << " Window name\t\t: " << gb_g_wndTitle << "\n";
	pFileStream << " Window size\t\t: " << gb_g_wndWidth << "x" << gb_g_wndHeight << " Pixel\n";
	pFileStream << " Color\t\t\t: " << gb_g_bitsColor << "bits\n";
	pFileStream << " Depth\t\t\t: " << gb_g_bitsDepth << "bits\n";
	pFileStream << " Alpha\t\t\t: " << gb_g_bitsAlpha << "bits\n";
	pFileStream << " ------------------------------------------------------------------------------------------------\n";

	return GB_OK;
}

//==================================================================
/**
		@fn		gbCurrentTime()
		@brief	Create timestamp of time
		@return	std::string tTime
**/
//==================================================================
GOOSEBERRY_API std::string gbCurrentTime()
{
	time_t tRawTime;
	struct tm tTimeInfo;

	time(&tRawTime);
	localtime_s(&tTimeInfo, &tRawTime);
	
	std::stringstream tSStream;
	tSStream << tTimeInfo.tm_hour << ":" << tTimeInfo.tm_min << ":"
		<< tTimeInfo.tm_sec;

	return tSStream.str();
}

//==================================================================
/**
		@fn		gbLog::fCurrentDate()
		@brief	Create timestamp of date
		@return	std::string tDate
**/
//==================================================================
GOOSEBERRY_API std::string gbCurrentDate()
{
	time_t tRawTime;
	struct tm tTimeInfo;

	time(&tRawTime);
	localtime_s(&tTimeInfo, &tRawTime);
	
	std::stringstream tSStream;
	tSStream << (tTimeInfo.tm_year + 1900) << "-" << tTimeInfo.tm_mon << "-" 
		<< tTimeInfo.tm_mday;

	return tSStream.str();
}