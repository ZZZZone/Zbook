// ZbookDlg.h : header file
//

#if !defined(AFX_ZBOOKDLG_H__84FF9E2B_F08F_402A_96DB_8454F2F461EA__INCLUDED_)
#define AFX_ZBOOKDLG_H__84FF9E2B_F08F_402A_96DB_8454F2F461EA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CZbookDlg dialog

class CZbookDlg : public CDialog
{
// Construction
public:
	int m_nowpos;
	CZbookDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CZbookDlg)
	enum { IDD = IDD_ZBOOK_DIALOG };
	CEdit	m_Info;
	CComboBox	m_Flist;
	CListCtrl	m_list;
	CString	m_Fname;
	CString	m_Ftel;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CZbookDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CZbookDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonAdd();
	afx_msg void OnButtonDel();
	afx_msg void OnButtonChange();
	afx_msg void OnButtonFind();
	afx_msg void OnSelchangeListTot();
	afx_msg void OnClickListTot(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnChangeEDITSinfo();
	afx_msg void OnButtonShow();
	afx_msg void OnButtonSave();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ZBOOKDLG_H__84FF9E2B_F08F_402A_96DB_8454F2F461EA__INCLUDED_)
