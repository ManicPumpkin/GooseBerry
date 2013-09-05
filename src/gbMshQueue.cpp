/**
	@file	gbMshQueue.cpp
	@brief	All functions of gbMshQueue class
	@author	drubner
	@date	2012-11-26
**/
//==================================================================
//	Include
//==================================================================
#include "gbMshQueue.h"

//==================================================================
//	(De-)Constructor
//==================================================================
/**
		@fn		gbMshQueue :: gbMshQueue
		@brief	Constructor which logs queue initialization
**/
//==================================================================
gbMshQueue :: gbMshQueue()
{
	GB_LINFO("Model queue initialized");
}
//==================================================================
//	Functions
//==================================================================
/**
		@fn		gbMshQueue :: fAddModel
		@brief	Add model to model queue
		@param	pModel	model object
		@return	VOID
**/
//==================================================================
VOID gbMshQueue :: fAddModel(gbMsh pModel)
{
	GB_LINFO("Model \"" +  pModel.mObjName + "\" added to queue");
	mModelQueue.push_back(pModel);
}
//==================================================================				
/**
		@fn		gbMshQueue :: fRemoveModelByName
		@brief	Remove model from model queue by name
		@param	pMdlName	name of model object
		@return	boolean value of success/failure
**/
//==================================================================
BOOL gbMshQueue :: fRemoveModelByName(std::string pMdlName)
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

	GB_LERROR("Error: Could not find model by name: " + pMdlName, "gbMshQueue Error");
	return FALSE;
}
//==================================================================
/**
		@fn		gbMshQueue :: fRemoveModelByFile
		@brief	Remove model from model queue by file name
		@param	pFileName	file name of model object
		@return	boolean value of success/failure
**/
//==================================================================
BOOL gbMshQueue :: fRemoveModelByFile(std::string pFileName)
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
	
	GB_LERROR("Error: Could not find model by file name: " + pFileName, "gbMshQueue Error");
	return FALSE;
}
//==================================================================
/**
		@fn		gbMshQueue :: fGetMdlCpyByID(int pID)
		@brief	Returns gbResult
		@param	pMdl	mesh of object, call by reference
		@param	pID		model id
		@return	gbResult	gb_ok or gb_error
**/
//==================================================================
gbResult gbMshQueue :: fGetMdlCpyByID(gbMsh * pMdl, unsigned int pID)
{
	if(pID < mModelQueue.size())
	{
		*pMdl	= mModelQueue[pID];
		return GB_OK;
	}

	return GB_ERROR;
}
//==================================================================
/**
		@fn		gbMshQueue :: fGetMdlCpyByName(std::string pMdlName)
		@brief	Returns gbResult
		@param	pMdl		mesh of object, call by reference
		@param	pMdlName	name of model
		@return	gbMsh* pointer to model
**/
//==================================================================
gbResult gbMshQueue :: fGetMdlCpyByName(gbMsh * pMdl, std::string pMdlName)
{
	for(unsigned int i = 0; i < mModelQueue.size(); i++)
	{
		if(mModelQueue[i].mObjName == pMdlName)
		{
			*pMdl = mModelQueue[i];
			return GB_OK;
		}
	}

	return GB_ERROR;
}
//==================================================================