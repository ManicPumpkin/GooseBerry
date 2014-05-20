/**
@file	GB_Timer.cpp
@brief	Includes GB_Timer methods
@author	drubner
@date	2014-05-20
**/
//==================================================================
//	INCLUDE
//==================================================================
#include "GB_Timer.h"

//==================================================================
//	Functions
//==================================================================
/**
@fn		GB_Timer::GB_Timer()
@brief	Standardconstructor
**/
//==================================================================
GB_Timer::GB_Timer()
{
	ticks_	= 0;
	calls_	= 0;
	clock_	= 0;
}

//==================================================================
/**
@fn		GB_Timer::Start()
@brief	Start timer
**/
//==================================================================
VOID GOOSEBERRY_API GB_Timer::Start()
{
	clock_	= clock();
	GB_LDEBUG("Timer started.");
}

//==================================================================
/**
@fn		GB_Timer::Stop()
@brief	Stop timer
**/
//==================================================================
VOID GOOSEBERRY_API GB_Timer::Stop()
{
	ticks_	+= clock() - clock_;
	calls_++;
}

//==================================================================
/**
@fn		GB_Timer::Result()
@brief	Result of timer
**/
//==================================================================
int GOOSEBERRY_API GB_Timer::Result()
{
	int milli_sec;
	milli_sec = ticks_ * 100 / CLOCKS_PER_SEC;

	GB_LDEBUG("Timer stopped. MS passed: " + milli_sec); 

	return milli_sec;
}