// Object_intro.cpp : Defines the initialization routines for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "Project6.h"

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

void CProject6App::listObjects()
{
	// Get the current database
	AcDbDatabase* pDb = acdbHostApplicationServices()->workingDatabase();
	// Get the current space object
	AcDbBlockTableRecord* pBlockTableRecord;
	Acad::ErrorStatus es = acdbOpenObject(pBlockTableRecord,
		pDb->currentSpaceId(),
		AcDb::kForRead);
	// Create a new block iterator that will be used to
	// step through each object in the current space
	AcDbBlockTableRecordIterator* pItr;
	pBlockTableRecord->newIterator(pItr);
	// Create a variable AcDbEntity type which is a generic
	// object to represent a Line, Circle, Arc, among other objects
	AcDbEntity* pEnt;
	// Step through each object in the current space
	for (pItr->start(); !pItr->done(); pItr->step())
	{
		// Get the entity and open it for read
		pItr->getEntity(pEnt, AcDb::kForRead);
		// Display the class name for the entity before
		// closing the object
		acutPrintf(_T("\nClass name: %s"), pEnt->isA()->name());
		pEnt->close();
	}
	// Close the current space object
	pBlockTableRecord->close();
	// Remove the block iterator object from memory
	delete pItr;
	// Display the AutoCAD Text Window
	acedTextScr();
}


extern "C"
int acrxEntryPoint(AcRx::AppMsgCode Msg, void* pkt) {
	switch (Msg) {
	case AcRx::kInitAppMsg:
		acrxUnlockApplication(pkt);
		acrxRegisterAppMDIAware(pkt);
		acutPrintf(L"\n Command Loaded");
		//below line for registering new command
		acedRegCmds->addCommand(_T("AUCommands"), _T("ListObjects"), _T("ListObjects"), ACRX_CMD_MODAL, &CProject6App::listObjects);
		break;
	case AcRx::kUnloadAppMsg:
		acutPrintf(_T("\n Command Unloaded"));
		break;
	}
	return AcRx::kRetOK;

}


// CObjectintroApp

BEGIN_MESSAGE_MAP(CProject6App, CWinApp)
END_MESSAGE_MAP()


// CObjectintroApp construction

CProject6App::CProject6App()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only CObjectintroApp object

CProject6App theApp;


// CObjectintroApp initialization

BOOL CProject6App::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}