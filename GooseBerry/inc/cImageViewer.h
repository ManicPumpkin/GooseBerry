//==================================================================
/**
	@file	cImageViewer.h
	@brief	This file includes the image viewer class
	@author	marco
	@date 2013-01-06
**/
//==================================================================
//	PRAGMA
//==================================================================
#pragma once
//==================================================================
//	INCLUDE
//==================================================================
#include "hLibraries.h"
//==================================================================
//	NAMESPACES
//==================================================================
using namespace System;
using namespace System::Drawing;
using namespace System::Collections;
using namespace System::ComponentModel;
using namespace System::Windows::Forms;
//==================================================================
/**
		@class	cImageViewer
		@brief	Renders current camera position to image viewer
**/
//==================================================================
ref class cImageViewer : System::Windows::Forms::Form
{
	protected:
	private:
		//  Variables
		//  Functions
		//  Get
	public:
		//Variables
		Graphics ^ mRenderedImage;
		//	(De-)Constructor
		cImageViewer();
		~cImageViewer();
	
		//  Functions
		//  Get
		//  Set
};
//==================================================================