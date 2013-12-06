/**
	@file	GB_MeshLoader.cpp
	@brief	This file includes all functions of GB_MeshLoader 
			class
	@author	drubner
	@date	Created 2013-07-31
**/
//==================================================================
//	Include
//==================================================================
//#include "GooseBerry.h"
#include "GB_MeshLoader.h"

//==================================================================
//	Functions
//==================================================================
/**
		@fn		GB_MeshLoader::LoadObj(std::string file)
		@brief	Fuction to load and *.obj file
**/
//==================================================================
GB_Mesh GB_MeshLoader::LoadObj(std::string file, bool is_quad)
{
	GB_Mesh model;

	if(is_quad)
		model.is_triangle_	= FALSE;

	std::ifstream file_stream;
	file_stream.open(file);

	if(file_stream.is_open())
	{
		GB_LINFO("Count properties of GB_Object file: " + file);
	
		model.obj_file_		= file;
		model.obj_name_		= GB_Func::ExtractName(file); 
		model.mat_path_		= GB_Func::ExtractName(file);

		std::string buffer, temp, GB_Array[4];
		while(!file_stream.eof())
		{
			ZeroMemory(&buffer, sizeof(std::string));
			std::getline(file_stream, buffer);
			std::istringstream line(buffer);

			if(strncmp("v ", buffer.c_str(), 2) == 0)
				model.num_vertices_++;
			else if(strncmp("vt ", buffer.c_str(), 3) == 0)
				model.num_tex_coords_++;
			else if(strncmp("n ", buffer.c_str(), 3) == 0)
				model.num_normals_++;
			else if(strncmp("f ", buffer.c_str(), 2) == 0)
				model.num_faces_++;
		}

		file_stream.close();

		model.faces_		= new GB_Struct::Face[model.num_faces_];
		model.vertices_		= new GB_Struct::Vertex[model.num_vertices_];
		model.normals_		= new GB_Struct::Normal[model.num_normals_];
		model.tex_coords_	= new GB_Struct::TexCoord[model.num_tex_coords_];

		file_stream.open(file);
		file_stream.clear();
		if(file_stream.is_open())
		{
			GB_LINFO("Parse GB_Object file: " + file);
			
			char * token	= "/";
			bool has_mat	= false;
			for(int v = 0, n = 0, t = 0, f = 0; !file_stream.eof();)
			{
				ZeroMemory(&buffer, sizeof(std::string));
				std::getline(file_stream, buffer);
				std::istringstream line(buffer);
				temp = GB_Array[0] = GB_Array[1] = GB_Array[2] = GB_Array[3] = "NULL";

				if(strncmp("mtllib ", buffer.c_str(), 7) == 0)
				{
					line >> temp >> GB_Array[0];
					model.mtl_lib_	= GB_Array[0];
					has_mat = true;
					continue;
				}
				else if(strncmp("usemtl ", buffer.c_str(), 7) == 0)
				{
					line >> temp >> GB_Array[0];
					model.mtl_use_	= GB_Array[0];
					continue;
				}
				else if(strncmp("v ", buffer.c_str(), 2) == 0)
				{
					line >> temp >> GB_Array[0] >> GB_Array[1] >> GB_Array[2];
					model.vertices_[v].x	= (float)atof(GB_Array[0].c_str());
					model.vertices_[v].y	= (float)atof(GB_Array[1].c_str());
					model.vertices_[v].z	= (float)atof(GB_Array[2].c_str());
					v++;
					continue;
				}
				else if(strncmp("vt ", buffer.c_str(), 3) == 0)
				{
					line >> temp >> GB_Array[0] >> GB_Array[1];
					model.tex_coords_[t].u	= (float)atof(GB_Array[0].c_str());
					model.tex_coords_[t].v	= (float)atof(GB_Array[1].c_str());
					t++;
					continue;
				}
				else if(strncmp("n ", buffer.c_str(), 3) == 0)
				{
					line >> temp >> GB_Array[0] >> GB_Array[1] >> GB_Array[2];
					model.normals_[n].x	= (float)atof(GB_Array[0].c_str());
					model.normals_[n].y	= (float)atof(GB_Array[1].c_str());
					model.normals_[n].z	= (float)atof(GB_Array[2].c_str());
					n++;
					continue;
				}
				else if(strncmp("f ", buffer.c_str(), 2) == 0)
				{
					if(model.num_tex_coords_ == 0)
						token			= "//";

					line >> temp >> GB_Array[0] >> GB_Array[1] >> GB_Array[2] >> GB_Array[3];
					std::vector<std::string> strings;
					GB_Func::SplitString(GB_Array[0], strings, token);

					model.faces_[f].vertex[0]		= atoi(strings[0].c_str());
					model.faces_[f].texcoord[0]	= atoi(strings[1].c_str());
					model.faces_[f].normal[0]		= atoi(strings[2].c_str());

					strings.clear();
					GB_Func::SplitString(GB_Array[1], strings, token);
					model.faces_[f].vertex[1]		= atoi(strings[0].c_str());
					model.faces_[f].texcoord[1]	= atoi(strings[1].c_str());
					model.faces_[f].normal[1]		= atoi(strings[2].c_str());

					strings.clear();
					GB_Func::SplitString(GB_Array[2], strings, token);
					model.faces_[f].vertex[2]		= atoi(strings[0].c_str());
					model.faces_[f].texcoord[2]	= atoi(strings[1].c_str());
					model.faces_[f].normal[2]		= atoi(strings[2].c_str());

					if(strcmp("NULL", GB_Array[3].c_str()) == 0)
						model.is_triangle_	= TRUE;
					else
					{
						model.is_triangle_	= FALSE;
						
						strings.clear();
						GB_Func::SplitString(GB_Array[3], strings, token);
						model.faces_[f].vertex[3]		= atoi(strings[0].c_str());
						model.faces_[f].texcoord[3]	= atoi(strings[1].c_str());
						model.faces_[f].normal[3]		= atoi(strings[2].c_str());
					}

					f++;
				}
			}

			file_stream.close();

			/*
			if(has_mat)
			{
				MaterialLoader tMatLoader;
				model.material_ = tMatLoader.fLoadMat(model.mat_path_ + model.mtl_lib_);
			}
			*/
			/*
			glGenBuffers(1, &model.v_ertexID);
			glBindBuffer(GL_GB_Array_BUFFER, model.v_ertexID);
			glBufferData(GL_GB_Array_BUFFER, model.num_vertices_ * sizeof(grVertex), model.vertices_, GL_STATIC_DRAW);

			glGenBuffers(1, &model.mIndexID);
			glBindBuffer(GL_ELEMENT_GB_Array_BUFFER, model.mIndexID);
			glBufferData(GL_ELEMENT_GB_Array_BUFFER, model.num_faces_ * sizeof(grFace), model.faces_, GL_STATIC_DRAW);
			*/ 
		}
		else // \todo include define error str and id
			GB_LERROR("Error while counting properties of file: " + file, "GB_MeshLoader Error");
	}
	else // \todo include define error str and id
		GB_LERROR("Error while open file: " + file, "GB_MeshLoader Error");

	return model;
}
//==================================================================