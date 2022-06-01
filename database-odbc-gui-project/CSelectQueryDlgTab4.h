#pragma once
#include "afxdialogex.h"


// CSelectQueryDlgTab4 dialog

class CSelectQueryDlgTab4 : public CDialog
{
	DECLARE_DYNAMIC(CSelectQueryDlgTab4)

public:
	CSelectQueryDlgTab4(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CSelectQueryDlgTab4();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_SELECT_QUERY_TAB4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_editName;
	afx_msg void OnBnClickedButtonQuery();
	CStatic m_staticResult;
};
