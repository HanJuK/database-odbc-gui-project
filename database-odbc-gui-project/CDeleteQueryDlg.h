#pragma once
#include "afxdialogex.h"

class CDeleteQueryDlgTab1;
class CDeleteQueryDlgTab2;

// CDeleteQueryDlg dialog

class CDeleteQueryDlg : public CDialog
{
	DECLARE_DYNAMIC(CDeleteQueryDlg)

public:
	CDeleteQueryDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CDeleteQueryDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_DELETE_QUERY };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl m_tabScenario;
	CDeleteQueryDlgTab1* p_m_tabScenarioTab1;
	CDeleteQueryDlgTab2* p_m_tabScenarioTab2;
	afx_msg void OnTcnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult);
};
