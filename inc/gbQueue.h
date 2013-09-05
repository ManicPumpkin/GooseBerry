/**
	@file	gbQueue.h
	@brief	Includes gbQueue class
	@author	drubner
	@date	2013-09-05
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
		@class	gbQueue
		@brief	Implements queue to store model objects
**/
//==================================================================
template <typename T>
class GOOSEBERRY_API gbQueue 
{
	public:
		//	Variables
		std::vector<T> mQueue;		//!< model queue
		
		//	(De-)Constructor
		gbQueue();

		//	Functions
		gbResult fAddMember(T pMember);			
		gbResult fRemoveMemberById(int pID);
		gbResult fGetMbrById(T * pMbr, unsigned int pId);

		/*
		BOOL fRemoveModelByName(std::string pMdlName);	
		BOOL fRemoveModelByFile(std::string pFileName);	
		gbResult fGetMdlCpyByID(gbMsh * pMdl, unsigned int pID);
		gbResult fGetMdlCpyByName(gbMsh * pMdl, std::string pMdlName);
		*/
		//	Get & Set
		/**
			@fn		fGetSize()
			@brief	get size
			@return	int		size of model queue
		**/
		int fGetSize() { return mQueue.size(); }

	private:
		//	Variables
		//	Functions

	protected:
};

//==================================================================
//	Functions
//==================================================================
/**
	@fn		gbQueue :: gbQueue()
	@brief	Standardconstructor
**/
//==================================================================
template <typename T>
gbQueue<T> :: gbQueue()
{
	mQueue	= new std::vector<T>();
}

//==================================================================
/**
	@fn		gbQueue :: fAddMember(T pMember);		
	@brief	Add a new member
	@param	pMember		member to add
	@return gbResult	GB_OK
**/
//==================================================================
template <typename T>
gbResult gbQueue<T> :: fAddMember(T pMember)
{
	mQueue.push_back(pMember);
	return GB_OK;
}

//==================================================================
/**
	@fn		gbQueue :: fRemoveMemberById(int pID);
	@brief	remove member by id
	@param	pId	id of member to remove
	@return gbResult	GB_OK or GB_NOTFOUND
**/
//==================================================================
template <typename T>
gbResult gbQueue<T> :: fRemoveMemberById(int pId)
{
	if(pId > mQueue.size())
		return GB_NOTFOUND;

	mQueue.erase(mQueue.begin() + pId);
	return GB_OK;
}

//==================================================================
/**
	@fn		gbQueue :: fGetMbrById(T * pMbr, unsigned int pId);
	@brief	Get member by id
	@param	pMbr		member object, call by reference
	@param	pId			id of member to return
	@return	gbResult	GB_OK or GB_NOTFOUND
**/
//==================================================================
template <typename T>
gbResult gbQueue<T> :: fGetMbrById(T * pMbr, unsigned int pId)
{
	if(pId > mQueue.size())
		return GB_NOTFOUND;

	pMbr	= mQueue[pId];
	return GB_OK;
}