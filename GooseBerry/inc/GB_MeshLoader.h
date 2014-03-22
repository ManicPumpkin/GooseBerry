/**
	@file	GB_MeshLoader.h
	@brief	Includes class of model GB_Object loader
	@author	drubner
	@date	2013-07-31
**/
//==================================================================
#pragma once

//==================================================================
//	INCLUDE
//==================================================================
#include "GooseBerry.h"

//==================================================================
//	CLASS PREDEFINITION
//==================================================================
class GB_Mesh;

//==================================================================
//	CLASS
//==================================================================
/**
		@class	GB_MeshLoader
		@brief	Loads an model GB_Object out of file
**/
//==================================================================
class GOOSEBERRY_API GB_MeshLoader 
{
	public:
		//	Variables
		//	Functions
		GB_Mesh LoadObj(std::string file, bool is_quad = FALSE);

	private:
		//	Variables
		//	Functions

	protected:
};