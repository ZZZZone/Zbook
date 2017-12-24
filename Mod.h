#if !defined(AFX_MOD_H__57F84A0E_BD41_4AEF_9253_438633704C7A__INCLUDED_)
#define AFX_MOD_H__57F84A0E_BD41_4AEF_9253_438633704C7A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Mod.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Mod dialog

class Mod : public CDialog
{
// Construction
public:
	int mod_pos;
//	int m_nowpos;
	int m_Mgroup_index;
	Mod(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Mod)
	enum { IDD = IDD_DIALOGMOD };
	CComboBox	m_Mgroup;
	CString	m_Minfo;
	CString	m_Mmail;
	CString	m_Mname;
	CString	m_Mtel;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Mod)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Mod)
	afx_msg void OnCancel2();
	afx_msg void OnMod();
	virtual BOOL OnInitDialog();
	afx_msg void OnEditchangeCOMBOCGroup();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MOD_H__57F84A0E_BD41_4AEF_9253_438633704C7A__INCLUDED_)
