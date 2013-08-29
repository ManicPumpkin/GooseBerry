/**
	@file	gbVector2d.cpp
	@brief	Includes all gbVector2d class methods
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
#include "gbVector2d.h"

//==================================================================
/**
	@fn		gbVector2d :: ~gbVector2d()
	@brief	Deconstructor
**/
//==================================================================
gbVector2d :: ~gbVector2d()
{
}

//==================================================================
/**
	@fn		gbVector2d :: gbVector2d()
	@brief	Standardconstructor
**/
//==================================================================
gbVector2d :: gbVector2d()
{
	mX = mY = 0;
}

//==================================================================
/**
	@fn		gbVector2d :: gbVector2d(float * pCoords)
	@brief	Extended Constructor
	@param	pPosition position of the object
**/
//==================================================================
gbVector2d :: gbVector2d(float * pCoords)
{
	mX		= pCoords[0];
	mY		= pCoords[1];
}


//==================================================================
/**
	@fn		gbVector2d :: gbVector2d(float pCoord)
	@brief	Extended Constructor
	@param	pCoord	x and y position of the object
**/
//==================================================================
gbVector2d :: gbVector2d(float pCoord)
{
	mX = mY = pCoord;
}

//==================================================================
/**
	@fn		gbVector2d :: gbVector2d(float pX, float pY)
	@brief	Extended Constructor
	@param	pX	x position of the object
	@param	pY	y position of the object
**/
//==================================================================
gbVector2d :: gbVector2d(float pX, float pY)
{
	mX		= pX;
	mY		= pY;
}

//==================================================================
/**
	@fn		gbVector2d :: operator+(const gbVector2d& pRight)
	@brief	Overload operator +
	@param	pRight	right vector
**/
//==================================================================
gbVector2d gbVector2d :: operator+(const gbVector2d& pRight)
{
	gbVector2d tResult;
	tResult.mX		= this->mX + pRight.mX;
	tResult.mY		= this->mY + pRight.mY;
	return tResult;
}

//==================================================================
/**
	@fn		gbVector2d :: operator-(const gbVector2d& pRight)
	@brief	Overload operator -
	@param	pRight	right vector
**/
//==================================================================
gbVector2d gbVector2d :: operator-(const gbVector2d& pRight)
{
	gbVector2d tResult;
	tResult.mX		= this->mX - pRight.mX;
	tResult.mY		= this->mY - pRight.mY;
	return tResult;
}

//==================================================================
/**
	@fn		gbVector2d :: operator*(const gbVector2d& pRight)
	@brief	Overload operator *
	@param	pRight	right vector
**/
//==================================================================
gbVector2d gbVector2d :: operator*(const gbVector2d& pRight)
{
	gbVector2d tResult;
	tResult.mX		= this->mX * pRight.mX;
	tResult.mY		= this->mY * pRight.mY;
	return tResult;
}

//==================================================================
/**
	@fn		gbVector2d :: operator/(const gbVector2d& pRight)
	@brief	Overload operator /
	@param	pRight	right vector
**/
//==================================================================
gbVector2d gbVector2d :: operator/(const gbVector2d& pRight)
{
	gbVector2d tResult;
	tResult.mX		= (pRight.mX != 0) ? this->mX / pRight.mX : 0;
	tResult.mY		= (pRight.mY != 0) ? this->mY / pRight.mY : 0;
	return tResult;
}