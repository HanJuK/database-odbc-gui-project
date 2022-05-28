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

	DECLARE_MESSAGE_MAP()
};
