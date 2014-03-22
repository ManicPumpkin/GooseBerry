//==================================================================
/**
		@file	cImageViewer.cpp
		@brief	This file includes all functions of image viewer 
				class
		@author	marco
		@date	2012-12-07
**/
//==================================================================
//	Include
//==================================================================
#include "cImageViewer.h"
#include "hGlobal.h"
//==================================================================
//	(De-)Constructor
//==================================================================
/**
	@fn		cImageViewer :: cImageViewer
	@brief	Standard constructor initializes windows form
**/
//==================================================================
cImageViewer::cImageViewer()
{
	cGlobal::gLog("Create ImageViewer Window", "\t");

	this->ResumeLayout();

	/*
	NOTE:
	use for example following:
		mRenderedImage->FillRectangle(gcnew SolidBrush(Color::FromArgb(50, 60, 70)), 100, 200, 1, 1);
	to set the pixel at position x=100, y=200, to the color red=50, green=60, blue =70
	*/
}
//==================================================================
/**
	@fn		cImageViewer :: ~cImageViewer
	@brief	frees memory
**/
//==================================================================
cImageViewer::~cImageViewer()
{
}
//==================================================================
//	Functions
//==================================================================
