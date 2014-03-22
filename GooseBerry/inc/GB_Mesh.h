//==================================================================
/**
	@file	GB_Mesh.h
	@brief	This file includes the GB_Object which been loaded from
			GB_MeshLoader

	Includes the model class. Contains all variables needed to
	hold loaded information of GB_Object/model files.

	@author	drubner
	@date	2013-07-31
**/
//==================================================================
#pragma once
#pragma warning(disable: 4251)

//==================================================================
//	INCLUDE
//==================================================================
#include "GooseBerry.h"
//#include "Material.h"

//==================================================================
//	CLASS
//==================================================================
/**
	@class	GB_Mesh
	@brief	Contains information about GB_Object/model files
**/
//==================================================================
class GOOSEBERRY_API GB_Mesh
{
	protected:
	private:
		//	Variables
		//	Functions
		VOID FreeMdl();
		
	public:
		//	Variables
		std::string				obj_name_;	//!< GB_Object name
		std::string				obj_file_;	//!< GB_Object file
		std::string				mat_path_;	//!< material file path
		std::string				mtl_lib_;	//!< material lib to use
		std::string				mtl_use_;	//!< material to use
		Material 	material_;	//!< material

		bool			is_triangle_;		//!< if object is made of triangles, else quads 

		unsigned int	num_faces_,			//!< number of faces
						num_vertices_,		//!< number of vertices
						num_normals_,		//!< number of normals
						num_tex_coords_;	//!< number of texture coordinates
		
		GB_Struct::Face *	faces_;				//!< list of faces
		GB_Struct::Vertex *	vertices_;			//!< list of vetices
		GB_Struct::Normal *	normals_;			//!< list of normals
		GB_Struct::TexCoord *	tex_coords_;	//!< list of texture coordiantes

		//	(De-)Constructor & Copy
		~GB_Mesh();
		GB_Mesh();
		GB_Mesh(const GB_Mesh & right);

		//	Functions
		VOID Draw();

		//	Get
		//	Set
};