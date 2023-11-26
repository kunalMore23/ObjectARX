// Project10.h : main header file for the Project10 DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CProject10App
// See Project10.cpp for the implementation of this class
//

class CProject10App : public CWinApp
{
public:
	CProject10App();

// Overrides
public:
	virtual BOOL InitInstance();
	static void addLine();

	DECLARE_MESSAGE_MAP()
};
