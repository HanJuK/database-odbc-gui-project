// CUpdateQueryDlgTab4.cpp : implementation file
//

#include "pch.h"
#include "database-odbc-gui-project.h"
#include "afxdialogex.h"
#include "CUpdateQueryDlgTab4.h"
#include "odbc.h"
#include "Util.h"
#include <vector>
#include <string>


// CUpdateQueryDlgTab4 dialog

IMPLEMENT_DYNAMIC(CUpdateQueryDlgTab4, CDialog)

CUpdateQueryDlgTab4::CUpdateQueryDlgTab4(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_UPDATE_QUERY_TAB4, pParent)
{

}

CUpdateQueryDlgTab4::~CUpdateQueryDlgTab4()
{
}

void CUpdateQueryDlgTab4::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_NAME, m_editName);
	DDX_Control(pDX, IDC_EDIT_BUILDER_EMPLOYEE_ID, m_editBuilderEmployeeId);
	DDX_Control(pDX, IDC_LIST_CUSTOM_PC, m_listCustomPC);
}


BEGIN_MESSAGE_MAP(CUpdateQueryDlgTab4, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_QUERY, &CUpdateQueryDlgTab4::OnBnClickedButtonQuery)
END_MESSAGE_MAP()


// CUpdateQueryDlgTab4 message handlers

BOOL CUpdateQueryDlgTab4::OnInitDialog()
{
	UpdateData(false);

	m_listCustomPC.InsertColumn(0, _T("Name"), LVCFMT_LEFT, 100);
	m_listCustomPC.InsertColumn(1, _T("Price"), LVCFMT_LEFT, 60);
	m_listCustomPC.InsertColumn(2, _T("Availability"), LVCFMT_LEFT, 90);
	m_listCustomPC.InsertColumn(3, _T("Type"), LVCFMT_LEFT, 100);
	m_listCustomPC.InsertColumn(4, _T("Rating"), LVCFMT_LEFT, 60);
	m_listCustomPC.InsertColumn(5, _T("Builder Employee ID"), LVCFMT_LEFT, 120);

	ODBC* odbc = new ODBC();

	if (odbc->DBConnect())
	{
		char* result;
		char query[1000] = "select C.NAME, C.PRICE, C.AVAILABILITY, C.TYPE, "
			"(C.RATING_SUM * 1.0) / NULLIF(C.RATING_COUNT, 0) as RATING, C.BUILDER_EMPLOYEE_ID "
			"from CUSTOM_PC as C";
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
			m_listCustomPC.SetItemText(nItem, 5, resultLineColumn[5].c_str());
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


void CUpdateQueryDlgTab4::OnBnClickedButtonQuery()
{
	ODBC* odbc1 = new ODBC(), * odbc2 = new ODBC();

	if (odbc1->DBConnect())
	{
		char* result;
		char query1[1000] = { '\0' };
		char query2[1000] = "select C.NAME, C.PRICE, C.AVAILABILITY, C.TYPE, "
			"(C.RATING_SUM * 1.0) / NULLIF(C.RATING_COUNT, 0) as RATING, C.BUILDER_EMPLOYEE_ID "
			"from CUSTOM_PC as C";
		int itemCount;
		std::vector<std::string> resultLine;

		CString name;
		CString builderEmployeeId;

		m_editName.GetWindowTextA(name);
		m_editBuilderEmployeeId.GetWindowTextA(builderEmployeeId);

		sprintf(query1 + strlen(query1), "update CUSTOM_PC set BUILDER_EMPLOYEE_ID = %s where NAME = '%s'",
				builderEmployeeId, name);
		odbc1->doInsertDeleteUpdateQuery(query1);

		if (odbc2->DBConnect())
		{
			result = odbc2->getSelectQueryResult(query2);

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
				m_listCustomPC.SetItemText(nItem, 5, resultLineColumn[5].c_str());
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
