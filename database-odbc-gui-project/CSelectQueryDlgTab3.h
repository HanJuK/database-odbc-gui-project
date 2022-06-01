#pragma once
#include "afxdialogex.h"


// CSelectQueryDlgTab3 dialog

class CSelectQueryDlgTab3 : public CDialog
{
	DECLARE_DYNAMIC(CSelectQueryDlgTab3)

public:
	CSelectQueryDlgTab3(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CSelectQueryDlgTab3();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_SELECT_QUERY_TAB3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_editName;
	CListCtrl m_listPart;
	afx_msg void OnBnClickedButtonQuery();
};
