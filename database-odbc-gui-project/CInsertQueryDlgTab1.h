#pragma once
#include "afxdialogex.h"


// CInsertQueryDlgTab1 dialog

class CInsertQueryDlgTab1 : public CDialog
{
	DECLARE_DYNAMIC(CInsertQueryDlgTab1)

public:
	CInsertQueryDlgTab1(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CInsertQueryDlgTab1();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_INSERT_QUERY_TAB1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_editId;
	CEdit m_editName;
	CEdit m_editPhone;
	CEdit m_editDepartment;
	CEdit m_editRole;
	CEdit m_editSalary;
	CEdit m_editSuperiorEmployeeId;
	CButton m_buttonQuery;
	afx_msg void OnBnClickedButtonQuery();
};
