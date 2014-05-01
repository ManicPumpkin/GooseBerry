//==================================================================
/**
@file	GB_BB3D.h
@brief	This file includes the BoundingBox class for 3D objects
@author	drubner
@date	2014-05-01
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
@class	GB_BB3D
@brief	Contains information about bounding box class
**/
//==================================================================
class GB_BB3D
{
	protected:

	private:
		GB_Struct::Vertex cornerstones_[8];

	public:
		//	Functions
		void InitializeBB(GB_Struct::Vertex * list_vertices);
		void Draw();

		//	(De-)Constructor
		GB_BB3D();
		GB_BB3D(GB_Struct::Vertex * list_vertices);
};