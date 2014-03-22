/**
	@file	GB_Object.cpp
	@brief	Includes all GB_Object class methods
	@author	drubner
	@date	2013-08-22
**/
//==================================================================
#pragma once

//==================================================================
//	Includes
//==================================================================
#include "GB_Object.h"

//==================================================================
/**
	@fn		GB_Object :: ~GB_Object()
	@brief	Deconstructor
**/
//==================================================================
GB_Object :: ~GB_Object()
{
}

//==================================================================
/**
	@fn		GB_Object :: GB_Object()
	@brief	Standardconstructor
**/
//==================================================================
GB_Object :: GB_Object()
{
	position_.x_	= 0;
	position_.y_	= 0;
	position_.z_	= 0;
}

//==================================================================
/**
	@fn		GB_Object :: GB_Object(GooseBerry::Vector3d position)
	@brief	Extended Constructor
	@param	position position of the GB_Object
**/
//==================================================================
GB_Object :: GB_Object(GB_Vector3 position)
{
	position_.x_		= position.x_;
	position_.y_		= position.y_;
	position_.z_		= position.z_;
}

//==================================================================
/**
	@fn		GB_Object :: GB_Object(float x, float y, float z)
	@brief	Extended Constructor
	@param	x	x position of the GB_Object
	@param	y	y position of the GB_Object
	@param	z	z position of the GB_Object
**/
//==================================================================
GB_Object :: GB_Object(float x, float y, float z)
{
	position_.x_		= x;
	position_.y_		= y;
	position_.z_		= z;
}

//==================================================================
/**
	@fn		GB_Object :: Reset()
	@brief	Reset the GB_Object
**/
//==================================================================
VOID GB_Object :: Reset()
{
	axis_x_		= GB_Vector3(1.0f, 0.0f, 0.0f);
	axis_y_		= GB_Vector3(0.0f, 1.0f, 0.0f);
	axis_z_		= GB_Vector3(0.0f, 0.0f, 1.0f);
	position_	= GB_Vector3(0.0f);
	velocity_	= GB_Vector3(0.0f);
	rotation_	= GB_Vector3(0.0f);
	scale_		= GB_Vector3(1.0f);

	Update();
}

//==================================================================
/**
	@fn		GB_Object :: Update()
	@brief	Update the GB_Object and its translation GooseBerry::GB_Matrix 
**/
//==================================================================
VOID GB_Object :: Update()
{
	matrix_		=	MatrixScale(scale_) *
					MatrixAxis(axis_x_, axis_y_, axis_z_) *
					MatrixTranslation(position_);
	inv_matrix_	=	MatrixInvert(matrix_);
}

//==================================================================
/**
	@fn		GB_Object :: Move(const float time)
	@brief	Move an GB_Object by passed time
	@param	time	time passed
**/
//==================================================================
VOID GB_Object :: Move(const float time)
{
	//	\todo Bewegen
	//	\todo Rotieren
	//	\todo Reibung

	Update();
}