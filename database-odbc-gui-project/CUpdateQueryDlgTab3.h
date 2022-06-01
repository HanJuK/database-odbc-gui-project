#pragma once
#include "afxdialogex.h"


// CUpdateQueryDlgTab3 dialog

class CUpdateQueryDlgTab3 : public CDialog
{
	DECLARE_DYNAMIC(CUpdateQueryDlgTab3)

public:
	CUpdateQueryDlgTab3(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CUpdateQueryDlgTab3();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_UPDATE_QUERY_TAB3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_editId;
	CEdit m_editDatetime;
	CEdit m_editRating;
	CString id;
	afx_msg void OnBnClickedButtonViewPurchased();
	afx_msg void OnBnClickedButtonQuery();
	CListCtrl m_listPurchase;
};
