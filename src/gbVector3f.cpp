/**
	@file	gbVector3f.cpp
	@brief	Includes all gbVector3f class methods
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
#include "gbVector3f.h"

//==================================================================
/**
	@fn		gbVector3f :: ~gbVector3f()
	@brief	Deconstructor
**/
//==================================================================
gbVector3f :: ~gbVector3f()
{
}

//==================================================================
/**
	@fn		gbObj :: gbObj()
	@brief	Standardconstructor
**/
//==================================================================
gbVector3f :: gbVector3f()
{
	mPosition.x		= 0;
	mPosition.y		= 0;
	mPosition.z		= 0;
}

//==================================================================
/**
	@fn		gbObj :: ~gbObj()
	@brief	Extended Constructor
	@param	pPosition position of the object
**/
//==================================================================
gbVector3f :: gbVector3f(gb_g_position pPosition)
{
	mPosition.x		= pPosition.x;
	mPosition.y		= pPosition.y;
	mPosition.z		= pPosition.z;
}

//==================================================================
/**
	@fn		gbObj :: ~gbObj()
	@brief	Extended Constructor
	@param	pX	x position of the object
	@param	pY	y position of the object
	@param	pZ	z position of the object
**/
//==================================================================
gbVector3f :: gbVector3f(float pX, float pY, float pZ)
{
	mPosition.x		= pX;
	mPosition.y		= pY;
	mPosition.z		= pZ;
}

//==================================================================
/**
	@fn		gbVector3f :: operator+(const gbVector3f& pRight)
	@brief	Overload operator +
	@param	pRight	right vector
**/
//==================================================================
gbVector3f gbVector3f :: operator+(const gbVector3f& pRight)
{
	gbVector3f tResult;
	tResult.mPosition.x		= this->mPosition.x + pRight.mPosition.x;
	tResult.mPosition.y		= this->mPosition.y + pRight.mPosition.y;
	tResult.mPosition.z		= this->mPosition.z + pRight.mPosition.z;
	return tResult;
}

//==================================================================
/**
	@fn		gbVector3f :: operator-(const gbVector3f& pRight)
	@brief	Overload operator -
	@param	pRight	right vector
**/
//==================================================================
gbVector3f gbVector3f :: operator-(const gbVector3f& pRight)
{
	gbVector3f tResult;
	tResult.mPosition.x		= this->mPosition.x - pRight.mPosition.x;
	tResult.mPosition.y		= this->mPosition.y - pRight.mPosition.y;
	tResult.mPosition.z		= this->mPosition.z - pRight.mPosition.z;
	return tResult;
}

//==================================================================
/**
	@fn		gbVector3f :: operator*(const gbVector3f& pRight)
	@brief	Overload operator *
	@param	pRight	right vector
**/
//==================================================================
gbVector3f gbVector3f :: operator*(const gbVector3f& pRight)
{
	gbVector3f tResult;
	tResult.mPosition.x		= this->mPosition.x * pRight.mPosition.x;
	tResult.mPosition.y		= this->mPosition.y * pRight.mPosition.y;
	tResult.mPosition.z		= this->mPosition.z * pRight.mPosition.z;
	return tResult;
}

//==================================================================
/**
	@fn		gbVector3f :: operator/(const gbVector3f& pRight)
	@brief	Overload operator /
	@param	pRight	right vector
**/
//==================================================================
gbVector3f gbVector3f :: operator/(const gbVector3f& pRight)
{
	gbVector3f tResult;
	tResult.mPosition.x		= (pRight.mPosition.x != 0) ? this->mPosition.x / pRight.mPosition.x : 0;
	tResult.mPosition.y		= (pRight.mPosition.y != 0) ? this->mPosition.y / pRight.mPosition.y : 0;
	tResult.mPosition.z		= (pRight.mPosition.z != 0) ? this->mPosition.z / pRight.mPosition.z : 0;
	return tResult;
}