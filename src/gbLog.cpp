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
	std::ofstream tFileStream;
	tFileStream.open(LOG_FILEPATH, std::fstream::in | std::fstream::app);
	
	if(tFileStream.is_open())
		tFileStream << "</table></html></head>\n";

	tFileStream.close();
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
		tFileStream << "<tr><th>" << gbCurrentTime() << "</th>" << pMsg;
	
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
		tFileStream << " " << gbCurrentTime() << pSpace << "\t> " << pMsg << "\n";
	
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
		tFileStream << "<html><head>\n";
		tFileStream << "<title>" << gb_g_wndTitle << "-Log</title>\n";
		tFileStream << "<link rel=\"stylesheet\" href=\"logfile.css\">\n";
		tFileStream << "</head><body>\n";
		tFileStream << "<hr class=\"divide_double\" />\n";
		tFileStream << "<p id=\"header\">"<< gb_g_wndTitle <<" - Logfile</p>\n";
		tFileStream << "<hr class=\"divide_simple\" />\n\n";
		tFileStream << "<table id=\"game_info\">\n";
		tFileStream << "<tr><th>window class name</th><td>:</td><td>"<< gb_g_wndName <<"</td></tr>\n";
		tFileStream << "<tr><th>window name</th><td>:</td><td>"<< gb_g_wndTitle <<"</td></tr>\n";
		tFileStream << "<tr><th>color</th><td>:</td><td>"<< gb_g_bitsColor <<"</td></tr>\n";
		tFileStream << "<tr><th>depth</th><td>:</td><td>"<< gb_g_bitsDepth <<"</td></tr>\n";
		tFileStream << "<tr><th>alpha</th><td>:</td><td>"<< gb_g_bitsAlpha <<"</td></tr>\n";
		tFileStream << "</table>\n";
		tFileStream << "<hr class=\"divide_simple\" />\n\n";
		tFileStream << "<table id=\"game_date\">\n";
		tFileStream << "<tr><th>time</th><td>:</td><td>"<< gbCurrentTime() <<"</td></tr>\n";
		tFileStream << "<tr><th>date</th><td>:</td><td>"<< gbCurrentDate() <<"</td></tr>\n";
		tFileStream << "</table>\n";
		tFileStream << "<hr class=\"divide_double\" />\n";
		tFileStream << "<table id=\"game_log\">\n";
	}

	tFileStream.close();
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