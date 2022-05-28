#pragma once
#include "afxdialogex.h"


// CInsertQueryDlgTab2 dialog

class CInsertQueryDlgTab2 : public CDialog
{
	DECLARE_DYNAMIC(CInsertQueryDlgTab2)

public:
	CInsertQueryDlgTab2(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CInsertQueryDlgTab2();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_INSERT_QUERY_TAB2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonQuery();
	CEdit m_editId;
	CEdit m_editName;
	CEdit m_editPhone;
	CEdit m_editEmail;
	CEdit m_editAddress;
	CEdit m_editMileage;
	CEdit m_editMarketing;
	CEdit m_editManagerEmployeeId;
};
