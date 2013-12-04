/**
	@file	Convert.h
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
	@brief	Converts a number into a string
	@return std::string convert.str()
**/
//==================================================================
template <typename T>
std::string NumToStr(T number)
{
	ostringstream convert;
	convert << number;
	return convert.str();
}

//==================================================================
/**
	@class	<T> StrToInt(std::string str)
	@brief	Converts a string into a number
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
