/**
	@file	cMdlQueue.h
	@brief	Includes cMdlQueue class
	@author	drubner
	@date	2012-11-26
**/
//==================================================================
#ifndef CMDLQUEUE_H
#define CMDLQUEUE_H
//==================================================================
//	INCLUDE
//==================================================================
#include "hLibraries.h"
//==================================================================
#include "cMdl.h"
//==================================================================
//	CLASS
//==================================================================
/**
		@class	cMdlQueue
		@brief	Implements queue to store model objects
**/
//==================================================================
public class cMdlQueue 
{
	public:
		//	Variables
		std::vector<cMdl> mModelQueue;		//!< model queue
		
		//	(De-)Constructor
		cMdlQueue();

		//	Functions
		VOID fAddModel(cMdl pModel);					
		BOOL fRemoveModelByName(std::string pMdlName);	
		BOOL fRemoveModelByFile(std::string pFileName);	
		cMdl* fGetMdlByID(int pID);

		//	Get & Set
		int fGetSize() { return mModelQueue.size(); }

	private:
		//	Variables
		//	Functions

	protected:
};
//==================================================================
#endif CMDLQUEUE_H
//==================================================================