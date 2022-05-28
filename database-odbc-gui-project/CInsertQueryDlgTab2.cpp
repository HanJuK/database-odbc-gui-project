// CInsertQueryDlgTab2.cpp : implementation file
//

#include "pch.h"
#include "database-odbc-gui-project.h"
#include "afxdialogex.h"
#include "CInsertQueryDlgTab2.h"
#include "ODBC.h"


// CInsertQueryDlgTab2 dialog

IMPLEMENT_DYNAMIC(CInsertQueryDlgTab2, CDialog)

CInsertQueryDlgTab2::CInsertQueryDlgTab2(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_INSERT_QUERY_TAB2, pParent)
{

}

CInsertQueryDlgTab2::~CInsertQueryDlgTab2()
{
}

void CInsertQueryDlgTab2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_ID, m_editId);
	DDX_Control(pDX, IDC_EDIT_NAME, m_editName);
	DDX_Control(pDX, IDC_EDIT_PHONE, m_editPhone);
	DDX_Control(pDX, IDC_EDIT_EMAIL, m_editEmail);
	DDX_Control(pDX, IDC_EDIT_ADDRESS, m_editAddress);
	DDX_Control(pDX, IDC_EDIT_MILEAGE, m_editMileage);
	DDX_Control(pDX, IDC_EDIT_MARKETING, m_editMarketing);
	DDX_Control(pDX, IDC_EDIT_MANAGER_EMPLOYEE_ID, m_editManagerEmployeeId);
}


BEGIN_MESSAGE_MAP(CInsertQueryDlgTab2, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_QUERY, &CInsertQueryDlgTab2::OnBnClickedButtonQuery)
END_MESSAGE_MAP()


// CInsertQueryDlgTab2 message handlers


void CInsertQueryDlgTab2::OnBnClickedButtonQuery()
{
	ODBC* odbc = new ODBC();

	if (odbc->DBConnect())
	{
		char query[1000] = { '\0' };

		CString id;
		CString name;
		CString phone;
		CString email;
		CString address;
		CString mileage;
		CString marketing;
		CString managerEmployeeId;

		m_editId.GetWindowTextA(id);
		m_editName.GetWindowTextA(name);
		m_editPhone.GetWindowTextA(phone);
		m_editEmail.GetWindowTextA(email);
		m_editAddress.GetWindowTextA(address);
		m_editMileage.GetWindowTextA(mileage);
		m_editMarketing.GetWindowTextA(marketing);
		m_editManagerEmployeeId.GetWindowTextA(managerEmployeeId);

		sprintf(query + strlen(query), "insert into CUSTOMER values(%s, '%s', '%s', '%s', '%s', %s, %s, %s)",
				id, name, phone, email, address, mileage, marketing, managerEmployeeId);
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
