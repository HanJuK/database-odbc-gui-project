// CSchemaCheckDlg.cpp : implementation file
//

#include "pch.h"
#include "database-odbc-gui-project.h"
#include "afxdialogex.h"
#include "CSchemaCheckDlg.h"


// CSchemaCheckDlg dialog

IMPLEMENT_DYNAMIC(CSchemaCheckDlg, CDialog)

CSchemaCheckDlg::CSchemaCheckDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_SCHEMA_CHECK, pParent)
{

}

CSchemaCheckDlg::~CSchemaCheckDlg()
{
}

void CSchemaCheckDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSchemaCheckDlg, CDialog)
END_MESSAGE_MAP()


// CSchemaCheckDlg message handlers
