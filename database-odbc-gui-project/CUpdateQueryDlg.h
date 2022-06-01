#pragma once
#include "afxdialogex.h"

class CUpdateQueryDlgTab1;
class CUpdateQueryDlgTab2;
class CUpdateQueryDlgTab3;
class CUpdateQueryDlgTab4;

// CUpdateQueryDlg dialog

class CUpdateQueryDlg : public CDialog
{
	DECLARE_DYNAMIC(CUpdateQueryDlg)

public:
	CUpdateQueryDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CUpdateQueryDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_UPDATE_QUERY };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl m_tabScenario;
	CUpdateQueryDlgTab1* p_m_tabScenarioTab1;
	CUpdateQueryDlgTab2* p_m_tabScenarioTab2;
	CUpdateQueryDlgTab3* p_m_tabScenarioTab3;
	CUpdateQueryDlgTab4* p_m_tabScenarioTab4;
	afx_msg void OnTcnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult);
};
