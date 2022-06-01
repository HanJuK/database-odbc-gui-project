#pragma once
#include "afxdialogex.h"


// CDeleteQueryDlgTab3 dialog

class CDeleteQueryDlgTab3 : public CDialog
{
	DECLARE_DYNAMIC(CDeleteQueryDlgTab3)

public:
	CDeleteQueryDlgTab3(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CDeleteQueryDlgTab3();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_DELETE_QUERY_TAB3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_editRating;
	CEdit m_editName;
	CListCtrl m_listCustomPC;
	afx_msg void OnBnClickedButtonViewCustomPc();
	afx_msg void OnBnClickedButtonQuery();
};
