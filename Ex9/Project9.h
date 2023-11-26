// Project9.h : main header file for the Project9 DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CProject9App
// See Project9.cpp for the implementation of this class
//

class CProject9App : public CWinApp
{
public:
	CProject9App();

// Overrides
public:
	virtual BOOL InitInstance();
	static void addLine();

	DECLARE_MESSAGE_MAP()
};
