// CDeleteQueryDlg.cpp : implementation file
//

#include "pch.h"
#include "database-odbc-gui-project.h"
#include "afxdialogex.h"
#include "CDeleteQueryDlg.h"
#include "CDeleteQueryDlgTab1.h"
#include "CDeleteQueryDlgTab2.h"
#include "CDeleteQueryDlgTab3.h"
#include "CDeleteQueryDlgTab4.h"


// CDeleteQueryDlg dialog

IMPLEMENT_DYNAMIC(CDeleteQueryDlg, CDialog)

CDeleteQueryDlg::CDeleteQueryDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_DELETE_QUERY, pParent)
{

}

CDeleteQueryDlg::~CDeleteQueryDlg()
{
}

void CDeleteQueryDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_tabScenario);
}


BEGIN_MESSAGE_MAP(CDeleteQueryDlg, CDialog)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &CDeleteQueryDlg::OnTcnSelchangeTab1)
END_MESSAGE_MAP()


// CDeleteQueryDlg message handlers

BOOL CDeleteQueryDlg::OnInitDialog()
{
	UpdateData(false);

	m_tabScenario.InsertItem(0, _T("Scenario 1"));
	m_tabScenario.InsertItem(1, _T("Scenario 2"));
	m_tabScenario.InsertItem(2, _T("Scenario 3"));
	m_tabScenario.InsertItem(3, _T("Scenario 4"));
	m_tabScenario.SetCurSel(0);

	CRect rect;
	m_tabScenario.GetWindowRect(rect);

	p_m_tabScenarioTab1 = new CDeleteQueryDlgTab1;
	p_m_tabScenarioTab1->Create(IDD_DIALOG_DELETE_QUERY_TAB1, &m_tabScenario);
	p_m_tabScenarioTab1->MoveWindow(0, 20, rect.Width(), rect.Height());
	p_m_tabScenarioTab1->ShowWindow(SW_SHOW);

	p_m_tabScenarioTab2 = new CDeleteQueryDlgTab2;
	p_m_tabScenarioTab2->Create(IDD_DIALOG_DELETE_QUERY_TAB2, &m_tabScenario);
	p_m_tabScenarioTab2->MoveWindow(0, 20, rect.Width(), rect.Height());
	p_m_tabScenarioTab2->ShowWindow(SW_HIDE);

	p_m_tabScenarioTab3 = new CDeleteQueryDlgTab3;
	p_m_tabScenarioTab3->Create(IDD_DIALOG_DELETE_QUERY_TAB3, &m_tabScenario);
	p_m_tabScenarioTab3->MoveWindow(0, 20, rect.Width(), rect.Height());
	p_m_tabScenarioTab3->ShowWindow(SW_HIDE);

	p_m_tabScenarioTab4 = new CDeleteQueryDlgTab4;
	p_m_tabScenarioTab4->Create(IDD_DIALOG_DELETE_QUERY_TAB4, &m_tabScenario);
	p_m_tabScenarioTab4->MoveWindow(0, 20, rect.Width(), rect.Height());
	p_m_tabScenarioTab4->ShowWindow(SW_HIDE);

	UpdateData(true);

	return true;
}

void CDeleteQueryDlg::OnTcnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult)
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
