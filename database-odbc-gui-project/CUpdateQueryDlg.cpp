// CUpdateQueryDlg.cpp : implementation file
//

#include "pch.h"
#include "database-odbc-gui-project.h"
#include "afxdialogex.h"
#include "CUpdateQueryDlg.h"
#include "CUpdateQueryDlgTab1.h"
#include "CUpdateQueryDlgTab2.h"
#include "CUpdateQueryDlgTab3.h"
#include "CUpdateQueryDlgTab4.h"


// CUpdateQueryDlg dialog

IMPLEMENT_DYNAMIC(CUpdateQueryDlg, CDialog)

CUpdateQueryDlg::CUpdateQueryDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_UPDATE_QUERY, pParent)
{

}

CUpdateQueryDlg::~CUpdateQueryDlg()
{
}

void CUpdateQueryDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_tabScenario);
}


BEGIN_MESSAGE_MAP(CUpdateQueryDlg, CDialog)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &CUpdateQueryDlg::OnTcnSelchangeTab1)
END_MESSAGE_MAP()


// CUpdateQueryDlg message handlers

BOOL CUpdateQueryDlg::OnInitDialog()
{
	UpdateData(false);

	m_tabScenario.InsertItem(0, _T("Scenario 1"));
	m_tabScenario.InsertItem(1, _T("Scenario 2"));
	m_tabScenario.InsertItem(2, _T("Scenario 3"));
	m_tabScenario.InsertItem(3, _T("Scenario 4"));
	m_tabScenario.SetCurSel(0);

	CRect rect;
	m_tabScenario.GetWindowRect(rect);

	p_m_tabScenarioTab1 = new CUpdateQueryDlgTab1;
	p_m_tabScenarioTab1->Create(IDD_DIALOG_UPDATE_QUERY_TAB1, &m_tabScenario);
	p_m_tabScenarioTab1->MoveWindow(0, 20, rect.Width(), rect.Height());
	p_m_tabScenarioTab1->ShowWindow(SW_SHOW);

	p_m_tabScenarioTab2 = new CUpdateQueryDlgTab2;
	p_m_tabScenarioTab2->Create(IDD_DIALOG_UPDATE_QUERY_TAB2, &m_tabScenario);
	p_m_tabScenarioTab2->MoveWindow(0, 20, rect.Width(), rect.Height());
	p_m_tabScenarioTab2->ShowWindow(SW_HIDE);

	p_m_tabScenarioTab3 = new CUpdateQueryDlgTab3;
	p_m_tabScenarioTab3->Create(IDD_DIALOG_UPDATE_QUERY_TAB3, &m_tabScenario);
	p_m_tabScenarioTab3->MoveWindow(0, 20, rect.Width(), rect.Height());
	p_m_tabScenarioTab3->ShowWindow(SW_HIDE);

	p_m_tabScenarioTab4 = new CUpdateQueryDlgTab4;
	p_m_tabScenarioTab4->Create(IDD_DIALOG_UPDATE_QUERY_TAB4, &m_tabScenario);
	p_m_tabScenarioTab4->MoveWindow(0, 20, rect.Width(), rect.Height());
	p_m_tabScenarioTab4->ShowWindow(SW_HIDE);

	UpdateData(true);

	return true;
}

void CUpdateQueryDlg::OnTcnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult)
{
	int selectedTabIdx = m_tabScenario.GetCurSel();

	switch (selectedTabIdx)
	{
		case 0:
			p_m_tabScenarioTab1->ShowWindow(SW_SHOW);
			p_m_tabScenarioTab2->ShowWindow(SW_HIDE);
			p_m_tabScenarioTab3->ShowWindow(SW_HIDE);
			p_m_tabScenarioTab4->ShowWindow(SW_HIDE);
			break;
		case 1:
			p_m_tabScenarioTab1->ShowWindow(SW_HIDE);
			p_m_tabScenarioTab2->ShowWindow(SW_SHOW);
			p_m_tabScenarioTab3->ShowWindow(SW_HIDE);
			p_m_tabScenarioTab4->ShowWindow(SW_HIDE);
			break;
		case 2:
			p_m_tabScenarioTab1->ShowWindow(SW_HIDE);
			p_m_tabScenarioTab2->ShowWindow(SW_HIDE);
			p_m_tabScenarioTab3->ShowWindow(SW_SHOW);
			p_m_tabScenarioTab4->ShowWindow(SW_HIDE);
			break;
		case 3:
			p_m_tabScenarioTab1->ShowWindow(SW_HIDE);
			p_m_tabScenarioTab2->ShowWindow(SW_HIDE);
			p_m_tabScenarioTab3->ShowWindow(SW_HIDE);
			p_m_tabScenarioTab4->ShowWindow(SW_SHOW);
			break;
		default:
			break;
			// TODO: 
	}

	*pResult = 0;

	return;
}
