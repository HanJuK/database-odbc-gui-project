// CUpdateQueryDlgTab3.cpp : implementation file
//

#include "pch.h"
#include "database-odbc-gui-project.h"
#include "afxdialogex.h"
#include "CUpdateQueryDlgTab3.h"
#include "odbc.h"
#include "Util.h"
#include <vector>
#include <string>


// CUpdateQueryDlgTab3 dialog

IMPLEMENT_DYNAMIC(CUpdateQueryDlgTab3, CDialog)

CUpdateQueryDlgTab3::CUpdateQueryDlgTab3(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_UPDATE_QUERY_TAB3, pParent)
{

}

CUpdateQueryDlgTab3::~CUpdateQueryDlgTab3()
{
}

void CUpdateQueryDlgTab3::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_ID, m_editId);
	DDX_Control(pDX, IDC_EDIT_DATETIME, m_editDatetime);
	DDX_Control(pDX, IDC_EDIT_RATING, m_editRating);
	DDX_Control(pDX, IDC_LIST_PURCHASE, m_listPurchase);
}


BEGIN_MESSAGE_MAP(CUpdateQueryDlgTab3, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_VIEW_PURCHASED, &CUpdateQueryDlgTab3::OnBnClickedButtonViewPurchased)
	ON_BN_CLICKED(IDC_BUTTON_QUERY, &CUpdateQueryDlgTab3::OnBnClickedButtonQuery)
END_MESSAGE_MAP()


// CUpdateQueryDlgTab3 message handlers

BOOL CUpdateQueryDlgTab3::OnInitDialog()
{
	UpdateData(false);

	m_listPurchase.InsertColumn(0, _T("Customer ID"), LVCFMT_LEFT, 90);
	m_listPurchase.InsertColumn(1, _T("Datetime"), LVCFMT_LEFT, 120);
	m_listPurchase.InsertColumn(2, _T("Custom PC Name"), LVCFMT_LEFT, 120);
	m_listPurchase.InsertColumn(3, _T("Rating"), LVCFMT_LEFT, 60);

	UpdateData(true);

	return true;
}


void CUpdateQueryDlgTab3::OnBnClickedButtonViewPurchased()
{
	ODBC* odbc = new ODBC();

	if (odbc->DBConnect())
	{
		char* result;
		char query[1000] = { '\0' };
		int itemCount;
		std::vector<std::string> resultLine;

		m_editId.GetWindowTextA(id);
		sprintf(query + strlen(query), "select * from PURCHASE where CUSTOMER_ID = %s", id);

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
			m_listPurchase.SetItemText(nItem, 2, resultLineColumn[2].c_str());
			m_listPurchase.SetItemText(nItem, 3, resultLineColumn[3].c_str());
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


void CUpdateQueryDlgTab3::OnBnClickedButtonQuery()
{
	ODBC* odbc1 = new ODBC(), * odbc2 = new ODBC(), * odbc3 = new ODBC(), * odbc4 = new ODBC();

	if (odbc1->DBConnect())
	{
		char* result1, * result2;
		char query1[1000] = { '\0' };
		char query2[1000] = { '\0' };
		char query3[1000] = { '\0' };
		char query4[1000] = { '\0' };
		int itemCount;
		std::vector<std::string> resultLine;

		CString datetime, rating;
		m_editDatetime.GetWindowTextA(datetime);
		m_editRating.GetWindowTextA(rating);

		sprintf(query1 + strlen(query1), "select * from PURCHASE where CUSTOMER_ID = %s and DATETIME = '%s'",
				id, datetime);
		result1 = odbc1->getSelectQueryResult(query1);

		resultLine = Util::splitString(result1, '\n');
		std::vector<std::string> resultLineColumn = Util::splitString(resultLine[0], '|');

		string prevRating = resultLineColumn[3].c_str();

		if (prevRating.find("NULL") != std::string::npos) // if prevRating was NULL
		{
			if (rating.Find("NULL") == -1) // if rating (to set) is not NULL
			{
				if (odbc2->DBConnect())
				{
					sprintf(query2 + strlen(query2), "update PURCHASE set RATING = %s where CUSTOMER_ID = %s and DATETIME = '%s'",
							rating, id, datetime);
					odbc2->doInsertDeleteUpdateQuery(query2);

					if (odbc3->DBConnect())
					{
						sprintf(query3 + strlen(query3), "update CUSTOM_PC "
								"set RATING_SUM = RATING_SUM + %s, RATING_COUNT = RATING_COUNT + 1 "
								"where NAME = '%s'",
								rating, resultLineColumn[2].c_str());
						odbc3->doInsertDeleteUpdateQuery(query3);
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

				odbc2->DBDisconnect();
				delete odbc2;
			}
		}
		else // if prevRating was NULL
		{
			if (odbc2->DBConnect())
			{
				sprintf(query2 + strlen(query2), "update PURCHASE set RATING = %s where CUSTOMER_ID = %s and DATETIME = '%s'",
						rating, id, datetime);
				odbc2->doInsertDeleteUpdateQuery(query2);

				if (odbc3->DBConnect())
				{
					if (rating.Find("NULL") == -1) // if rating (to set) is not NULL
					{
						sprintf(query3 + strlen(query3), "update CUSTOM_PC "
								"set RATING_SUM = RATING_SUM - %s + %s where NAME = '%s'",
								prevRating.c_str(), rating, resultLineColumn[2].c_str());
						odbc3->doInsertDeleteUpdateQuery(query3);
					}
					else // if rating (to set) is NULL (0)
					{
						sprintf(query3 + strlen(query3), "update CUSTOM_PC "
								"set RATING_SUM = RATING_SUM - %s, RATING_COUNT = RATING_COUNT - 1 "
								"where NAME = '%s'",
								prevRating.c_str(), resultLineColumn[2].c_str());
						odbc3->doInsertDeleteUpdateQuery(query3);
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

			odbc2->DBDisconnect();
			delete odbc2;
		}

		if (odbc4->DBConnect())
		{
			sprintf(query4 + strlen(query4), "select * from PURCHASE where CUSTOMER_ID = %s", id);

			result2 = odbc4->getSelectQueryResult(query4);

			itemCount = m_listPurchase.GetItemCount();
			for (int i = 0; i < itemCount; ++i)
			{
				m_listPurchase.DeleteItem(0);
			}

			resultLine = Util::splitString(result2, '\n');
			for (int i = 0; i < resultLine.size(); ++i)
			{
				std::vector<std::string> resultLineColumn = Util::splitString(resultLine[i], '|');

				int nItem;
				nItem = m_listPurchase.InsertItem(i, resultLineColumn[0].c_str());
				m_listPurchase.SetItemText(nItem, 1, resultLineColumn[1].c_str());
				m_listPurchase.SetItemText(nItem, 2, resultLineColumn[2].c_str());
				m_listPurchase.SetItemText(nItem, 3, resultLineColumn[3].c_str());
			}
		}
		else
		{
			// TODO: handle exception
		}

		odbc4->DBDisconnect();
		delete odbc4;
	}
	else
	{
		// TODO: handle exception
	}

	odbc1->DBDisconnect();
	delete odbc1;

	return;
}
