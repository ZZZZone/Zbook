#if !defined(AFX_ADD_H__87383C4B_9F54_45D0_A2C9_D146622D4994__INCLUDED_)
#define AFX_ADD_H__87383C4B_9F54_45D0_A2C9_D146622D4994__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ADD.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// ADD dialog

class ADD : public CDialog
{
// Construction
public:
	int addgroup_index;
	ADD(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(ADD)
	enum { IDD = IDD_DIALOGADD };
	CComboBox	m_addgroup;
	CString	m_Aname;
	CString	m_Atel;
	CString	m_Amail;
	CString	m_Ainfo;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ADD)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(ADD)
	virtual void OnCancel();
	afx_msg void OnAdd();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADD_H__87383C4B_9F54_45D0_A2C9_D146622D4994__INCLUDED_)
