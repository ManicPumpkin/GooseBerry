//==================================================================
/**
@file	GB_TextureManager.cc
@brief	This file includes all functions of GB_TextureManager class
@author	drubner
@date	2014-05-23
**/
//==================================================================
//	INCLUDE
//==================================================================
#include "GB_TextureManager.h"

//==================================================================
//	INITIALIZE
//==================================================================
GB_TextureManager* GB_TextureManager::instance_ = 0;

//==================================================================
//	FUNCTIONS
//==================================================================
/**
@fn		GB_TextureManager::GB_TextureManager()
@brief	Standardconstructor
**/
//==================================================================
GB_TextureManager::GB_TextureManager()
{
	num_textures_		= 0;
	available_space_	= 0;
	textures_			= 0;
}

//==================================================================
/**
@fn		GB_TextureManager::Initialize()
@brief	Initialize texture manager
**/
//==================================================================
void GB_TextureManager::Initialize()
{
	GB_LDEBUG("Texture manager initialized");

	instance_->num_textures_		= 0;
	instance_->available_space_		= 0;
	instance_->textures_			= new int[TEXMANAGER_INIT_SIZE];

	for (int i = 0; i < instance_->available_space_; i++)
		instance_->textures_[i]		= -1;
}

//==================================================================
/**
@fn		GB_TextureManager::Destroy()
@brief	Destroy texture manager
**/
//==================================================================
void GB_TextureManager::Destroy()
{
	GB_LDEBUG("Texture manager destroyed");

	if (instance_)
	{
		delete[] instance_->textures_;
		instance_->textures_	= NULL;

		delete instance_;
		instance_				= NULL;
	}
}

//==================================================================
/**
@fn		GB_TextureManager::LoadTexture(const char *filename, int id = -1);
@brief	Load new texture
@return int		id of texture
**/
//==================================================================
int GB_TextureManager::LoadTexture(const char *filename, int id)
{
	unsigned char * pixel_data	= NULL;
	int tex_width, tex_height, tex_n;
	GB_Loader::LoadTextureFile(filename, pixel_data, &tex_width, &tex_height, &tex_n);

	int texture_id = GetNewTextureId();
	glBindTexture(GL_TEXTURE_2D, texture_id);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, tex_width, tex_height, 0, GL_RGB, GL_UNSIGNED_BYTE, pixel_data);
	
	stbi_image_free(pixel_data);
	return texture_id;
}

//==================================================================
/**
@fn		GB_TextureManager::LoadTextureFromMemory()
@brief	Get texture from memory
@return	int		id of texture
**/
//==================================================================
int GB_TextureManager::LoadTextureFromMemory()
{
	return 0;
}

//==================================================================
/**
@fn		GB_TextureManager::FreeTexture(int id)
@brief	Delete texture of id
**/
//==================================================================
void GB_TextureManager::FreeTexture(int id)
{
	int index	= -1;
	for (int i = 0; i < instance_->available_space_; i++)
	{
		if (instance_->textures_[i] == id)
		{
			instance_->textures_[i] = -1;
			index = i;
			break;
		}
	}

	if (index != -1)
	{
		unsigned int u_id = (unsigned int) id;
		glDeleteTextures(1, &u_id);
	}
}

//==================================================================
/**
@fn		GB_TextureManager::FreeAllTextures()
@brief	Delete all textures
**/
//==================================================================
void GB_TextureManager::FreeAllTextures()
{
	unsigned int *u_ids = new unsigned int[instance_->num_textures_];
	for (int i = 0, j = 0; i < instance_->num_textures_; i++)
		if (instance_->textures_[i] != -1)
			u_ids[j++] = instance_->textures_[i];

	glDeleteTextures(instance_->num_textures_, u_ids);

	delete[] u_ids;
	delete[] instance_->textures_;

	instance_->textures_		= new int[TEXMANAGER_INIT_SIZE];
	instance_->available_space_ = TEXMANAGER_INIT_SIZE;
	instance_->num_textures_	= 0;
	for (int i = 0; i < TEXMANAGER_INIT_SIZE; i++)
		instance_->textures_[i] = -1;
}

//==================================================================
/**
@fn		GB_TextureManager::GetNewTextureId()
@brief	Delete all textures
@retrun	int		new id
**/
//==================================================================
int GB_TextureManager::GetNewTextureId()
{
	int				texture_id;
	unsigned int	temp_id;
	glGenTextures(1, &temp_id);
	texture_id = (int)temp_id;

	int index = 0;
	while (instance_->textures_[index] != -1 && index < instance_->available_space_)
		index++;

	if (index >= instance_->available_space_)
	{
		int* new_ids	= new int[instance_->available_space_ + TEXMANAGER_STEP];

		for (int i = 0; i < instance_->available_space_; i++)
			new_ids[i] = instance_->textures_[i];		

		for (int i = 1; i < TEXMANAGER_STEP; i++)
			new_ids[i + instance_->available_space_] = -1;

		new_ids[instance_->available_space_] = texture_id;
		instance_->available_space_ += TEXMANAGER_STEP;
		delete[] instance_->textures_;
		instance_->textures_ = new_ids;
	}
	else
		instance_->textures_[index]		= texture_id;

	instance_->num_textures_++;
	return texture_id;
}