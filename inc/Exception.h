/**
	@file	Exception.h
	@brief	Includes Exception class
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
#define GB_EXCEPTION_ICON { MB_OK | GB_ERROR }

//==================================================================
//	Class
//==================================================================
/**
		@class	Exception
		@brief	Includes exception handling methods and variables
**/
//==================================================================
class Exception : public std::exception
{
	protected:
	private:
		//	Variables
		std::string msg_;	//!<	exception message
		std::string id_;	//!<	exception id

	public:
		//	(De-)Constructor
		Exception(const std::string& str_msg, const std::string& str_id)
		{
			msg_	= str_msg;
			id_		= str_id;
		}

		virtual ~Exception() {}

		//	Functions
		const char* GetStr() const	{ return msg_.c_str();	}
		const char* GetId() const	{ return id_.c_str();	}
};