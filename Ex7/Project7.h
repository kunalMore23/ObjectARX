// Project7.h : main header file for the Project7 DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CProject7App
// See Project7.cpp for the implementation of this class
//

class CProject7App : public CWinApp
{
public:
	CProject7App();

// Overrides
public:
	virtual BOOL InitInstance();
	static void inputLine();

	DECLARE_MESSAGE_MAP()
};
