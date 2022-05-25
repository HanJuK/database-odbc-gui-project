#pragma once
#include "afxdialogex.h"


// CSchemaCheckDlg dialog

class CSchemaCheckDlg : public CDialog
{
	DECLARE_DYNAMIC(CSchemaCheckDlg)

public:
	CSchemaCheckDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CSchemaCheckDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_SCHEMA_CHECK };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
