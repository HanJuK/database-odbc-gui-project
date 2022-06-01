#pragma once
#include "afxdialogex.h"


// CDeleteQueryDlgTab4 dialog

class CDeleteQueryDlgTab4 : public CDialog
{
	DECLARE_DYNAMIC(CDeleteQueryDlgTab4)

public:
	CDeleteQueryDlgTab4(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CDeleteQueryDlgTab4();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_DELETE_QUERY_TAB4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_editEndDate;
	afx_msg void OnBnClickedButtonViewPartner();
	afx_msg void OnBnClickedButtonQuery();
	CListCtrl m_listPartner;
	CEdit m_editName;
};
