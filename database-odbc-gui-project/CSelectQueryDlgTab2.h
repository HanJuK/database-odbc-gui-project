#pragma once
#include "afxdialogex.h"


// CSelectQueryDlgTab2 dialog

class CSelectQueryDlgTab2 : public CDialog
{
	DECLARE_DYNAMIC(CSelectQueryDlgTab2)

public:
	CSelectQueryDlgTab2(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CSelectQueryDlgTab2();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_SELECT_QUERY_TAB2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
