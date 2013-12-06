/**
	@file	GB_Vector3.cpp
	@brief	Includes all GB_Vector3 class methods
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
#include "GB_Vector3.h"

//==================================================================
/**
	@fn		GB_Vector3 :: ~GB_Vector3()
	@brief	Deconstructor
**/
//==================================================================
GB_Vector3 :: ~GB_Vector3()
{
}

//==================================================================
/**
	@fn		GB_Vector3 :: GB_Vector3()
	@brief	Standardconstructor
**/
//==================================================================
GB_Vector3 :: GB_Vector3()
{
	x_ = y_ = z_ = 0;
}

//==================================================================
/**
	@fn		GB_Vector3 :: GB_Vector3(float coord)
	@brief	Extended Constructor
	@param	coord	x, y and z position of the GB_Object
**/
//==================================================================
GB_Vector3 :: GB_Vector3(float coord)
{
	x_ = y_ = z_ = coord;
}

//==================================================================
/**
	@fn		GB_Vector3 :: GB_Vector3(float * coords)
	@brief	Extended Constructor
	@param	coords	position of the GB_Object
**/
//==================================================================
GB_Vector3 :: GB_Vector3(float * coords)
{
	x_		= coords[0];
	y_		= coords[1];
	z_		= coords[2];
}

//==================================================================
/**
	@fn		GB_Vector3 :: GB_Vector3(float x, float y, float z)
	@brief	Extended Constructor
	@param	x	x position of the GB_Object
	@param	y	y position of the GB_Object
	@param	z	z position of the GB_Object
**/
//==================================================================
GB_Vector3 :: GB_Vector3(float x, float y, float z)
{
	x_		= x;
	y_		= y;
	z_		= z;
}

//==================================================================
/**
	@fn		GB_Vector3 :: operator+(const GB_Vector3& right)
	@brief	Overload operator +
	@param	right	right vector
**/
//==================================================================
GB_Vector3 GB_Vector3 :: operator+(const GB_Vector3& right)
{
	GB_Vector3 result;
	result.x_		= this->x_ + right.x_;
	result.y_		= this->y_ + right.y_;
	result.z_		= this->z_ + right.z_;
	return result;
}

//==================================================================
/**
	@fn		GB_Vector3 :: operator-(const GB_Vector3& right)
	@brief	Overload operator -
	@param	right	right vector
**/
//==================================================================
GB_Vector3 GB_Vector3 :: operator-(const GB_Vector3& right)
{
	GB_Vector3 result;
	result.x_		= this->x_ - right.x_;
	result.y_		= this->y_ - right.y_;
	result.z_		= this->z_ - right.z_;
	return result;
}

//==================================================================
/**
	@fn		GB_Vector3 :: operator*(const GB_Vector3& right)
	@brief	Overload operator *
	@param	right	right vector
**/
//==================================================================
GB_Vector3 GB_Vector3 :: operator*(const GB_Vector3& right)
{
	GB_Vector3 result;
	result.x_		= this->x_ * right.x_;
	result.y_		= this->y_ * right.y_;
	result.z_		= this->z_ * right.z_;
	return result;
}

//==================================================================
/**
	@fn		GB_Vector3 :: operator/(const GB_Vector3& right)
	@brief	Overload operator /
	@param	right	right vector
**/
//==================================================================
GB_Vector3 GB_Vector3 :: operator/(const GB_Vector3& right)
{
	GB_Vector3 result;
	result.x_		= (right.x_ != 0) ? this->x_ / right.x_ : 0;
	result.y_		= (right.y_ != 0) ? this->y_ / right.y_ : 0;
	result.z_		= (right.z_ != 0) ? this->z_ / right.z_ : 0;
	return result;
}