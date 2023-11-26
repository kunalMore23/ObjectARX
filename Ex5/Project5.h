// Project5.h : main header file for the Project5 DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CProject5App
// See Project5.cpp for the implementation of this class
//

class CProject5App : public CWinApp
{
public:
	CProject5App();

// Overrides
public:
	virtual BOOL InitInstance();
	static void makeLayer();
	DECLARE_MESSAGE_MAP()
};
