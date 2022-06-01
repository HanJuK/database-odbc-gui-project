#pragma once
#include "afxdialogex.h"


// CUpdateQueryDlgTab4 dialog

class CUpdateQueryDlgTab4 : public CDialog
{
	DECLARE_DYNAMIC(CUpdateQueryDlgTab4)

public:
	CUpdateQueryDlgTab4(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CUpdateQueryDlgTab4();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_UPDATE_QUERY_TAB4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_editName;
	CEdit m_editBuilderEmployeeId;
	CListCtrl m_listCustomPC;
	afx_msg void OnBnClickedButtonQuery();
};
