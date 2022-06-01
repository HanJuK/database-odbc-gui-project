// CDeleteQueryDlgTab4.cpp : implementation file
//

#include "pch.h"
#include "database-odbc-gui-project.h"
#include "afxdialogex.h"
#include "CDeleteQueryDlgTab4.h"
#include "odbc.h"
#include "Util.h"
#include <vector>
#include <string>


// CDeleteQueryDlgTab4 dialog

IMPLEMENT_DYNAMIC(CDeleteQueryDlgTab4, CDialog)

CDeleteQueryDlgTab4::CDeleteQueryDlgTab4(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_DELETE_QUERY_TAB4, pParent)
{

}

CDeleteQueryDlgTab4::~CDeleteQueryDlgTab4()
{
}

void CDeleteQueryDlgTab4::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_END_DATE, m_editEndDate);
	DDX_Control(pDX, IDC_LIST_PARTNER, m_listPartner);
	DDX_Control(pDX, IDC_EDIT_NAME, m_editName);
}


BEGIN_MESSAGE_MAP(CDeleteQueryDlgTab4, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_VIEW_PARTNER, &CDeleteQueryDlgTab4::OnBnClickedButtonViewPartner)
	ON_BN_CLICKED(IDC_BUTTON_QUERY, &CDeleteQueryDlgTab4::OnBnClickedButtonQuery)
END_MESSAGE_MAP()


// CDeleteQueryDlgTab4 message handlers

BOOL CDeleteQueryDlgTab4::OnInitDialog()
{
	UpdateData(false);

	m_listPartner.InsertColumn(0, _T("Name"), LVCFMT_LEFT, 120);
	m_listPartner.InsertColumn(1, _T("Start Date"), LVCFMT_LEFT, 120);
	m_listPartner.InsertColumn(2, _T("End Date"), LVCFMT_LEFT, 120);

	UpdateData(true);

	return true;
}


void CDeleteQueryDlgTab4::OnBnClickedButtonViewPartner()
{
	ODBC* odbc = new ODBC();

	if (odbc->DBConnect())
	{
		char* result;
		char query[1000] = { '\0' };
		int itemCount;
		std::vector<std::string> resultLine;

		CString endDate;
		m_editEndDate.GetWindowTextA(endDate);
		sprintf(query + strlen(query), "select * from PARTNER where END_DATE < '%s'", endDate);

		result = odbc->getSelectQueryResult(query);

		itemCount = m_listPartner.GetItemCount();
		for (int i = 0; i < itemCount; ++i)
		{
			m_listPartner.DeleteItem(0);
		}

		resultLine = Util::splitString(result, '\n');
		for (int i = 0; i < resultLine.size(); ++i)
		{
			std::vector<std::string> resultLineColumn = Util::splitString(resultLine[i], '|');

			int nItem;
			nItem = m_listPartner.InsertItem(i, resultLineColumn[0].c_str());
			m_listPartner.SetItemText(nItem, 1, resultLineColumn[1].c_str());
			m_listPartner.SetItemText(nItem, 2, resultLineColumn[2].c_str());
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


void CDeleteQueryDlgTab4::OnBnClickedButtonQuery()
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
		sprintf(query1 + strlen(query1), "delete from PARTNER where NAME = '%s'", name);

		odbc1->doInsertDeleteUpdateQuery(query1);

		if (odbc2->DBConnect())
		{
			sprintf(query2 + strlen(query2), "update PURCHASE set PARTNER_NAME = NULL where PARTNER_NAME = '%s'", name);
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
			CString name;
			m_editName.GetWindowTextA(name);
			sprintf(query1 + strlen(query1), "delete from PARTNER where NAME = '%s'", name);

			result = odbc3->getSelectQueryResult(query3);

			itemCount = m_listPartner.GetItemCount();
			for (int i = 0; i < itemCount; ++i)
			{
				m_listPartner.DeleteItem(0);
			}

			resultLine = Util::splitString(result, '\n');
			for (int i = 0; i < resultLine.size(); ++i)
			{
				std::vector<std::string> resultLineColumn = Util::splitString(resultLine[i], '|');

				int nItem;
				nItem = m_listPartner.InsertItem(i, resultLineColumn[0].c_str());
				m_listPartner.SetItemText(nItem, 1, resultLineColumn[1].c_str());
				m_listPartner.SetItemText(nItem, 2, resultLineColumn[2].c_str());
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
