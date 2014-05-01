//==================================================================
/**
		@file	GB_Mesh.cpp
		@brief	This file includes all functions of GB_Mesh class
		@author	drubner
		@date	2013-07-31
**/
//==================================================================
//	INCLUDE
//==================================================================
#include "GB_Mesh.h"

//==================================================================
//	FUNCTIONS
//==================================================================
/**
		@fn		GB_Mesh::GB_Mesh()
		@brief	Standardconstructor
**/
//==================================================================
GB_Mesh :: GB_Mesh()
{
	num_vertices_	= 0;
	num_normals_	= 0;
	num_tex_coords_	= 0;
	num_faces_		= 0;
	is_triangle_	= TRUE;
	faces_			= NULL;
	vertices_		= NULL;
	normals_		= NULL;
	tex_coords_		= NULL;
}

//==================================================================
/**
		@fn		GB_Mesh::GB_Mesh(const GB_Mesh& right)
		@brief	copy constructor for deep coy

		Deep copy an GB_Mesh GB_Object with another.
**/
//==================================================================
GB_Mesh :: GB_Mesh(const GB_Mesh & right)
{
	this->msh_name_			= right.msh_name_;
	this->msh_file_			= right.msh_file_;
	this->msh_path_			= right.msh_path_;
	this->mtl_lib_			= right.mtl_lib_;
	this->mtl_use_			= right.mtl_use_;
	this->is_triangle_		= right.is_triangle_;
	this->num_faces_		= right.num_faces_;
	this->num_vertices_		= right.num_vertices_;
	this->num_normals_		= right.num_normals_;
	this->num_tex_coords_	= right.num_tex_coords_;

	faces_		= new GB_Struct::Face[num_faces_];
	vertices_	= new GB_Struct::Vertex[num_vertices_];
	normals_	= new GB_Struct::Normal[num_normals_];
	tex_coords_ = new GB_Struct::TexCoord[num_tex_coords_];

	for(unsigned int tI = 0; tI < num_faces_; tI++)
	{
		for(int tJ = 0; tJ < 4; tJ++)
		{
			faces_[tI].vertex[tJ]	= right.faces_[tI].vertex[tJ];
			faces_[tI].normal[tJ]	= right.faces_[tI].normal[tJ];
			faces_[tI].texcoord[tJ]	= right.faces_[tI].texcoord[tJ];
		}
	}

	for(unsigned int tI = 0; tI < num_vertices_; tI++)
	{
		vertices_[tI].x	= right.vertices_[tI].x;
		vertices_[tI].y	= right.vertices_[tI].y;
		vertices_[tI].z	= right.vertices_[tI].z;
	}

	for(unsigned int tI = 0; tI < num_normals_; tI++)
	{
		normals_[tI].x	= right.normals_[tI].x;
		normals_[tI].y	= right.normals_[tI].y;
		normals_[tI].z	= right.normals_[tI].z;
	}

	for(unsigned int tI = 0; tI < num_tex_coords_; tI++)
	{
		tex_coords_[tI].u	= right.tex_coords_[tI].u;
		tex_coords_[tI].v	= right.tex_coords_[tI].v;
	}
}

//==================================================================
/**
@fn		GB_Mesh::operator= (GB_Mesh const& right);
@brief	operator= overload

Copy values of right to current object
**/
//==================================================================
GB_Mesh GB_Mesh::operator= (GB_Mesh const& right)
{
	this->msh_name_			= right.msh_name_;
	this->msh_file_			= right.msh_file_;
	this->msh_path_			= right.msh_path_;
	this->mtl_lib_			= right.mtl_lib_;
	this->mtl_use_			= right.mtl_use_;
	this->is_triangle_		= right.is_triangle_;
	this->num_faces_		= right.num_faces_;
	this->num_vertices_		= right.num_vertices_;
	this->num_normals_		= right.num_normals_;
	this->num_tex_coords_	= right.num_tex_coords_;

	faces_		= new GB_Struct::Face[num_faces_];
	vertices_	= new GB_Struct::Vertex[num_vertices_];
	normals_	= new GB_Struct::Normal[num_normals_];
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

	return *this;
}

//==================================================================
/**
		@fn		GB_Mesh :: ~GB_Mesh
		@brief	Deconstructor calls fFreeMdl method
**/
//==================================================================
GB_Mesh :: ~GB_Mesh()
{
	FreeMdl();
}

//==================================================================
/**
		@fn		GB_Mesh::FreeMdl()
		@brief	Frees space of pointer GB_Arrays and set it to NULL
		@return	VOID
**/
//==================================================================
VOID GB_Mesh :: FreeMdl()
{
	if(faces_)		delete[] faces_;
	if(vertices_)	delete[] vertices_;
	if(normals_)	delete[] normals_;
	if(tex_coords_)	delete[] tex_coords_;

	faces_			= NULL;
	vertices_		= NULL;
	normals_		= NULL;
	tex_coords_		= NULL;
}

//==================================================================
/**
		@fn		GB_Mesh::Draw()
		@brief	Draw GB_Object and material

				Initialize different materials and draw the triangle
				with its normals and vertices.
**/
//==================================================================
VOID GB_Mesh :: Draw()
{
	if (this->is_triangle_)
	{
		glBegin(GL_TRIANGLES);
		for(unsigned int i = 0; i < this->num_faces_; i++)
		{
			for(int j = 0; j < 3; j++)
			{
				glNormal3f
				(
					this->normals_[this->faces_[i].normal[j] - 1].x, 
					this->normals_[this->faces_[i].normal[j] - 1].y, 
					this->normals_[this->faces_[i].normal[j] - 1].z
				);
				glTexCoord2f
				(	
					this->tex_coords_[this->faces_[i].texcoord[j] - 1].u,
					this->tex_coords_[this->faces_[i].texcoord[j] - 1].v		
				);
				glVertex3f
				(
					this->vertices_[this->faces_[i].vertex[j] - 1].x, 
					this->vertices_[this->faces_[i].vertex[j] - 1].y, 
					this->vertices_[this->faces_[i].vertex[j] - 1].z
				);
			}
		}
		glEnd();
	}
	else
	{
		glBegin(GL_QUADS);
		for (unsigned int i = 0; i < this->num_faces_; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				glNormal3f
				(
					this->normals_[this->faces_[i].normal[j] - 1].x,
					this->normals_[this->faces_[i].normal[j] - 1].y,
					this->normals_[this->faces_[i].normal[j] - 1].z
				);
				glTexCoord2f
				(	
					//	invert direction for texture loading from file (*.obj)
					1-this->tex_coords_[this->faces_[i].texcoord[j] - 1].u,
					1-this->tex_coords_[this->faces_[i].texcoord[j] - 1].v		
				);
				glVertex3f
				(
					this->vertices_[this->faces_[i].vertex[j] - 1].x,
					this->vertices_[this->faces_[i].vertex[j] - 1].y,
					this->vertices_[this->faces_[i].vertex[j] - 1].z
				);
			}
		}
		glEnd();
	}

	glEnable(GL_COLOR_MATERIAL);
}
//==================================================================