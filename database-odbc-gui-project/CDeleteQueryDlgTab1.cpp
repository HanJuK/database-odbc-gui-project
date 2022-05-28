// CDeleteQueryDlgTab1.cpp : implementation file
//

#include "pch.h"
#include "database-odbc-gui-project.h"
#include "afxdialogex.h"
#include "CDeleteQueryDlgTab1.h"
#include "odbc.h"
#include "Util.h"
#include <vector>
#include <string>


// CDeleteQueryDlgTab1 dialog

IMPLEMENT_DYNAMIC(CDeleteQueryDlgTab1, CDialog)

CDeleteQueryDlgTab1::CDeleteQueryDlgTab1(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_DELETE_QUERY_TAB1, pParent)
{

}

CDeleteQueryDlgTab1::~CDeleteQueryDlgTab1()
{
}

void CDeleteQueryDlgTab1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_NAME, m_editName);
	DDX_Control(pDX, IDC_BUTTON_QUERY, m_buttonQuery);
	DDX_Control(pDX, IDC_LIST_CUSTOM_PC, m_listCustomPC);
}


BEGIN_MESSAGE_MAP(CDeleteQueryDlgTab1, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_QUERY, &CDeleteQueryDlgTab1::OnBnClickedButtonQuery)
END_MESSAGE_MAP()


// CDeleteQueryDlgTab1 message handlers

BOOL CDeleteQueryDlgTab1::OnInitDialog()
{
	UpdateData(false);

	m_listCustomPC.InsertColumn(0, _T("Name"), LVCFMT_LEFT, 100);
	m_listCustomPC.InsertColumn(1, _T("Price"), LVCFMT_LEFT, 100);
	m_listCustomPC.InsertColumn(2, _T("Type"), LVCFMT_LEFT, 100);
	m_listCustomPC.InsertColumn(3, _T("Rating"), LVCFMT_LEFT, 100);
	m_listCustomPC.InsertColumn(4, _T("Builder Employee ID"), LVCFMT_LEFT, 100);

	ODBC* odbc = new ODBC();

	if (odbc->DBConnect())
	{
		char* result;
		char query[1000] = "select C.NAME, C.PRICE, C.TYPE, "
			"(C.RATING_SUM * 1.0) / NULLIF(C.RATING_COUNT, 0) as RATING, C.BUILDER_EMPLOYEE_ID "
			"from CUSTOM_PC as C "
			"where C.availability = 0";
		int itemCount;
		std::vector<std::string> resultLine;

		result = odbc->getSelectQueryResult(query);

		itemCount = m_listCustomPC.GetItemCount();
		for (int i = 0; i < itemCount; ++i)
		{
			m_listCustomPC.DeleteItem(0);
		}

		resultLine = Util::splitString(result, '\n');
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

	UpdateData(true);

	return true;
}


void CDeleteQueryDlgTab1::OnBnClickedButtonQuery()
{
	ODBC* odbc = new ODBC();

	if (odbc->DBConnect())
	{
		char* result;
		char query1[1000] = { '\0' };
		char query2[1000] = { '\0' };
		char query3[1000] = "select C.NAME, C.PRICE, C.TYPE, "
			"(C.RATING_SUM * 1.0) / NULLIF(C.RATING_COUNT, 0) as RATING, C.BUILDER_EMPLOYEE_ID "
			"from CUSTOM_PC as C "
			"where C.availability = 0";
		int itemCount;
		std::vector<std::string> resultLine;

		CString name;
		m_editName.GetWindowTextA(name);

		sprintf(query1 + strlen(query1), "delete from CUSTOM_PC where NAME = '%s'", name);
		odbc->doInsertQuery(query1);

		sprintf(query2 + strlen(query2), "update PURCHASE set CUSTOM_PC_NAME = NULL where CUSTOM_PC_NAME = '%s'", name);
		odbc->doInsertQuery(query2);

		result = odbc->getSelectQueryResult(query3);

		itemCount = m_listCustomPC.GetItemCount();
		for (int i = 0; i < itemCount; ++i)
		{
			m_listCustomPC.DeleteItem(0);
		}

		resultLine = Util::splitString(result, '\n');
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
