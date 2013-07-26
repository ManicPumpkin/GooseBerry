/**
	@file	cMdlLoader.h
	@brief	Includes class of model object loader
	@author	drubner
	@date	2012-11-24
**/
//==================================================================
#ifndef CMDLLOADER_H
#define CMDLLOADER_H
//==================================================================
//	INCLUDE
//==================================================================
#include "cMdl.h"
//==================================================================
//	CLASS
//==================================================================
/**
		@class	cMdlLoader
		@brief	Loads an model object out of file
**/
//==================================================================
public class cMdlLoader 
{
	public:
		//	Variables
		//	Functions
		cMdl	fLoadObj(std::string pFile, bool pIsQuad = FALSE);

	private:
		//	Variables
		//	Functions

	protected:
};
//==================================================================
#endif CMDLLOADER_H
//==================================================================
