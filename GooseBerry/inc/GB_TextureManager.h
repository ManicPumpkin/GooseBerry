//==================================================================
/**
@file	GB_TextureManager.h
@brief	This file includes the GB_TextureManager class
@author	drubner
@date	2014-05-23
**/
//==================================================================
#pragma once

//==================================================================
//	DEFINE
//==================================================================
#define TEXMANAGER				GB_TextureManager::GetInstance()
#define TEXMANAGER_INIT_SIZE	16
#define TEXMANAGER_STEP			8

//==================================================================
//	CLASS
//==================================================================
/**
@class	GB_TextureManager
@brief	Contains information about textures and manage them
**/
//==================================================================
class GOOSEBERRY_API GB_TextureManager
{
	protected:
	private:
		//	Variables
		static	GB_TextureManager* instance_;
		int		num_textures_;
		int		available_space_;
		int*	textures_;

		//	Functions
		static void Initialize();
		static void Destroy();

		//	Get&Set
		int GetNewTextureId();

		//	(Standard-/Copy-/De-)Constructor
		GB_TextureManager();
		GB_TextureManager(const GB_TextureManager&){}
		~GB_TextureManager(){}

	public:
		//	Funtctions
		GB_Enum::gbResult	LoadTexture(const char *filename, int * texture_nr);
		int					LoadTextureFromMemory(/*UBYTE *data, int width, int height, int bpp, int id = -1*/);
		void				FreeTexture(int id);
		void				FreeAllTextures();

		//	Get&Set
		static GB_TextureManager* GetInstance()
		{
			if (instance_ == NULL)
			{
				instance_ = new GB_TextureManager();
				Initialize();
			}

			return instance_;
		}

		int GetNumTextures()	{	return num_textures_;		}
		int GetAvailableSpace()	{	return available_space_;	}
		int GetTexId(int index)	{	return (index >= 0 && index < instance_->available_space_) ? textures_[index] : 0;	}

};
