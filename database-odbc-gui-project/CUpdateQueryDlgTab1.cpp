// CUpdateQueryDlgTab1.cpp : implementation file
//

#include "pch.h"
#include "database-odbc-gui-project.h"
#include "afxdialogex.h"
#include "CUpdateQueryDlgTab1.h"
#include "odbc.h"
#include "Util.h"
#include <vector>
#include <string>


// CUpdateQueryDlgTab1 dialog

IMPLEMENT_DYNAMIC(CUpdateQueryDlgTab1, CDialog)

CUpdateQueryDlgTab1::CUpdateQueryDlgTab1(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_UPDATE_QUERY_TAB1, pParent)
{

}

CUpdateQueryDlgTab1::~CUpdateQueryDlgTab1()
{
}

void CUpdateQueryDlgTab1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_ID, m_editId);
	DDX_Control(pDX, IDC_EDIT_SALARY, m_editSalary);
	DDX_Control(pDX, IDC_BUTTON_QUERY, m_buttonQuery);
	DDX_Control(pDX, IDC_LIST_EMPLOYEE, m_listEmployee);
}


BEGIN_MESSAGE_MAP(CUpdateQueryDlgTab1, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_QUERY, &CUpdateQueryDlgTab1::OnBnClickedButtonQuery)
END_MESSAGE_MAP()


// CUpdateQueryDlgTab1 message handlers

BOOL CUpdateQueryDlgTab1::OnInitDialog()
{
	UpdateData(false);

	m_listEmployee.InsertColumn(0, _T("Id"), LVCFMT_LEFT, 60);
	m_listEmployee.InsertColumn(1, _T("Name"), LVCFMT_LEFT, 100);
	m_listEmployee.InsertColumn(2, _T("Phone"), LVCFMT_LEFT, 100);
	m_listEmployee.InsertColumn(3, _T("Department"), LVCFMT_LEFT, 100);
	m_listEmployee.InsertColumn(4, _T("Role"), LVCFMT_LEFT, 90);
	m_listEmployee.InsertColumn(5, _T("Salary"), LVCFMT_LEFT, 90);
	m_listEmployee.InsertColumn(6, _T("Superior Employee ID"), LVCFMT_LEFT, 120);

	ODBC* odbc = new ODBC();

	if (odbc->DBConnect())
	{
		char* result;
		char query[1000] = "select * from EMPLOYEE";
		int itemCount;
		std::vector<std::string> resultLine;

		result = odbc->getSelectQueryResult(query);

		itemCount = m_listEmployee.GetItemCount();
		for (int i = 0; i < itemCount; ++i)
		{
			m_listEmployee.DeleteItem(0);
		}

		resultLine = Util::splitString(result, '\n');
		for (int i = 0; i < resultLine.size(); ++i)
		{
			std::vector<std::string> resultLineColumn = Util::splitString(resultLine[i], '|');

			int nItem;
			nItem = m_listEmployee.InsertItem(i, resultLineColumn[0].c_str());
			m_listEmployee.SetItemText(nItem, 1, resultLineColumn[1].c_str());
			m_listEmployee.SetItemText(nItem, 2, resultLineColumn[2].c_str());
			m_listEmployee.SetItemText(nItem, 3, resultLineColumn[3].c_str());
			m_listEmployee.SetItemText(nItem, 4, resultLineColumn[4].c_str());
			m_listEmployee.SetItemText(nItem, 5, resultLineColumn[5].c_str());
			m_listEmployee.SetItemText(nItem, 6, resultLineColumn[6].c_str());
		}
	}
	else
	{
		// TODO: handle exception
	}

	odbc->DBDisconnect();
	delete odbc;

	UpdateData(true);

	return true;
}


void CUpdateQueryDlgTab1::OnBnClickedButtonQuery()
{
	ODBC* odbc1 = new ODBC(), * odbc2 = new ODBC();

	if (odbc1->DBConnect())
	{
		char* result;
		char query1[1000] = { '\0' };
		char query2[1000] = "select * from EMPLOYEE";
		int itemCount;
		std::vector<std::string> resultLine;

		CString id;
		CString salary;

		m_editId.GetWindowTextA(id);
		m_editSalary.GetWindowTextA(salary);

		sprintf(query1 + strlen(query1), "update EMPLOYEE set SALARY = %s where ID = %s", salary, id);
		odbc1->doInsertDeleteUpdateQuery(query1);

		if (odbc2->DBConnect())
		{
			result = odbc2->getSelectQueryResult(query2);

			itemCount = m_listEmployee.GetItemCount();
			for (int i = 0; i < itemCount; ++i)
			{
				m_listEmployee.DeleteItem(0);
			}

			resultLine = Util::splitString(result, '\n');
			for (int i = 0; i < resultLine.size(); ++i)
			{
				std::vector<std::string> resultLineColumn = Util::splitString(resultLine[i], '|');

				int nItem;
				nItem = m_listEmployee.InsertItem(i, resultLineColumn[0].c_str());
				m_listEmployee.SetItemText(nItem, 1, resultLineColumn[1].c_str());
				m_listEmployee.SetItemText(nItem, 2, resultLineColumn[2].c_str());
				m_listEmployee.SetItemText(nItem, 3, resultLineColumn[3].c_str());
				m_listEmployee.SetItemText(nItem, 4, resultLineColumn[4].c_str());
				m_listEmployee.SetItemText(nItem, 5, resultLineColumn[5].c_str());
				m_listEmployee.SetItemText(nItem, 6, resultLineColumn[6].c_str());
			}
		}
		else
		{
			// TODO: handle exception
		}

		odbc2->DBDisconnect();
		delete odbc2;
	}
	else
	{
		// TODO: handle exception
	}

	odbc1->DBDisconnect();
	delete odbc1;

	return;
}
