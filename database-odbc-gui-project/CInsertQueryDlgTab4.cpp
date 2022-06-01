// CInsertQueryDlgTab4.cpp : implementation file
//

#include "pch.h"
#include "database-odbc-gui-project.h"
#include "afxdialogex.h"
#include "CInsertQueryDlgTab4.h"
#include "ODBC.h"


// CInsertQueryDlgTab4 dialog

IMPLEMENT_DYNAMIC(CInsertQueryDlgTab4, CDialog)

CInsertQueryDlgTab4::CInsertQueryDlgTab4(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_INSERT_QUERY_TAB4, pParent)
{

}

CInsertQueryDlgTab4::~CInsertQueryDlgTab4()
{
}

void CInsertQueryDlgTab4::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_NAME, m_editName);
	DDX_Control(pDX, IDC_EDIT_PHONE, m_editPrice);
	DDX_Control(pDX, IDC_EDIT_ADDRESS, m_editAvailability);
	DDX_Control(pDX, IDC_EDIT_EMAIL, m_editType);
	DDX_Control(pDX, IDC_EDIT_MANAGER_EMPLOYEE_ID, m_editBuilderEmployeeId);
}


BEGIN_MESSAGE_MAP(CInsertQueryDlgTab4, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_QUERY, &CInsertQueryDlgTab4::OnBnClickedButtonQuery)
END_MESSAGE_MAP()


// CInsertQueryDlgTab4 message handlers


void CInsertQueryDlgTab4::OnBnClickedButtonQuery()
{
	ODBC* odbc = new ODBC();

	if (odbc->DBConnect())
	{
		char query[1000] = { '\0' };

		CString name;
		CString price;
		CString availability;
		CString type;
		CString builderEmployeeId;

		m_editName.GetWindowTextA(name);
		m_editPrice.GetWindowTextA(price);
		m_editAvailability.GetWindowTextA(availability);
		m_editType.GetWindowTextA(type);
		m_editBuilderEmployeeId.GetWindowTextA(builderEmployeeId);

		sprintf(query + strlen(query), "insert into CUSTOM_PC values('%s', %s, %s, '%s', 0, 0, %s)",
				name, price, availability, type, builderEmployeeId);
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
