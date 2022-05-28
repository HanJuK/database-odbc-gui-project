#pragma once
#include "afxdialogex.h"


// CDeleteQueryDlgTab2 dialog

class CDeleteQueryDlgTab2 : public CDialog
{
	DECLARE_DYNAMIC(CDeleteQueryDlgTab2)

public:
	CDeleteQueryDlgTab2(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CDeleteQueryDlgTab2();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_DELETE_QUERY_TAB2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	CString id;
	CEdit m_editId;
	CButton m_buttonViewPurchased;
	CEdit m_editDatetime;
	CButton m_buttonQuery;
	CListCtrl m_listPurchase;
	afx_msg void OnBnClickedButtonViewPurchased();
	afx_msg void OnBnClickedButtonQuery();
};
