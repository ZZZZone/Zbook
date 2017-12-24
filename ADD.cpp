// ADD.cpp : implementation file
//

#include "stdafx.h"
#include "zbook.h"
#include "ADD.h"
#include "Myclass.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// ADD dialog


ADD::ADD(CWnd* pParent /*=NULL*/)
	: CDialog(ADD::IDD, pParent)
{
	//{{AFX_DATA_INIT(ADD)
	m_Aname = _T("");
	m_Atel = _T("");
	m_Amail = _T("");
	m_Ainfo = _T("");
	//}}AFX_DATA_INIT
}


void ADD::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ADD)
	DDX_Control(pDX, IDC_COMBO_AGroup, m_addgroup);
	DDX_Text(pDX, IDC_EDIT_AName, m_Aname);
	DDV_MaxChars(pDX, m_Aname, 20);
	DDX_Text(pDX, IDC_EDIT_ATel, m_Atel);
	DDV_MaxChars(pDX, m_Atel, 20);
	DDX_Text(pDX, IDC_EDIT_AMail, m_Amail);
	DDV_MaxChars(pDX, m_Amail, 30);
	DDX_Text(pDX, IDC_EDIT_AInfo, m_Ainfo);
	DDV_MaxChars(pDX, m_Ainfo, 500);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(ADD, CDialog)
	//{{AFX_MSG_MAP(ADD)
	ON_BN_CLICKED(IDAdd, OnAdd)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ADD message handlers


void ADD::OnCancel() 
{
	// TODO: Add extra cleanup here
	CDialog::OnCancel();
}

void ADD::OnAdd() 
{
	UpdateData(TRUE);
	bool flag = true;
	CString str;
	str = m_Aname; // 处理空信息
	str.TrimLeft(); str.TrimRight();
	if(str.IsEmpty()) flag = false;
	str= m_Amail;
	str.TrimLeft(); str.TrimRight();
	if(str.IsEmpty()) flag = false;
	str = m_Atel;
	str.TrimLeft(); str.TrimRight();
	if(str.IsEmpty()) flag = false;
	if(!flag) { MessageBox("添加联系人信息不能为空"); }
	else if(People[0].CheckIn(str) != -1){
		MessageBox("改电话已存在,请勿重复添加");
	}
	else{
		addgroup_index = m_addgroup.GetCurSel();
		CDialog::OnOK();
	}
	// TODO: Add your control notification handler code here
	
}

BOOL ADD::OnInitDialog() 
{
	CDialog::OnInitDialog();
	// TODO: Add extra initialization here
	//UPDATE(TRUE);
	GetDlgItem(IDC_EDIT_AInfo)->SetWindowText("无");
	m_addgroup.SetCurSel(0);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
