/**
	@file	GB_Exception.h
	@brief	Includes GB_Exception class
	@author	drubner
	@date	2012-11-10
**/
//==================================================================
#pragma once 

//==================================================================
//	Include
//==================================================================
#include "GooseBerry.h"

//==================================================================
//	Defines
//==================================================================
#define GB_GB_Exception_ICON { MB_OK | GB_ERROR }

//==================================================================
//	Class
//==================================================================
/**
		@class	GB_Exception
		@brief	Includes GB_Exception handling methods and variables
**/
//==================================================================
class GB_Exception : public std::exception
{
	protected:
	private:
		//	Variables
		std::string msg_;	//!<	GB_Exception message
		std::string id_;	//!<	GB_Exception id

	public:
		//	(De-)Constructor
		GB_Exception(const std::string& str_msg, const std::string& str_id)
		{
			msg_	= str_msg;
			id_		= str_id;
		}

		virtual ~GB_Exception() {}

		//	Functions
		const char* GetStr() const	{ return msg_.c_str();	}
		const char* GetId() const	{ return id_.c_str();	}
};