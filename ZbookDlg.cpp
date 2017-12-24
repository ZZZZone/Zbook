// ZbookDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Zbook.h"
#include "ZbookDlg.h"
#include "ADD.h"
#include "Mod.h"
#include "Myclass.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CZbookDlg dialog

CZbookDlg::CZbookDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CZbookDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CZbookDlg)
	m_Fname = _T("");
	m_Ftel = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CZbookDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CZbookDlg)
	DDX_Control(pDX, IDC_EDIT_Sinfo, m_Info);
	DDX_Control(pDX, IDC_COMBO_Fgroup, m_Flist);
	DDX_Control(pDX, IDC_LIST_TOT, m_list);
	DDX_Text(pDX, IDC_EDIT_Fname, m_Fname);
	DDV_MaxChars(pDX, m_Fname, 20);
	DDX_Text(pDX, IDC_EDIT_Ftel, m_Ftel);
	DDV_MaxChars(pDX, m_Ftel, 20);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CZbookDlg, CDialog)
	//{{AFX_MSG_MAP(CZbookDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_ADD, OnButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_DEL, OnButtonDel)
	ON_BN_CLICKED(IDC_BUTTON_CHANGE, OnButtonChange)
	ON_BN_CLICKED(IDC_BUTTON_FIND, OnButtonFind)
	ON_LBN_SELCHANGE(IDC_LIST_TOT, OnSelchangeListTot)
	ON_NOTIFY(NM_CLICK, IDC_LIST_TOT, OnClickListTot)
	ON_EN_CHANGE(IDC_EDIT_Sinfo, OnChangeEDITSinfo)
	ON_BN_CLICKED(IDC_BUTTON_SHOW, OnButtonShow)
	ON_BN_CLICKED(IDC_BUTTON_SAVE, OnButtonSave)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CZbookDlg message handlers

BOOL CZbookDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	// Add "About..." menu item to system menu.
	CListCtrl* pmyListCtrl = (CListCtrl*)GetDlgItem(IDC_LIST_TOT); //��ȡ�б�ؼ�
	DWORD dwStyle = GetWindowLong(pmyListCtrl->m_hWnd, GWL_STYLE);
	SetWindowLong( pmyListCtrl->m_hWnd, GWL_STYLE, dwStyle | LVS_REPORT);
	DWORD styles = pmyListCtrl->GetExtendedStyle(); 
    pmyListCtrl->SetExtendedStyle(styles|LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);//����listctrl��������ѡ�����������
	CRect rect;
    pmyListCtrl->GetWindowRect(&rect);
	m_list.InsertColumn(0,"����",LVCFMT_CENTER,rect.Width()/6);//������
	m_list.InsertColumn(1,"�绰",LVCFMT_CENTER,rect.Width()/6*2);
	m_list.InsertColumn(2,"����",LVCFMT_CENTER,rect.Width()/6*2);
	m_list.InsertColumn(3,"����",LVCFMT_CENTER,rect.Width()/6);
	///////////////�������б�Ի����ʼ��////////////////
	 ///////////////////�������б��ȡ///////////////////
	m_Flist.SetCurSel(0);//��ʼ������ѡ����������Ĭ��ѡ�
	GetDlgItem(IDC_BUTTON_DEL)-> EnableWindow(FALSE); //��ʼ��û��ѡ������ �����޸ģ� ����ɾ��
	GetDlgItem(IDC_BUTTON_CHANGE)-> EnableWindow(FALSE);
	m_nowpos = 1;
	People[0].Readbook();
	q_tot = -1; int i;
	for(i = 0; i <= m_tot; i++) que[++q_tot] = i;
	for(i = 0; i <= q_tot; i++){
		int pos = que[i];
		CString strout;
		m_list.InsertItem(pos, People[pos].Name);
		m_list.SetItemText(pos, 1, People[pos].Number);
		m_list.SetItemText(pos, 2, People[pos].E_mail);
		m_list.SetItemText(pos, 3, People[pos].Group);
	}
	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);
	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}
	
	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CZbookDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CZbookDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CZbookDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CZbookDlg::OnButtonAdd() 
{
	ADD dlg;
	if(IDOK == dlg.DoModal()){
		m_tot++;
		int i;
		CString str;
		int nHeadNum = m_list.GetItemCount();//��ȡ��ǰ����  �����ϵ�˵��б�
		str = dlg.m_Aname;//���� 
		str.TrimLeft(); str.TrimRight();
		People[m_tot].Name = str;
		str = dlg.m_Atel;//�绰
		str.TrimLeft(); str.TrimRight();
		People[m_tot].Number = str;
		str = dlg.m_Amail;//����
		str.TrimLeft(); str.TrimRight();
		People[m_tot].E_mail = str;
		str = dlg.m_Ainfo;//��ע
		People[m_tot].Information = str;
		People[m_tot].group_index = dlg.addgroup_index;// ����
		if(dlg.addgroup_index == 0) str = "��";
		else if(dlg.addgroup_index == 1) str = "����";
		else if(dlg.addgroup_index == 2) str = "ͬ��";
		else if(dlg.addgroup_index == 3) str = "����";
		People[m_tot].Group = str;
		while(m_list.DeleteItem(0));
		q_tot = -1;
		for(i = 0; i <= m_tot; i++) que[++q_tot] = i;
		for(i = 0; i <= q_tot; i++){
			int pos = que[i];
			m_list.InsertItem(i, People[pos].Name);
			m_list.SetItemText(i, 1, People[pos].Number);
			m_list.SetItemText(i, 2, People[pos].E_mail);
			m_list.SetItemText(i, 3, People[pos].Group);
		}
	}

	// TODO: Add your control notification handler code here	
}

void CZbookDlg::OnButtonDel() 
{
	CString check;
	int nItem = -1, i;
	// TODO: Add your control notification handler code here
	while(m_list.GetNextItem(-1,LVNI_ALL | LVNI_SELECTED) != -1){ 
		nItem = m_list.GetNextItem(-1,LVNI_ALL | LVNI_SELECTED);
	}
	if(nItem == -1){ MessageBox("��ѡ��Ҫɾ������ϵ��"); }
	else{
		m_list.DeleteItem(nItem);
		int pos = que[nItem];
		for(i = pos; i < m_tot; i++){ //ʵ�������ɾ��
			//People[i] = People[i+1];
			People[i].Name = People[i+1].Name;
			People[i].Number = People[i+1].Number;
			People[i].E_mail = People[i+1].E_mail;
			People[i].Information = People[i+1].Information;
			People[i].Group = People[i+1].Group;
			People[i].group_index = People[i+1].group_index;
		}
		for(i = nItem; i < q_tot; i++) que[i] = que[i+1]-1;
		m_tot--; q_tot--;
	}
	GetDlgItem(IDC_BUTTON_DEL)-> EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_CHANGE)-> EnableWindow(FALSE);
}

void CZbookDlg::OnButtonChange() 
{
	Mod dlg;
	int nlist = -1;
	while(m_list.GetNextItem(-1,LVNI_ALL | LVNI_SELECTED) != -1){
		nlist = m_list.GetNextItem(-1,LVNI_ALL | LVNI_SELECTED);
	}
	if(nlist == -1) MessageBox("��ѡ��Ҫ�޸ĵ���ϵ��");
	else{
	//int nlist = m_list.GetNextItem(-1, LVNI_SELECTED); //����б��ѡ���λ��
	int real_pos = que[nlist];
	dlg.m_Mname = People[real_pos].Name;
	dlg.m_Mtel = People[real_pos].Number;
	dlg.m_Mmail = People[real_pos].E_mail;
	dlg.m_Minfo = People[real_pos].Information;
	dlg.m_Mgroup_index = People[real_pos].group_index;
	dlg.mod_pos = real_pos;
	if(IDOK == dlg.DoModal()){
		m_list.DeleteItem(nlist);
		CString str; int i;
		str = dlg.m_Mname;//���� 
		str.TrimLeft(); str.TrimRight();
		m_list.InsertItem(nlist, str);
		People[real_pos].Name = str;
		str = dlg.m_Mtel;// �绰
		str.TrimLeft(); str.TrimRight();
		m_list.SetItemText(nlist, 1, str);
		People[real_pos].Number = str;
		str = dlg.m_Mmail;//  ����
		str.TrimLeft(); str.TrimRight();
		m_list.SetItemText(nlist, 2, str);
		People[real_pos].E_mail = str;
		str = dlg.m_Minfo;// ��ע
		str.TrimLeft(); str.TrimRight();
		People[real_pos].Information = str;
		People[real_pos].group_index = dlg.m_Mgroup_index;// ����
		if(dlg.m_Mgroup_index == 0) str = "��";
		else if(dlg.m_Mgroup_index == 1) str = "����";
		else if(dlg.m_Mgroup_index == 2) str = "ͬ��";
		else if(dlg.m_Mgroup_index == 3) str = "����";
		People[real_pos].Group = str;
		m_list.SetItemText(nlist, 3, str);
	}
	}
	GetDlgItem(IDC_BUTTON_DEL)-> EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_CHANGE)-> EnableWindow(FALSE);
}

void CZbookDlg::OnButtonFind() 
{
	UpdateData(TRUE);
	Myclass Sfind;
	CString str; int i;
	bool ok1 = false, ok2 = false, ok3 = false;
	str = m_Fname;
	str.TrimLeft(); str.TrimRight();
	Sfind.Name = str;
	if(str.IsEmpty()) ok1 = true;
	str = m_Ftel;
	str.TrimLeft(); str.TrimRight();
	Sfind.Number = str;
	if(str.IsEmpty()) ok2 = true;
	Sfind.group_index = m_Flist.GetCurSel(); 
	if(Sfind.group_index == 0) ok3 = true;
	if(ok1 && ok2 && ok3){
		MessageBox("����д������Ϣ");
	}
	else{
		int i;
		q_tot = -1;
		CString s1, s2, check;
		for(i = 0; i <= m_tot; i++){
			if(Sfind.group_index != 0 && Sfind.group_index != (People[i].group_index+1)) continue;
			s1 = Sfind.Name; s2 = People[i].Name;
			if(!s1.IsEmpty() && s2.Find(s1) == -1) continue;
			s1 = Sfind.Number; s2 = People[i].Number;
			if(!s1.IsEmpty() && s2.Find(s1) == -1) continue;
			que[++q_tot] = i;
		}
		check.Format("���鵽%d����ϵ��", q_tot+1);
		MessageBox(check); //��ɾ����ǰ�б����ʾ����Ϣ
		while(m_list.DeleteItem(0));
		for(i = 0; i <= q_tot; i++){
			int pos = que[i];
			m_list.InsertItem(i, People[pos].Name);
			m_list.SetItemText(i, 1, People[pos].Number);
			m_list.SetItemText(i, 2, People[pos].E_mail);
			m_list.SetItemText(i, 3, People[pos].Group);
		}
		GetDlgItem(IDC_BUTTON_DEL)-> EnableWindow(TRUE);
		GetDlgItem(IDC_BUTTON_CHANGE)-> EnableWindow(TRUE);
	}
	// TODO: Add your control notification handler code here
	
}


void CZbookDlg::OnSelchangeListTot() 
{ 
	// TODO: Add your control notification handler code here
	
}

void CZbookDlg::OnClickListTot(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	DWORD dwPos = GetMessagePos();//ͨ���鿴���λ�� ȷ���޸ĺ�ɾ����ť�Ƿ�ɵ㡣
	CPoint point( LOWORD(dwPos), HIWORD(dwPos) );
	m_list.ScreenToClient(&point);
    LVHITTESTINFO lvinfo;
    lvinfo.pt = point;
    lvinfo.flags = LVHT_ABOVE;
    int nItem = m_list.SubItemHitTest(&lvinfo);
    if(nItem != -1)
    {
		m_Info.SetWindowText(People[que[lvinfo.iItem]].Information);// �ڱ�ע����ʾ�����Ϣ
		UpdateData(FALSE);
		GetDlgItem(IDC_BUTTON_DEL)-> EnableWindow(TRUE);
		GetDlgItem(IDC_BUTTON_CHANGE)-> EnableWindow(TRUE);
    }
	else{
		GetDlgItem(IDC_BUTTON_DEL)-> EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON_CHANGE)-> EnableWindow(FALSE);
	}
	*pResult = 0;
}

void CZbookDlg::OnChangeEDITSinfo() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	// TODO: Add your control notification handler code here IDC_EDIT_Sinfo
	
}




void CZbookDlg::OnButtonShow() 
{
	while(m_list.DeleteItem(0));
	q_tot = -1;
	int i;
	for(i = 0; i <= m_tot; i++) que[++q_tot] = i;
	for(i = 0; i <= q_tot; i++){
		int pos = que[i];
		m_list.InsertItem(i, People[pos].Name);
		m_list.SetItemText(i, 1, People[pos].Number);
		m_list.SetItemText(i, 2, People[pos].E_mail);
		m_list.SetItemText(i, 3, People[pos].Group);
	}
	m_Fname.Format("");
	m_Ftel.Format("");
	m_Flist.SetCurSel(0);
	UpdateData(FALSE);
	// TODO: Add your control notification handler code here
}

void CZbookDlg::OnButtonSave() 
{
	CStdioFile file;
	file.Open("test.txt",CFile::modeCreate|CFile::modeWrite);
	CString str, tmp;
	tmp.Format("\n");
	for(int i = 0; i <= m_tot; i++){
		str = People[i].Name + tmp; file.WriteString(str);
		str = People[i].Number + tmp; file.WriteString(str);
		str = People[i].E_mail + tmp; file.WriteString(str);
		str.Format("%d\n", People[i].group_index); file.WriteString(str);
		str = People[i].Information + tmp; file.WriteString(str);
	}
	MessageBox("����ɹ�");
	// TODO: Add your control notification handler code here
	
}
