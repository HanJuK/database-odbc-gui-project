// CInsertQueryDlgTab1.cpp : implementation file
//

#include "pch.h"
#include "database-odbc-gui-project.h"
#include "afxdialogex.h"
#include "CInsertQueryDlgTab1.h"
#include "ODBC.h"


// CInsertQueryDlgTab1 dialog

IMPLEMENT_DYNAMIC(CInsertQueryDlgTab1, CDialog)

CInsertQueryDlgTab1::CInsertQueryDlgTab1(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_INSERT_QUERY_TAB1, pParent)
{

}

CInsertQueryDlgTab1::~CInsertQueryDlgTab1()
{
}

void CInsertQueryDlgTab1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_ID, m_editId);
	DDX_Control(pDX, IDC_EDIT_NAME, m_editName);
	DDX_Control(pDX, IDC_EDIT_PHONE, m_editPhone);
	DDX_Control(pDX, IDC_EDIT_DEPARTMENT, m_editDepartment);
	DDX_Control(pDX, IDC_EDIT_ROLE, m_editRole);
	DDX_Control(pDX, IDC_EDIT6, m_editSalary);
	DDX_Control(pDX, IDC_EDIT7, m_editSuperiorEmployeeId);
	DDX_Control(pDX, IDC_BUTTON_QUERY, m_buttonQuery);
}


BEGIN_MESSAGE_MAP(CInsertQueryDlgTab1, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_QUERY, &CInsertQueryDlgTab1::OnBnClickedButtonQuery)
END_MESSAGE_MAP()


// CInsertQueryDlgTab1 message handlers


void CInsertQueryDlgTab1::OnBnClickedButtonQuery()
{
	ODBC* odbc = new ODBC();

	if (odbc->DBConnect())
	{
		char query[1000] = { '\0' };

		CString id;
		CString name;
		CString phone;
		CString department;
		CString role;
		CString salary;
		CString superiorEmployeeId;

		m_editId.GetWindowTextA(id);
		m_editName.GetWindowTextA(name);
		m_editPhone.GetWindowTextA(phone);
		m_editDepartment.GetWindowTextA(department);
		m_editRole.GetWindowTextA(role);
		m_editSalary.GetWindowTextA(salary);
		m_editSuperiorEmployeeId.GetWindowTextA(superiorEmployeeId);

		sprintf(query + strlen(query), "insert into EMPLOYEE values(%s, '%s', '%s', '%s', '%s', %s, %s)",
				id, name, phone, department, role, salary, superiorEmployeeId);
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
