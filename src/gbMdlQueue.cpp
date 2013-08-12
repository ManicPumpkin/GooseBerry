/**
	@file	gbMdlQueue.cpp
	@brief	All functions of gbMdlQueue class
	@author	drubner
	@date	2012-11-26
**/
//==================================================================
//	Include
//==================================================================
#include "gbMdlQueue.h"

//==================================================================
//	(De-)Constructor
//==================================================================
/**
		@fn		gbMdlQueue :: gbMdlQueue
		@brief	Constructor which logs queue initialization
**/
//==================================================================
gbMdlQueue :: gbMdlQueue()
{
	GB_LINFO("Model queue initialized");
}
//==================================================================
//	Functions
//==================================================================
/**
		@fn		gbMdlQueue :: fAddModel
		@brief	Add model to model queue
		@param	pModel	model object
		@return	VOID
**/
//==================================================================
VOID gbMdlQueue :: fAddModel(gbMdl pModel)
{
	GB_LINFO("Model \"" +  pModel.mObjName + "\" added to queue");
	mModelQueue.push_back(pModel);
}
//==================================================================				
/**
		@fn		gbMdlQueue :: fRemoveModelByName
		@brief	Remove model from model queue by name
		@param	pMdlName	name of model object
		@return	boolean value of success/failure
**/
//==================================================================
BOOL gbMdlQueue :: fRemoveModelByName(std::string pMdlName)
{
	for(int i = 0; i < this->fGetSize(); i++)
	{
		if(mModelQueue[i].mObjName == pMdlName)
		{
			mModelQueue.erase(mModelQueue.begin() + (i - 1));
			GB_LINFO("Model removed by name: " + pMdlName);
			return TRUE;
		}
	}

	GB_LERROR("Error: Could not find model by name: " + pMdlName, "gbMdlQueue Error");
	return FALSE;
}
//==================================================================
/**
		@fn		gbMdlQueue :: fRemoveModelByFile
		@brief	Remove model from model queue by file name
		@param	pFileName	file name of model object
		@return	boolean value of success/failure
**/
//==================================================================
BOOL gbMdlQueue :: fRemoveModelByFile(std::string pFileName)
{
	for(int i = 0; i < this->fGetSize(); i++)
	{
		if(mModelQueue[i].mObjFile == pFileName)
		{
			mModelQueue.erase(mModelQueue.begin() + (i - 1));
			GB_LINFO("Model removed by file name: " + pFileName);
			return TRUE;
		}
	}
	
	GB_LERROR("Error: Could not find model by file name: " + pFileName, "gbMdlQueue Error");
	return FALSE;
}
//==================================================================
/**
		@fn		gbMdlQueue :: fGetMdlCpyByID(int pID)
		@brief	Returns gbResult
		@param	pID	model id
		@return	gbMdl* pointer to model
**/
//==================================================================
gbResult gbMdlQueue :: fGetMdlCpyByID(int pID, gbMdl * pMdl)
{
	pMdl	= &mModelQueue[pID];
	return GB_OK;
}
//==================================================================
/**
		@fn		gbMdlQueue :: fGetMdlCpyByName(std::string pMdlName)
		@brief	Returns gbResult
		@param	pMdlName model name
		@return	gbMdl* pointer to model
**/
//==================================================================
gbResult gbMdlQueue :: fGetMdlCpyByName(std::string pMdlName, gbMdl * pMdl)
{
	for(gbMdl tMdl : mModelQueue)
	{
		if(tMdl.mObjName == pMdlName)
		{
			pMdl = &tMdl;
			return GB_OK;
		}
	}

	return GB_ERROR;
}
//==================================================================