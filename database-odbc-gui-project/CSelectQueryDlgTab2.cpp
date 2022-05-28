// CSelectQueryDlgTab2.cpp : implementation file
//

#include "pch.h"
#include "database-odbc-gui-project.h"
#include "afxdialogex.h"
#include "CSelectQueryDlgTab2.h"
#include "odbc.h"
#include "Util.h"
#include <vector>
#include <string>


// CSelectQueryDlgTab2 dialog

IMPLEMENT_DYNAMIC(CSelectQueryDlgTab2, CDialog)

CSelectQueryDlgTab2::CSelectQueryDlgTab2(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_SELECT_QUERY_TAB2, pParent)
{

}

CSelectQueryDlgTab2::~CSelectQueryDlgTab2()
{
}

void CSelectQueryDlgTab2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_CUSTOM_PC, m_listCustomPC);
}


BEGIN_MESSAGE_MAP(CSelectQueryDlgTab2, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_QUERY, &CSelectQueryDlgTab2::OnBnClickedButtonQuery)
END_MESSAGE_MAP()


// CSelectQueryDlgTab2 message handlers

BOOL CSelectQueryDlgTab2::OnInitDialog()
{
	UpdateData(false);

	m_listCustomPC.InsertColumn(0, _T("Name"), LVCFMT_LEFT, 100);
	m_listCustomPC.InsertColumn(1, _T("Price"), LVCFMT_LEFT, 100);
	m_listCustomPC.InsertColumn(2, _T("Availability"), LVCFMT_LEFT, 100);
	m_listCustomPC.InsertColumn(3, _T("Type"), LVCFMT_LEFT, 100);
	m_listCustomPC.InsertColumn(4, _T("Rating"), LVCFMT_LEFT, 100);
	m_listCustomPC.InsertColumn(5, _T("Builder Employee ID"), LVCFMT_LEFT, 100);

	UpdateData(true);

	return true;
}

void CSelectQueryDlgTab2::OnBnClickedButtonQuery()
{
	ODBC* odbc = new ODBC();

	if (odbc->DBConnect())
	{
		char* result;
		char query[1000] = "select C.NAME, C.PRICE, C.AVAILABILITY, C.TYPE, "
			"(C.RATING_SUM * 1.0) / NULLIF(C.RATING_COUNT, 0) as RATING, C.BUILDER_EMPLOYEE_ID "
			"from CUSTOM_PC as C "
			"order by RATING desc";
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

	return;
}
