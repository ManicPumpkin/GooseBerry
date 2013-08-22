/**
	@file	gbMdlQueue.h
	@brief	Includes gbMdlQueue class
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
		@class	gbMdlQueue
		@brief	Implements queue to store model objects
**/
//==================================================================
class GOOSEBERRY_API gbMdlQueue 
{
	public:
		//	Variables
		std::vector<gbMdl> mModelQueue;		//!< model queue
		
		//	(De-)Constructor
		gbMdlQueue();

		//	Functions
		VOID fAddModel(gbMdl pModel);					
		BOOL fRemoveModelByName(std::string pMdlName);	
		BOOL fRemoveModelByFile(std::string pFileName);	
		gbResult fGetMdlCpyByID(gbMdl * pMdl, unsigned int pID);
		gbResult fGetMdlCpyByName(gbMdl * pMdl, std::string pMdlName);

		//	Get & Set
		int fGetSize() { return mModelQueue.size(); }

	private:
		//	Variables
		//	Functions

	protected:
};