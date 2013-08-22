/**
	@file	gbArray.h
	@brief	Includes all common pragmas, includes and namespaces
	@author	drubner
	@date	2013-08-20
**/
//==================================================================
#pragma once 

//==================================================================
// INCLUDE
//==================================================================
#include "gooseberry.h"

//==================================================================
// FORWARD DECLARATION
//==================================================================

//==================================================================
/**
	@class	gbArray
	@brief	Contains information about object/model files
**/
//==================================================================
template <typename T>
class gbArray
{
	protected:
	private:
		//	Variables
		T * mArray;
		int mRows, mCols;
		
	public:
		//	(De-)Constructor & Copy
		gbArray(int pRows, int pCols);
		~gbArray();

		//	Operators
		const T& operator[](int pIndex) const;
		T & operator[](int pIndex);
		T& operator= (T const& tRHS);
};

//==================================================================
//	Functions
//==================================================================
/**
	@fn		gbArray :: gbArray(int pRows, int pCols)
	@brief	Constructor
**/
//==================================================================
template <typename T>
gbArray<T> :: gbArray(int pRows, int pCols)
{
	this->mRows		= pRows;
	this->mCols		= pCols;
	this->mArray	= new T[pRows * pCols];
}

//==================================================================
/**
	@fn		gbArray :: ~gbArray()
	@brief	Deonstructor
**/
//==================================================================
template <typename T>
gbArray<T> :: ~gbArray()
{
	if(mArray)
		delete [] mArray;
}

//==================================================================
/**
	@fn		gbArray :: operator[](int pRow)
	@brief	operator[] overloading
**/
//==================================================================
template <typename T>
T & gbArray<T> :: operator[](int pRow)
{
	return mArray[pRow * mCols];
}

//==================================================================
/**
	@fn		gbArray :: operator[](int pRow)
	@brief	operator[] overloading
**/
//==================================================================
template <typename T>
const T & gbArray<T> :: operator[](int pRow) const
{
	return mArray[pRow * mCols];
}

//==================================================================
/**
	@fn		gbArray<T> :: operator= (T const& tRHS)
	@brief	operator= overloading
**/
//==================================================================
template <typename T>
T& gbArray<T> :: operator= (T const& tRHS)
{
	this->mRows	= tRHS->mRows;
	this->mCols	= tRHS->mCols;

	for(int i = 0; i < (this->mRows * this->mCols); i++)
		this->mArray[i]		= tRHS->mArray[i];
}