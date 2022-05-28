
// database-odbc-gui-projectDlg.h : header file
//

#pragma once


// CdatabaseodbcguiprojectDlg dialog
class CdatabaseodbcguiprojectDlg : public CDialogEx
{
// Construction
public:
	CdatabaseodbcguiprojectDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DATABASEODBCGUIPROJECT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedSchemaCheck();
	afx_msg void OnBnClickedSelectQuery();
	afx_msg void OnBnClickedButtonInsertQuery();
	afx_msg void OnBnClickedButtonDeleteQuery();
};
