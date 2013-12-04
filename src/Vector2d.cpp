/**
	@file	Vector2d.cpp
	@brief	Includes all Vector2d class methods
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
#include "Vector2d.h"

//==================================================================
/**
	@fn		Vector2d :: ~Vector2d()
	@brief	Deconstructor
**/
//==================================================================
Vector2d :: ~Vector2d()
{
}

//==================================================================
/**
	@fn		Vector2d :: Vector2d()
	@brief	Standardconstructor
**/
//==================================================================
Vector2d :: Vector2d()
{
	x_ = y_ = 0;
}

//==================================================================
/**
	@fn		Vector2d :: Vector2d(float * coords)
	@brief	Extended Constructor
	@param	coords	coordinates of the object
**/
//==================================================================
Vector2d :: Vector2d(float * coords)
{
	x_		= coords[0];
	y_		= coords[1];
}


//==================================================================
/**
	@fn		Vector2d :: Vector2d(float coord)
	@brief	Extended Constructor
	@param	coord	x and y position of the object
**/
//==================================================================
Vector2d :: Vector2d(float coord)
{
	x_ = y_ = coord;
}

//==================================================================
/**
	@fn		Vector2d :: Vector2d(float x, float y)
	@brief	Extended Constructor
	@param	x	x position of the object
	@param	y	y position of the object
**/
//==================================================================
Vector2d :: Vector2d(float x, float y)
{
	x_		= x;
	y_		= y;
}

//==================================================================
/**
	@fn		Vector2d :: operator+(const Vector2d& right)
	@brief	Overload operator +
	@param	right	right vector
**/
//==================================================================
Vector2d Vector2d :: operator+(const Vector2d& right)
{
	Vector2d result;
	result.x_		= this->x_ + right.x_;
	result.y_		= this->y_ + right.y_;
	return result;
}

//==================================================================
/**
	@fn		Vector2d :: operator-(const Vector2d& right)
	@brief	Overload operator -
	@param	right	right vector
**/
//==================================================================
Vector2d Vector2d :: operator-(const Vector2d& right)
{
	Vector2d result;
	result.x_		= this->x_ - right.x_;
	result.y_		= this->y_ - right.y_;
	return result;
}

//==================================================================
/**
	@fn		Vector2d :: operator*(const Vector2d& right)
	@brief	Overload operator *
	@param	right	right vector
**/
//==================================================================
Vector2d Vector2d :: operator*(const Vector2d& right)
{
	Vector2d result;
	result.x_		= this->x_ * right.x_;
	result.y_		= this->y_ * right.y_;
	return result;
}

//==================================================================
/**
	@fn		Vector2d :: operator/(const Vector2d& right)
	@brief	Overload operator /
	@param	right	right vector
**/
//==================================================================
Vector2d Vector2d :: operator/(const Vector2d& right)
{
	Vector2d result;
	result.x_		= (right.x_ != 0) ? this->x_ / right.x_ : 0;
	result.y_		= (right.y_ != 0) ? this->y_ / right.y_ : 0;
	return result;
}