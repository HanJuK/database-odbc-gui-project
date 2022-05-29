// CCustomQueryDlg.cpp : implementation file
//

#include "pch.h"
#include "database-odbc-gui-project.h"
#include "afxdialogex.h"
#include "CCustomQueryDlg.h"
#include "odbc.h"
#include "Util.h"
#include <vector>
#include <string>


// CCustomQueryDlg dialog

IMPLEMENT_DYNAMIC(CCustomQueryDlg, CDialog)

CCustomQueryDlg::CCustomQueryDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_CUSTOM_QUERY, pParent)
{

}

CCustomQueryDlg::~CCustomQueryDlg()
{
}

void CCustomQueryDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_QUERY, m_editQuery);
	DDX_Control(pDX, IDC_BUTTON_QUERY, m_buttonQuery);
	DDX_Control(pDX, IDC_LIST_RESULT, m_listResult);
}


BEGIN_MESSAGE_MAP(CCustomQueryDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_QUERY, &CCustomQueryDlg::OnBnClickedButtonQuery)
END_MESSAGE_MAP()


// CCustomQueryDlg message handlers


void CCustomQueryDlg::OnBnClickedButtonQuery()
{
	CString query, queryUpper;
	m_editQuery.GetWindowTextA(query);

	queryUpper = query;
	queryUpper.MakeUpper();

	CHeaderCtrl* pHeaderCtrl = m_listResult.GetHeaderCtrl();
	int columnCount = pHeaderCtrl->GetItemCount();
	for (int i = 0; i < columnCount; ++i)
	{
		m_listResult.DeleteColumn(0);
	}
	m_listResult.DeleteAllItems();

	if (queryUpper.Left(6).Find("SELECT") != -1)
	{
		ODBC* odbc1 = new ODBC(), * odbc2 = new ODBC();

		if (odbc1->DBConnect())
		{
			char* result1, * result2, queryChar[1000] = { '\0' };

			strcpy(queryChar, query);
			result1 = odbc1->getDescribeCol(queryChar);

			std::vector<std::string> resultLine = Util::splitString(result1, '\n');
			for (int i = 0; i < resultLine.size(); ++i)
			{
				std::vector<std::string> resultLineColumn = Util::splitString(resultLine[i], '|');

				m_listResult.InsertColumn(i, resultLineColumn[0].c_str(), LVCFMT_LEFT, 90);
			}

			if (odbc2->DBConnect())
			{
				result2 = odbc2->getSelectQueryResult(queryChar);

				resultLine = Util::splitString(result2, '\n');
				for (int i = 0; i < resultLine.size(); ++i)
				{
					std::vector<std::string> resultLineColumn = Util::splitString(resultLine[i], '|');

					int nItem;
					columnCount = pHeaderCtrl->GetItemCount();

					for (int j = 0; j < columnCount; ++j)
					{
						if (j == 0)
						{
							nItem = m_listResult.InsertItem(i, resultLineColumn[j].c_str());
						}
						else
						{
							m_listResult.SetItemText(nItem, j, resultLineColumn[j].c_str());
						}
					}
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
	}
	else
	{
		// TODO: 
	}

	return;
}
