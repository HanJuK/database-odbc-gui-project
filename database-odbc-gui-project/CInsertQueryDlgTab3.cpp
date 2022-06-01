// CInsertQueryDlgTab3.cpp : implementation file
//

#include "pch.h"
#include "database-odbc-gui-project.h"
#include "afxdialogex.h"
#include "CInsertQueryDlgTab3.h"
#include "ODBC.h"


// CInsertQueryDlgTab3 dialog

IMPLEMENT_DYNAMIC(CInsertQueryDlgTab3, CDialog)

CInsertQueryDlgTab3::CInsertQueryDlgTab3(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_INSERT_QUERY_TAB3, pParent)
{

}

CInsertQueryDlgTab3::~CInsertQueryDlgTab3()
{
}

void CInsertQueryDlgTab3::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_CUSTOMER_ID, m_editCustomerId);
	DDX_Control(pDX, IDC_EDIT_DATETIME, m_editDatetime);
	DDX_Control(pDX, IDC_EDIT2, m_editCustomPCName);
	DDX_Control(pDX, IDC_EDIT_RATING, m_editRating);
}


BEGIN_MESSAGE_MAP(CInsertQueryDlgTab3, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_QUERY, &CInsertQueryDlgTab3::OnBnClickedButtonQuery)
END_MESSAGE_MAP()


// CInsertQueryDlgTab3 message handlers


void CInsertQueryDlgTab3::OnBnClickedButtonQuery()
{
	ODBC* odbc = new ODBC();

	if (odbc->DBConnect())
	{
		char query[1000] = { '\0' };

		CString customerId;
		CString datetime;
		CString customPCName;
		CString rating;

		m_editCustomerId.GetWindowTextA(customerId);
		m_editDatetime.GetWindowTextA(datetime);
		m_editCustomPCName.GetWindowTextA(customPCName);
		m_editRating.GetWindowTextA(rating);

		sprintf(query + strlen(query), "insert into PURCHASE values(%s, '%s', '%s', %s)",
				customerId, datetime, customPCName, rating);
		odbc->doInsertDeleteUpdateQuery(query);
	}
	else
	{
		// TODO: handle exception
	}

	odbc->DBDisconnect();
	delete odbc;

	return;
}
