#pragma once
#include "afxdialogex.h"


// CUpdateQueryDlgTab1 dialog

class CUpdateQueryDlgTab1 : public CDialog
{
	DECLARE_DYNAMIC(CUpdateQueryDlgTab1)

public:
	CUpdateQueryDlgTab1(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CUpdateQueryDlgTab1();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_UPDATE_QUERY_TAB1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_editId;
	CEdit m_editSalary;
	CButton m_buttonQuery;
	CListCtrl m_listEmployee;
	afx_msg void OnBnClickedButtonQuery();
};
