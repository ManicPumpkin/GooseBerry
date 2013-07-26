//==================================================================
/**
		@file	cMatLoader.cpp
		@brief	This file includes all functions of cMatLoader class
		@author	drubner
		@date	2012-12-02
**/
//==================================================================
//	Include
//==================================================================
#include "hGlobal.h"
//==================================================================
#include "cMatLoader.h"
#include "cMat.h"
//==================================================================
//	Functions
//==================================================================
/**
		@fn		cMatLoader :: fLoadMat(std::string pFile)
		@brief	copy constructor for deep copy
		@param	pFile string to material file
		@return	cMat return loaded mat object
**/
//==================================================================
cMat cMatLoader :: fLoadMat(std::string pFile)
{
	cMat tMat(pFile);

	std::ifstream tFileStream;
	tFileStream.open(pFile);

	if(tFileStream.is_open())
	{
		cGlobal::gLog("Load properties of material file: " + pFile, "\t\t");
	
		std::string tBuffer, tTemp, tArr[4];
		for(; !tFileStream.eof(); )
		{
			ZeroMemory(&tBuffer, sizeof(std::string));
			std::getline(tFileStream, tBuffer);
			std::istringstream tLine(tBuffer);
			//tTemp = tArr[0] = tArr[1] = tArr[2] = tArr[3] = "NULL";

			if(strncmp("Kd ", tBuffer.c_str(), 3) == 0)
			{
				// Kd = diffuse color
				tLine >> tTemp >> (float)tMat.mDiffuse[0] >> (float)tMat.mDiffuse[1] >> (float)tMat.mDiffuse[2];
				tMat.mDiffuse[3]	= 1.0f;
				tMat.mHasDiffuse	= true;
				continue;
			}
			else if(strncmp("Ka ", tBuffer.c_str(), 3) == 0)
			{
				// Ka = ambient color
				tLine >> tTemp >> (float)tMat.mAmbient[0] >> (float)tMat.mAmbient[1] >> (float)tMat.mAmbient[2];
				tMat.mAmbient[3]	= 1.0f;
				tMat.mHasAmbient	= true;
				continue;
			}
			else if(strncmp("Ks ", tBuffer.c_str(), 3) == 0)
			{
				// Ks = specular color
				tLine >> tTemp >> (float)tMat.mSpecular[0] >> (float)tMat.mSpecular[1] >> (float)tMat.mSpecular[2];
				tMat.mHasSpecular	= true;
				continue;
			}
			else if(strncmp("Tf ", tBuffer.c_str(), 3) == 0)
			{
				// \todo Tf = transmission filter
				continue;
			}
			else if(strncmp("Ni ", tBuffer.c_str(), 3) == 0)
			{
				// \todo Ni = optical density
				continue;
			}
			else if(strncmp("illum ", tBuffer.c_str(), 6) == 0)
			{
				// \todo illum = illumination model
				// source: paulbourke.net/dataformats/mtl
				continue;
			}
		}

		tFileStream.close();
	}
	else
		cGlobal::gLog("Error while open file: " + pFile);

	return tMat;
}
//==================================================================