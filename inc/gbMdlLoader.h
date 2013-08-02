/**
	@file	gbMdlLoader.h
	@brief	Includes class of model object loader
	@author	drubner
	@date	2013-07-31
**/
//==================================================================
#pragma once

//==================================================================
//	INCLUDE
//==================================================================
#include "gbMdl.h"

//==================================================================
//	CLASS
//==================================================================
/**
		@class	cMdlLoader
		@brief	Loads an model object out of file
**/
//==================================================================
class GOOSEBERRY_API gbMdlLoader 
{
	public:
		//	Variables
		//	Functions
		gbMdl	fLoadObj(std::string pFile, bool pIsQuad = FALSE);

	private:
		//	Variables
		//	Functions

	protected:
};