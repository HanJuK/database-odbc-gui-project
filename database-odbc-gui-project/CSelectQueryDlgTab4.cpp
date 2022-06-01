// CSelectQueryDlgTab4.cpp : implementation file
//

#include "pch.h"
#include "database-odbc-gui-project.h"
#include "afxdialogex.h"
#include "CSelectQueryDlgTab4.h"
#include "odbc.h"
#include "Util.h"
#include <vector>
#include <string>


// CSelectQueryDlgTab4 dialog

IMPLEMENT_DYNAMIC(CSelectQueryDlgTab4, CDialog)

CSelectQueryDlgTab4::CSelectQueryDlgTab4(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_SELECT_QUERY_TAB4, pParent)
{

}

CSelectQueryDlgTab4::~CSelectQueryDlgTab4()
{
}

void CSelectQueryDlgTab4::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_NAME, m_editName);
	DDX_Control(pDX, IDC_STATIC_RESULT, m_staticResult);
}


BEGIN_MESSAGE_MAP(CSelectQueryDlgTab4, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_QUERY, &CSelectQueryDlgTab4::OnBnClickedButtonQuery)
END_MESSAGE_MAP()


// CSelectQueryDlgTab4 message handlers


void CSelectQueryDlgTab4::OnBnClickedButtonQuery()
{
	ODBC* odbc1 = new ODBC(), * odbc2 = new ODBC();

	if (odbc1->DBConnect())
	{
		char* result1, * result2;
		char query1[1000] = { '\0' };
		char query2[1000] = { '\0' };
		int itemCount;
		std::vector<std::string> resultLine;

		CString name;
		m_editName.GetWindowTextA(name);
		sprintf(query1 + strlen(query1), "select P.NAME, P.STOCK, P.TYPE from PART as P, CONTAINS_RELATION as C "
				"where C.CUSTOM_PC_NAME = '%s' and P.NAME = C.PART_NAME ", name);

		result1 = odbc1->getSelectQueryResult(query1);
		resultLine = Util::splitString(result1, '\n');

		if (resultLine.size() < 10)
		{
			m_staticResult.SetWindowTextA(_T("CUSTOM PC NOT AVAILABLE!"));
		}
		else
		{
			if (odbc2->DBConnect())
			{
				sprintf(query2 + strlen(query2), "select PA.END_DATE "
						"from PART as P, CONTAINS_RELATION as C, PARTNER as PA "
						"where C.CUSTOM_PC_NAME = '%s' and P.NAME = C.PART_NAME and C.PARTNER_NAME = PA.NAME "
						"order by PA.END_DATE asc", name);

				result2 = odbc2->getSelectQueryResult(query2);
				resultLine = Util::splitString(result2, '\n');

				m_staticResult.SetWindowTextA(_T(resultLine[0].substr(0, resultLine[0].length() - 1).c_str()));
			}
			else
			{
				// TODO: handle exception
			}

			odbc2->DBDisconnect();
			delete odbc2;
		}
	}
	else
	{
		// TODO: handle exception
	}

	odbc1->DBDisconnect();
	delete odbc1;

	return;
}
