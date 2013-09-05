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
#include "gooseberry.h"

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
		BOOL fRemoveModelByName(std::string pMdlName);	
		BOOL fRemoveModelByFile(std::string pFileName);	
		gbResult fGetMdlCpyByID(gbMsh * pMdl, unsigned int pID);
		gbResult fGetMdlCpyByName(gbMsh * pMdl, std::string pMdlName);

		//	Get & Set
		/**
			@fn		fGetSize()
			@brief	get size
			@return	int		size of model queue
		**/
		int fGetSize() { return mModelQueue.size(); }

	private:
		//	Variables
		//	Functions

	protected:
};