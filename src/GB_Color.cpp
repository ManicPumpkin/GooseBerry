/**
	@file	GB_Color.cpp
	@brief	Implements GB_Color methods
	@author	drubner
	@date	2013-08-28
**/
//==================================================================
//	Include
//==================================================================
#include "GB_Color.h"

//==================================================================
/**
	@fn		GB_Color :: GooseBerry::GB_Color()
	@brief	Standardconstructor
**/
//==================================================================
GB_Color :: GB_Color()
{
}

//==================================================================
/**
	@fn		GB_Color(float r, float g, float b)
	@brief	Enhanced constructor
**/
//==================================================================
GB_Color :: GB_Color(float r, float g, float b)
{
	this->r	= r;
	this->g	= g;
	this->b	= b;
	this->a	= 1.0f;
}

//==================================================================
/**
	@fn		GB_Color(float r, float g, float b, float a)
	@brief	Enhanced constructor
**/
//==================================================================
GB_Color :: GB_Color(float r, float g, float b, float a)
{
	this->r	= r;
	this->g	= g;
	this->b	= b;
	this->a	= a;
}

//==================================================================
/**
	@fn		GB_Color :: GB_Color(float * colors)
	@brief	Enhanced constructor
**/
//==================================================================
GB_Color :: GB_Color(float * colors)
{
	this->r	= colors[0];
	this->g	= colors[1];
	this->b	= colors[2];
	this->a	= colors[3];
}