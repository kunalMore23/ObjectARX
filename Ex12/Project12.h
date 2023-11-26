// Project12.h : main header file for the Project12 DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CProject12App
// See Project12.cpp for the implementation of this class
//

class CProject12App : public CWinApp
{
public:
	CProject12App();

// Overrides
public:
	virtual BOOL InitInstance();
	static void userInfo();
	DECLARE_MESSAGE_MAP()
};
