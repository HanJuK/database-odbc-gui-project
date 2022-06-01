#pragma once
#include "afxdialogex.h"


// CInsertQueryDlgTab3 dialog

class CInsertQueryDlgTab3 : public CDialog
{
	DECLARE_DYNAMIC(CInsertQueryDlgTab3)

public:
	CInsertQueryDlgTab3(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CInsertQueryDlgTab3();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_INSERT_QUERY_TAB3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_editCustomerId;
	CEdit m_editDatetime;
	CEdit m_editCustomPCName;
	CEdit m_editRating;
	afx_msg void OnBnClickedButtonQuery();
};
