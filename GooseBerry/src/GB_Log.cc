//==================================================================
/**
		@file	GB_Log.cpp
		@brief	This file includes all functions of cGB_Log class
		@author	drubner
		@date	Created 2012-08-14
**/
//==================================================================
//	INCLUDE
//==================================================================
#include <sstream>
#include <time.h>

#include "GB_Log.h"

//==================================================================
//	NAMEPSACE
//==================================================================

//==================================================================
//	FUNCTIONS
//==================================================================
/**
		@fn		gbStopLog()
		@brief	Stop logging
		@return	GB_Enum::gbResult
**/
//==================================================================
GOOSEBERRY_API GB_Enum::gbResult StopLog()
{
	std::ofstream file_stream;
	file_stream.open(LOG_FILEPATH, std::fstream::in | std::fstream::app);
	
	if(file_stream.is_open())
		file_stream << "</table></html></head>\n";

	file_stream.close();
	return GB_Enum::GB_OK;
}

//==================================================================
/**
		@fn		Log(std::string msg)
		@brief	Log a message into the mFile file
		@param	msg	Message to log
		@return	VOID
**/
//==================================================================
GOOSEBERRY_API GB_Enum::gbResult Log(std::string msg)
{
	std::ofstream file_stream;
	file_stream.open(LOG_FILEPATH, std::fstream::in | std::fstream::app);

	if(file_stream.is_open())
		file_stream << "<tr><th>" << CurrentTime() << "</th>" << msg;
	
	file_stream.close();
	return GB_Enum::GB_OK;
}

//==================================================================
/**
		@fn		InitializeLog()
		@brief	Makes log file ready for logging operations
		@return	VOID
**/
//==================================================================
GOOSEBERRY_API GB_Enum::gbResult InitializeLog()
{
	std::ofstream file_stream;
	CreateDirectory(LOG_PATH, NULL);
	file_stream.open(LOG_FILEPATH, std::fstream::trunc);
	
	if(file_stream.is_open())
	{
		file_stream << "<html><head>\n";
		file_stream << "<title>" << GB_Var::g_wnd_title << "-Logfile</title>\n";
		file_stream << "<link rel=\"stylesheet\" href=\"logfile.css\">\n";
		file_stream << "</head><body>\n";
		file_stream << "<hr class=\"divide_double\" />\n";
		file_stream << "<p id=\"header\">"<< GB_Var::g_wnd_title <<" - GB_Logfile</p>\n";
		file_stream << "<hr class=\"divide_simple\" />\n\n";
		file_stream << "<table id=\"game_info\">\n";
		file_stream << "<tr><th>window class name</th><td>:</td><td>"<< GB_Var::g_wnd_name <<"</td></tr>\n";
		file_stream << "<tr><th>window name</th><td>:</td><td>"<< GB_Var::g_wnd_title <<"</td></tr>\n";
		file_stream << "<tr><th>color</th><td>:</td><td>"<< GB_Var::g_bits_color <<"</td></tr>\n";
		file_stream << "<tr><th>depth</th><td>:</td><td>"<< GB_Var::g_bits_depth <<"</td></tr>\n";
		file_stream << "<tr><th>alpha</th><td>:</td><td>"<< GB_Var::g_bits_alpha <<"</td></tr>\n";
		file_stream << "</table>\n";
		file_stream << "<hr class=\"divide_simple\" />\n\n";
		file_stream << "<table id=\"game_date\">\n";
		file_stream << "<tr><th>time</th><td>:</td><td>" << CurrentTime() << "</td></tr>\n";
		file_stream << "<tr><th>date</th><td>:</td><td>" << CurrentDate() << "</td></tr>\n";
		file_stream << "</table>\n";
		file_stream << "<hr class=\"divide_double\" />\n";
		file_stream << "<table id=\"game_GB_Log\">\n";
	}

	file_stream.close();
	return GB_Enum::GB_OK;
}

//==================================================================
/**
		@fn		CurrenTime()
		@brief	Create timestamp of time
		@return	std::string time
**/
//==================================================================
GOOSEBERRY_API std::string CurrentTime()
{
	time_t		raw_time;
	struct tm	time_info;
	char		time_buffer[16]	= "HH:MM:SS";

	time(&raw_time);
	localtime_s(&time_info, &raw_time);
	strftime(time_buffer, sizeof(time_buffer), "%H:%M:%S", &time_info);

	//return string_stream.str();
	return time_buffer;
}

//==================================================================
/**
		@fn		CurrentDate()
		@brief	Create timestamp of date
		@return	std::string tDate
**/
//==================================================================
GOOSEBERRY_API std::string CurrentDate()
{
	time_t raw_time;
	struct tm time_info;

	time(&raw_time);
	localtime_s(&time_info, &raw_time);
	
	std::stringstream string_stream;
	string_stream << (time_info.tm_year + 1900) << "-" << time_info.tm_mon << "-" 
		<< time_info.tm_mday;

	return string_stream.str();
}