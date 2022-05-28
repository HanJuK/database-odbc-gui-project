#pragma once
#include "afxdialogex.h"


// CUpdateQueryDlgTab2 dialog

class CUpdateQueryDlgTab2 : public CDialog
{
	DECLARE_DYNAMIC(CUpdateQueryDlgTab2)

public:
	CUpdateQueryDlgTab2(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CUpdateQueryDlgTab2();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_UPDATE_QUERY_TAB2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
