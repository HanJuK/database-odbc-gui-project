// CSelectQueryDlgTab3.cpp : implementation file
//

#include "pch.h"
#include "database-odbc-gui-project.h"
#include "afxdialogex.h"
#include "CSelectQueryDlgTab3.h"
#include "odbc.h"
#include "Util.h"
#include <vector>
#include <string>


// CSelectQueryDlgTab3 dialog

IMPLEMENT_DYNAMIC(CSelectQueryDlgTab3, CDialog)

CSelectQueryDlgTab3::CSelectQueryDlgTab3(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_SELECT_QUERY_TAB3, pParent)
{

}

CSelectQueryDlgTab3::~CSelectQueryDlgTab3()
{
}

void CSelectQueryDlgTab3::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_NAME, m_editName);
	DDX_Control(pDX, IDC_LIST1, m_listPart);
}


BEGIN_MESSAGE_MAP(CSelectQueryDlgTab3, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_QUERY, &CSelectQueryDlgTab3::OnBnClickedButtonQuery)
END_MESSAGE_MAP()


// CSelectQueryDlgTab3 message handlers

BOOL CSelectQueryDlgTab3::OnInitDialog()
{
	UpdateData(false);

	m_listPart.InsertColumn(0, _T("Name"), LVCFMT_LEFT, 120);
	m_listPart.InsertColumn(1, _T("Stock"), LVCFMT_LEFT, 90);
	m_listPart.InsertColumn(2, _T("Type"), LVCFMT_LEFT, 120);

	UpdateData(true);

	return true;
}


void CSelectQueryDlgTab3::OnBnClickedButtonQuery()
{
	ODBC* odbc = new ODBC();

	if (odbc->DBConnect())
	{
		char* result;
		char query[1000] = { '\0' };
		int itemCount;
		std::vector<std::string> resultLine;

		CString name;
		m_editName.GetWindowTextA(name);
		sprintf(query + strlen(query), "select P.NAME, P.STOCK, P.TYPE from PART as P, CONTAINS_RELATION as C "
				"where C.CUSTOM_PC_NAME = '%s' and P.NAME = C.PART_NAME ", name);

		result = odbc->getSelectQueryResult(query);

		itemCount = m_listPart.GetItemCount();
		for (int i = 0; i < itemCount; ++i)
		{
			m_listPart.DeleteItem(0);
		}

		resultLine = Util::splitString(result, '\n');
		for (int i = 0; i < resultLine.size(); ++i)
		{
			std::vector<std::string> resultLineColumn = Util::splitString(resultLine[i], '|');

			int nItem;
			nItem = m_listPart.InsertItem(i, resultLineColumn[0].c_str());
			m_listPart.SetItemText(nItem, 1, resultLineColumn[1].c_str());
			m_listPart.SetItemText(nItem, 2, resultLineColumn[2].c_str());
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
