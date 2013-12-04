/**
	@file	Color.cpp
	@brief	Implements Color methods
	@author	drubner
	@date	2013-08-28
**/
//==================================================================
//	Include
//==================================================================
#include "Color.h"

//==================================================================
/**
	@fn		Color :: Color()
	@brief	Standardconstructor
**/
//==================================================================
Color :: Color()
{
}

//==================================================================
/**
	@fn		Color(float r, float g, float b)
	@brief	Enhanced constructor
**/
//==================================================================
Color :: Color(float r, float g, float b)
{
	this->r	= r;
	this->g	= g;
	this->b	= b;
	this->a	= 1.0f;
}

//==================================================================
/**
	@fn		Color(float r, float g, float b, float a)
	@brief	Enhanced constructor
**/
//==================================================================
Color :: Color(float r, float g, float b, float a)
{
	this->r	= r;
	this->g	= g;
	this->b	= b;
	this->a	= a;
}

//==================================================================
/**
	@fn		Color :: Color(float * pColors)
	@brief	Enhanced constructor
**/
//==================================================================
Color :: Color(float * pColors)
{
	this->r	= pColors[0];
	this->g	= pColors[1];
	this->b	= pColors[2];
	this->a	= pColors[3];
}