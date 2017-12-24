// Zbook.h : main header file for the ZBOOK application
//

#if !defined(AFX_ZBOOK_H__502C2D17_0B96_417B_95AB_901384B9DDE9__INCLUDED_)
#define AFX_ZBOOK_H__502C2D17_0B96_417B_95AB_901384B9DDE9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CZbookApp:
// See Zbook.cpp for the implementation of this class
//

class CZbookApp : public CWinApp
{
public:
	CZbookApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CZbookApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CZbookApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ZBOOK_H__502C2D17_0B96_417B_95AB_901384B9DDE9__INCLUDED_)
