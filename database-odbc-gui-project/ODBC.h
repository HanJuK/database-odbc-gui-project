#pragma warning(disable:4996)
#pragma once

#include <Windows.h>
#include <sql.h>
#include <sqlext.h>

#define SERVER_NAME "DB01_SERVER"
#define SERVER_ID "KIM"
#define SERVER_PW "KIM123"

class ODBC
{
public:
	ODBC() {}

private:
	SQLHENV hEnv = NULL; // for saving the current environment settings
	SQLHENV hDbc = NULL; // for saving the current connection settings

public:
	bool DBConnect()
	{
		SQLRETURN Ret;

		/** Allocate the Environment Handle (hEnv) */
		if (SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv) != SQL_SUCCESS)
		{
			return false;
		}

		/** Set attributes of the Environment Handle (hEnv) */
		if (SQLSetEnvAttr(hEnv, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, SQL_IS_INTEGER) != SQL_SUCCESS)
		{
			return false;
		}

		/** Allocate the Connection Handle (hDbc) */
		if (SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc) != SQL_SUCCESS)
		{
			return false;
		}

		/** Connect to the SQL Sever with ODBC name, ID, and PW */
		Ret = SQLConnect(hDbc, (SQLCHAR *)SERVER_NAME, SQL_NTS,
						 (SQLCHAR *)SERVER_ID, SQL_NTS,
						 (SQLCHAR *)SERVER_PW, SQL_NTS);
		if ((Ret != SQL_SUCCESS) && (Ret != SQL_SUCCESS_WITH_INFO))
		{
			return false;
		}

		return true;
	}

	void DBDisconnect()
	{
		SQLDisconnect(hDbc);					// Disconnect from the SQL Server
		SQLFreeHandle(SQL_HANDLE_DBC, hDbc);	// Free the Connection Handle
		SQLFreeHandle(SQL_HANDLE_ENV, hEnv);	// Free the Environment Handle

		return;
	}

	char* getDescribeCol(static char* query)
	{
		char result[10000] = { '\0' };

		SQLCHAR querySQL[100]; // query statement for SQL
		SQLHSTMT hStmt; // statement handle

		if (SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt) == SQL_SUCCESS)
		{
			SQLCHAR ColumnName[50][50];
			SQLSMALLINT ColumnNameLen[50];
			SQLSMALLINT ColumnDataType[50];
			SQLULEN ColumnDataSize[50];
			SQLSMALLINT ColumnDataDigits[50];
			SQLSMALLINT ColumnDataNullable[50];
			SQLSMALLINT numCols = -1;

			sprintf((char*)querySQL, query);
			SQLExecDirect(hStmt, querySQL, SQL_NTS);

			SQLNumResultCols(hStmt, &numCols);
			for (int i = 0; i < numCols; ++i)
			{
				SQLDescribeCol(
					hStmt,
					i + 1,
					ColumnName[i],
					50,
					&ColumnNameLen[i],
					&ColumnDataType[i],
					&ColumnDataSize[i],
					&ColumnDataDigits[i],
					&ColumnDataNullable[i]
				);

				sprintf(result + strlen(result), "%s %d %d %d %d\n",
						ColumnName[i], (int)ColumnNameLen[i], (int)ColumnDataType[i],
						(int)ColumnDataSize[i], (int)ColumnDataNullable[i]);
			}
		}

		return result;
	}
};