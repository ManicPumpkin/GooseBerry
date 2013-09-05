/**
	@file	gbMshLoader.h
	@brief	Includes class of model object loader
	@author	drubner
	@date	2013-07-31
**/
//==================================================================
#pragma once

//==================================================================
//	INCLUDE
//==================================================================
#include "gooseberry.h"

//==================================================================
//	PREDEFINITION
//==================================================================
class gbMsh;

//==================================================================
//	CLASS
//==================================================================
/**
		@class	gbMshLoader
		@brief	Loads an model object out of file
**/
//==================================================================
class GOOSEBERRY_API gbMshLoader 
{
	public:
		//	Variables
		//	Functions
		gbMsh fLoadObj(std::string pFile, bool pIsQuad = FALSE);

	private:
		//	Variables
		//	Functions

	protected:
};