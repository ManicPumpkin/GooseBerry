/**
	@file	Queue.h
	@brief	Includes Queue class
	@author	drubner
	@date	2013-09-05
**/
//==================================================================
#pragma once

//==================================================================
//	NAMESPACE
//==================================================================
using namespace gbGlobal;

//==================================================================
//	INCLUDE
//==================================================================
#include "GooseBerry.h"

//==================================================================
//	CLASS
//==================================================================
/**
		@class	Queue
		@brief	Implements queue to store model objects
**/
//==================================================================
template <typename T>
class GOOSEBERRY_API Queue 
{
	public:
		//	Variables
		std::vector<T> queue_;		//!< model queue
		
		//	(De-)Constructor
		Queue();

		//	Functions
		gbResult AddMember(T member);			
		gbResult RemoveMemberById(int id);
		gbResult GetMbrById(T * member, unsigned int id);

		/*
		BOOL RemoveModelByName(std::string model_name);	
		BOOL RemoveModelByFile(std::string file_name);	
		gbResult GetMdlCyByID(gbMsh * mdl, unsigned int id);
		gbResult GetMdlCyByName(gbMsh * mdl, std::string model_name);
		*/
		//	Get & Set
		/**
			@fn		GetSize()
			@brief	get size
			@return	int		size of model queue
		**/
		int GetSize() { return queue_.size(); }

	private:
		//	Variables
		//	Functions

	protected:
};

//==================================================================
//	Functions
//==================================================================
/**
	@fn		Queue :: Queue()
	@brief	Standardconstructor
**/
//==================================================================
template <typename T>
Queue<T> :: Queue()
{
	queue_	= new std::vector<T>();
}

//==================================================================
/**
	@fn		Queue :: AddMember(T member);		
	@brief	Add a new member
	@param	member		member to add
	@return gbResult	GB_OK
**/
//==================================================================
template <typename T>
gbResult Queue<T> :: AddMember(T member)
{
	queue_.push_back(member);
	return GB_OK;
}

//==================================================================
/**
	@fn		Queue :: RemoveMemberById(int id);
	@brief	remove member by id
	@param	id	id of member to remove
	@return gbResult	GB_OK or GB_NOTFOUND
**/
//==================================================================
template <typename T>
gbResult Queue<T> :: RemoveMemberById(int id)
{
	if(id > queue_.size())
		return GB_NOTFOUND;

	queue_.erase(queue_.begin() + id);
	return GB_OK;
}

//==================================================================
/**
	@fn		Queue :: GetMbrById(T * member, unsigned int id);
	@brief	Get member by id
	@param	member		member object, call by reference
	@param	id			id of member to return
	@return	gbResult	GB_OK or GB_NOTFOUND
**/
//==================================================================
template <typename T>
gbResult Queue<T> :: GetMbrById(T * member, unsigned int id)
{
	if(id > queue_.size())
		return GB_NOTFOUND;

	member	= queue_[id];
	return GB_OK;
}