#pragma once
#include "afxdialogex.h"


// CInsertQueryDlgTab4 dialog

class CInsertQueryDlgTab4 : public CDialog
{
	DECLARE_DYNAMIC(CInsertQueryDlgTab4)

public:
	CInsertQueryDlgTab4(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CInsertQueryDlgTab4();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_INSERT_QUERY_TAB4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_editName;
	CEdit m_editPrice;
	CEdit m_editAvailability;
	CEdit m_editType;
	CEdit m_editBuilderEmployeeId;
	afx_msg void OnBnClickedButtonQuery();
};
