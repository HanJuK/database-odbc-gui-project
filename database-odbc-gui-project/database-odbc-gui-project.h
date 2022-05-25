
// database-odbc-gui-project.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CdatabaseodbcguiprojectApp:
// See database-odbc-gui-project.cpp for the implementation of this class
//

class CdatabaseodbcguiprojectApp : public CWinApp
{
public:
	CdatabaseodbcguiprojectApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CdatabaseodbcguiprojectApp theApp;
