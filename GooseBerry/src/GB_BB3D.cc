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
	centre_.x	= 0.0f;
	centre_.y	= 0.0f;
	centre_.z	= 0.0f;

	corner_max_	= NULL;
	corner_min_	= NULL;
}

//==================================================================
/**
@fn		GB_BB3D::GB_BB3D(GB_Struct::Vertex * list_vertices)
@brief	Enhanced contructor
**/
//==================================================================
GB_BB3D::GB_BB3D(GB_Struct::Vertex * list_vertices)
{
	InitializeBB(list_vertices);
}

//==================================================================
/**
@fn		GB_BB3D::GB_BB3D(GB_Struct::Vertex * list_vertices, int num_vertices)
@brief	Enhanced contructor
**/
//==================================================================
GB_BB3D::GB_BB3D(GB_Struct::Vertex * list_vertices, int num_vertices)
{
	InitializeBB(list_vertices, num_vertices);
}

//==================================================================
/**
@fn		GB_BB3D::InitializeBB(GB_Struct::Vertex * list_vertices)
@brief	Initialize bounding box
**/
//==================================================================
// \todo test function and add function without pointer
void GB_BB3D::InitializeBB(GB_Struct::Vertex * list_vertices)
{
	float	x_min = 0.0f, x_max = 0.0f,
			y_min = 0.0f, y_max = 0.0f,
			z_min = 0.0f, z_max = 0.0f;

	for (int i = 0; i < (sizeof(list_vertices) / sizeof(list_vertices[0])); i++)
	{
		if (x_min > list_vertices[i].x) x_min = list_vertices[i].x;
		if (x_max < list_vertices[i].x) x_max = list_vertices[i].x;
		if (y_min > list_vertices[i].y) y_min = list_vertices[i].y;
		if (y_max < list_vertices[i].y) y_max = list_vertices[i].y;
		if (z_min > list_vertices[i].z) z_min = list_vertices[i].z;
		if (z_max < list_vertices[i].z) z_max = list_vertices[i].z;
	}

	centre_.x = x_max - x_min;
	centre_.y = y_max - y_min;
	centre_.z = z_max - z_min;

	corner_min_ = new GB_Vector3(x_min, y_min, z_min);
	corner_max_ = new GB_Vector3(x_max, y_max, z_max);
}

//==================================================================
/**
@fn		void InitializeBB(GB_Struct::Vertex * list_vertices, int num_vertices)
@brief	Initialize bounding box
**/
//==================================================================
void GB_BB3D::InitializeBB(GB_Struct::Vertex * list_vertices, int num_vertices)
{
	float	x_min = 0.0f, x_max = 0.0f,
			y_min = 0.0f, y_max = 0.0f,
			z_min = 0.0f, z_max = 0.0f;

	for (int i = 0; i < num_vertices; i++)
	{
		if (x_min > list_vertices[i].x) x_min = list_vertices[i].x;
		if (x_max < list_vertices[i].x) x_max = list_vertices[i].x;
		if (y_min > list_vertices[i].y) y_min = list_vertices[i].y;
		if (y_max < list_vertices[i].y) y_max = list_vertices[i].y;
		if (z_min > list_vertices[i].z) z_min = list_vertices[i].z;
		if (z_max < list_vertices[i].z) z_max = list_vertices[i].z;
	}

	centre_.x	= x_max - x_min;
	centre_.y	= y_max - y_min;
	centre_.z	= z_max - z_min;

	corner_min_	= new GB_Vector3(x_min, y_min, z_min);
	corner_max_	= new GB_Vector3(x_max, y_max, z_max);
}

//==================================================================
/**
@fn		GB_BB3D::Draw()
@brief	Draw bounding box
**/
//==================================================================
void GB_BB3D::Draw()
{
	if (GB_Settings::BoundingBox::g_show)
	{
		glEnable(GL_LINE_SMOOTH);
		glLineWidth(GB_Settings::BoundingBox::g_line_width);
		glColor3f(	GB_Settings::BoundingBox::g_line_color[0],
					GB_Settings::BoundingBox::g_line_color[1],
					GB_Settings::BoundingBox::g_line_color[2]	);
		glBegin(GL_LINE_LOOP);
		glVertex3f(corner_min_->x_, corner_min_->y_, corner_min_->z_);
		glVertex3f(corner_max_->x_, corner_min_->y_, corner_min_->z_);
		glVertex3f(corner_max_->x_, corner_max_->y_, corner_min_->z_);
		glVertex3f(corner_min_->x_, corner_max_->y_, corner_min_->z_);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glVertex3f(corner_min_->x_, corner_min_->y_, corner_max_->z_);
		glVertex3f(corner_max_->x_, corner_min_->y_, corner_max_->z_);
		glVertex3f(corner_max_->x_, corner_max_->y_, corner_max_->z_);
		glVertex3f(corner_min_->x_, corner_max_->y_, corner_max_->z_);
		glEnd();
		glBegin(GL_LINES);
		glVertex3f(corner_min_->x_, corner_min_->y_, corner_min_->z_);
		glVertex3f(corner_min_->x_, corner_min_->y_, corner_max_->z_);
		glVertex3f(corner_max_->x_, corner_min_->y_, corner_min_->z_);
		glVertex3f(corner_max_->x_, corner_min_->y_, corner_max_->z_);
		glVertex3f(corner_max_->x_, corner_max_->y_, corner_min_->z_);
		glVertex3f(corner_max_->x_, corner_max_->y_, corner_max_->z_);
		glVertex3f(corner_min_->x_, corner_max_->y_, corner_min_->z_);
		glVertex3f(corner_min_->x_, corner_max_->y_, corner_max_->z_);
		glEnd();
	}
}