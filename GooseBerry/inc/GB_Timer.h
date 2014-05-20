/**
@file	GB_Timer.h
@brief	Includes timer class
@author	drubner
@date	2014-05-20
**/
//==================================================================
//	PRAGMA ONCE
//==================================================================
#pragma once

//==================================================================
//	INCLUDE
//==================================================================
#include "gooseberry.h"
#include <time.h>

//==================================================================
//	CLASS
//==================================================================
/**
@class	GB_Timer
@brief	Class for GB_Timer operations
**/
//==================================================================
class GOOSEBERRY_API GB_Timer
{
	protected:
	private:
		unsigned int ticks_;
		unsigned int calls_;
		unsigned int clock_;

	public:
		~GB_Timer();
		GB_Timer();
		
		VOID Start();
		VOID Stop();
		int  Result();
};