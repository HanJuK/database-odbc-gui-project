#pragma once
#include "afxdialogex.h"

class CInsertQueryDlgTab1;
class CInsertQueryDlgTab2;
class CInsertQueryDlgTab3;
class CInsertQueryDlgTab4;

// CInsertQueryDlg dialog

class CInsertQueryDlg : public CDialog
{
	DECLARE_DYNAMIC(CInsertQueryDlg)

public:
	CInsertQueryDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CInsertQueryDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_INSERT_QUERY };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl m_tabScenario;
	CInsertQueryDlgTab1* p_m_tabScenarioTab1;
	CInsertQueryDlgTab2* p_m_tabScenarioTab2;
	CInsertQueryDlgTab3* p_m_tabScenarioTab3;
	CInsertQueryDlgTab4* p_m_tabScenarioTab4;
	afx_msg void OnTcnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult);
};
