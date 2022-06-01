#pragma once
#include "afxdialogex.h"


// CSelectQueryDlgTab5 dialog

class CSelectQueryDlgTab5 : public CDialog
{
	DECLARE_DYNAMIC(CSelectQueryDlgTab5)

public:
	CSelectQueryDlgTab5(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CSelectQueryDlgTab5();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_SELECT_QUERY_TAB5 };
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
