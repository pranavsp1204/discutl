
// discutl.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols
#include "string.h"

// CdiscutlApp:
// See discutl.cpp for the implementation of this class
//

class CdiscutlApp : public CWinApp
{
public:
	CdiscutlApp();
	// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CdiscutlApp theApp;
