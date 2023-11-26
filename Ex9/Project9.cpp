// Object_intro.cpp : Defines the initialization routines for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "Project9.h"

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


void CProject9App::addLine()
{
	// Get the current database 
	AcDbDatabase* pDb = acdbHostApplicationServices()->workingDatabase();
	// Open the Block Table for read-only 
	AcDbBlockTable* pBlockTable;
	pDb->getSymbolTable(pBlockTable, AcDb::kForRead);
	// Get the Model Space block 
	AcDbBlockTableRecord* pBlockTableRecord;
	pBlockTable->getAt(ACDB_MODEL_SPACE,
		pBlockTableRecord, AcDb::kForWrite);
	pBlockTable->close();
	// Define the points that will be used to define the Line object  
	AcGePoint3d startPt(7.0, 3.0, 0.0);
	AcGePoint3d endPt(15.0, 3.0, 0.0);
	// Create the new Line object in memory 
	AcDbLine* pLine = new AcDbLine(startPt, endPt);
	// Add the new Line object to Model space 
	pBlockTableRecord->appendAcDbEntity(pLine);
	// Close the Model space block 
	pBlockTableRecord->close();
	// Close the new line object 
	pLine->close();
}

int acrxEntryPoint(AcRx::AppMsgCode Msg, void* pkt) {
	switch (Msg) {
	case AcRx::kInitAppMsg:
		acrxUnlockApplication(pkt);
		acrxRegisterAppMDIAware(pkt);
		acutPrintf(L"\n Command Loaded");
		//below line for registering new command
		acedRegCmds->addCommand(_T("AUCommands"), _T("AddLine"), _T("AddLine"), ACRX_CMD_MODAL, &CProject9App::addLine);
		break;
	case AcRx::kUnloadAppMsg:
		acutPrintf(_T("\n Command Unloaded"));
		break;
	}
	return AcRx::kRetOK;

}

// CObjectintroApp

BEGIN_MESSAGE_MAP(CProject9App, CWinApp)
END_MESSAGE_MAP()


// CObjectintroApp construction

CProject9App::CProject9App()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only CObjectintroApp object

CProject9App theApp;


// CObjectintroApp initialization

BOOL CProject9App::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}