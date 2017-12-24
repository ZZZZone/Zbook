// Mod.cpp : implementation file
//

#include "stdafx.h"
#include "zbook.h"
#include "Mod.h"
#include "Myclass.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Mod dialog


Mod::Mod(CWnd* pParent /*=NULL*/)
	: CDialog(Mod::IDD, pParent)
{
	//{{AFX_DATA_INIT(Mod)
	m_Minfo = _T("");
	m_Mmail = _T("");
	m_Mname = _T("");
	m_Mtel = _T("");
	//}}AFX_DATA_INIT
}


void Mod::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Mod)
	DDX_Control(pDX, IDC_COMBO_CGroup, m_Mgroup);
	DDX_Text(pDX, IDC_EDIT_CInfo, m_Minfo);
	DDV_MaxChars(pDX, m_Minfo, 500);
	DDX_Text(pDX, IDC_EDIT_CMail, m_Mmail);
	DDV_MaxChars(pDX, m_Mmail, 30);
	DDX_Text(pDX, IDC_EDIT_CName, m_Mname);
	DDV_MaxChars(pDX, m_Mname, 20);
	DDX_Text(pDX, IDC_EDIT_CTel, m_Mtel);
	DDV_MaxChars(pDX, m_Mtel, 20);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Mod, CDialog)
	//{{AFX_MSG_MAP(Mod)
	ON_BN_CLICKED(IDCANCEL2, OnCancel2)
	ON_BN_CLICKED(IDMod, OnMod)
	ON_CBN_EDITCHANGE(IDC_COMBO_CGroup, OnEditchangeCOMBOCGroup)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Mod message handlers


void Mod::OnCancel2() 
{
	// TODO: Add your control notification handler code here
	CDialog::OnCancel();
}

void Mod::OnMod() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	CString str = m_Mtel;
	int find_pos = People[0].CheckIn(str);
	if(find_pos != -1 && find_pos != mod_pos){
		MessageBox("该电话以存在,请勿重复添加");
	}else{
		m_Mgroup_index = m_Mgroup.GetCurSel(); 
		CDialog::OnOK();
	}
}

BOOL Mod::OnInitDialog() 
{
	CDialog::OnInitDialog();
	m_Mgroup.SetCurSel(m_Mgroup_index);
	// TODO: Add extra initialization here
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void Mod::OnEditchangeCOMBOCGroup() 
{
	// TODO: Add your control notification handler code here
	
}
