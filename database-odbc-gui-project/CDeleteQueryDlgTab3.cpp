// CDeleteQueryDlgTab3.cpp : implementation file
//

#include "pch.h"
#include "database-odbc-gui-project.h"
#include "afxdialogex.h"
#include "CDeleteQueryDlgTab3.h"
#include "odbc.h"
#include "Util.h"
#include <vector>
#include <string>


// CDeleteQueryDlgTab3 dialog

IMPLEMENT_DYNAMIC(CDeleteQueryDlgTab3, CDialog)

CDeleteQueryDlgTab3::CDeleteQueryDlgTab3(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_DELETE_QUERY_TAB3, pParent)
{

}

CDeleteQueryDlgTab3::~CDeleteQueryDlgTab3()
{
}

void CDeleteQueryDlgTab3::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_RATING, m_editRating);
	DDX_Control(pDX, IDC_EDIT_NAME, m_editName);
	DDX_Control(pDX, IDC_LIST_CUSTOM_PC, m_listCustomPC);
}


BEGIN_MESSAGE_MAP(CDeleteQueryDlgTab3, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_VIEW_CUSTOM_PC, &CDeleteQueryDlgTab3::OnBnClickedButtonViewCustomPc)
	ON_BN_CLICKED(IDC_BUTTON_QUERY, &CDeleteQueryDlgTab3::OnBnClickedButtonQuery)
END_MESSAGE_MAP()


// CDeleteQueryDlgTab3 message handlers

BOOL CDeleteQueryDlgTab3::OnInitDialog()
{
	UpdateData(false);

	m_listCustomPC.InsertColumn(0, _T("Name"), LVCFMT_LEFT, 100);
	m_listCustomPC.InsertColumn(1, _T("Price"), LVCFMT_LEFT, 60);
	m_listCustomPC.InsertColumn(2, _T("Type"), LVCFMT_LEFT, 90);
	m_listCustomPC.InsertColumn(3, _T("Rating"), LVCFMT_LEFT, 60);
	m_listCustomPC.InsertColumn(4, _T("Builder Employee ID"), LVCFMT_LEFT, 120);

	UpdateData(true);

	return true;
}


void CDeleteQueryDlgTab3::OnBnClickedButtonViewCustomPc()
{
	ODBC* odbc = new ODBC();

	if (odbc->DBConnect())
	{
		char* result;
		char query[1000] = { '\0' };
		int itemCount;
		std::vector<std::string> resultLine;

		CString rating;
		m_editRating.GetWindowTextA(rating);
		sprintf(query + strlen(query), "select C.NAME, C.PRICE, C.TYPE, "
				"(C.RATING_SUM * 1.0) / NULLIF(C.RATING_COUNT, 0) as RATING, C.BUILDER_EMPLOYEE_ID "
				"from CUSTOM_PC as C "
				"where (C.RATING_SUM * 1.0) / NULLIF(C.RATING_COUNT, 0) <= %s", rating);

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

	return;
}


void CDeleteQueryDlgTab3::OnBnClickedButtonQuery()
{
	ODBC* odbc1 = new ODBC(), * odbc2 = new ODBC(), * odbc3 = new ODBC();

	if (odbc1->DBConnect())
	{
		char* result;
		char query1[1000] = { '\0' };
		char query2[1000] = { '\0' };
		char query3[1000] = { '\0' };
		int itemCount;
		std::vector<std::string> resultLine;

		CString name;
		m_editName.GetWindowTextA(name);

		sprintf(query1 + strlen(query1), "delete from CUSTOM_PC where NAME = '%s'", name);
		odbc1->doInsertDeleteUpdateQuery(query1);

		if (odbc2->DBConnect())
		{
			sprintf(query2 + strlen(query2), "update PURCHASE set CUSTOM_PC_NAME = NULL where CUSTOM_PC_NAME = '%s'", name);
			odbc2->doInsertDeleteUpdateQuery(query2);
		}
		else
		{
			// TODO: handle exception
		}

		odbc2->DBDisconnect();
		delete odbc2;

		if (odbc3->DBConnect())
		{
			CString rating;
			m_editRating.GetWindowTextA(rating);
			sprintf(query3 + strlen(query3), "select C.NAME, C.PRICE, C.TYPE, "
					"(C.RATING_SUM * 1.0) / NULLIF(C.RATING_COUNT, 0) as RATING, C.BUILDER_EMPLOYEE_ID "
					"from CUSTOM_PC as C "
					"where (C.RATING_SUM * 1.0) / NULLIF(C.RATING_COUNT, 0) <= %s", rating);

			result = odbc3->getSelectQueryResult(query3);

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

		odbc3->DBDisconnect();
		delete odbc3;
	}
	else
	{
		// TODO: handle exception
	}

	odbc1->DBDisconnect();
	delete odbc1;

	return;
}
