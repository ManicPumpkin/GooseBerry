/**
	@file	GB_Convert.h
	@brief	Includes all global conversation functions
	@author	drubner
	@date	2013-08-22
**/
//==================================================================
#pragma once 

//==================================================================
// INCLUDE
//==================================================================
#include "GooseBerry.h"

//==================================================================
/**
	@class	std::string NumToStr(T number)
	@brief	GB_Converts a number into a string
	@return std::string GB_Convert.str()
**/
//==================================================================
template <typename T>
std::string NumToStr(T number)
{
	ostringstream GB_Convert;
	GB_Convert << number;
	return GB_Convert.str();
}

//==================================================================
/**
	@class	<T> StrToInt(std::string str)
	@brief	GB_Converts a string into a number
	@return <T> result
**/
//==================================================================
template <typename T>
T StrToInt(std::string str)
{
	T result;
	if(!(istringstream(str) >> result))
		result = 0;
	return result;
}
