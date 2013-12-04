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
	mPosition.x_	= 0;
	mPosition.y_	= 0;
	mPosition.z_	= 0;
}

//==================================================================
/**
	@fn		gbObj :: gbObj(Vector3d pPosition)
	@brief	Extended Constructor
	@param	pPosition position of the object
**/
//==================================================================
gbObj :: gbObj(Vector3d pPosition)
{
	mPosition.x_		= pPosition.x_;
	mPosition.y_		= pPosition.y_;
	mPosition.z_		= pPosition.z_;
}

//==================================================================
/**
	@fn		gbObj :: gbObj(float x, float y, float z)
	@brief	Extended Constructor
	@param	x	x position of the object
	@param	y	y position of the object
	@param	z	z position of the object
**/
//==================================================================
gbObj :: gbObj(float x, float y, float z)
{
	mPosition.x_		= x;
	mPosition.y_		= y;
	mPosition.z_		= z;
}

//==================================================================
/**
	@fn		gbObj :: fReset()
	@brief	Reset the object
**/
//==================================================================
VOID gbObj :: fReset()
{
	mAxisX		= Vector3d(1.0f, 0.0f, 0.0f);
	mAxisY		= Vector3d(0.0f, 1.0f, 0.0f);
	mAxisZ		= Vector3d(0.0f, 0.0f, 1.0f);
	mPosition	= Vector3d(0.0f);
	v_elocity	= Vector3d(0.0f);
	mRotation	= Vector3d(0.0f);
	mScale		= Vector3d(1.0f);

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
	mMatrix		=	MatrixScale(mScale) *
					MatrixAxis(mAxisX, mAxisY, mAxisZ) *
					MatrixTranslation(mPosition);
	mInvMatrix	=	MatrixInvert(mMatrix);
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