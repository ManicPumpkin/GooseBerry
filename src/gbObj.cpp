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
gbObj :: gbObj(gb_g_position pPosition)
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
gbObj :: gbObj(float pX, float pY, float pZ)
{
	mPosition.x		= pX;
	mPosition.y		= pY;
	mPosition.z		= pZ;
}