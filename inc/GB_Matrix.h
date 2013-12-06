/**
	@file	GB_Matrix.h
	@brief	Includes GB_Matrix class
	@author	drubner
	@date	2013-08-28
**/
//==================================================================
//	PRAGMA
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
//	FORWARD DECLARATION
//==================================================================
class GB_Matrix;
class GB_Vector3;

//==================================================================
//	FUNCTION DECLARATION
//==================================================================
GOOSEBERRY_API GB_Matrix MatrixRotationX(const float angle);
GOOSEBERRY_API GB_Matrix MatrixRotationY(const float angle);
GOOSEBERRY_API GB_Matrix MatrixRotationZ(const float angle);
GOOSEBERRY_API GB_Matrix MatrixRotation(const float angle_x, const float angle_y, const float angle_z);
GOOSEBERRY_API GB_Matrix MatrixRotation(const float * rot_angle_3d);
GOOSEBERRY_API GB_Matrix MatrixRotation(const GB_Vector3 angle_vector);
GOOSEBERRY_API GB_Matrix MatrixAxis(const GB_Vector3 axis_x, const GB_Vector3 axis_y, const GB_Vector3 axis_z);
GOOSEBERRY_API GB_Matrix MatrixTranslation(const float x, const float y, const float z);
GOOSEBERRY_API GB_Matrix MatrixTranslation(const float * translation_3d);
GOOSEBERRY_API GB_Matrix MatrixTranslation(const GB_Vector3 vector);
GOOSEBERRY_API GB_Matrix MatrixScale(const float x, const float y, const float z);
GOOSEBERRY_API GB_Matrix MatrixScale(const float * scale_3d);
GOOSEBERRY_API GB_Matrix MatrixScale(const GB_Vector3 vector);
GOOSEBERRY_API GB_Matrix MatrixIdentity();
GOOSEBERRY_API GB_Matrix MatrixTranspose(const GB_Matrix & GB_Matrix );
GOOSEBERRY_API GB_Matrix MatrixInvert(const GB_Matrix & GB_Matrix );
GOOSEBERRY_API float MatrixDeterminant(const GB_Matrix & GB_Matrix );

//==================================================================
//	CLASS
//==================================================================
/**
		@class	GB_Matrix 
		@brief	Class for GB_Matrix  operations
**/
//==================================================================
class GOOSEBERRY_API GB_Matrix 
{
	public:
		//  Variables
		union
		{
			struct
			{
				float m11_, m12_, m13_, m14_;
				float m21_, m22_, m23_, m24_;
				float m31_, m32_, m33_, m34_;
				float m41_, m42_, m43_, m44_;
			};

			float d2_[4][4];
			float d1_[16];
		};

		//	(De-)Constructor
		GB_Matrix ();
		GB_Matrix(float * one_dim_arr);
		GB_Matrix (float p11, float p12, float p13, float p14, float p21, float p22, float p23, float p24,
				float p31, float p32, float p33, float p34, float p41, float p42, float p43, float p44);
		~GB_Matrix (){}

		//	Operators
		GB_Matrix  operator +	(const GB_Matrix & right);
		GB_Matrix  operator -	(const GB_Matrix & right);
		GB_Matrix  operator *	(const GB_Matrix & right);
		GB_Matrix  operator /	(const GB_Matrix & right);
		GB_Matrix  operator *	(const float value);
		GB_Matrix  operator /	(const float value);
		GB_Matrix  operator +=	(const GB_Matrix & right);
		GB_Matrix  operator -=	(const GB_Matrix & right);
		GB_Matrix  operator *=	(const GB_Matrix & right);
		GB_Matrix  operator /=	(const GB_Matrix & right);
		GB_Matrix  operator *=	(const float value);
		GB_Matrix  operator /=	(const float value);
		bool	 operator ==	(const GB_Matrix & right);
		bool     operator !=	(const GB_Matrix & right);
		GB_Matrix  operator =	(const GB_Matrix & right);
				
	private:
	protected:
};