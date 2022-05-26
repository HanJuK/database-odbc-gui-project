// CSchemaCheckDlg.cpp : implementation file
//

#include "pch.h"
#include "database-odbc-gui-project.h"
#include "afxdialogex.h"
#include "CSchemaCheckDlg.h"
#include "ODBC.h"
#include "Util.h"
#include <vector>
#include <string>

// CSchemaCheckDlg dialog

IMPLEMENT_DYNAMIC(CSchemaCheckDlg, CDialog)

CSchemaCheckDlg::CSchemaCheckDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_SCHEMA_CHECK, pParent)
{

}

CSchemaCheckDlg::~CSchemaCheckDlg()
{
}

void CSchemaCheckDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_TABLE, m_comboTable);
	DDX_Control(pDX, IDC_LIST_SCHEMA, m_listSchema);
}


BEGIN_MESSAGE_MAP(CSchemaCheckDlg, CDialog)
	ON_CBN_SELCHANGE(IDC_COMBO_TABLE, &CSchemaCheckDlg::OnCbnSelchangeComboTable)
END_MESSAGE_MAP()


// CSchemaCheckDlg message handlers

BOOL CSchemaCheckDlg::OnInitDialog()
{
	UpdateData(false);

	m_comboTable.AddString(_T("EMPLOYEE"));
	m_comboTable.AddString(_T("CUSTOMER"));
	m_comboTable.AddString(_T("PURCHASE"));
	m_comboTable.AddString(_T("CUSTOM_PC"));
	m_comboTable.AddString(_T("PART"));
	m_comboTable.AddString(_T("PARTNER"));

	m_listSchema.InsertColumn(0, _T("Column Name"), LVCFMT_LEFT, 100);
	m_listSchema.InsertColumn(1, _T("Column Name Length"), LVCFMT_LEFT, 100);
	m_listSchema.InsertColumn(2, _T("SQL Data Type"), LVCFMT_LEFT, 100);
	m_listSchema.InsertColumn(3, _T("Data Size"), LVCFMT_LEFT, 100);
	m_listSchema.InsertColumn(4, _T("Data Nullable"), LVCFMT_LEFT, 100);

	UpdateData(true);

	return true;
}

void CSchemaCheckDlg::OnCbnSelchangeComboTable()
{
	ODBC* odbc = new ODBC();

	if (odbc->DBConnect())
	{
		char* result;
		char query[30] = "select * from ", table[10];

		m_comboTable.GetLBText(m_comboTable.GetCurSel(), table);
		strcat(query, table);

		result = odbc->getDescribeCol(query);

		int itemCount = m_listSchema.GetItemCount();
		for (int i = 0; i < itemCount; ++i)
		{
			m_listSchema.DeleteItem(0);
		}

		std::vector<std::string> resultLine = Util::splitString(result, '\n');
		for (int i = 0; i < resultLine.size(); ++i)
		{
			std::vector<std::string> resultLineColumn = Util::splitString(resultLine[i], ' ');

			int nItem;
			nItem = m_listSchema.InsertItem(i, resultLineColumn[0].c_str());
			m_listSchema.SetItemText(nItem, 1, resultLineColumn[1].c_str());
			m_listSchema.SetItemText(nItem, 2, Util::getSQLDataTypeInString(std::stoi(resultLineColumn[2])).c_str());
			m_listSchema.SetItemText(nItem, 3, resultLineColumn[3].c_str());
			m_listSchema.SetItemText(nItem, 4, Util::getSQLNullableString(std::stoi(resultLineColumn[4])).c_str());
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
