/**
	@file	gbVector3d.cpp
	@brief	Includes all gbVector3d class methods
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
#include "gbVector3d.h"

//==================================================================
/**
	@fn		gbVector3d :: ~gbVector3d()
	@brief	Deconstructor
**/
//==================================================================
gbVector3d :: ~gbVector3d()
{
}

//==================================================================
/**
	@fn		gbVector3d :: gbVector3d()
	@brief	Standardconstructor
**/
//==================================================================
gbVector3d :: gbVector3d()
{
	mX		= 0;
	mY		= 0;
	mZ		= 0;
}

//==================================================================
/**
	@fn		gbVector3d :: gbVector3d(float * pCoords)
	@brief	Extended Constructor
	@param	pPosition position of the object
**/
//==================================================================
gbVector3d :: gbVector3d(float * pCoords)
{
	mX		= pCoords[0];
	mY		= pCoords[1];
	mZ		= pCoords[2];
}

//==================================================================
/**
	@fn		gbVector3d :: gbVector3d(float pX, float pY, float pZ)
	@brief	Extended Constructor
	@param	pX	x position of the object
	@param	pY	y position of the object
	@param	pZ	z position of the object
**/
//==================================================================
gbVector3d :: gbVector3d(float pX, float pY, float pZ)
{
	mX		= pX;
	mY		= pY;
	mZ		= pZ;
}

//==================================================================
/**
	@fn		gbVector3d :: operator+(const gbVector3d& pRight)
	@brief	Overload operator +
	@param	pRight	right vector
**/
//==================================================================
gbVector3d gbVector3d :: operator+(const gbVector3d& pRight)
{
	gbVector3d tResult;
	tResult.mX		= this->mX + pRight.mX;
	tResult.mY		= this->mY + pRight.mY;
	tResult.mZ		= this->mZ + pRight.mZ;
	return tResult;
}

//==================================================================
/**
	@fn		gbVector3d :: operator-(const gbVector3d& pRight)
	@brief	Overload operator -
	@param	pRight	right vector
**/
//==================================================================
gbVector3d gbVector3d :: operator-(const gbVector3d& pRight)
{
	gbVector3d tResult;
	tResult.mX		= this->mX - pRight.mX;
	tResult.mY		= this->mY - pRight.mY;
	tResult.mZ		= this->mZ - pRight.mZ;
	return tResult;
}

//==================================================================
/**
	@fn		gbVector3d :: operator*(const gbVector3d& pRight)
	@brief	Overload operator *
	@param	pRight	right vector
**/
//==================================================================
gbVector3d gbVector3d :: operator*(const gbVector3d& pRight)
{
	gbVector3d tResult;
	tResult.mX		= this->mX * pRight.mX;
	tResult.mY		= this->mY * pRight.mY;
	tResult.mZ		= this->mZ * pRight.mZ;
	return tResult;
}

//==================================================================
/**
	@fn		gbVector3d :: operator/(const gbVector3d& pRight)
	@brief	Overload operator /
	@param	pRight	right vector
**/
//==================================================================
gbVector3d gbVector3d :: operator/(const gbVector3d& pRight)
{
	gbVector3d tResult;
	tResult.mX		= (pRight.mX != 0) ? this->mX / pRight.mX : 0;
	tResult.mY		= (pRight.mY != 0) ? this->mY / pRight.mY : 0;
	tResult.mZ		= (pRight.mZ != 0) ? this->mZ / pRight.mZ : 0;
	return tResult;
}