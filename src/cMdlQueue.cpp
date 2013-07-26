/**
	@file	cMdlQueue.cpp
	@brief	All functions of cMdlQueue class
	@author	drubner
	@date	2012-11-26
**/
//==================================================================
//	Include
//==================================================================
#include "hGlobal.h"
//==================================================================
#include "cMdlQueue.h"
//==================================================================
//	(De-)Constructor
//==================================================================
/**
		@fn		cMdlQueue :: cMdlQueue
		@brief	Constructor which logs queue initialization
**/
//==================================================================
cMdlQueue :: cMdlQueue()
{
	cGlobal::gLog("Model queue initialized", "\t");
}
//==================================================================
//	Functions
//==================================================================
/**
		@fn		cMdlQueue :: fAddModel
		@brief	Add model to model queue
		@param	pModel	model object
		@return	VOID
**/
//==================================================================
VOID cMdlQueue :: fAddModel(cMdl pModel)
{
	cGlobal::gLog("Model added to queue: " + pModel.mObjName, "\t");
	mModelQueue.push_back(pModel);
}
//==================================================================				
/**
		@fn		cMdlQueue :: fRemoveModelByName
		@brief	Remove model from model queue by name
		@param	pMdlName	name of model object
		@return	boolean value of success/failure
**/
//==================================================================
BOOL cMdlQueue :: fRemoveModelByName(std::string pMdlName)
{
	for(int i = 0; i < this->fGetSize(); i++)
	{
		if(mModelQueue[i].mObjName == pMdlName)
		{
			mModelQueue.erase(mModelQueue.begin() + (i - 1));
			cGlobal::gLog("Model removed by name: " + pMdlName, "\t");
			return TRUE;
		}
	}

	cGlobal::gLog("Error: Could not find model by name: " + pMdlName, "\t");
	return FALSE;
}
//==================================================================
/**
		@fn		cMdlQueue :: fRemoveModelByFile
		@brief	Remove model from model queue by file name
		@param	pFileName	file name of model object
		@return	boolean value of success/failure
**/
//==================================================================
BOOL cMdlQueue :: fRemoveModelByFile(std::string pFileName)
{
	for(int i = 0; i < this->fGetSize(); i++)
	{
		if(mModelQueue[i].mObjFile == pFileName)
		{
			mModelQueue.erase(mModelQueue.begin() + (i - 1));
			cGlobal::gLog("Model removed by file name: " + pFileName, "\t");
			return TRUE;
		}
	}
	
	cGlobal::gLog("Error: Could not find model by file name: " + pFileName, "\t");
	return FALSE;
}
//==================================================================
/**
		@fn		cMdlQueue :: fGetMdlByID(int pID)
		@brief	Returns model by ID
		@param	pID	model id
		@return	cMDL* pointer to model
**/
//==================================================================
cMdl* cMdlQueue :: fGetMdlByID(int pID)
{
	cMdl * tMdl	= &mModelQueue[pID];
	return tMdl;
}
//==================================================================