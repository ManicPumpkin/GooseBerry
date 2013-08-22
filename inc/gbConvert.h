/**
	@file	gbConvert.h
	@brief	Includes all global conversation functions
	@author	drubner
	@date	2013-08-22
**/
//==================================================================
#pragma once 

//==================================================================
// INCLUDE
//==================================================================
#include "gooseberry.h"

//==================================================================
/**
	@class	std::string gbNumToStr(T pNumber)
	@brief	Converts a number into a string
	@return std::string tConvert.str()
**/
//==================================================================
template <typename T>
std::string gbNumToStr(T pNumber)
{
	ostringstream tConvert;
	tConvert << pNumber;
	return tConvert.str();
}

//==================================================================
/**
	@class	<T> gbStrToInt(std::string pStr)
	@brief	Converts a string into a number
	@return <T> tResult
**/
//==================================================================
template <typename T>
T gbStrToInt(std::string pStr)
{
	T tResult;
	if(!(istringstream(pStr) >> tResult))
		tResult = 0;
	return tResult;
}
