//==================================================================
/**
@file	GB_BB3D.cpp
@brief	This file includes all functions of GB_BB3D class
@author	drubner
@date	2014-05-01
**/
//==================================================================
//	INCLUDE
//==================================================================
#include "GB_BB3D.h"

//==================================================================
//	FUNCTIONS
//==================================================================
/**
@fn		GB_BB3D::GB_BB3D()
@brief	Standardconstructor
**/
//==================================================================
GB_BB3D::GB_BB3D()
{
	for (int i = 0; i < sizeof(cornerstones_); i++)
	{
		cornerstones_[i].x = 0.0f;
		cornerstones_[i].y = 0.0f;
		cornerstones_[i].z = 0.0f;
	}
}

//==================================================================
/**
@fn		GB_BB3D::GB_BB3D(GB_Struct::Vertex * list_vertices)
@brief	Enhanced contructor
**/
//==================================================================
GB_BB3D::GB_BB3D(GB_Struct::Vertex * list_vertices)
{
	float	x_min = 0.0f, x_max = 0.0f, 
			y_min = 0.0f, y_max = 0.0f, 
			z_min = 0.0f, z_max = 0.0f;

	for (int i = 0; i < sizeof(list_vertices); i++)
	{
		if (x_min > list_vertices[i].x) x_min = list_vertices[i].x;
		if (x_max > list_vertices[i].x) x_max = list_vertices[i].x;
		if (y_min > list_vertices[i].y) y_min = list_vertices[i].y;
		if (y_max > list_vertices[i].y) y_max = list_vertices[i].y;
		if (z_min > list_vertices[i].z) z_min = list_vertices[i].z;
		if (z_max > list_vertices[i].z) z_max = list_vertices[i].z;
	}

}

//==================================================================
/**
@fn		GB_BB3D::InitializeBB(GB_Struct::Vertex * list_vertices)
@brief	Initialize bounding box
**/
//==================================================================
void GB_BB3D::InitializeBB(GB_Struct::Vertex * list_vertices)
{

}

//==================================================================
/**
@fn		GB_BB3D::Draw()
@brief	Draw bounding box
**/
//==================================================================
void GB_BB3D::Draw()
{

}