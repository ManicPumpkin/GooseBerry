//==================================================================
/**
@file	GB_MeshSimple.cpp
@brief	This file includes all functions of GB_MeshSimple class
@author	drubner
@date	2014-03-31
**/
//==================================================================
//	INCLUDE
//==================================================================
#include "GB_MeshSimple.h"

//==================================================================
//	STATIC EXTERN SIMPLE MESHES
//==================================================================
GB_MeshSimple GB_SimpleMeshes::gbCube = GB_MeshLoader::GetInstance()->LoadObj(".\\dta\\cube.obj");

//==================================================================
//	FUNCTIONS
//==================================================================
/**
@fn		GB_MeshSimple::~GB_MeshSimple()
@brief	Standarddeconstructor
**/
//==================================================================
GB_MeshSimple::~GB_MeshSimple()
{
}

//==================================================================
/**
@fn		GB_MeshSimple::GB_MeshSimple()
@brief	Standardconstructor
**/
//==================================================================
GB_MeshSimple :: GB_MeshSimple()
{
	obj_name_		= "NULL";
	obj_file_		= "NULL";
	is_triangle_	= NULL;
	faces_			= NULL;
	vertices_		= NULL;
	normals_		= NULL;
	tex_coords_		= NULL;
}

//==================================================================
/**
@fn		GB_MeshSimple::GB_MeshSimple(std::string obj_name, bool is_triangle, 
			GB_Struct::Face& faces, GB_Struct::Vertex& vertices,
			GB_Struct::Normal& normals, GB_Struct::TexCoord& tex_coords)
@brief	Standardconstructor
@param	obj_name	name of mesh
@param	is_triangle	triangle or quad
@param	faces		faces list of mesh
@param	vertices	vertices list of mesh
@param	normals		normals list of mesh
@param	tex_coords	texture coordiantes of mesh
**/
//==================================================================
GB_MeshSimple :: GB_MeshSimple(	std::string obj_name, bool is_triangle,
								GB_Struct::Face& faces, GB_Struct::Vertex& vertices,
								GB_Struct::Normal& normals, GB_Struct::TexCoord& tex_coords)
{
	obj_name_		= obj_name;
	is_triangle_	= is_triangle;
	faces_			= &faces;
	vertices_		= &vertices;
	normals_		= &normals;
	tex_coords_		= &tex_coords;

	obj_file_		= "NULL";
}

//==================================================================
/**
@fn		GB_MeshSimple::GB_MeshSimple(const GB_Mesh & right)
@brief	copy constructor for deep copy (GB_Mesh to GB_MeshSimple)

Deep copy an GB_Mesh with GB_MeshSimple.
**/
//==================================================================
GB_MeshSimple::GB_MeshSimple(const GB_Mesh & right)
{
	this->obj_name_ = right.obj_name_;
	this->obj_file_ = right.obj_file_;
	this->mtl_lib_ = right.mtl_lib_;
	this->mtl_use_ = right.mtl_use_;
	this->is_triangle_ = right.is_triangle_;
	this->num_faces_ = right.num_faces_;
	this->num_vertices_ = right.num_vertices_;
	this->num_normals_ = right.num_normals_;
	this->num_tex_coords_ = right.num_tex_coords_;
	//this->material_		= right.material_;

	faces_ = new GB_Struct::Face[num_faces_];
	vertices_ = new GB_Struct::Vertex[num_vertices_];
	normals_ = new GB_Struct::Normal[num_normals_];
	tex_coords_ = new GB_Struct::TexCoord[num_tex_coords_];

	for (unsigned int tI = 0; tI < num_faces_; tI++)
	{
		for (int tJ = 0; tJ < 4; tJ++)
		{
			faces_[tI].vertex[tJ] = right.faces_[tI].vertex[tJ];
			faces_[tI].normal[tJ] = right.faces_[tI].normal[tJ];
			faces_[tI].texcoord[tJ] = right.faces_[tI].texcoord[tJ];
		}
	}

	for (unsigned int tI = 0; tI < num_vertices_; tI++)
	{
		vertices_[tI].x = right.vertices_[tI].x;
		vertices_[tI].y = right.vertices_[tI].y;
		vertices_[tI].z = right.vertices_[tI].z;
	}

	for (unsigned int tI = 0; tI < num_normals_; tI++)
	{
		normals_[tI].x = right.normals_[tI].x;
		normals_[tI].y = right.normals_[tI].y;
		normals_[tI].z = right.normals_[tI].z;
	}

	for (unsigned int tI = 0; tI < num_tex_coords_; tI++)
	{
		tex_coords_[tI].u = right.tex_coords_[tI].u;
		tex_coords_[tI].v = right.tex_coords_[tI].v;
	}
}
