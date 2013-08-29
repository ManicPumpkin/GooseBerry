/**
	@file	gbMatrix.cpp
	@brief	Includes all gbMatrix class methods
	@author	drubner
	@date	2013-08-28
**/
//==================================================================
//	Include
//==================================================================
#include "gbMatrix.h"

//==================================================================
//	Functions
//==================================================================
/**
	@fn		gbMatrixRotationX (const float pValue)
	@brief	Matrix rotation along the x axis
	@param  pValue	rotation value
	@return gbMatrix
**/
//==================================================================
GOOSEBERRY_API gbMatrix gbMatrixRotationX (const float pValue)
{
	return gbMatrix(	1.0f, 0.0f, 0.0f, 0.0f,
						0.0f, cosf(pValue), sinf(pValue), 0.0f,
						0.0f, -sinf(pValue), cosf(pValue), 0.0f,
						0.0f, 0.0f, 0.0f, 1.0f						);
}

//==================================================================
/**
	@fn		gbMatrixRotationY (const float pValue)
	@brief	Matrix rotation along the y axis
	@param  pValue	rotation value
	@return gbMatrix
**/
//==================================================================
GOOSEBERRY_API gbMatrix gbMatrixRotationY (const float pValue)
{
	return gbMatrix(	cosf(pValue), 0.0f, sinf(pValue), 0.0f,
						0.0f, 1.0f, 0.0f, 0.0f,
						-sinf(pValue), 0.0f, cosf(pValue), 0.0f,
						0.0f, 0.0f, 0.0f, 1.0f						);
}

//==================================================================
/**
	@fn		gbMatrixRotationZ (const float pValue)
	@brief	Matrix rotation along the z axis
	@param  pValue	rotation value
	@return gbMatrix
**/
//==================================================================
GOOSEBERRY_API gbMatrix gbMatrixRotationZ (const float pValue)
{
	return gbMatrix(	cosf(pValue), sinf(pValue), 0.0f, 0.0f,
						-sinf(pValue), cosf(pValue), 0.0f, 0.0f,
						0.0f, 0.0f, 1.0f, 0.0f,
						0.0f, 0.0f, 0.0f, 1.0f						);
}

//==================================================================
/**
	@fn		gbMatrixRotation (const float pX, const float pY, const float pZ)
	@brief	Matrix rotation by float values
	@param  pX	rotation value for x axis
	@param  pY	rotation value for y axis
	@param  pZ	rotation value for z axis
	@return gbMatrix
**/
//==================================================================
GOOSEBERRY_API gbMatrix gbMatrixRotation (const float pX, const float pY, const float pZ)
{
	return	gbMatrixRotationX(pX) *
			gbMatrixRotationY(pY) *
			gbMatrixRotationZ(pZ);
}

//==================================================================
/**
	@fn		gbMatrixRotation (const float * pRotation3D)
	@brief	Matrix rotation by tree dimension float array
	@param  pRotation3D	rotation array for x, y and z axis
	@return gbMatrix
**/
//==================================================================
GOOSEBERRY_API gbMatrix gbMatrixRotation (const float * pRotation3D)
{
	return	gbMatrixRotationX(pRotation3D[0]) *
			gbMatrixRotationY(pRotation3D[1]) *
			gbMatrixRotationZ(pRotation3D[2]);
}

//==================================================================
/**
	@fn		gbMatrixRotation (const gbVector3d pVector)
	@brief	Matrix rotation by vector
	@param  pVector	rotation vector for x, y and z axis
	@return gbMatrix
**/
//==================================================================
GOOSEBERRY_API gbMatrix gbMatrixRotation (const gbVector3d pVector)
{
	return	gbMatrixRotationX(pVector.mX) *
			gbMatrixRotationY(pVector.mY) *
			gbMatrixRotationZ(pVector.mZ);
}

//==================================================================
/**
	@fn		gbMatrixAxis (const gbVector3d pAxisX, const gbVector3d pAxisY, const gbVector3d pAxisZ);
	@brief	Returns a axis matrix of all axis given by tree 
			axis vectors
	@param  pAxisX	x axis vector
	@param  pAxisY	y axis vector
	@param  pAxisZ	z axis vector
	@return gbMatrix
**/
//==================================================================
GOOSEBERRY_API gbMatrix gbMatrixAxis (const gbVector3d pAxisX, const gbVector3d pAxisY, const gbVector3d pAxisZ)
{
	return gbMatrix(	pAxisX.mX, pAxisX.mY, pAxisX.mZ, 0.0f,
						pAxisY.mX, pAxisY.mY, pAxisY.mZ, 0.0f,
						pAxisZ.mX, pAxisZ.mY, pAxisZ.mZ, 0.0f,
						0.0f, 0.0f, 0.0f, 1.0f					);
}

//==================================================================
/**
	@fn		gbMatrixTranslation (const float pX, const float pY, const float pZ)	
	@brief	Matrix translation by float values
	@param  pX	translation value for x axis
	@param  pY	translation value for y axis
	@param  pZ	translation value for z axis
	@return gbMatrix
**/
//==================================================================
GOOSEBERRY_API gbMatrix gbMatrixTranslation (const float pX, const float pY, const float pZ)
{
	return gbMatrix(	1.0f, 0.0f, 0.0f, 0.0f,
						0.0f, 1.0f, 0.0f, 0.0f,
						0.0f, 0.0f, 1.0f, 0.0f,
						pX, pY, pZ, 1.0f		);
}

//==================================================================
/**
	@fn		gbMatrixTranslation (const float * pTranslation3D)
	@brief	Matrix translation by tree dimension float array
	@param  pTranslation3D	translation array for x, y and z axis
	@return gbMatrix
**/
//==================================================================
GOOSEBERRY_API gbMatrix gbMatrixTranslation (const float * pTranslation3D)
{
	return gbMatrix(	1.0f, 0.0f, 0.0f, 0.0f,
						0.0f, 1.0f, 0.0f, 0.0f,
						0.0f, 0.0f, 1.0f, 0.0f,
						pTranslation3D[0], pTranslation3D[1], pTranslation3D[2], 1.0f );
}

//==================================================================
/**
	@fn		gbMatrixTranslation (const gbVector3d pVector)
	@brief	Matrix translation by vector
	@param  pVector	translation vector for x, y and z axis
	@return gbMatrix
**/
//==================================================================
GOOSEBERRY_API gbMatrix gbMatrixTranslation (const gbVector3d pVector)
{
	return gbMatrix(	1.0f, 0.0f, 0.0f, 0.0f,
						0.0f, 1.0f, 0.0f, 0.0f,
						0.0f, 0.0f, 1.0f, 0.0f,
						pVector.mX, pVector.mY, pVector.mZ, 1.0f );
}

//==================================================================
/**
	@fn		gbMatrixScale (const float pX, const float pY, const float pZ)
	@brief	Matrix scaling by float values
	@param  pX	scale value for x axis
	@param  pY	scale value for y axis
	@param  pZ	scale value for z axis
	@return gbMatrix
**/
//==================================================================
GOOSEBERRY_API gbMatrix gbMatrixScale (const float pX, const float pY, const float pZ)
{
	return gbMatrix(	pX  , 0.0f, 0.0f, 0.0f,
						0.0f, pY  , 0.0f, 0.0f,
						0.0f, 0.0f, pZ  , 0.0f,
						0.0f, 0.0f, 0.0f, 1.0f	);
}

//==================================================================
/**
	@fn		gbMatrixScale (const float * pScale3D)
	@brief	Matrix scaling by tree dimension float array
	@param  pScale3D	scale array for x, y and z axis
	@return gbMatrix
**/
//==================================================================
GOOSEBERRY_API gbMatrix gbMatrixScale (const float * pScale3D)
{
	return gbMatrix(	pScale3D[0], 0.0f, 0.0f, 0.0f,
						0.0f, pScale3D[1], 0.0f, 0.0f,
						0.0f, 0.0f, pScale3D[2], 0.0f,
						0.0f, 0.0f, 0.0f, 1.0f			);
}

//==================================================================
/**
	@fn		gbMatrixScale (const gbVector3d pVector)
	@brief	Matrix scaling by vector
	@param  pVector	scale vector for x, y and z axis
	@return gbMatrix
**/
//==================================================================
GOOSEBERRY_API gbMatrix gbMatrixScale (const gbVector3d pVector)
{
	return gbMatrix(	pVector.mX, 0.0f, 0.0f, 0.0f,
						0.0f, pVector.mY, 0.0f, 0.0f,
						0.0f, 0.0f, pVector.mZ, 0.0f,
						0.0f, 0.0f, 0.0f, 1.0f			);
}

//==================================================================
/**
	@fn		gbMatrixScale (const gbVector3d pVector)
	@brief	Returns the indentity matrix
	@return gbMatrix
**/
//==================================================================
GOOSEBERRY_API gbMatrix gbMatrixIdentity()
{
	return gbMatrix(	1.0f, 0.0f, 0.0f, 0.0f,
						0.0f, 1.0f, 0.0f, 0.0f,
						0.0f, 0.0f, 1.0f, 0.0f,
						0.0f, 0.0f, 0.0f, 1.0f	);
}

//==================================================================
/**
	@fn		gbMatrixTranspose (const gbMatrix & pMatrix)
	@brief	Transpose a given matrix
	@param	pMatrix	matrix to transpose
	@return gbMatrix
**/
//==================================================================
GOOSEBERRY_API gbMatrix gbMatrixTranspose (const gbMatrix & pMatrix)
{
	return gbMatrix(	pMatrix.m11, pMatrix.m21, pMatrix.m31, pMatrix.m41,
						pMatrix.m12, pMatrix.m22, pMatrix.m32, pMatrix.m42,
						pMatrix.m13, pMatrix.m23, pMatrix.m33, pMatrix.m43,
						pMatrix.m14, pMatrix.m24, pMatrix.m34, pMatrix.m44	);
}

//==================================================================
/**
	@fn		gbMatrixScale (const gbVector3d pVector)
	@brief	Calculates the inverted matrix of a given matrix
	@param	pMatrix	matrix to invert
	@return gbMatrix
**/
//==================================================================
GOOSEBERRY_API gbMatrix gbMatrixInvert (const gbMatrix & pMatrix)
{
	float tInvDet = gbMatrixDeterminant(pMatrix);
	if(tInvDet == 0.0f)
		return gbMatrixIdentity();
	tInvDet = 1.0f / tInvDet;

	gbMatrix tMatrix;
	tMatrix.m11		= tInvDet * (pMatrix.m22 * pMatrix.m33 - pMatrix.m23 * pMatrix.m32);
	tMatrix.m12		= -tInvDet * (pMatrix.m12 * pMatrix.m33 - pMatrix.m13 * pMatrix.m32);
	tMatrix.m13		= tInvDet * (pMatrix.m12 * pMatrix.m23 - pMatrix.m13 * pMatrix.m22);
	tMatrix.m14		= 0.0f;
	tMatrix.m21		= -tInvDet * (pMatrix.m21 * pMatrix.m33 - pMatrix.m23 * pMatrix.m31);
	tMatrix.m22		= tInvDet * (pMatrix.m11 * pMatrix.m33 - pMatrix.m13 * pMatrix.m32);
	tMatrix.m23		= -tInvDet * (pMatrix.m11 * pMatrix.m23 - pMatrix.m13 * pMatrix.m21);
	tMatrix.m24		= 0.0f;
	tMatrix.m31		= tInvDet * (pMatrix.m32 * pMatrix.m32 - pMatrix.m22 * pMatrix.m31);
	tMatrix.m32		= -tInvDet * (pMatrix.m11 * pMatrix.m32 - pMatrix.m12 * pMatrix.m32);
	tMatrix.m33		= tInvDet * (pMatrix.m11 * pMatrix.m22 - pMatrix.m12 * pMatrix.m32);
	tMatrix.m34		= 0.0f;
	tMatrix.m41		= -(pMatrix.m41 * tMatrix.m11 + pMatrix.m42 * tMatrix.m21 + pMatrix.m43 * tMatrix.m31);	
	tMatrix.m42		= -(pMatrix.m41 * tMatrix.m12 + pMatrix.m42 * tMatrix.m22 + pMatrix.m43 * tMatrix.m32);	
	tMatrix.m43		= -(pMatrix.m41 * tMatrix.m13 + pMatrix.m42 * tMatrix.m23 + pMatrix.m43 * tMatrix.m33);
	tMatrix.m44		= 1.0f;
	return tMatrix;
}

//==================================================================
/**
	@fn		gbMatrixDeterminant (const gbMatrix & pMatrix)
	@brief	Calculates the top left determinant of a given matrix
	@param	Matrix to build the determinant from
	@return float
**/
//==================================================================
GOOSEBERRY_API float gbMatrixDeterminant (const gbMatrix & pMatrix)
{
	return	pMatrix.m11 * (pMatrix.m22 * pMatrix.m33 - pMatrix.m23 * pMatrix.m32) -
			pMatrix.m12 * (pMatrix.m21 * pMatrix.m33 - pMatrix.m23 * pMatrix.m31) + 
			pMatrix.m13 * (pMatrix.m21 * pMatrix.m32 - pMatrix.m22 * pMatrix.m31);
}

//==================================================================
//	Class Functions
//==================================================================
/**
	@fn		cWorldEle :: cWorldEle()
	@brief	Standardconstructor, sets all values to zero
**/
//==================================================================
gbMatrix :: gbMatrix()
{
	for(int i = 0; i < sizeof(m1D); i++)
		m1D[i]	= 0;
}

//==================================================================
/**
	@fn		gbMatrix(float * p1DimArray)
	@brief	Extended constructor, sets all values to values of a
			given array
	@param	float * p1DimArray
**/
//==================================================================
gbMatrix :: gbMatrix(float * p1DimArray)
{
	for(int i = 0; i < sizeof(m1D); i++)
		m1D[i]	= p1DimArray[i];
}

//==================================================================
/**
	@fn		gbMatrix(...)
	@brief	Extended constructor, sets all values to given values
	@param	p11 ... p44
**/
//==================================================================
gbMatrix :: gbMatrix(float p11, float p12, float p13, float p14, float p21, float p22, float p23, float p24,
		float p31, float p32, float p33, float p34, float p41, float p42, float p43, float p44)
{
	m11 = p11; m12 = p12; m13 = p13; m14 = p14;
	m21 = p21; m22 = p22; m23 = p23; m24 = p24;
	m31 = p31; m32 = p32; m33 = p33; m34 = p34;
	m41 = p41; m42 = p42; m43 = p43; m44 = p44;
}

//==================================================================
/**
	@fn		gbMatrix :: operator+(const gbMatrix & pRight)
	@brief	Overload operator +
	@param	pRight	Matrix of right side
	@return gbMatrix
**/
//==================================================================
gbMatrix gbMatrix :: operator+(const gbMatrix & pRight)
{
	for(int i = 0; i < sizeof(m1D); i++)
		m1D[i]	+= pRight.m1D[i];

	return *this;
}

//==================================================================
/**
	@fn		gbMatrix :: operator-(const gbMatrix & pRight)
	@brief	Overload operator -
	@param	pRight	Matrix of right side
	@return gbMatrix
**/
//==================================================================
gbMatrix gbMatrix :: operator-(const gbMatrix & pRight)
{
	for(int i = 0; i < sizeof(m1D); i++)
		m1D[i]	-= pRight.m1D[i];

	return *this;
}

//==================================================================
/**
	@fn		gbMatrix :: operator*(const gbMatrix & pRight)
	@brief	Overload operator *
	@param	pRight	Matrix of right side
	@return gbMatrix
**/
//==================================================================
gbMatrix gbMatrix :: operator*(const gbMatrix & pRight)
{
	return *this *= pRight;
}

//==================================================================
/**
	@fn		gbMatrix :: operator*(const gbMatrix & pRight)
	@brief	Overload operator *
	@param	pRight	Matrix of right side
	@return gbMatrix
**/
//==================================================================
gbMatrix gbMatrix :: operator*(const float pValue)
{
	for(int i = 0; i < sizeof(m1D); i++)
		m1D[i]	*= pValue;

	return *this;	
}

//==================================================================
/**
	@fn		gbMatrix :: operator/(const gbMatrix & pRight)
	@brief	Overload operator /
	@param	pRight	Matrix of right side
	@return gbMatrix
**/
//==================================================================
gbMatrix gbMatrix :: operator/(const gbMatrix & pRight)
{
	return *this *= gbMatrixInvert(pRight);
}

//==================================================================
/**
	@fn		gbMatrix :: operator/(const float pValue)
	@brief	Overload operator /
	@param	pRight	Matrix of right side
	@return gbMatrix
**/
//==================================================================
gbMatrix gbMatrix :: operator/(const float pValue)
{
	for(int i = 0; i < sizeof(m1D); i++)
		m1D[i]	/= pValue;

	return *this;	
}

//==================================================================
/**
	@fn		gbMatrix :: operator+=(const gbMatrix & pRight)
	@brief	Overload operator +=
	@param	pRight	Matrix of right side
	@return gbMatrix
**/
//==================================================================
gbMatrix gbMatrix :: operator+=(const gbMatrix & pRight)
{
	for(int i = 0; i < sizeof(m1D); i++)
		m1D[i]	+= pRight.m1D[i];

	return *this;	
}

//==================================================================
/**
	@fn		gbMatrix :: operator-=(const gbMatrix & pRight)
	@brief	Overload operator -=
	@param	pRight	Matrix of right side
	@return gbMatrix
**/
//==================================================================
gbMatrix gbMatrix :: operator-=(const gbMatrix & pRight)
{
	for(int i = 0; i < sizeof(m1D); i++)
		m1D[i]	-= pRight.m1D[i];

	return *this;
}

//==================================================================
/**
	@fn		gbMatrix :: operator*=(const gbMatrix & pRight)
	@brief	Overload operator *=
	@param	pRight	Matrix of right side
	@return gbMatrix
**/
//==================================================================
gbMatrix gbMatrix :: operator*=(const gbMatrix & pRight)
{
	return *this = gbMatrix(	pRight.m11 * m11 + pRight.m21 * m12 + pRight.m31 * m13 + pRight.m41 * m14,
								pRight.m12 * m11 + pRight.m22 * m12 + pRight.m32 * m13 + pRight.m42 * m14,
								pRight.m13 * m11 + pRight.m23 * m12 + pRight.m33 * m13 + pRight.m43 * m14,
								pRight.m14 * m11 + pRight.m24 * m12 + pRight.m34 * m13 + pRight.m44 * m14,
								pRight.m11 * m21 + pRight.m21 * m22 + pRight.m31 * m23 + pRight.m41 * m24,
								pRight.m12 * m21 + pRight.m22 * m22 + pRight.m32 * m23 + pRight.m42 * m24,
								pRight.m13 * m21 + pRight.m23 * m22 + pRight.m33 * m23 + pRight.m43 * m24,
								pRight.m14 * m21 + pRight.m24 * m22 + pRight.m34 * m23 + pRight.m44 * m24,
								pRight.m11 * m31 + pRight.m21 * m32 + pRight.m31 * m33 + pRight.m41 * m34,
								pRight.m12 * m31 + pRight.m22 * m32 + pRight.m32 * m33 + pRight.m42 * m34,
								pRight.m13 * m31 + pRight.m23 * m32 + pRight.m33 * m33 + pRight.m43 * m34,
								pRight.m14 * m31 + pRight.m24 * m32 + pRight.m34 * m33 + pRight.m44 * m34,
								pRight.m11 * m41 + pRight.m21 * m42 + pRight.m31 * m43 + pRight.m41 * m44,
								pRight.m12 * m41 + pRight.m22 * m42 + pRight.m32 * m43 + pRight.m42 * m44,
								pRight.m13 * m41 + pRight.m23 * m42 + pRight.m33 * m43 + pRight.m43 * m44,
								pRight.m14 * m41 + pRight.m24 * m42 + pRight.m34 * m43 + pRight.m44 * m44	);
}

//==================================================================
/**
	@fn		gbMatrix :: operator*=(const float pValue)
	@brief	Overload operator *=
	@param	pRight	Matrix of right side
	@return gbMatrix
**/
//==================================================================
gbMatrix gbMatrix :: operator*=(const float pValue)
{
	for(int i = 0; i < sizeof(m1D); i++)
		m1D[i]	*= pValue;

	return *this;
}

//==================================================================
/**
	@fn		gbMatrix :: operator/=(const gbMatrix & pRight)
	@brief	Overload operator /=
	@param	pRight	Matrix of right side
	@return gbMatrix
**/
//==================================================================
gbMatrix gbMatrix :: operator/=(const gbMatrix & pRight)
{
	return *this *= gbMatrixInvert(pRight);
}

//==================================================================
/**
	@fn		gbMatrix :: operator/=(const float pValue)
	@brief	Overload operator /=
	@param	pRight	Matrix of right side
	@return gbMatrix
**/
//==================================================================
gbMatrix gbMatrix :: operator/=(const float pValue)
{
	for(int i = 0; i < sizeof(m1D); i++)
		m1D[i]	/= pValue;

	return *this;
}

//==================================================================
/**
	@fn		gbMatrix :: operator==(const gbMatrix & pRight)
	@brief	Overload operator ==
	@param	pRight	Matrix of right side
	@return true or false
**/
//==================================================================
bool gbMatrix :: operator==(const gbMatrix & pRight)
{
	for(int i = 0; i < sizeof(m1D); i++)
		if(m1D[i] != pRight.m1D[i])
			return false;

	return true;
}

//==================================================================
/**
	@fn		gbMatrix :: operator!=(const gbMatrix & pRight)
	@brief	Overload operator !=
	@param	pRight	Matrix of right side
	@return true or false
**/
//==================================================================
bool gbMatrix :: operator!=(const gbMatrix & pRight)
{
	for(int i = 0; i < sizeof(m1D); i++)
		if(m1D[i] == pRight.m1D[i])
			return false;

	return true;
}

//==================================================================
/**
	@fn		gbMatrix :: operator=(const gbMatrix & pRight)
	@brief	Overload operator =
	@param	pRight	Matrix of right side
	@return gbMatrix
**/
//==================================================================
gbMatrix gbMatrix :: operator=(const gbMatrix & pRight)
{
	for(int i = 0; i < sizeof(m1D); i++)
		m1D[i] = pRight.m1D[i];

	return *this;
}