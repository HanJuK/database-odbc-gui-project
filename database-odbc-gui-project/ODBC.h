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

	char* getTableNames(static char* query)
	{
		char result[10000] = { '\0' };

		SQLCHAR querySQL[100]; // query statement for SQL
		SQLHSTMT hStmt; // statement handle

		if (SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt) == SQL_SUCCESS)
		{
			SQLCHAR tableName[50];

			sprintf((char*)querySQL, query);
			if (SQLExecDirect(hStmt, querySQL, SQL_NTS) == SQL_ERROR)
			{
				// TODO: handle exception
			}

			SQLBindCol(hStmt, 1, SQL_C_CHAR, tableName, 50, NULL);
			while (SQLFetch(hStmt) != SQL_NO_DATA)
			{
				sprintf(result + strlen(result), "%s\n", tableName);
			}
		}
		else
		{
			// TODO: handle error
		}

		return result;
	}

	char* getDescribeCol(static char* query)
	{
		char result[10000] = { '\0' };

		SQLCHAR querySQL[100]; // query statement for SQL
		SQLHSTMT hStmt; // statement handle

		if (SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt) == SQL_SUCCESS)
		{
			SQLCHAR columnName[50][50];
			SQLSMALLINT columnNameLen[50];
			SQLSMALLINT columnDataType[50];
			SQLULEN columnDataSize[50];
			SQLSMALLINT columnDataDigits[50];
			SQLSMALLINT columnDataNullable[50];
			SQLSMALLINT numCols = -1;

			sprintf((char*)querySQL, query);
			if (SQLExecDirect(hStmt, querySQL, SQL_NTS) == SQL_ERROR)
			{
				// TODO: handle exception
			}

			SQLNumResultCols(hStmt, &numCols);
			for (int i = 0; i < numCols; ++i)
			{
				SQLDescribeCol(
					hStmt,
					i + 1,
					columnName[i],
					50,
					&columnNameLen[i],
					&columnDataType[i],
					&columnDataSize[i],
					&columnDataDigits[i],
					&columnDataNullable[i]
				);

				sprintf(result + strlen(result), "%s|%d|%d|%d|%d\n",
						columnName[i], (int)columnNameLen[i], (int)columnDataType[i],
						(int)columnDataSize[i], (int)columnDataNullable[i]);
			}
		}
		else
		{
			// TODO: handle error
		}

		return result;
	}

	char* getSelectQueryResult(static char* query)
	{
		char result[10000] = { '\0' };

		SQLCHAR querySQL[1000]; // query statement for SQL
		SQLHSTMT hStmt; // statement handle

		if (SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt) == SQL_SUCCESS)
		{
			SQLSMALLINT colCount = -1;
			SQLCHAR data[100][50];
			SQLLEN nulldata[100];

			sprintf((char*)querySQL, query);
			if (SQLExecDirect(hStmt, querySQL, SQL_NTS) == SQL_ERROR)
			{
				// TODO: handle exception
			}

			SQLNumResultCols(hStmt, &colCount);
			for (int i = 0; i < colCount; ++i)
			{
				SQLBindCol(hStmt, i + 1, SQL_C_CHAR, data[i], sizeof(data[i]), &(nulldata[i]));
			}

			while (SQLFetch(hStmt) != SQL_NO_DATA)
			{
				for (int i = 0; i < colCount; ++i)
				{
					if (nulldata[i] == SQL_NULL_DATA) sprintf(result + strlen(result), "NULL|");
					else sprintf(result + strlen(result), "%s|", data[i]);
				}
				sprintf(result + strlen(result), "\n");
			}
		}
		else
		{
			// TODO: handle error
		}

		return result;
	}

	void doInsertDeleteUpdateQuery(static char* query)
	{
		SQLCHAR querySQL[1000]; // query statement for SQL
		SQLHSTMT hStmt; // statement handle

		if (SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt) == SQL_SUCCESS)
		{
			sprintf((char*)querySQL, query);
			if (SQLExecDirect(hStmt, querySQL, SQL_NTS) == SQL_ERROR)
			{
				// TODO: handle exception
			}
		}
		else
		{
			// TODO: handle error
		}

		return;
	}
};