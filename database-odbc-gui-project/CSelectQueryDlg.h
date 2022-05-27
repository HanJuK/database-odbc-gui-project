#pragma once
#include "afxdialogex.h"

class CSelectQueryDlgTab1;
class CSelectQueryDlgTab2;

// CSelectQueryDlg dialog

class CSelectQueryDlg : public CDialog
{
	DECLARE_DYNAMIC(CSelectQueryDlg)

public:
	CSelectQueryDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CSelectQueryDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_SELECT_QUERY };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl m_tabScenario;
	CSelectQueryDlgTab1* p_m_tabScenarioTab1;
	CSelectQueryDlgTab2* p_m_tabScenarioTab2;
	afx_msg void OnTcnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult);
};
