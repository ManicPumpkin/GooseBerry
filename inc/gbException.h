/**
	@file	gbException.h
	@brief	Includes cException class
	@author	drubner
	@date	2012-11-10
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
		@class	gbException
		@brief	Includes exception handling methods and variables
**/
//==================================================================
class gbException : public std::exception
{
	protected:
	private:
		//	Variables
		std::string mMessage;		//!<	exception message
		std::string mId;			//!<	exception id

	public:
		//	(De-)Constructor
		gbException(const std::string& pStrMessage, const std::string& pStrId)
		{
			mMessage	= pStrMessage;
			mId			= pStrId;
		}

		virtual ~gbException() {}

		//	Functions
		const char* fGetStr() const { return mMessage.c_str();	}
		const char* fGetId() const	{ return mId.c_str();		}
};