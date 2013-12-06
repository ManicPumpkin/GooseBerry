/**
	@file	GB_Array.h
	@brief	Includes all common pragmas, includes and namespaces
	@author	drubner
	@date	2013-08-20
**/
//==================================================================
#pragma once 

//==================================================================
// INCLUDE
//==================================================================
#include "GooseBerry.h"

//==================================================================
// FORWARD DECLARATION
//==================================================================

//==================================================================
/**
	@class	GB_Array
	@brief	Contains information about GB_Object/model files
**/
//==================================================================
template <typename T>
class GB_Array
{
	protected:
	private:
		//	Variables
		T * GB_Array_;
		int rows_, cols_;
		
	public:
		//	(De-)Constructor & Coy
		GB_Array(int rows, int cols);
		~GB_Array();

		//	Operators
		const T& operator[](int index) const;
		T & operator[](int index);
		T& operator= (T const& rhs);
};

//==================================================================
//	Functions
//==================================================================
/**
	@fn		GB_Array :: GB_Array(int rows, int cols)
	@brief	Constructor
**/
//==================================================================
template <typename T>
GB_Array<T> :: GB_Array(int rows, int cols)
{
	this->rows_		= rows;
	this->cols_		= cols;
	this->GB_Array_	= new T[rows * cols];
}

//==================================================================
/**
	@fn		GB_Array :: ~GB_Array()
	@brief	Deonstructor
**/
//==================================================================
template <typename T>
GB_Array<T> :: ~GB_Array()
{
	if(GB_Array_)
		delete [] GB_Array_;
}

//==================================================================
/**
	@fn		GB_Array :: operator[](int row)
	@brief	operator[] overloading
**/
//==================================================================
template <typename T>
T & GB_Array<T> :: operator[](int row)
{
	return GB_Array_[row * cols_];
}

//==================================================================
/**
	@fn		GB_Array :: operator[](int row)
	@brief	operator[] overloading
**/
//==================================================================
template <typename T>
const T & GB_Array<T> :: operator[](int row) const
{
	return GB_Array_[row * cols_];
}

//==================================================================
/**
	@fn		GB_Array<T> :: operator= (T const& rhs)
	@brief	operator= overloading
**/
//==================================================================
template <typename T>
T& GB_Array<T> :: operator= (T const& rhs)
{
	this->rows_	= rhs->rows_;
	this->cols_	= rhs->cols_;

	for(int i = 0; i < (this->rows_ * this->cols_); i++)
		this->GB_Array_[i]		= rhs->GB_Array_[i];
}