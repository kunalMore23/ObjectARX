// Project8.h : main header file for the Project8 DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CProject8App
// See Project8.cpp for the implementation of this class
//

class CProject8App : public CWinApp
{
public:
	CProject8App();

// Overrides
public:
	virtual BOOL InitInstance();
	static void changeColor();

	DECLARE_MESSAGE_MAP()
};
