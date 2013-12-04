/**
	@file	Vector3d.cpp
	@brief	Includes all Vector3d class methods
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
#include "Vector3d.h"

//==================================================================
/**
	@fn		Vector3d :: ~Vector3d()
	@brief	Deconstructor
**/
//==================================================================
Vector3d :: ~Vector3d()
{
}

//==================================================================
/**
	@fn		Vector3d :: Vector3d()
	@brief	Standardconstructor
**/
//==================================================================
Vector3d :: Vector3d()
{
	x_ = y_ = z_ = 0;
}

//==================================================================
/**
	@fn		Vector3d :: Vector3d(float coord)
	@brief	Extended Constructor
	@param	coord	x, y and z position of the object
**/
//==================================================================
Vector3d :: Vector3d(float coord)
{
	x_ = y_ = z_ = coord;
}

//==================================================================
/**
	@fn		Vector3d :: Vector3d(float * coords)
	@brief	Extended Constructor
	@param	coords	position of the object
**/
//==================================================================
Vector3d :: Vector3d(float * coords)
{
	x_		= coords[0];
	y_		= coords[1];
	z_		= coords[2];
}

//==================================================================
/**
	@fn		Vector3d :: Vector3d(float x, float y, float z)
	@brief	Extended Constructor
	@param	x	x position of the object
	@param	y	y position of the object
	@param	z	z position of the object
**/
//==================================================================
Vector3d :: Vector3d(float x, float y, float z)
{
	x_		= x;
	y_		= y;
	z_		= z;
}

//==================================================================
/**
	@fn		Vector3d :: operator+(const Vector3d& right)
	@brief	Overload operator +
	@param	right	right vector
**/
//==================================================================
Vector3d Vector3d :: operator+(const Vector3d& right)
{
	Vector3d result;
	result.x_		= this->x_ + right.x_;
	result.y_		= this->y_ + right.y_;
	result.z_		= this->z_ + right.z_;
	return result;
}

//==================================================================
/**
	@fn		Vector3d :: operator-(const Vector3d& right)
	@brief	Overload operator -
	@param	right	right vector
**/
//==================================================================
Vector3d Vector3d :: operator-(const Vector3d& right)
{
	Vector3d result;
	result.x_		= this->x_ - right.x_;
	result.y_		= this->y_ - right.y_;
	result.z_		= this->z_ - right.z_;
	return result;
}

//==================================================================
/**
	@fn		Vector3d :: operator*(const Vector3d& right)
	@brief	Overload operator *
	@param	right	right vector
**/
//==================================================================
Vector3d Vector3d :: operator*(const Vector3d& right)
{
	Vector3d result;
	result.x_		= this->x_ * right.x_;
	result.y_		= this->y_ * right.y_;
	result.z_		= this->z_ * right.z_;
	return result;
}

//==================================================================
/**
	@fn		Vector3d :: operator/(const Vector3d& right)
	@brief	Overload operator /
	@param	right	right vector
**/
//==================================================================
Vector3d Vector3d :: operator/(const Vector3d& right)
{
	Vector3d result;
	result.x_		= (right.x_ != 0) ? this->x_ / right.x_ : 0;
	result.y_		= (right.y_ != 0) ? this->y_ / right.y_ : 0;
	result.z_		= (right.z_ != 0) ? this->z_ / right.z_ : 0;
	return result;
}