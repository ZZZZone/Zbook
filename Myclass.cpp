// Myclass.cpp : implementation file
//

#include "stdafx.h"
#include "zbook.h"
#include "Myclass.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Myclass

IMPLEMENT_DYNAMIC(Myclass, CColorDialog)

Myclass::Myclass(COLORREF clrInit, DWORD dwFlags, CWnd* pParentWnd) :
	CColorDialog(clrInit, dwFlags, pParentWnd)
{
}

BEGIN_MESSAGE_MAP(Myclass, CColorDialog)
	//{{AFX_MSG_MAP(Myclass)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()



int Myclass::CheckIn(CString s)
{
	CString t;
	for(int i = 0; i <= m_tot; i++)
		if(s == People[i].Number) return i;
	return -1;
}

void Myclass::Readbook()
{
	CStdioFile file;
	CString str;
	file.Open("test.txt", CFile::modeRead);
	int now = 0;
	while (file.ReadString(str) != NULL)
	{
		int i;
		if(now == 0) {
			m_tot++;
			People[m_tot].Name = str;
		}
		else if(now == 1) People[m_tot].Number = str;
		else if(now == 2) People[m_tot].E_mail = str;
		else if(now == 3){
			int x = People[m_tot].group_index = _ttoi(str);
			if(x == 0) People[m_tot].Group =  "无";
			else if(x == 1) People[m_tot].Group = "家人";
			else if(x == 2) People[m_tot].Group = "同事";
			else if(x == 3) People[m_tot].Group =  "朋友";
		}
		else if(now == 4) People[m_tot].Information =str;
		now++; now %= 5;
	}
}
