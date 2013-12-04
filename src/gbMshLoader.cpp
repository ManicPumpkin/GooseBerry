/**
	@file	gbMshLoader.cpp
	@brief	This file includes all functions of gbMshLoader 
			class
	@author	drubner
	@date	Created 2013-07-31
**/
//==================================================================
//	Include
//==================================================================
//#include "GooseBerry.h"
#include "gbMshLoader.h"
//#include "gbMsh.h"

//==================================================================
//	Functions
//==================================================================
/**
		@fn		gbMshLoader::fLoadObj(std::string pFile)
		@brief	Fuction to load and *.obj file
**/
//==================================================================
gbMsh gbMshLoader::fLoadObj(std::string pFile, bool pIsQuad)
{
	gbMsh tModel;

	if(pIsQuad)
		tModel.mIsTriangle	= FALSE;

	std::ifstream tFileStream;
	tFileStream.open(pFile);

	if(tFileStream.is_open())
	{
		GB_LINFO("Count properties of object file: " + pFile);
	
		tModel.mObjFile			= pFile;
		tModel.mObjName			= ExtractName(pFile); 
		tModel.mMatPath			= ExtractName(pFile);

		std::string tBuffer, tTemp, tArr[4];
		while(!tFileStream.eof())
		{
			ZeroMemory(&tBuffer, sizeof(std::string));
			std::getline(tFileStream, tBuffer);
			std::istringstream tLine(tBuffer);

			if(strncmp("v ", tBuffer.c_str(), 2) == 0)
				tModel.mNuv_ertices++;
			else if(strncmp("vt ", tBuffer.c_str(), 3) == 0)
				tModel.mNumTexCoords++;
			else if(strncmp("vn ", tBuffer.c_str(), 3) == 0)
				tModel.mNumNormals++;
			else if(strncmp("f ", tBuffer.c_str(), 2) == 0)
				tModel.mNumFaces++;
		}

		tFileStream.close();

		tModel.mFaces		= new gb_g_face[tModel.mNumFaces];
		tModel.v_ertices	= new gb_g_vertex[tModel.mNuv_ertices];
		tModel.mNormals		= new gb_g_normal[tModel.mNumNormals];
		tModel.mTexCoords	= new gb_g_texCoord[tModel.mNumTexCoords];

		tFileStream.open(pFile);
		tFileStream.clear();
		if(tFileStream.is_open())
		{
			GB_LINFO("Parse object file: " + pFile);
			
			char * tToken	= "/";
			bool tHasMat	= false;
			for(int tV = 0, tVN = 0, tT = 0, tF = 0; !tFileStream.eof();)
			{
				ZeroMemory(&tBuffer, sizeof(std::string));
				std::getline(tFileStream, tBuffer);
				std::istringstream tLine(tBuffer);
				tTemp = tArr[0] = tArr[1] = tArr[2] = tArr[3] = "NULL";

				if(strncmp("mtllib ", tBuffer.c_str(), 7) == 0)
				{
					tLine >> tTemp >> tArr[0];
					tModel.mMtllib	= tArr[0];
					tHasMat = true;
					continue;
				}
				else if(strncmp("usemtl ", tBuffer.c_str(), 7) == 0)
				{
					tLine >> tTemp >> tArr[0];
					tModel.u_semtl	= tArr[0];
					continue;
				}
				else if(strncmp("v ", tBuffer.c_str(), 2) == 0)
				{
					tLine >> tTemp >> tArr[0] >> tArr[1] >> tArr[2];
					tModel.v_ertices[tV].x	= (float)atof(tArr[0].c_str());
					tModel.v_ertices[tV].y	= (float)atof(tArr[1].c_str());
					tModel.v_ertices[tV].z	= (float)atof(tArr[2].c_str());
					tV++;
					continue;
				}
				else if(strncmp("vt ", tBuffer.c_str(), 3) == 0)
				{
					tLine >> tTemp >> tArr[0] >> tArr[1];
					tModel.mTexCoords[tT].u	= (float)atof(tArr[0].c_str());
					tModel.mTexCoords[tT].v	= (float)atof(tArr[1].c_str());
					tT++;
					continue;
				}
				else if(strncmp("vn ", tBuffer.c_str(), 3) == 0)
				{
					tLine >> tTemp >> tArr[0] >> tArr[1] >> tArr[2];
					tModel.mNormals[tVN].x	= (float)atof(tArr[0].c_str());
					tModel.mNormals[tVN].y	= (float)atof(tArr[1].c_str());
					tModel.mNormals[tVN].z	= (float)atof(tArr[2].c_str());
					tVN++;
					continue;
				}
				else if(strncmp("f ", tBuffer.c_str(), 2) == 0)
				{
					if(tModel.mNumTexCoords == 0)
						tToken			= "//";

					tLine >> tTemp >> tArr[0] >> tArr[1] >> tArr[2] >> tArr[3];
					std::vector<std::string> tStrings;
					SplitString(tArr[0], tStrings, tToken);

					tModel.mFaces[tF].vertex[0]		= atoi(tStrings[0].c_str());
					tModel.mFaces[tF].texcoord[0]	= atoi(tStrings[1].c_str());
					tModel.mFaces[tF].normal[0]		= atoi(tStrings[2].c_str());

					tStrings.clear();
					SplitString(tArr[1], tStrings, tToken);
					tModel.mFaces[tF].vertex[1]		= atoi(tStrings[0].c_str());
					tModel.mFaces[tF].texcoord[1]	= atoi(tStrings[1].c_str());
					tModel.mFaces[tF].normal[1]		= atoi(tStrings[2].c_str());

					tStrings.clear();
					SplitString(tArr[2], tStrings, tToken);
					tModel.mFaces[tF].vertex[2]		= atoi(tStrings[0].c_str());
					tModel.mFaces[tF].texcoord[2]	= atoi(tStrings[1].c_str());
					tModel.mFaces[tF].normal[2]		= atoi(tStrings[2].c_str());

					if(strcmp("NULL", tArr[3].c_str()) == 0)
						tModel.mIsTriangle	= TRUE;
					else
					{
						tModel.mIsTriangle	= FALSE;
						
						tStrings.clear();
						SplitString(tArr[3], tStrings, tToken);
						tModel.mFaces[tF].vertex[3]		= atoi(tStrings[0].c_str());
						tModel.mFaces[tF].texcoord[3]	= atoi(tStrings[1].c_str());
						tModel.mFaces[tF].normal[3]		= atoi(tStrings[2].c_str());
					}

					tF++;
				}
			}

			tFileStream.close();

			/*
			if(tHasMat)
			{
				gbMatLoader tMatLoader;
				tModel.mMaterial = tMatLoader.fLoadMat(tModel.mMatPath + tModel.mMtllib);
			}
			*/
			/*
			glGenBuffers(1, &tModel.v_ertexID);
			glBindBuffer(GL_ARRAY_BUFFER, tModel.v_ertexID);
			glBufferData(GL_ARRAY_BUFFER, tModel.mNuv_ertices * sizeof(grVertex), tModel.v_ertices, GL_STATIC_DRAW);

			glGenBuffers(1, &tModel.mIndexID);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, tModel.mIndexID);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, tModel.mNumFaces * sizeof(grFace), tModel.mFaces, GL_STATIC_DRAW);
			*/ 
		}
		else // \todo include define error str and id
			GB_LERROR("Error while counting properties of file: " + pFile, "gbMshLoader Error");
	}
	else // \todo include define error str and id
		GB_LERROR("Error while open file: " + pFile, "gbMshLoader Error");

	return tModel;
}
//==================================================================