// Project4.h : main header file for the Project4 DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CProject4App
// See Project4.cpp for the implementation of this class
//

class CProject4App : public CWinApp
{
public:
	CProject4App();

// Overrides
public:
	virtual BOOL InitInstance();
	static void addLine();

	DECLARE_MESSAGE_MAP()
};
