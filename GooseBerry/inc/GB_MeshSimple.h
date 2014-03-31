//==================================================================
/**
@file	GB_MeshSimple.h
@brief	Simple geometrical mesh objects (cube, pyramid, sphere etc.)

Contains simple geometrical mesh objects

@author	drubner
@date	2014-03-31
**/
//==================================================================
#pragma once

//==================================================================
//	INCLUDE
//==================================================================
//#include "GB_Mesh.h"
#include "gooseberry.h"

//==================================================================
//	CLASS
//==================================================================
/**
@class	GB_MeshSimple
@brief	Contains information about simple mesh objects
**/
//==================================================================
class GOOSEBERRY_API GB_MeshSimple : public GB_Mesh
{
	protected:	
	private:
	public:
		//	Variables
		~GB_MeshSimple();
		GB_MeshSimple();
		GB_MeshSimple(const GB_Mesh & right);
		GB_MeshSimple(	std::string obj_name, bool is_triangle, 
			GB_Struct::Face& faces, GB_Struct::Vertex& vertices,
			GB_Struct::Normal& normals, GB_Struct::TexCoord& tex_coords);
};

//==================================================================
//	STATIC SIMPLE MESHES
//==================================================================
namespace GB_SimpleMeshes
{
	GOOSEBERRY_API extern GB_MeshSimple gbCube;
	//GOOSEBERRY_API extern GB_MeshSimple gbPyramid;
	//GOOSEBERRY_API extern GB_MeshSimple gbRamp;
	//GOOSEBERRY_API extern GB_MeshSimple gbThreeVert;
	//GOOSEBERRY_API extern GB_MeshSimple gbOneVert;
}