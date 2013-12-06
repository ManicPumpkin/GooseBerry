/**
	@file	GB_Vector2.cpp
	@brief	Includes all GB_Vector2 class methods
	@author	drubner
	@date	2013-08-22
**/
//==================================================================
//	PRAGMA
//==================================================================
#pragma once

//==================================================================
//	INCLUDE
//==================================================================
#include "GB_Vector2.h"

//==================================================================
/**
	@fn		GB_Vector2 :: ~GB_Vector2()
	@brief	Deconstructor
**/
//==================================================================
GB_Vector2 :: ~GB_Vector2()
{
}

//==================================================================
/**
	@fn		GB_Vector2 :: GB_Vector2()
	@brief	Standardconstructor
**/
//==================================================================
GB_Vector2 :: GB_Vector2()
{
	x_ = y_ = 0;
}

//==================================================================
/**
	@fn		GB_Vector2 :: GB_Vector2(float * coords)
	@brief	Extended Constructor
	@param	coords	coordinates of the GB_Object
**/
//==================================================================
GB_Vector2 :: GB_Vector2(float * coords)
{
	x_		= coords[0];
	y_		= coords[1];
}


//==================================================================
/**
	@fn		GB_Vector2 :: GB_Vector2(float coord)
	@brief	Extended Constructor
	@param	coord	x and y position of the GB_Object
**/
//==================================================================
GB_Vector2 :: GB_Vector2(float coord)
{
	x_ = y_ = coord;
}

//==================================================================
/**
	@fn		GB_Vector2 :: GB_Vector2(float x, float y)
	@brief	Extended Constructor
	@param	x	x position of the GB_Object
	@param	y	y position of the GB_Object
**/
//==================================================================
GB_Vector2 :: GB_Vector2(float x, float y)
{
	x_		= x;
	y_		= y;
}

//==================================================================
/**
	@fn		GB_Vector2 :: operator+(const GB_Vector2& right)
	@brief	Overload operator +
	@param	right	right vector
**/
//==================================================================
GB_Vector2 GB_Vector2 :: operator+(const GB_Vector2& right)
{
	GB_Vector2 result;
	result.x_		= this->x_ + right.x_;
	result.y_		= this->y_ + right.y_;
	return result;
}

//==================================================================
/**
	@fn		GB_Vector2 :: operator-(const GB_Vector2& right)
	@brief	Overload operator -
	@param	right	right vector
**/
//==================================================================
GB_Vector2 GB_Vector2 :: operator-(const GB_Vector2& right)
{
	GB_Vector2 result;
	result.x_		= this->x_ - right.x_;
	result.y_		= this->y_ - right.y_;
	return result;
}

//==================================================================
/**
	@fn		GB_Vector2 :: operator*(const GB_Vector2& right)
	@brief	Overload operator *
	@param	right	right vector
**/
//==================================================================
GB_Vector2 GB_Vector2 :: operator*(const GB_Vector2& right)
{
	GB_Vector2 result;
	result.x_		= this->x_ * right.x_;
	result.y_		= this->y_ * right.y_;
	return result;
}

//==================================================================
/**
	@fn		GB_Vector2 :: operator/(const GB_Vector2& right)
	@brief	Overload operator /
	@param	right	right vector
**/
//==================================================================
GB_Vector2 GB_Vector2 :: operator/(const GB_Vector2& right)
{
	GB_Vector2 result;
	result.x_		= (right.x_ != 0) ? this->x_ / right.x_ : 0;
	result.y_		= (right.y_ != 0) ? this->y_ / right.y_ : 0;
	return result;
}