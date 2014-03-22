/**
	@file	GB_Matrix.cpp
	@brief	Includes all GB_Matrix class methods
	@author	drubner
	@date	2013-08-28
**/
//==================================================================
//	INCLUDE
//==================================================================
#include "GB_Matrix.h"

//==================================================================
//	NAMESPACE
//==================================================================

//==================================================================
//	FUNCTIONS
//==================================================================
/**
	@fn		MatrixRotationX (const float angle)
	@brief	GB_Matrix rotation along the x axis
	@param  angle  rotation angle
	@return GB_Matrix 
**/
//==================================================================
GOOSEBERRY_API GB_Matrix MatrixRotationX (const float angle)
{
	return GB_Matrix(	1.0f, 0.0f, 0.0f, 0.0f,
						0.0f, cosf(angle), sinf(angle), 0.0f,
						0.0f, -sinf(angle), cosf(angle), 0.0f,
						0.0f, 0.0f, 0.0f, 1.0f						);
}

//==================================================================
/**
	@fn		MatrixRotationY (const float angle)
	@brief	GB_Matrix rotation along the y axis
	@param  angle  rotation angle
	@return GB_Matrix 
**/
//==================================================================
GOOSEBERRY_API GB_Matrix MatrixRotationY (const float angle)
{
	return GB_Matrix(cosf(angle), 0.0f, sinf(angle), 0.0f,
						0.0f, 1.0f, 0.0f, 0.0f,
						-sinf(angle), 0.0f, cosf(angle), 0.0f,
						0.0f, 0.0f, 0.0f, 1.0f						);
}

//==================================================================
/**
	@fn		MatrixRotationZ (const float angle)
	@brief	GB_Matrix rotation along the z axis
	@param  angle  rotation angle
	@return GB_Matrix 
**/
//==================================================================
GOOSEBERRY_API GB_Matrix MatrixRotationZ(const float angle)
{
	return GB_Matrix(	cosf(angle), sinf(angle), 0.0f, 0.0f,
						-sinf(angle), cosf(angle), 0.0f, 0.0f,
						0.0f, 0.0f, 1.0f, 0.0f,
						0.0f, 0.0f, 0.0f, 1.0f						);
}

//==================================================================
/**
	@fn		MatrixRotation (const float angle_x, const float angle_y, const float angle_z)
	@brief	GB_Matrix rotation by float values
	@param  x	rotation angle for x axis
	@param  y	rotation angle for y axis
	@param  z	rotation angle for z axis
	@return GB_Matrix 
**/
//==================================================================
GOOSEBERRY_API GB_Matrix MatrixRotation(const float angle_x, const float angle_y, const float angle_z)
{
	return	MatrixRotationX(angle_x) *
			MatrixRotationY(angle_y) *
			MatrixRotationZ(angle_z);
}

//==================================================================
/**
	@fn		MatrixRotation (const float * rot_angle_3d)
	@brief	GB_Matrix rotation by tree dimension float angle GB_Array
	@param  pRotation3D	rotation angle GB_Array for x, y and z axis
	@return GB_Matrix 
**/
//==================================================================
GOOSEBERRY_API GB_Matrix MatrixRotation(const float * rot_angle_3d)
{
	return	MatrixRotationX(rot_angle_3d[0]) *
			MatrixRotationY(rot_angle_3d[1]) *
			MatrixRotationZ(rot_angle_3d[2]);
}

//==================================================================
/**
	@fn		MatrixRotation (const GB_Vector3 angle_vector)
	@brief	GB_Matrix rotation by angle vector
	@param  vector	rotation angle vector for x, y and z axis
	@return GB_Matrix 
**/
//==================================================================
GOOSEBERRY_API GB_Matrix MatrixRotation(const GB_Vector3 angle_vector)
{
	return	MatrixRotationX(angle_vector.x_) *
			MatrixRotationY(angle_vector.y_) *
			MatrixRotationZ(angle_vector.z_);
}

//==================================================================
/**
	@fn		MatrixAxis (const GB_Vector3 axis_x, const GB_Vector3 axis_y, const GB_Vector3 axis_z);
	@brief	Returns a axis GB_Matrix of all axis given by tree 
			axis vectors
	@param  axis_x	x axis vector
	@param  axis_y	y axis vector
	@param  axis_z	z axis vector
	@return GB_Matrix 
**/
//==================================================================
GOOSEBERRY_API GB_Matrix MatrixAxis(const GB_Vector3 axis_x, const GB_Vector3 axis_y, const GB_Vector3 axis_z)
{
	return GB_Matrix (	axis_x.x_, axis_x.y_, axis_x.z_, 0.0f,
						axis_y.x_, axis_y.y_, axis_y.z_, 0.0f,
						axis_z.x_, axis_z.y_, axis_z.z_, 0.0f,
						0.0f, 0.0f, 0.0f, 1.0f					);
}

//==================================================================
/**
	@fn		MatrixTranslation (const float x, const float y, const float z)	
	@brief	GB_Matrix translation by float values
	@param  x	translation value for x axis
	@param  y	translation value for y axis
	@param  z	translation value for z axis
	@return GB_Matrix 
**/
//==================================================================
GOOSEBERRY_API GB_Matrix MatrixTranslation(const float x, const float y, const float z)
{
	return GB_Matrix (	1.0f, 0.0f, 0.0f, 0.0f,
						0.0f, 1.0f, 0.0f, 0.0f,
						0.0f, 0.0f, 1.0f, 0.0f,
						x, y, z, 1.0f			);
}

//==================================================================
/**
	@fn		MatrixTranslation (const float * translation_3d)
	@brief	GB_Matrix translation by tree dimension float GB_Array
	@param  translation_3d	translation GB_Array for x, y and z axis
	@return GB_Matrix 
**/
//==================================================================
GOOSEBERRY_API GB_Matrix MatrixTranslation(const float * translation_3d)
{
	return GB_Matrix (	1.0f, 0.0f, 0.0f, 0.0f,
						0.0f, 1.0f, 0.0f, 0.0f,
						0.0f, 0.0f, 1.0f, 0.0f,
						translation_3d[0], translation_3d[1], translation_3d[2], 1.0f );
}

//==================================================================
/**
	@fn		MatrixTranslation (const GB_Vector3 vector)
	@brief	GB_Matrix translation by vector
	@param  vector	translation vector for x, y and z axis
	@return GB_Matrix 
**/
//==================================================================
GOOSEBERRY_API GB_Matrix MatrixTranslation(const GB_Vector3 vector)
{
	return GB_Matrix (	1.0f, 0.0f, 0.0f, 0.0f,
						0.0f, 1.0f, 0.0f, 0.0f,
						0.0f, 0.0f, 1.0f, 0.0f,
						vector.x_, vector.y_, vector.z_, 1.0f );
}

//==================================================================
/**
	@fn		MatrixScale (const float x, const float y, const float z)
	@brief	GB_Matrix scaling by float values
	@param  x	scale value for x axis
	@param  y	scale value for y axis
	@param  z	scale value for z axis
	@return GB_Matrix 
**/
//==================================================================
GOOSEBERRY_API GB_Matrix MatrixScale(const float x, const float y, const float z)
{
	return GB_Matrix (	x  , 0.0f, 0.0f, 0.0f,
						0.0f, y  , 0.0f, 0.0f,
						0.0f, 0.0f, z  , 0.0f,
						0.0f, 0.0f, 0.0f, 1.0f	);
}

//==================================================================
/**
	@fn		MatrixScale (const float * scale_3d)
	@brief	GB_Matrix scaling by tree dimension float GB_Array
	@param  scale_3d	scale GB_Array for x, y and z axis
	@return GB_Matrix 
**/
//==================================================================
GOOSEBERRY_API GB_Matrix MatrixScale(const float * scale_3d)
{
	return GB_Matrix (	scale_3d[0], 0.0f, 0.0f, 0.0f,
						0.0f, scale_3d[1], 0.0f, 0.0f,
						0.0f, 0.0f, scale_3d[2], 0.0f,
						0.0f, 0.0f, 0.0f, 1.0f			);
}

//==================================================================
/**
	@fn		MatrixScale (const GB_Vector3 vector)
	@brief	GB_Matrix scaling by vector
	@param  vector	scale vector for x, y and z axis
	@return GB_Matrix 
**/
//==================================================================
GOOSEBERRY_API GB_Matrix MatrixScale(const GB_Vector3 vector)
{
	return GB_Matrix (	vector.x_, 0.0f, 0.0f, 0.0f,
						0.0f, vector.y_, 0.0f, 0.0f,
						0.0f, 0.0f, vector.z_, 0.0f,
						0.0f, 0.0f, 0.0f, 1.0f			);
}

//==================================================================
/**
	@fn		MatrixIdentity()
	@brief	Returns the indentity GB_Matrix 
	@return GB_Matrix 
**/
//==================================================================
GOOSEBERRY_API GB_Matrix MatrixIdentity()
{
	return GB_Matrix (	1.0f, 0.0f, 0.0f, 0.0f,
						0.0f, 1.0f, 0.0f, 0.0f,
						0.0f, 0.0f, 1.0f, 0.0f,
						0.0f, 0.0f, 0.0f, 1.0f	);
}

//==================================================================
/**
	@fn		MatrixTranspose (const GB_Matrix & GB_Matrix )
	@brief	Transpose a given GB_Matrix 
	@param	GB_Matrix 	GB_Matrix  to transpose
	@return GB_Matrix 
**/
//==================================================================
GOOSEBERRY_API GB_Matrix MatrixTranspose(const GB_Matrix & matrix )
{
	return GB_Matrix(	matrix.m11_, matrix.m21_, matrix.m31_, matrix.m41_,
						matrix.m12_, matrix.m22_, matrix.m32_, matrix.m42_,
						matrix.m13_, matrix.m23_, matrix.m33_, matrix.m43_,
						matrix.m14_, matrix.m24_, matrix.m34_, matrix.m44_	);
}

//==================================================================
/**
	@fn		GB_Matrix Scale (const GB_Vector3 vector)
	@brief	Calculates the inverted GB_Matrix  of a given GB_Matrix 
	@param	GB_Matrix 	GB_Matrix  to invert
	@return GB_Matrix 
**/
//==================================================================
GOOSEBERRY_API GB_Matrix MatrixInvert(const GB_Matrix & matrix )
{
	float inv_det = MatrixDeterminant(matrix);
	if(inv_det == 0.0f)
		return MatrixIdentity();
	inv_det = 1.0f / inv_det;

	GB_Matrix res_matrix;
	res_matrix.m11_		= inv_det * (matrix.m22_ * matrix.m33_ - matrix.m23_ * matrix.m32_);
	res_matrix.m12_		= -inv_det * (matrix.m12_ * matrix.m33_ - matrix.m13_ * matrix.m32_);
	res_matrix.m13_		= inv_det * (matrix.m12_ * matrix.m23_ - matrix.m13_ * matrix.m22_);
	res_matrix.m14_		= 0.0f;
	res_matrix.m21_		= -inv_det * (matrix.m21_ * matrix.m33_ - matrix.m23_ * matrix.m31_);
	res_matrix.m22_		= inv_det * (matrix.m11_ * matrix.m33_ - matrix.m13_ * matrix.m32_);
	res_matrix.m23_		= -inv_det * (matrix.m11_ * matrix.m23_ - matrix.m13_ * matrix.m21_);
	res_matrix.m24_		= 0.0f;
	res_matrix.m31_		= inv_det * (matrix.m32_ * matrix.m32_ - matrix.m22_ * matrix.m31_);
	res_matrix.m32_		= -inv_det * (matrix.m11_ * matrix.m32_ - matrix.m12_ * matrix.m32_);
	res_matrix.m33_		= inv_det * (matrix.m11_ * matrix.m22_ - matrix.m12_ * matrix.m32_);
	res_matrix.m34_		= 0.0f;
	res_matrix.m41_		= -(matrix.m41_ * res_matrix.m11_ + matrix.m42_ * res_matrix.m21_ + matrix.m43_ * res_matrix.m31_);	
	res_matrix.m42_		= -(matrix.m41_ * res_matrix.m12_ + matrix.m42_ * res_matrix.m22_ + matrix.m43_ * res_matrix.m32_);	
	res_matrix.m43_		= -(matrix.m41_ * res_matrix.m13_ + matrix.m42_ * res_matrix.m23_ + matrix.m43_ * res_matrix.m33_);
	res_matrix.m44_		= 1.0f;
	return res_matrix ;
}

//==================================================================
/**
	@fn		GB_Matrix Determinant (const GB_Matrix  & GB_Matrix )
	@brief	Calculates the top left determinant of a given GB_Matrix 
	@param	GB_Matrix  to build the determinant from
	@return float
**/
//==================================================================
GOOSEBERRY_API float MatrixDeterminant(const GB_Matrix & matrix)
{
	return	matrix.m11_ * (matrix.m22_ * matrix.m33_ - matrix.m23_ * matrix.m32_) -
			matrix.m12_ * (matrix.m21_ * matrix.m33_ - matrix.m23_ * matrix.m31_) + 
			matrix.m13_ * (matrix.m21_ * matrix.m32_ - matrix.m22_ * matrix.m31_);
}

//==================================================================
//	Class Functions
//==================================================================
/**
	@fn		GB_Matrix  :: GB_Matrix ()
	@brief	Standardconstructor, sets all values to zero
**/
//==================================================================
GB_Matrix  :: GB_Matrix()
{
	for(int i = 0; i < sizeof(d1_); i++)
		d1_[i]	= 0;
}

//==================================================================
/**
	@fn		GB_Matrix  :: GB_Matrix (float * p1DimGB_Array)
	@brief	Extended constructor, sets all values to values of a
			given GB_Array
	@param	float * p1DimGB_Array
**/
//==================================================================
GB_Matrix  :: GB_Matrix(float * one_dim_arr)
{
	for(int i = 0; i < sizeof(d1_); i++)
		d1_[i] = one_dim_arr[i];
}

//==================================================================
/**
	@fn		GB_Matrix  :: GB_Matrix (float p11, float p12, float p13, float p14, float p21, float p22, float p23, float p24,
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
GB_Matrix :: GB_Matrix(float p11, float p12, float p13, float p14, float p21, float p22, float p23, float p24,
		float p31, float p32, float p33, float p34, float p41, float p42, float p43, float p44)
{
	m11_ = p11; m12_ = p12; m13_ = p13; m14_ = p14;
	m21_ = p21; m22_ = p22; m23_ = p23; m24_ = p24;
	m31_ = p31; m32_ = p32; m33_ = p33; m34_ = p34;
	m41_ = p41; m42_ = p42; m43_ = p43; m44_ = p44;
}

//==================================================================
/**
	@fn		GB_Matrix :: operator+(const GB_Matrix & right)
	@brief	Overload operator +
	@param	right	GB_Matrix  of right side
	@return GB_Matrix 
**/
//==================================================================
GB_Matrix GB_Matrix :: operator+(const GB_Matrix & right)
{
	for(int i = 0; i < sizeof(d1_); i++)
		d1_[i]	+= right.d1_[i];

	return *this;
}

//==================================================================
/**
	@fn		GB_Matrix :: operator-(const GB_Matrix & right)
	@brief	Overload operator -
	@param	right	GB_Matrix  of right side
	@return GB_Matrix 
**/
//==================================================================
GB_Matrix GB_Matrix :: operator-(const GB_Matrix  & right)
{
	for(int i = 0; i < sizeof(d1_); i++)
		d1_[i]	-= right.d1_[i];

	return *this;
}

//==================================================================
/**
	@fn		GB_Matrix :: operator*(const GB_Matrix & right)
	@brief	Overload operator *
	@param	right	GB_Matrix  of right side
	@return GB_Matrix 
**/
//==================================================================
GB_Matrix GB_Matrix :: operator*(const GB_Matrix & right)
{
	return *this *= right;
}

//==================================================================
/**
	@fn		GB_Matrix :: operator*(const float value)
	@brief	Overload operator *
	@param	value	value to u_ltiply
	@return GB_Matrix 
**/
//==================================================================
GB_Matrix GB_Matrix :: operator*(const float value)
{
	for(int i = 0; i < sizeof(d1_); i++)
		d1_[i]	*= value;

	return *this;	
}

//==================================================================
/**
	@fn		GB_Matrix :: operator/(const GB_Matrix  & right)
	@brief	Overload operator /
	@param	right	GB_Matrix  of right side
	@return GB_Matrix 
**/
//==================================================================
GB_Matrix GB_Matrix :: operator/(const GB_Matrix & right)
{
	return *this *= MatrixInvert(right);
}

//==================================================================
/**
	@fn		GB_Matrix :: operator/(const float value)
	@brief	Overload operator /
	@param	value	value to divide
	@return GB_Matrix 
**/
//==================================================================
GB_Matrix GB_Matrix :: operator/(const float value)
{
	for(int i = 0; i < sizeof(d1_); i++)
		d1_[i]	/= value;

	return *this;	
}

//==================================================================
/**
	@fn		GB_Matrix :: operator+=(const GB_Matrix  & right)
	@brief	Overload operator +=
	@param	right	GB_Matrix  of right side
	@return GB_Matrix 
**/
//==================================================================
GB_Matrix GB_Matrix :: operator+=(const GB_Matrix  & right)
{
	for(int i = 0; i < sizeof(d1_); i++)
		d1_[i]	+= right.d1_[i];

	return *this;	
}

//==================================================================
/**
	@fn		GB_Matrix :: operator-=(const GB_Matrix  & right)
	@brief	Overload operator -=
	@param	right	GB_Matrix  of right side
	@return GB_Matrix 
**/
//==================================================================
GB_Matrix GB_Matrix :: operator-=(const GB_Matrix  & right)
{
	for(int i = 0; i < sizeof(d1_); i++)
		d1_[i]	-= right.d1_[i];

	return *this;
}

//==================================================================
/**
	@fn		GB_Matrix :: operator*=(const GB_Matrix  & right)
	@brief	Overload operator *=
	@param	right	GB_Matrix  of right side
	@return GB_Matrix 
**/
//==================================================================
GB_Matrix GB_Matrix :: operator*=(const GB_Matrix  & right)
{
	return *this = GB_Matrix (	right.m11_ * m11_ + right.m21_ * m12_ + right.m31_ * m13_ + right.m41_ * m14_,
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
	@fn		GB_Matrix :: operator*=(const float value)
	@brief	Overload operator *=
	@param	value	value to u_ltiply
	@return GB_Matrix 
**/
//==================================================================
GB_Matrix GB_Matrix :: operator*=(const float value)
{
	for(int i = 0; i < sizeof(d1_); i++)
		d1_[i]	*= value;

	return *this;
}

//==================================================================
/**
	@fn		GB_Matrix :: operator/=(const GB_Matrix & right)
	@brief	Overload operator /=
	@param	right	GB_Matrix  of right side
	@return GB_Matrix 
**/
//==================================================================
GB_Matrix GB_Matrix :: operator/=(const GB_Matrix & right)
{
	return *this *= MatrixInvert(right);
}

//==================================================================
/**
	@fn		GB_Matrix :: operator/=(const float value)
	@brief	Overload operator /=
	@param	value	value to divide
	@return GB_Matrix 
**/
//==================================================================
GB_Matrix GB_Matrix :: operator/=(const float value)
{
	for(int i = 0; i < sizeof(d1_); i++)
		d1_[i]	/= value;

	return *this;
}

//==================================================================
/**
	@fn		GB_Matrix :: operator==(const GB_Matrix & right)
	@brief	Overload operator ==
	@param	right	GB_Matrix  of right side
	@return true or false
**/
//==================================================================
bool GB_Matrix :: operator==(const GB_Matrix & right)
{
	for(int i = 0; i < sizeof(d1_); i++)
		if(d1_[i] != right.d1_[i])
			return false;

	return true;
}

//==================================================================
/**
	@fn		GB_Matrix :: operator!=(const GB_Matrix & right)
	@brief	Overload operator !=
	@param	right	GB_Matrix  of right side
	@return true or false
**/
//==================================================================
bool GB_Matrix :: operator!=(const GB_Matrix & right)
{
	for(int i = 0; i < sizeof(d1_); i++)
		if(d1_[i] == right.d1_[i])
			return false;

	return true;
}

//==================================================================
/**
	@fn		GB_Matrix :: operator=(const GB_Matrix & right)
	@brief	Overload operator =
	@param	right	GB_Matrix  of right side
	@return GB_Matrix 
**/
//==================================================================
GB_Matrix GB_Matrix :: operator=(const GB_Matrix & right)
{
	for(int i = 0; i < sizeof(d1_); i++)
		d1_[i] = right.d1_[i];

	return *this;
}