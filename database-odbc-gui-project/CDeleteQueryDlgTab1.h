#pragma once
#include "afxdialogex.h"


// CDeleteQueryDlgTab1 dialog

class CDeleteQueryDlgTab1 : public CDialog
{
	DECLARE_DYNAMIC(CDeleteQueryDlgTab1)

public:
	CDeleteQueryDlgTab1(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CDeleteQueryDlgTab1();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_DELETE_QUERY_TAB1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_editName;
	CButton m_buttonQuery;
	CListCtrl m_listCustomPC;
	afx_msg void OnBnClickedButtonQuery();
};
