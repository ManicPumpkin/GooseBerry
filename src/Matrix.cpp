/**
	@file	Matrix.cpp
	@brief	Includes all Matrix class methods
	@author	drubner
	@date	2013-08-28
**/
//==================================================================
//	Include
//==================================================================
#include "Matrix.h"

//==================================================================
//	Functions
//==================================================================
/**
	@fn		MatrixRotationX (const float angle)
	@brief	Matrix rotation along the x axis
	@param  angle	rotation angle
	@return Matrix
**/
//==================================================================
GOOSEBERRY_API Matrix MatrixRotationX (const float angle)
{
	return Matrix(	1.0f, 0.0f, 0.0f, 0.0f,
						0.0f, cosf(angle), sinf(angle), 0.0f,
						0.0f, -sinf(angle), cosf(angle), 0.0f,
						0.0f, 0.0f, 0.0f, 1.0f						);
}

//==================================================================
/**
	@fn		MatrixRotationY (const float angle)
	@brief	Matrix rotation along the y axis
	@param  angle	rotation angle
	@return Matrix
**/
//==================================================================
GOOSEBERRY_API Matrix MatrixRotationY (const float angle)
{
	return Matrix(	cosf(angle), 0.0f, sinf(angle), 0.0f,
						0.0f, 1.0f, 0.0f, 0.0f,
						-sinf(angle), 0.0f, cosf(angle), 0.0f,
						0.0f, 0.0f, 0.0f, 1.0f						);
}

//==================================================================
/**
	@fn		MatrixRotationZ (const float angle)
	@brief	Matrix rotation along the z axis
	@param  angle	rotation angle
	@return Matrix
**/
//==================================================================
GOOSEBERRY_API Matrix MatrixRotationZ (const float angle)
{
	return Matrix(	cosf(angle), sinf(angle), 0.0f, 0.0f,
						-sinf(angle), cosf(angle), 0.0f, 0.0f,
						0.0f, 0.0f, 1.0f, 0.0f,
						0.0f, 0.0f, 0.0f, 1.0f						);
}

//==================================================================
/**
	@fn		MatrixRotation (const float angle_x, const float angle_y, const float angle_z)
	@brief	Matrix rotation by float values
	@param  x	rotation angle for x axis
	@param  y	rotation angle for y axis
	@param  z	rotation angle for z axis
	@return Matrix
**/
//==================================================================
GOOSEBERRY_API Matrix MatrixRotation (const float angle_x, const float angle_y, const float angle_z)
{
	return	MatrixRotationX(angle_x) *
			MatrixRotationY(angle_y) *
			MatrixRotationZ(angle_z);
}

//==================================================================
/**
	@fn		MatrixRotation (const float * rot_angle_3d)
	@brief	Matrix rotation by tree dimension float angle array
	@param  pRotation3D	rotation angle array for x, y and z axis
	@return Matrix
**/
//==================================================================
GOOSEBERRY_API Matrix MatrixRotation (const float * rot_angle_3d)
{
	return	MatrixRotationX(rot_angle_3d[0]) *
			MatrixRotationY(rot_angle_3d[1]) *
			MatrixRotationZ(rot_angle_3d[2]);
}

//==================================================================
/**
	@fn		MatrixRotation (const Vector3d angle_vector)
	@brief	Matrix rotation by angle vector
	@param  vector	rotation angle vector for x, y and z axis
	@return Matrix
**/
//==================================================================
GOOSEBERRY_API Matrix MatrixRotation (const Vector3d angle_vector)
{
	return	MatrixRotationX(angle_vector.x_) *
			MatrixRotationY(angle_vector.y_) *
			MatrixRotationZ(angle_vector.z_);
}

//==================================================================
/**
	@fn		MatrixAxis (const Vector3d axis_x, const Vector3d axis_y, const Vector3d axis_z);
	@brief	Returns a axis matrix of all axis given by tree 
			axis vectors
	@param  axis_x	x axis vector
	@param  axis_y	y axis vector
	@param  axis_z	z axis vector
	@return Matrix
**/
//==================================================================
GOOSEBERRY_API Matrix MatrixAxis (const Vector3d axis_x, const Vector3d axis_y, const Vector3d axis_z)
{
	return Matrix(	axis_x.x_, axis_x.y_, axis_x.z_, 0.0f,
						axis_y.x_, axis_y.y_, axis_y.z_, 0.0f,
						axis_z.x_, axis_z.y_, axis_z.z_, 0.0f,
						0.0f, 0.0f, 0.0f, 1.0f					);
}

//==================================================================
/**
	@fn		MatrixTranslation (const float x, const float y, const float z)	
	@brief	Matrix translation by float values
	@param  x	translation value for x axis
	@param  y	translation value for y axis
	@param  z	translation value for z axis
	@return Matrix
**/
//==================================================================
GOOSEBERRY_API Matrix MatrixTranslation (const float x, const float y, const float z)
{
	return Matrix(	1.0f, 0.0f, 0.0f, 0.0f,
						0.0f, 1.0f, 0.0f, 0.0f,
						0.0f, 0.0f, 1.0f, 0.0f,
						x, y, z, 1.0f		);
}

//==================================================================
/**
	@fn		MatrixTranslation (const float * translation_3d)
	@brief	Matrix translation by tree dimension float array
	@param  translation_3d	translation array for x, y and z axis
	@return Matrix
**/
//==================================================================
GOOSEBERRY_API Matrix MatrixTranslation (const float * translation_3d)
{
	return Matrix(	1.0f, 0.0f, 0.0f, 0.0f,
						0.0f, 1.0f, 0.0f, 0.0f,
						0.0f, 0.0f, 1.0f, 0.0f,
						translation_3d[0], translation_3d[1], translation_3d[2], 1.0f );
}

//==================================================================
/**
	@fn		MatrixTranslation (const Vector3d vector)
	@brief	Matrix translation by vector
	@param  vector	translation vector for x, y and z axis
	@return Matrix
**/
//==================================================================
GOOSEBERRY_API Matrix MatrixTranslation (const Vector3d vector)
{
	return Matrix(	1.0f, 0.0f, 0.0f, 0.0f,
						0.0f, 1.0f, 0.0f, 0.0f,
						0.0f, 0.0f, 1.0f, 0.0f,
						vector.x_, vector.y_, vector.z_, 1.0f );
}

//==================================================================
/**
	@fn		MatrixScale (const float x, const float y, const float z)
	@brief	Matrix scaling by float values
	@param  x	scale value for x axis
	@param  y	scale value for y axis
	@param  z	scale value for z axis
	@return Matrix
**/
//==================================================================
GOOSEBERRY_API Matrix MatrixScale (const float x, const float y, const float z)
{
	return Matrix(	x  , 0.0f, 0.0f, 0.0f,
						0.0f, y  , 0.0f, 0.0f,
						0.0f, 0.0f, z  , 0.0f,
						0.0f, 0.0f, 0.0f, 1.0f	);
}

//==================================================================
/**
	@fn		MatrixScale (const float * scale_3d)
	@brief	Matrix scaling by tree dimension float array
	@param  scale_3d	scale array for x, y and z axis
	@return Matrix
**/
//==================================================================
GOOSEBERRY_API Matrix MatrixScale (const float * scale_3d)
{
	return Matrix(	scale_3d[0], 0.0f, 0.0f, 0.0f,
						0.0f, scale_3d[1], 0.0f, 0.0f,
						0.0f, 0.0f, scale_3d[2], 0.0f,
						0.0f, 0.0f, 0.0f, 1.0f			);
}

//==================================================================
/**
	@fn		MatrixScale (const Vector3d vector)
	@brief	Matrix scaling by vector
	@param  vector	scale vector for x, y and z axis
	@return Matrix
**/
//==================================================================
GOOSEBERRY_API Matrix MatrixScale (const Vector3d vector)
{
	return Matrix(	vector.x_, 0.0f, 0.0f, 0.0f,
						0.0f, vector.y_, 0.0f, 0.0f,
						0.0f, 0.0f, vector.z_, 0.0f,
						0.0f, 0.0f, 0.0f, 1.0f			);
}

//==================================================================
/**
	@fn		MatrixScale (const Vector3d vector)
	@brief	Returns the indentity matrix
	@return Matrix
**/
//==================================================================
GOOSEBERRY_API Matrix MatrixIdentity()
{
	return Matrix(	1.0f, 0.0f, 0.0f, 0.0f,
						0.0f, 1.0f, 0.0f, 0.0f,
						0.0f, 0.0f, 1.0f, 0.0f,
						0.0f, 0.0f, 0.0f, 1.0f	);
}

//==================================================================
/**
	@fn		MatrixTranspose (const Matrix & matrix)
	@brief	Transpose a given matrix
	@param	matrix	matrix to transpose
	@return Matrix
**/
//==================================================================
GOOSEBERRY_API Matrix MatrixTranspose (const Matrix & matrix)
{
	return Matrix(	matrix.m11_, matrix.m21_, matrix.m31_, matrix.m41_,
						matrix.m12_, matrix.m22_, matrix.m32_, matrix.m42_,
						matrix.m13_, matrix.m23_, matrix.m33_, matrix.m43_,
						matrix.m14_, matrix.m24_, matrix.m34_, matrix.m44_	);
}

//==================================================================
/**
	@fn		MatrixScale (const Vector3d vector)
	@brief	Calculates the inverted matrix of a given matrix
	@param	matrix	matrix to invert
	@return Matrix
**/
//==================================================================
GOOSEBERRY_API Matrix MatrixInvert (const Matrix & matrix)
{
	float tInvDet = MatrixDeterminant(matrix);
	if(tInvDet == 0.0f)
		return MatrixIdentity();
	tInvDet = 1.0f / tInvDet;

	Matrix tMatrix;
	tMatrix.m11_		= tInvDet * (matrix.m22_ * matrix.m33_ - matrix.m23_ * matrix.m32_);
	tMatrix.m12_		= -tInvDet * (matrix.m12_ * matrix.m33_ - matrix.m13_ * matrix.m32_);
	tMatrix.m13_		= tInvDet * (matrix.m12_ * matrix.m23_ - matrix.m13_ * matrix.m22_);
	tMatrix.m14_		= 0.0f;
	tMatrix.m21_		= -tInvDet * (matrix.m21_ * matrix.m33_ - matrix.m23_ * matrix.m31_);
	tMatrix.m22_		= tInvDet * (matrix.m11_ * matrix.m33_ - matrix.m13_ * matrix.m32_);
	tMatrix.m23_		= -tInvDet * (matrix.m11_ * matrix.m23_ - matrix.m13_ * matrix.m21_);
	tMatrix.m24_		= 0.0f;
	tMatrix.m31_		= tInvDet * (matrix.m32_ * matrix.m32_ - matrix.m22_ * matrix.m31_);
	tMatrix.m32_		= -tInvDet * (matrix.m11_ * matrix.m32_ - matrix.m12_ * matrix.m32_);
	tMatrix.m33_		= tInvDet * (matrix.m11_ * matrix.m22_ - matrix.m12_ * matrix.m32_);
	tMatrix.m34_		= 0.0f;
	tMatrix.m41_		= -(matrix.m41_ * tMatrix.m11_ + matrix.m42_ * tMatrix.m21_ + matrix.m43_ * tMatrix.m31_);	
	tMatrix.m42_		= -(matrix.m41_ * tMatrix.m12_ + matrix.m42_ * tMatrix.m22_ + matrix.m43_ * tMatrix.m32_);	
	tMatrix.m43_		= -(matrix.m41_ * tMatrix.m13_ + matrix.m42_ * tMatrix.m23_ + matrix.m43_ * tMatrix.m33_);
	tMatrix.m44_		= 1.0f;
	return tMatrix;
}

//==================================================================
/**
	@fn		MatrixDeterminant (const Matrix & matrix)
	@brief	Calculates the top left determinant of a given matrix
	@param	Matrix to build the determinant from
	@return float
**/
//==================================================================
GOOSEBERRY_API float MatrixDeterminant (const Matrix & matrix)
{
	return	matrix.m11_ * (matrix.m22_ * matrix.m33_ - matrix.m23_ * matrix.m32_) -
			matrix.m12_ * (matrix.m21_ * matrix.m33_ - matrix.m23_ * matrix.m31_) + 
			matrix.m13_ * (matrix.m21_ * matrix.m32_ - matrix.m22_ * matrix.m31_);
}

//==================================================================
//	Class Functions
//==================================================================
/**
	@fn		Matrix :: Matrix()
	@brief	Standardconstructor, sets all values to zero
**/
//==================================================================
Matrix :: Matrix()
{
	for(int i = 0; i < sizeof(d1_); i++)
		d1_[i]	= 0;
}

//==================================================================
/**
	@fn		Matrix :: Matrix(float * p1DimArray)
	@brief	Extended constructor, sets all values to values of a
			given array
	@param	float * p1DimArray
**/
//==================================================================
Matrix :: Matrix(float * p1DimArray)
{
	for(int i = 0; i < sizeof(d1_); i++)
		d1_[i]	= p1DimArray[i];
}

//==================================================================
/**
	@fn		Matrix :: Matrix(float p11, float p12, float p13, float p14, float p21, float p22, float p23, float p24,
				float p31, float p32, float p33, float p34, float p41, float p42, float p43, float p44)
	@brief	Extended constructor, sets all values to given values
	@param	p11	member row 1 col 1
	@param	p12	member row 1 col 2
	@param	p13	member row 1 col 3
	@param	p14 member row 1 col 4
	@param	p21	member row 2 col 1
	@param	p22	member row 2 col 2
	@param	p23	member row 2 col 3
	@param	p24 member row 2 col 4
	@param	p31	member row 3 col 1
	@param	p32	member row 3 col 2
	@param	p33	member row 3 col 3
	@param	p34 member row 3 col 4
	@param	p41	member row 4 col 1
	@param	p42	member row 4 col 2
	@param	p43	member row 4 col 3
	@param	p44 member row 4 col 4
**/
//==================================================================
Matrix :: Matrix(float p11, float p12, float p13, float p14, float p21, float p22, float p23, float p24,
		float p31, float p32, float p33, float p34, float p41, float p42, float p43, float p44)
{
	m11_ = p11; m12_ = p12; m13_ = p13; m14_ = p14;
	m21_ = p21; m22_ = p22; m23_ = p23; m24_ = p24;
	m31_ = p31; m32_ = p32; m33_ = p33; m34_ = p34;
	m41_ = p41; m42_ = p42; m43_ = p43; m44_ = p44;
}

//==================================================================
/**
	@fn		Matrix :: operator+(const Matrix & right)
	@brief	Overload operator +
	@param	right	Matrix of right side
	@return Matrix
**/
//==================================================================
Matrix Matrix :: operator+(const Matrix & right)
{
	for(int i = 0; i < sizeof(d1_); i++)
		d1_[i]	+= right.d1_[i];

	return *this;
}

//==================================================================
/**
	@fn		Matrix :: operator-(const Matrix & right)
	@brief	Overload operator -
	@param	right	Matrix of right side
	@return Matrix
**/
//==================================================================
Matrix Matrix :: operator-(const Matrix & right)
{
	for(int i = 0; i < sizeof(d1_); i++)
		d1_[i]	-= right.d1_[i];

	return *this;
}

//==================================================================
/**
	@fn		Matrix :: operator*(const Matrix & right)
	@brief	Overload operator *
	@param	right	Matrix of right side
	@return Matrix
**/
//==================================================================
Matrix Matrix :: operator*(const Matrix & right)
{
	return *this *= right;
}

//==================================================================
/**
	@fn		Matrix :: operator*(const float value)
	@brief	Overload operator *
	@param	value	value to u_ltiply
	@return Matrix
**/
//==================================================================
Matrix Matrix :: operator*(const float value)
{
	for(int i = 0; i < sizeof(d1_); i++)
		d1_[i]	*= value;

	return *this;	
}

//==================================================================
/**
	@fn		Matrix :: operator/(const Matrix & right)
	@brief	Overload operator /
	@param	right	Matrix of right side
	@return Matrix
**/
//==================================================================
Matrix Matrix :: operator/(const Matrix & right)
{
	return *this *= MatrixInvert(right);
}

//==================================================================
/**
	@fn		Matrix :: operator/(const float value)
	@brief	Overload operator /
	@param	value	value to divide
	@return Matrix
**/
//==================================================================
Matrix Matrix :: operator/(const float value)
{
	for(int i = 0; i < sizeof(d1_); i++)
		d1_[i]	/= value;

	return *this;	
}

//==================================================================
/**
	@fn		Matrix :: operator+=(const Matrix & right)
	@brief	Overload operator +=
	@param	right	Matrix of right side
	@return Matrix
**/
//==================================================================
Matrix Matrix :: operator+=(const Matrix & right)
{
	for(int i = 0; i < sizeof(d1_); i++)
		d1_[i]	+= right.d1_[i];

	return *this;	
}

//==================================================================
/**
	@fn		Matrix :: operator-=(const Matrix & right)
	@brief	Overload operator -=
	@param	right	Matrix of right side
	@return Matrix
**/
//==================================================================
Matrix Matrix :: operator-=(const Matrix & right)
{
	for(int i = 0; i < sizeof(d1_); i++)
		d1_[i]	-= right.d1_[i];

	return *this;
}

//==================================================================
/**
	@fn		Matrix :: operator*=(const Matrix & right)
	@brief	Overload operator *=
	@param	right	Matrix of right side
	@return Matrix
**/
//==================================================================
Matrix Matrix :: operator*=(const Matrix & right)
{
	return *this = Matrix(	right.m11_ * m11_ + right.m21_ * m12_ + right.m31_ * m13_ + right.m41_ * m14_,
								right.m12_ * m11_ + right.m22_ * m12_ + right.m32_ * m13_ + right.m42_ * m14_,
								right.m13_ * m11_ + right.m23_ * m12_ + right.m33_ * m13_ + right.m43_ * m14_,
								right.m14_ * m11_ + right.m24_ * m12_ + right.m34_ * m13_ + right.m44_ * m14_,
								right.m11_ * m21_ + right.m21_ * m22_ + right.m31_ * m23_ + right.m41_ * m24_,
								right.m12_ * m21_ + right.m22_ * m22_ + right.m32_ * m23_ + right.m42_ * m24_,
								right.m13_ * m21_ + right.m23_ * m22_ + right.m33_ * m23_ + right.m43_ * m24_,
								right.m14_ * m21_ + right.m24_ * m22_ + right.m34_ * m23_ + right.m44_ * m24_,
								right.m11_ * m31_ + right.m21_ * m32_ + right.m31_ * m33_ + right.m41_ * m34_,
								right.m12_ * m31_ + right.m22_ * m32_ + right.m32_ * m33_ + right.m42_ * m34_,
								right.m13_ * m31_ + right.m23_ * m32_ + right.m33_ * m33_ + right.m43_ * m34_,
								right.m14_ * m31_ + right.m24_ * m32_ + right.m34_ * m33_ + right.m44_ * m34_,
								right.m11_ * m41_ + right.m21_ * m42_ + right.m31_ * m43_ + right.m41_ * m44_,
								right.m12_ * m41_ + right.m22_ * m42_ + right.m32_ * m43_ + right.m42_ * m44_,
								right.m13_ * m41_ + right.m23_ * m42_ + right.m33_ * m43_ + right.m43_ * m44_,
								right.m14_ * m41_ + right.m24_ * m42_ + right.m34_ * m43_ + right.m44_ * m44_	);
}

//==================================================================
/**
	@fn		Matrix :: operator*=(const float value)
	@brief	Overload operator *=
	@param	value	value to u_ltiply
	@return Matrix
**/
//==================================================================
Matrix Matrix :: operator*=(const float value)
{
	for(int i = 0; i < sizeof(d1_); i++)
		d1_[i]	*= value;

	return *this;
}

//==================================================================
/**
	@fn		Matrix :: operator/=(const Matrix & right)
	@brief	Overload operator /=
	@param	right	Matrix of right side
	@return Matrix
**/
//==================================================================
Matrix Matrix :: operator/=(const Matrix & right)
{
	return *this *= MatrixInvert(right);
}

//==================================================================
/**
	@fn		Matrix :: operator/=(const float value)
	@brief	Overload operator /=
	@param	value	value to divide
	@return Matrix
**/
//==================================================================
Matrix Matrix :: operator/=(const float value)
{
	for(int i = 0; i < sizeof(d1_); i++)
		d1_[i]	/= value;

	return *this;
}

//==================================================================
/**
	@fn		Matrix :: operator==(const Matrix & right)
	@brief	Overload operator ==
	@param	right	Matrix of right side
	@return true or false
**/
//==================================================================
bool Matrix :: operator==(const Matrix & right)
{
	for(int i = 0; i < sizeof(d1_); i++)
		if(d1_[i] != right.d1_[i])
			return false;

	return true;
}

//==================================================================
/**
	@fn		Matrix :: operator!=(const Matrix & right)
	@brief	Overload operator !=
	@param	right	Matrix of right side
	@return true or false
**/
//==================================================================
bool Matrix :: operator!=(const Matrix & right)
{
	for(int i = 0; i < sizeof(d1_); i++)
		if(d1_[i] == right.d1_[i])
			return false;

	return true;
}

//==================================================================
/**
	@fn		Matrix :: operator=(const Matrix & right)
	@brief	Overload operator =
	@param	right	Matrix of right side
	@return Matrix
**/
//==================================================================
Matrix Matrix :: operator=(const Matrix & right)
{
	for(int i = 0; i < sizeof(d1_); i++)
		d1_[i] = right.d1_[i];

	return *this;
}