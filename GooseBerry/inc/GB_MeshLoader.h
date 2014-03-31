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
#include "gooseberry.h"

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
		static GB_MeshLoader* GetInstance()
		{
			if (instance == NULL)
				instance = new GB_MeshLoader();

			return instance;
		}

		//	Functions
		GB_Mesh LoadObj(std::string file, bool is_quad = FALSE);

	private:
		//	Variables
		static GB_MeshLoader *instance;

		//	Functions

	protected:
		//	Functions
		GB_MeshLoader() {}
};
