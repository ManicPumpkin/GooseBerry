/**
	@file	GB_MeshQueue.cpp
	@brief	All functions of GB_MeshQueue class
	@author	drubner
	@date	2012-11-26
**/
//==================================================================
//	INCLUDE
//==================================================================
#include "GB_MeshQueue.h"

//==================================================================
//	(DE-)CONSTRUCTOR
//==================================================================
/**
		@fn		GB_MeshQueue :: GB_MeshQueue
		@brief	Constructor which GB_Logs queue initialization
**/
//==================================================================
GB_MeshQueue :: GB_MeshQueue()
{
	GB_LINFO("Model queue initialized");
}
//==================================================================
//	Functions
//==================================================================
/**
		@fn		GB_MeshQueue :: AddModel
		@brief	Add model to model queue
		@param	model	model GB_Object
		@return	VOID
**/
//==================================================================
VOID GB_MeshQueue::AddModel(GB_Mesh model)
{
	GB_LINFO("Model \"" +  model.obj_name_ + "\" added to queue");
	model_queue_.push_back(model);
}
//==================================================================				
/**
		@fn		GB_MeshQueue :: RemoveModelByName
		@brief	Remove model from model queue by name
		@param	model_name	name of model GB_Object
		@return	boolean value of success/failure
**/
//==================================================================
BOOL GB_MeshQueue :: RemoveModelByName(std::string model_name)
{
	for(int i = 0; i < this->GetSize(); i++)
	{
		if(model_queue_[i].obj_name_ == model_name)
		{
			model_queue_.erase(model_queue_.begin() + (i - 1));
			GB_LINFO("Model removed by name: " + model_name);
			return TRUE;
		}
	}

	GB_LERROR("Error: Could not find model by name: " + model_name, "GB_MeshQueue Error");
	return FALSE;
}
//==================================================================
/**
		@fn		GB_MeshQueue :: RemoveModelByFile
		@brief	Remove model from model queue by file name
		@param	file_name	file name of model GB_Object
		@return	boolean value of success/failure
**/
//==================================================================
BOOL GB_MeshQueue :: RemoveModelByFile(std::string file_name)
{
	for(int i = 0; i < this->GetSize(); i++)
	{
		if(model_queue_[i].obj_file_ == file_name)
		{
			model_queue_.erase(model_queue_.begin() + (i - 1));
			GB_LINFO("Model removed by file name: " + file_name);
			return TRUE;
		}
	}
	
	GB_LERROR("Error: Could not find model by file name: " + file_name, "GB_MeshQueue Error");
	return FALSE;
}
//==================================================================
/**
		@fn		GB_MeshQueue :: GetMdlCyByID(int id)
		@brief	Returns GB_Enum::gbResult
		@param	mdl	mesh of GB_Object, call by reference
		@param	id		model id
		@return	GB_Enum::gbResult	gb_ok or gb_error
**/
//==================================================================
GB_Enum::gbResult GB_MeshQueue::GetMdlCyByID(GB_Mesh * mdl, unsigned int id)
{
	if(id < model_queue_.size())
	{
		*mdl	= model_queue_[id];
		return GB_Enum::GB_OK;
	}

	return GB_Enum::GB_ERROR;
}
//==================================================================
/**
		@fn		GB_MeshQueue :: GetMdlCyByName(std::string model_name)
		@brief	Returns GB_Enum::gbResult
		@param	mdl		mesh of GB_Object, call by reference
		@param	model_name	name of model
		@return	Mesh* pointer to model
**/
//==================================================================
GB_Enum::gbResult GB_MeshQueue::GetMdlCyByName(GB_Mesh * mdl, std::string model_name)
{
	for(unsigned int i = 0; i < model_queue_.size(); i++)
	{
		if(model_queue_[i].obj_name_ == model_name)
		{
			*mdl = model_queue_[i];
			return GB_Enum::GB_OK;
		}
	}

	return GB_Enum::GB_ERROR;
}
//==================================================================