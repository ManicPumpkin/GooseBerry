//==================================================================
/**
	@file	GB_Object.h
	@brief	This file includes the GB_Object 

	Includes the GB_Object class. Contains all variables needed to
	hold information of the GB_Object and contains variables such
	as model, position etc.

	@author	drubner
	@date	2013-08-22
**/
//==================================================================
#pragma once

//==================================================================
//	INCLUDE
//==================================================================
#include "GooseBerry.h"

//==================================================================
//	NAMESPACE
//==================================================================

//==================================================================
//	CLASS
//==================================================================
/**
	@class	GB_Object
	@brief	Contains information about GB_Object/model files
**/
//==================================================================
class GOOSEBERRY_API GB_Object
{
	protected:
	private:
		//	Variables
		GB_Mesh		model_;			//!< model of GB_Object
		GB_Vector3	axis_x_;		//!< x axis
		GB_Vector3	axis_y_;		//!< y axis
		GB_Vector3	axis_z_;		//!< z axis
		GB_Vector3	position_;		//!< position
		GB_Vector3	scale_;			//!< scaling
		GB_Vector3	rotation_;		//!< rotation
		GB_Vector3	velocity_;		//!< velocity
		GB_Matrix 	matrix_;		//!< transform GB_Matrix 
		GB_Matrix 	inv_matrix_;	//!< inverse transform GB_Matrix 

		//	Functions
		VOID Reset();
		VOID Update();
		VOID Move(const float time);
		
	public:
		//	Variables
		//	(De-)Constructor & Copy
		~GB_Object();
		GB_Object();
		GB_Object(GB_Vector3 position);
		GB_Object(float x, float y, float z);
};