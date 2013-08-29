/**
	@file	gbMatrix.h
	@brief	Includes gbMatrix class
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
#include "gooseberry.h"

//==================================================================
//	FORWARD DECLARATION
//==================================================================
class gbMatrix;
class gbVector3d;

//==================================================================
//	FUNCTION DECLARATION
//==================================================================
GOOSEBERRY_API gbMatrix gbMatrixRotationX	(const float pValue);
GOOSEBERRY_API gbMatrix gbMatrixRotationY	(const float pValue);
GOOSEBERRY_API gbMatrix gbMatrixRotationZ	(const float pValue);
GOOSEBERRY_API gbMatrix gbMatrixRotation	(const float pX, const float pY, const float pZ);
GOOSEBERRY_API gbMatrix gbMatrixRotation	(const float * pRotation3D);
GOOSEBERRY_API gbMatrix gbMatrixRotation	(const gbVector3d pVector);
GOOSEBERRY_API gbMatrix gbMatrixAxis		(const gbVector3d pAxisX, const gbVector3d pAxisY, const gbVector3d pAxisZ);
GOOSEBERRY_API gbMatrix gbMatrixTranslation (const float pX, const float pY, const float pZ);
GOOSEBERRY_API gbMatrix gbMatrixTranslation (const float * pTranslation3D);
GOOSEBERRY_API gbMatrix gbMatrixTranslation (const gbVector3d pVector);
GOOSEBERRY_API gbMatrix gbMatrixScale		(const float pX, const float pY, const float pZ);
GOOSEBERRY_API gbMatrix gbMatrixScale		(const float * pScale3D);
GOOSEBERRY_API gbMatrix gbMatrixScale		(const gbVector3d pVector);
GOOSEBERRY_API gbMatrix gbMatrixIdentity	();
GOOSEBERRY_API gbMatrix gbMatrixTranspose	(const gbMatrix & pMatrix);
GOOSEBERRY_API gbMatrix gbMatrixInvert		(const gbMatrix & pMatrix);
GOOSEBERRY_API float	gbMatrixDeterminant (const gbMatrix & pMatrix);

//==================================================================
//	CLASS
//==================================================================
/**
		@class	gbMatrix
		@brief	Class for matrix operations
**/
//==================================================================
class GOOSEBERRY_API gbMatrix
{
	public:
		//  Variables
		union
		{
			struct
			{
				float m11, m12, m13, m14;
				float m21, m22, m23, m24;
				float m31, m32, m33, m34;
				float m41, m42, m43, m44;
			};

			float m2D[4][4];
			float m1D[16];
		};

		//	(De-)Constructor
		gbMatrix();
		gbMatrix(float * p1DimArray);
		gbMatrix(float p11, float p12, float p13, float p14, float p21, float p22, float p23, float p24,
				float p31, float p32, float p33, float p34, float p41, float p42, float p43, float p44);
		~gbMatrix(){}

		//	Operators
		gbMatrix operator +		(const gbMatrix& pRight);
		gbMatrix operator -		(const gbMatrix& pRight);
		gbMatrix operator *		(const gbMatrix& pRight);
		gbMatrix operator /		(const gbMatrix& pRight);
		gbMatrix operator *		(const float pValue);
		gbMatrix operator /		(const float pValue);
		gbMatrix operator +=	(const gbMatrix& pRight);
		gbMatrix operator -=	(const gbMatrix& pRight);
		gbMatrix operator *=	(const gbMatrix& pRight);
		gbMatrix operator /=	(const gbMatrix& pRight);
		gbMatrix operator *=	(const float pValue);
		gbMatrix operator /=	(const float pValue);
		bool	 operator ==	(const gbMatrix& pRight);
		bool     operator !=	(const gbMatrix& pRight);
		gbMatrix operator =		(const gbMatrix& pRight);
				
	private:
	protected:
};