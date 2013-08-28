/**
	@file	gbColor.cpp
	@brief	Implements gbColor methods
	@author	drubner
	@date	2013-08-28
**/
//==================================================================
//	Include
//==================================================================
#include "gbColor.h"

//==================================================================
/**
	@fn		gbColor :: gbColor()
	@brief	Standardconstructor
**/
//==================================================================
gbColor :: gbColor()
{
}

//==================================================================
/**
	@fn		gbColor(float pR, float pG, float pB)
	@brief	Enhanced constructor
**/
//==================================================================
gbColor :: gbColor(float pR, float pG, float pB)
{
	mR	= pR;
	mG	= pG;
	mB	= pB;
	mA	= 1.0f;
}

//==================================================================
/**
	@fn		gbColor(float pR, float pG, float pB, float pA)
	@brief	Enhanced constructor
**/
//==================================================================
gbColor :: gbColor(float pR, float pG, float pB, float pA)
{
	mR	= pR;
	mG	= pG;
	mB	= pB;
	mA	= pA;
}

//==================================================================
/**
	@fn		gbColor :: gbColor(float * pColors)
	@brief	Enhanced constructor
**/
//==================================================================
gbColor :: gbColor(float * pColors)
{
	mR	= pColors[0];
	mG	= pColors[1];
	mB	= pColors[2];
	mA	= pColors[3];
}