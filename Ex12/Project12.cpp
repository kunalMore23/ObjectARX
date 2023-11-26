// Object_intro.cpp : Defines the initialization routines for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "Project12.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include <tchar.h>
#include "rxregsvc.h"
#include "acutads.h"
#include "accmd.h"
#pragma comment(linker,"/EXPORT:acrxEntryPoint")
#pragma comment(linker,"/EXPORT:acrxGetApiVersion")

#include "rxregsvc.h"
#include "acutads.h"
#include "aced.h"
#include "acdb.h"
#include <Windows.h>
#include <string.h>
#include <stdlib.h>
#include <aced.h>
#include <dbents.h>
#include <dbsymtb.h>
#include <adslib.h>
#include <geassign.h>
#include <dbidmap.h>
#include <dbapserv.h>
#include <acgi.h>
#include "tchar.h"
#include "dbents.h"
#include "acedCmdNF.h"


void CProject12App::userInfo()
{
	// Request the user's age
	int nAge = 0;
	acedGetInt(_T("\nEnter your age: "), &nAge);
	// Request the user's name
	TCHAR cName[30];

	acedGetString(NULL, _T("\nEnter your name: "), cName);
	// Specify the insertion point for the first single line text object
	ads_point pt;
	acedGetPoint(NULL, _T("\nSpecify insertion point: "), pt);
	// Convert the entered age from an Integer to a character array
	TCHAR cAge[33];
	_itot_s(nAge, cAge, 10);
	// Build the string for the first text object
	TCHAR cVal1[512];
	_tcscpy_s(cVal1, _T("Age: "));
	_tcscat_s(cVal1, cAge);
	// Build the string for the second text object
	TCHAR cVal2[512];
	_tcscpy_s(cVal2, _T("Name: "));
	_tcscat_s(cVal2, cName);
	// Get the current database
	AcDbDatabase* pDb = acdbHostApplicationServices()->workingDatabase();
	// Get the current space object
	AcDbBlockTableRecord* pBlockTableRecord;
	Acad::ErrorStatus es = acdbOpenObject(pBlockTableRecord,
		pDb->currentSpaceId(), AcDb::kForWrite);
	if (es == Acad::eOk)
	{
		AcGePoint3d ptIns(pt[0], pt[1], pt[2]);
		// Create the first text object at a height of 3.5
		AcDbText* pText1 = new AcDbText(ptIns, cVal1);
		pText1->setHeight(3.5);
		// Define the insertion point for the second text object
		ptIns.y = ptIns.y - 5;
		// Create the second text object at a height of 3.5
		AcDbText* pText2 = new AcDbText(ptIns, cVal2);
		pText2->setHeight(3.5);
		// Create a new ObjectId for the new Text objects
		AcDbObjectId text1Id, text2Id;
		// Add the new Text objects to the current space
		pBlockTableRecord->appendAcDbEntity(text1Id, pText1);
		pBlockTableRecord->appendAcDbEntity(text2Id, pText2);
		// Close the current space block
		pBlockTableRecord->close();

		// Close the new text objects
		pText1->close();
		pText2->close();
	}
	else {
		acutPrintf(_T("\nERROR: Block could not be opened for write."));
	}
}

int acrxEntryPoint(AcRx::AppMsgCode Msg, void* pkt) {
	switch (Msg) {
	case AcRx::kInitAppMsg:
		acrxUnlockApplication(pkt);
		acrxRegisterAppMDIAware(pkt);
		acutPrintf(L"\n Command Loaded");
		//below line for registering new command
		acedRegCmds->addCommand(_T("AUCommands"), _T("UserInfo "), _T("UserInfo"), ACRX_CMD_MODAL, &CProject12App::userInfo);
		break;
	case AcRx::kUnloadAppMsg:
		acutPrintf(_T("\n Command Unloaded"));
		break;
	}
	return AcRx::kRetOK;

}

// CObjectintroApp

BEGIN_MESSAGE_MAP(CProject12App, CWinApp)
END_MESSAGE_MAP()


// CObjectintroApp construction

CProject12App::CProject12App()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

// The one and only CObjectintroApp object

CProject12App theApp;


// CObjectintroApp initialization

BOOL CProject12App::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}