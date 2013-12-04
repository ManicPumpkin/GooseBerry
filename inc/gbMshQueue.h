/**
	@file	gbMshQueue.h
	@brief	Includes gbMshQueue class
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
//	CLASS
//==================================================================
/**
		@class	gbMshQueue
		@brief	Implements queue to store model objects
**/
//==================================================================
class GOOSEBERRY_API gbMshQueue 
{
	public:
		//	Variables
		std::vector<gbMsh> mModelQueue;		//!< model queue
		
		//	(De-)Constructor
		gbMshQueue();

		//	Functions
		VOID fAddModel(gbMsh pModel);					
		BOOL RemoveModelByName(std::string model_name);	
		BOOL RemoveModelByFile(std::string file_name);	
		gbResult GetMdlCyByID(gbMsh * mdl, unsigned int id);
		gbResult GetMdlCyByName(gbMsh * mdl, std::string model_name);

		//	Get & Set
		/**
			@fn		GetSize()
			@brief	get size
			@return	int		size of model queue
		**/
		int GetSize() { return mModelQueue.size(); }

	private:
		//	Variables
		//	Functions

	protected:
};