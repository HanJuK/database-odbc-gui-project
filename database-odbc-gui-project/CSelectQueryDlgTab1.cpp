// CSelectQueryDlgTab1.cpp : implementation file
//

#include "pch.h"
#include "database-odbc-gui-project.h"
#include "afxdialogex.h"
#include "CSelectQueryDlgTab1.h"
#include "odbc.h"
#include "Util.h"
#include <vector>
#include <string>


// CSelectQueryDlgTab1 dialog

IMPLEMENT_DYNAMIC(CSelectQueryDlgTab1, CDialog)

CSelectQueryDlgTab1::CSelectQueryDlgTab1(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_SELECT_QUERY_TAB1, pParent)
{

}

CSelectQueryDlgTab1::~CSelectQueryDlgTab1()
{
}

void CSelectQueryDlgTab1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_EMPLOYEE_ID, m_editEmployeeId);
	DDX_Control(pDX, IDC_LIST_CUSTOMER, m_listCustomer);
	DDX_Control(pDX, IDC_LIST_CUSTOM_PC, m_listCustomPC);
}


BEGIN_MESSAGE_MAP(CSelectQueryDlgTab1, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_QUERY, &CSelectQueryDlgTab1::OnBnClickedButtonQuery)
END_MESSAGE_MAP()


// CSelectQueryDlgTab1 message handlers

BOOL CSelectQueryDlgTab1::OnInitDialog()
{
	UpdateData(false);

	m_listCustomer.InsertColumn(0, _T("ID"), LVCFMT_LEFT, 100);
	m_listCustomer.InsertColumn(1, _T("Name"), LVCFMT_LEFT, 100);
	m_listCustomer.InsertColumn(2, _T("Phone"), LVCFMT_LEFT, 100);
	m_listCustomer.InsertColumn(3, _T("Email"), LVCFMT_LEFT, 100);
	m_listCustomer.InsertColumn(4, _T("Address"), LVCFMT_LEFT, 100);
	m_listCustomer.InsertColumn(5, _T("Mileage"), LVCFMT_LEFT, 100);
	m_listCustomer.InsertColumn(6, _T("Marketing"), LVCFMT_LEFT, 100);

	m_listCustomPC.InsertColumn(0, _T("Name"), LVCFMT_LEFT, 100);
	m_listCustomPC.InsertColumn(1, _T("Price"), LVCFMT_LEFT, 100);
	m_listCustomPC.InsertColumn(2, _T("Availability"), LVCFMT_LEFT, 100);
	m_listCustomPC.InsertColumn(3, _T("Type"), LVCFMT_LEFT, 100);
	m_listCustomPC.InsertColumn(4, _T("Rating"), LVCFMT_LEFT, 100);

	UpdateData(true);

	return true;
}

void CSelectQueryDlgTab1::OnBnClickedButtonQuery()
{
	ODBC* odbc = new ODBC();

	if (odbc->DBConnect())
	{
		char* result1, * result2;
		char query1[1000] = "select C.ID, C.NAME, C.PHONE, C.EMAIL, C.ADDRESS, C.MILEAGE, C.MARKETING "
			"from EMPLOYEE as E, CUSTOMER as C "
			"where E.id = C.MANAGER_EMPLOYEE_ID and E.id = ";
		char query2[1000] = "select C.NAME, C.PRICE, C.AVAILABILITY, C.TYPE, "
			"(C.RATING_SUM * 1.0) / NULLIF(C.RATING_COUNT, 0) as RATING "
			"from EMPLOYEE as E, CUSTOM_PC as C "
			"where E.id = C.BUILDER_EMPLOYEE_ID and E.id = ";
		CString employeeId;
		int itemCount;
		std::vector<std::string> resultLine;

		m_editEmployeeId.GetWindowTextA(employeeId);
		strcat(query1, employeeId);
		strcat(query2, employeeId);

		result1 = odbc->getSelectQueryResult(query1);

		itemCount = m_listCustomer.GetItemCount();
		for (int i = 0; i < itemCount; ++i)
		{
			m_listCustomer.DeleteItem(0);
		}

		resultLine = Util::splitString(result1, '\n');
		for (int i = 0; i < resultLine.size(); ++i)
		{
			std::vector<std::string> resultLineColumn = Util::splitString(resultLine[i], '|');

			int nItem;
			nItem = m_listCustomer.InsertItem(i, resultLineColumn[0].c_str());
			m_listCustomer.SetItemText(nItem, 1, resultLineColumn[1].c_str());
			m_listCustomer.SetItemText(nItem, 2, resultLineColumn[2].c_str());
			m_listCustomer.SetItemText(nItem, 3, resultLineColumn[3].c_str());
			m_listCustomer.SetItemText(nItem, 4, resultLineColumn[4].c_str());
			m_listCustomer.SetItemText(nItem, 5, resultLineColumn[5].c_str());
			m_listCustomer.SetItemText(nItem, 6, resultLineColumn[6].c_str());
		}

		result2 = odbc->getSelectQueryResult(query2);

		itemCount = m_listCustomPC.GetItemCount();
		for (int i = 0; i < itemCount; ++i)
		{
			m_listCustomPC.DeleteItem(0);
		}

		resultLine = Util::splitString(result2, '\n');
		for (int i = 0; i < resultLine.size(); ++i)
		{
			std::vector<std::string> resultLineColumn = Util::splitString(resultLine[i], '|');

			int nItem;
			nItem = m_listCustomPC.InsertItem(i, resultLineColumn[0].c_str());
			m_listCustomPC.SetItemText(nItem, 1, resultLineColumn[1].c_str());
			m_listCustomPC.SetItemText(nItem, 2, resultLineColumn[2].c_str());
			m_listCustomPC.SetItemText(nItem, 3, resultLineColumn[3].c_str());
			m_listCustomPC.SetItemText(nItem, 4, resultLineColumn[4].c_str());
		}
	}
	else
	{
		// TODO: handle exception
	}

	odbc->DBDisconnect();
	delete odbc;

	return;
}
