/**
	@file	gbObj.cpp
	@brief	Includes all gbObj class methods
	@author	drubner
	@date	2013-08-22
**/
//==================================================================
#pragma once

//==================================================================
//	Includes
//==================================================================
#include "gbObj.h"

//==================================================================
/**
	@fn		gbObj :: ~gbObj()
	@brief	Deconstructor
**/
//==================================================================
gbObj :: ~gbObj()
{
}

//==================================================================
/**
	@fn		gbObj :: gbObj()
	@brief	Standardconstructor
**/
//==================================================================
gbObj :: gbObj()
{
	mPosition.mX	= 0;
	mPosition.mY	= 0;
	mPosition.mZ	= 0;
}

//==================================================================
/**
	@fn		gbObj :: ~gbObj()
	@brief	Extended Constructor
	@param	pPosition position of the object
**/
//==================================================================
gbObj :: gbObj(gbVector3d pPosition)
{
	mPosition.mX		= pPosition.mX;
	mPosition.mY		= pPosition.mY;
	mPosition.mZ		= pPosition.mZ;
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
gbObj :: gbObj(float pX, float pY, float pZ)
{
	mPosition.mX		= pX;
	mPosition.mY		= pY;
	mPosition.mZ		= pZ;
}