#if !defined(AFX_MYCLASS_H__7A4BE402_0870_49D5_A9DC_A6D229BF1D98__INCLUDED_)
#define AFX_MYCLASS_H__7A4BE402_0870_49D5_A9DC_A6D229BF1D98__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Myclass.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Myclass dialog

class Myclass : public CColorDialog
{
	DECLARE_DYNAMIC(Myclass)

public:
	void Readbook();
	int CheckIn(CString);
	Myclass(COLORREF clrInit = 0, DWORD dwFlags = 0,
			CWnd* pParentWnd = NULL);
	CString Name;
	CString Number;
	CString E_mail;
	CString Group;
	CString Information;
	int group_index;
protected:
	//{{AFX_MSG(Myclass)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYCLASS_H__7A4BE402_0870_49D5_A9DC_A6D229BF1D98__INCLUDED_)


