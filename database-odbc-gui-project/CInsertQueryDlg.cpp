// CInsertQueryDlg.cpp : implementation file
//

#include "pch.h"
#include "database-odbc-gui-project.h"
#include "afxdialogex.h"
#include "CInsertQueryDlg.h"
#include "CInsertQueryDlgTab1.h"
#include "CInsertQueryDlgTab2.h"


// CInsertQueryDlg dialog

IMPLEMENT_DYNAMIC(CInsertQueryDlg, CDialog)

CInsertQueryDlg::CInsertQueryDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_INSERT_QUERY, pParent)
{

}

CInsertQueryDlg::~CInsertQueryDlg()
{
}

void CInsertQueryDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_tabScenario);
}


BEGIN_MESSAGE_MAP(CInsertQueryDlg, CDialog)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &CInsertQueryDlg::OnTcnSelchangeTab1)
END_MESSAGE_MAP()


// CInsertQueryDlg message handlers

BOOL CInsertQueryDlg::OnInitDialog()
{
	UpdateData(false);

	m_tabScenario.InsertItem(0, _T("Scenario 1"));
	m_tabScenario.InsertItem(1, _T("Scenario 2"));
	m_tabScenario.SetCurSel(0);

	CRect rect;
	m_tabScenario.GetWindowRect(rect);

	p_m_tabScenarioTab1 = new CInsertQueryDlgTab1;
	p_m_tabScenarioTab1->Create(IDD_DIALOG_INSERT_QUERY_TAB1, &m_tabScenario);
	p_m_tabScenarioTab1->MoveWindow(0, 20, rect.Width(), rect.Height());
	p_m_tabScenarioTab1->ShowWindow(SW_SHOW);

	p_m_tabScenarioTab2 = new CInsertQueryDlgTab2;
	p_m_tabScenarioTab2->Create(IDD_DIALOG_INSERT_QUERY_TAB2, &m_tabScenario);
	p_m_tabScenarioTab2->MoveWindow(0, 20, rect.Width(), rect.Height());
	p_m_tabScenarioTab2->ShowWindow(SW_HIDE);

	UpdateData(true);

	return true;
}

void CInsertQueryDlg::OnTcnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult)
{
	int selectedTabIdx = m_tabScenario.GetCurSel();

	switch (selectedTabIdx)
	{
		case 0:
			p_m_tabScenarioTab1->ShowWindow(SW_SHOW);
			p_m_tabScenarioTab2->ShowWindow(SW_HIDE);
			break;
		case 1:
			p_m_tabScenarioTab1->ShowWindow(SW_HIDE);
			p_m_tabScenarioTab2->ShowWindow(SW_SHOW);
			break;
		default:
			break;
			// TODO: 
	}

	*pResult = 0;

	return;
}
