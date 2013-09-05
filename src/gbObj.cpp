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
	@fn		gbObj :: gbObj(gbVector3d pPosition)
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
	@fn		gbObj :: gbObj(float pX, float pY, float pZ)
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

//==================================================================
/**
	@fn		gbObj :: fReset()
	@brief	Reset the object
**/
//==================================================================
VOID gbObj :: fReset()
{
	mAxisX		= gbVector3d(1.0f, 0.0f, 0.0f);
	mAxisY		= gbVector3d(0.0f, 1.0f, 0.0f);
	mAxisZ		= gbVector3d(0.0f, 0.0f, 1.0f);
	mPosition	= gbVector3d(0.0f);
	mVelocity	= gbVector3d(0.0f);
	mRotation	= gbVector3d(0.0f);
	mScale		= gbVector3d(1.0f);

	fUpdate();
}

//==================================================================
/**
	@fn		gbObj :: fUpdate()
	@brief	Update the object and its translation matrix
**/
//==================================================================
VOID gbObj :: fUpdate()
{
	mMatrix		=	gbMatrixScale(mScale) *
					gbMatrixAxis(mAxisX, mAxisY, mAxisZ) *
					gbMatrixTranslation(mPosition);
	mInvMatrix	=	gbMatrixInvert(mMatrix);
}

//==================================================================
/**
	@fn		gbObj :: fMove(const float pTime)
	@brief	Move an object by passed time
	@param	pTime	time passed
**/
//==================================================================
VOID gbObj :: fMove(const float pTime)
{
	//	\todo Bewegen
	//	\todo Rotieren
	//	\todo Reibung

	fUpdate();
}