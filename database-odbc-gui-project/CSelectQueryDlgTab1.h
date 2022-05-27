#pragma once
#include "afxdialogex.h"


// CSelectQueryDlgTab1 dialog

class CSelectQueryDlgTab1 : public CDialog
{
	DECLARE_DYNAMIC(CSelectQueryDlgTab1)

public:
	CSelectQueryDlgTab1(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CSelectQueryDlgTab1();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_SELECT_QUERY_TAB1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_editEmployeeId;
	afx_msg void OnBnClickedButtonQuery();
	CListCtrl m_listCustomer;
	CListCtrl m_listCustomPC;
};
