#pragma once
#include "afxdialogex.h"


// CDeleteQueryDlgTab2 dialog

class CDeleteQueryDlgTab2 : public CDialog
{
	DECLARE_DYNAMIC(CDeleteQueryDlgTab2)

public:
	CDeleteQueryDlgTab2(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CDeleteQueryDlgTab2();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_DELETE_QUERY_TAB2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
