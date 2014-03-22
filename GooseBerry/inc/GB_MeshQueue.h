/**
	@file	GB_MeshQueue.h
	@brief	Includes GB_MeshQueue class
	@author	drubner
	@date	2012-11-26
**/
//==================================================================
#pragma once

//==================================================================
//	INCLUDE
//==================================================================
#include "GooseBerry.h"

//==================================================================
//	NAMESPACE
//==================================================================

//==================================================================
//	CLASS
//==================================================================
/**
		@class	GB_MeshQueue
		@brief	Implements queue to store model GB_Objects
**/
//==================================================================
class GOOSEBERRY_API GB_MeshQueue 
{
	public:
		//	Variables
		std::vector<GB_Mesh> model_queue_;		//!< model queue
		
		//	(De-)Constructor
		GB_MeshQueue();

		//	Functions
		VOID AddModel(GB_Mesh model);
		BOOL RemoveModelByName(std::string model_name);	
		BOOL RemoveModelByFile(std::string file_name);	
		GB_Enum::gbResult GetMdlCyByID(GB_Mesh * mdl, unsigned int id);
		GB_Enum::gbResult GetMdlCyByName(GB_Mesh * mdl, std::string model_name);

		//	Get & Set
		/**
			@fn		GetSize()
			@brief	get size
			@return	int		size of model queue
		**/
		int GetSize() { return model_queue_.size(); }

	private:
		//	Variables
		//	Functions

	protected:
};