#pragma once
#include "afxdialogex.h"


// CCustomQueryDlg dialog

class CCustomQueryDlg : public CDialog
{
	DECLARE_DYNAMIC(CCustomQueryDlg)

public:
	CCustomQueryDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CCustomQueryDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_CUSTOM_QUERY };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_editQuery;
	CButton m_buttonQuery;
	CListCtrl m_listResult;
	afx_msg void OnBnClickedButtonQuery();
};
