/**
	@file	Matrix.h
	@brief	Includes Matrix class
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
//	FORWARD DECLARATION
//==================================================================
class Matrix;
class Vector3d;

//==================================================================
//	FUNCTION DECLARATION
//==================================================================
GOOSEBERRY_API Matrix MatrixRotationX	(const float angle);
GOOSEBERRY_API Matrix MatrixRotationY	(const float angle);
GOOSEBERRY_API Matrix MatrixRotationZ	(const float angle);
GOOSEBERRY_API Matrix MatrixRotation	(const float angle_x, const float angle_y, const float angle_z);
GOOSEBERRY_API Matrix MatrixRotation	(const float * rot_angle_3d);
GOOSEBERRY_API Matrix MatrixRotation	(const Vector3d angle_vector);
GOOSEBERRY_API Matrix MatrixAxis		(const Vector3d axis_x, const Vector3d axis_y, const Vector3d axis_z);
GOOSEBERRY_API Matrix MatrixTranslation (const float x, const float y, const float z);
GOOSEBERRY_API Matrix MatrixTranslation (const float * translation_3d);
GOOSEBERRY_API Matrix MatrixTranslation (const Vector3d vector);
GOOSEBERRY_API Matrix MatrixScale		(const float x, const float y, const float z);
GOOSEBERRY_API Matrix MatrixScale		(const float * scale_3d);
GOOSEBERRY_API Matrix MatrixScale		(const Vector3d vector);
GOOSEBERRY_API Matrix MatrixIdentity	();
GOOSEBERRY_API Matrix MatrixTranspose	(const Matrix & matrix);
GOOSEBERRY_API Matrix MatrixInvert		(const Matrix & matrix);
GOOSEBERRY_API float  MatrixDeterminant (const Matrix & matrix);

//==================================================================
//	CLASS
//==================================================================
/**
		@class	Matrix
		@brief	Class for matrix operations
**/
//==================================================================
class GOOSEBERRY_API Matrix
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
		Matrix();
		Matrix(float * p1DimArray);
		Matrix(float p11, float p12, float p13, float p14, float p21, float p22, float p23, float p24,
				float p31, float p32, float p33, float p34, float p41, float p42, float p43, float p44);
		~Matrix(){}

		//	Operators
		Matrix operator +		(const Matrix& right);
		Matrix operator -		(const Matrix& right);
		Matrix operator *		(const Matrix& right);
		Matrix operator /		(const Matrix& right);
		Matrix operator *		(const float value);
		Matrix operator /		(const float value);
		Matrix operator +=		(const Matrix& right);
		Matrix operator -=		(const Matrix& right);
		Matrix operator *=		(const Matrix& right);
		Matrix operator /=		(const Matrix& right);
		Matrix operator *=		(const float value);
		Matrix operator /=		(const float value);
		bool	 operator ==	(const Matrix& right);
		bool     operator !=	(const Matrix& right);
		Matrix operator =		(const Matrix& right);
				
	private:
	protected:
};