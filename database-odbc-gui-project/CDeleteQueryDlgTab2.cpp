// CDeleteQueryDlgTab2.cpp : implementation file
//

#include "pch.h"
#include "database-odbc-gui-project.h"
#include "afxdialogex.h"
#include "CDeleteQueryDlgTab2.h"
#include "odbc.h"
#include "Util.h"
#include <vector>
#include <string>


// CDeleteQueryDlgTab2 dialog

IMPLEMENT_DYNAMIC(CDeleteQueryDlgTab2, CDialog)

CDeleteQueryDlgTab2::CDeleteQueryDlgTab2(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_DELETE_QUERY_TAB2, pParent)
{

}

CDeleteQueryDlgTab2::~CDeleteQueryDlgTab2()
{
}

void CDeleteQueryDlgTab2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_ID, m_editId);
	DDX_Control(pDX, IDC_BUTTON_VIEW_PURCHASED, m_buttonViewPurchased);
	DDX_Control(pDX, IDC_EDIT_DATETIME, m_editDatetime);
	DDX_Control(pDX, IDC_BUTTON_QUERY, m_buttonQuery);
	DDX_Control(pDX, IDC_LIST_PURCHASE, m_listPurchase);
}


BEGIN_MESSAGE_MAP(CDeleteQueryDlgTab2, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_VIEW_PURCHASED, &CDeleteQueryDlgTab2::OnBnClickedButtonViewPurchased)
	ON_BN_CLICKED(IDC_BUTTON_QUERY, &CDeleteQueryDlgTab2::OnBnClickedButtonQuery)
END_MESSAGE_MAP()


// CDeleteQueryDlgTab2 message handlers

BOOL CDeleteQueryDlgTab2::OnInitDialog()
{
	UpdateData(false);

	m_listPurchase.InsertColumn(0, _T("Datetime"), LVCFMT_LEFT, 150);
	m_listPurchase.InsertColumn(1, _T("Custom PC Name"), LVCFMT_LEFT, 120);
	
	UpdateData(true);

	return true;
}

void CDeleteQueryDlgTab2::OnBnClickedButtonViewPurchased()
{
	ODBC* odbc = new ODBC();

	if (odbc->DBConnect())
	{
		char* result;
		char query[1000] = { '\0' };
		int itemCount;
		std::vector<std::string> resultLine;

		m_editId.GetWindowTextA(id);
		sprintf(query + strlen(query), "select PURCHASE.DATETIME, PURCHASE.CUSTOM_PC_NAME "
				"from PURCHASE "
				"where CUSTOMER_ID = %s and RATING is NULL", id);

		result = odbc->getSelectQueryResult(query);

		itemCount = m_listPurchase.GetItemCount();
		for (int i = 0; i < itemCount; ++i)
		{
			m_listPurchase.DeleteItem(0);
		}

		resultLine = Util::splitString(result, '\n');
		for (int i = 0; i < resultLine.size(); ++i)
		{
			std::vector<std::string> resultLineColumn = Util::splitString(resultLine[i], '|');

			int nItem;
			nItem = m_listPurchase.InsertItem(i, resultLineColumn[0].c_str());
			m_listPurchase.SetItemText(nItem, 1, resultLineColumn[1].c_str());
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


void CDeleteQueryDlgTab2::OnBnClickedButtonQuery()
{
	ODBC* odbc1 = new ODBC(), * odbc2 = new ODBC();

	if (odbc1->DBConnect())
	{
		char* result;
		char query1[1000] = { '\0' };
		char query2[1000] = { '\0' };
		int itemCount;
		std::vector<std::string> resultLine;

		CString datetime;
		m_editDatetime.GetWindowTextA(datetime);

		sprintf(query1 + strlen(query1), "delete from PURCHASE where CUSTOMER_ID = %s and DATETIME = '%s'",
				id, datetime);
		odbc1->doInsertDeleteUpdateQuery(query1);

		if (odbc2->DBConnect())
		{
			sprintf(query2 + strlen(query2), "select PURCHASE.DATETIME, PURCHASE.CUSTOM_PC_NAME "
					"from PURCHASE "
					"where CUSTOMER_ID = %s and RATING is NULL", id);

			result = odbc2->getSelectQueryResult(query2);

			itemCount = m_listPurchase.GetItemCount();
			for (int i = 0; i < itemCount; ++i)
			{
				m_listPurchase.DeleteItem(0);
			}

			resultLine = Util::splitString(result, '\n');
			for (int i = 0; i < resultLine.size(); ++i)
			{
				std::vector<std::string> resultLineColumn = Util::splitString(resultLine[i], '|');

				int nItem;
				nItem = m_listPurchase.InsertItem(i, resultLineColumn[0].c_str());
				m_listPurchase.SetItemText(nItem, 1, resultLineColumn[1].c_str());
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
