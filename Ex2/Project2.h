// Project2.h : main header file for the Project2 DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CProject2App
// See Project2.cpp for the implementation of this class
//

class CProject2App : public CWinApp
{
public:
	CProject2App();

// Overrides
public:
	virtual BOOL InitInstance();
	static void MyCommand();

	DECLARE_MESSAGE_MAP()
};
