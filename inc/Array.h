/**
	@file	Array.h
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
	@class	Array
	@brief	Contains information about object/model files
**/
//==================================================================
template <typename T>
class Array
{
	protected:
	private:
		//	Variables
		T * array_;
		int rows_, cols_;
		
	public:
		//	(De-)Constructor & Coy
		Array(int rows, int cols);
		~Array();

		//	Operators
		const T& operator[](int index) const;
		T & operator[](int index);
		T& operator= (T const& rhs);
};

//==================================================================
//	Functions
//==================================================================
/**
	@fn		Array :: Array(int rows, int cols)
	@brief	Constructor
**/
//==================================================================
template <typename T>
Array<T> :: Array(int rows, int cols)
{
	this->rows_		= rows;
	this->cols_		= cols;
	this->array_	= new T[rows * cols];
}

//==================================================================
/**
	@fn		Array :: ~Array()
	@brief	Deonstructor
**/
//==================================================================
template <typename T>
Array<T> :: ~Array()
{
	if(array_)
		delete [] array_;
}

//==================================================================
/**
	@fn		Array :: operator[](int row)
	@brief	operator[] overloading
**/
//==================================================================
template <typename T>
T & Array<T> :: operator[](int row)
{
	return array_[row * cols_];
}

//==================================================================
/**
	@fn		Array :: operator[](int row)
	@brief	operator[] overloading
**/
//==================================================================
template <typename T>
const T & Array<T> :: operator[](int row) const
{
	return array_[row * cols_];
}

//==================================================================
/**
	@fn		Array<T> :: operator= (T const& rhs)
	@brief	operator= overloading
**/
//==================================================================
template <typename T>
T& Array<T> :: operator= (T const& rhs)
{
	this->rows_	= rhs->rows_;
	this->cols_	= rhs->cols_;

	for(int i = 0; i < (this->rows_ * this->cols_); i++)
		this->array_[i]		= rhs->array_[i];
}