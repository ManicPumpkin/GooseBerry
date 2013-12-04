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
		@fn		gbMshQueue :: RemoveModelByName
		@brief	Remove model from model queue by name
		@param	model_name	name of model object
		@return	boolean value of success/failure
**/
//==================================================================
BOOL gbMshQueue :: RemoveModelByName(std::string model_name)
{
	for(int i = 0; i < this->GetSize(); i++)
	{
		if(mModelQueue[i].mObjName == model_name)
		{
			mModelQueue.erase(mModelQueue.begin() + (i - 1));
			GB_LINFO("Model removed by name: " + model_name);
			return TRUE;
		}
	}

	GB_LERROR("Error: Could not find model by name: " + model_name, "gbMshQueue Error");
	return FALSE;
}
//==================================================================
/**
		@fn		gbMshQueue :: RemoveModelByFile
		@brief	Remove model from model queue by file name
		@param	file_name	file name of model object
		@return	boolean value of success/failure
**/
//==================================================================
BOOL gbMshQueue :: RemoveModelByFile(std::string file_name)
{
	for(int i = 0; i < this->GetSize(); i++)
	{
		if(mModelQueue[i].mObjFile == file_name)
		{
			mModelQueue.erase(mModelQueue.begin() + (i - 1));
			GB_LINFO("Model removed by file name: " + file_name);
			return TRUE;
		}
	}
	
	GB_LERROR("Error: Could not find model by file name: " + file_name, "gbMshQueue Error");
	return FALSE;
}
//==================================================================
/**
		@fn		gbMshQueue :: GetMdlCyByID(int id)
		@brief	Returns gbResult
		@param	mdl	mesh of object, call by reference
		@param	id		model id
		@return	gbResult	gb_ok or gb_error
**/
//==================================================================
gbResult gbMshQueue :: GetMdlCyByID(gbMsh * mdl, unsigned int id)
{
	if(id < mModelQueue.size())
	{
		*mdl	= mModelQueue[id];
		return GB_OK;
	}

	return GB_ERROR;
}
//==================================================================
/**
		@fn		gbMshQueue :: GetMdlCyByName(std::string model_name)
		@brief	Returns gbResult
		@param	mdl		mesh of object, call by reference
		@param	model_name	name of model
		@return	gbMsh* pointer to model
**/
//==================================================================
gbResult gbMshQueue :: GetMdlCyByName(gbMsh * mdl, std::string model_name)
{
	for(unsigned int i = 0; i < mModelQueue.size(); i++)
	{
		if(mModelQueue[i].mObjName == model_name)
		{
			*mdl = mModelQueue[i];
			return GB_OK;
		}
	}

	return GB_ERROR;
}
//==================================================================