// CCustomQueryDlg.cpp : implementation file
//

#include "pch.h"
#include "database-odbc-gui-project.h"
#include "afxdialogex.h"
#include "CCustomQueryDlg.h"


// CCustomQueryDlg dialog

IMPLEMENT_DYNAMIC(CCustomQueryDlg, CDialog)

CCustomQueryDlg::CCustomQueryDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_CUSTOM_QUERY, pParent)
{

}

CCustomQueryDlg::~CCustomQueryDlg()
{
}

void CCustomQueryDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_QUERY, m_editQuery);
	DDX_Control(pDX, IDC_BUTTON_QUERY, m_buttonQuery);
	DDX_Control(pDX, IDC_LIST_RESULT, m_listResult);
}


BEGIN_MESSAGE_MAP(CCustomQueryDlg, CDialog)
END_MESSAGE_MAP()


// CCustomQueryDlg message handlers
