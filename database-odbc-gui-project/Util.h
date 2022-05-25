#pragma once

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

class Util
{
public:
	static vector<string> splitString(string input, char delimiter)
	{
        vector<string> result;
        stringstream stringStream(input);
        string token;

        while (getline(stringStream, token, delimiter))
        {
            result.push_back(token);
        }

        return result;
	}

    static string getSQLDataTypeInString(int dataType)
    {
        switch (dataType)
        {
            case SQL_CHAR:
                return "CHAR";
                break;
            case SQL_VARCHAR:
                return "VARCHAR";
                break;
            case SQL_LONGVARCHAR:
                return "LONGVARCHAR";
                break;
            case SQL_WCHAR:
                return "WCHAR";
                break;
            case SQL_WVARCHAR:
                return "WVARCHAR";
                break;
            case SQL_WLONGVARCHAR:
                return "WLONGVARCHAR";
                break;
            case SQL_NUMERIC:
                return "NUMERIC";
                break;
            case SQL_SMALLINT:
                return "SMALLINT";
                break;
            case SQL_INTEGER:
                return "INTEGER";
                break;
            case SQL_REAL:
                return "REAL";
                break;
            case SQL_FLOAT:
                return "FLOAT";
                break;
            case SQL_DOUBLE:
                return "DOUBLE";
                break;
            case SQL_BIT:
                return "BIT";
                break;
            case SQL_TINYINT:
                return "TINYINT";
                break;
            case SQL_BIGINT:
                return "BIGINT";
                break;
            case SQL_BINARY:
                return "BINARY";
                break;
            case SQL_VARBINARY:
                return "VARBINARY";
                break;
            case SQL_LONGVARBINARY:
                return "LONGVARBINARY";
                break;
            case SQL_TYPE_DATE:
                return "TYPE_DATE";
                break;
            case SQL_TYPE_TIME:
                return "TYPE_TIME";
                break;
            case SQL_TYPE_TIMESTAMP:
                return "TYPE_TIMESTAMP";
                break;
            case SQL_INTERVAL_MONTH:
                return "INTERVAL_MONTH";
                break;
            case SQL_INTERVAL_YEAR:
                return "INTERVAL_YEAR";
                break;
            case SQL_INTERVAL_YEAR_TO_MONTH:
                return "INTERVAL_YEAR_TO_MONTH";
                break;
            case SQL_INTERVAL_DAY:
                return "INTERVAL_DAY";
                break;
            case SQL_INTERVAL_HOUR:
                return "INTERVAL_HOUR";
                break;
            case SQL_INTERVAL_MINUTE:
                return "INTERVAL_MINUTE";
                break;
            case SQL_INTERVAL_SECOND:
                return "INTERVAL_SECOND";
                break;
            case SQL_INTERVAL_DAY_TO_HOUR:
                return "INTERVAL_DAY_TO_HOUR";
                break;
            case SQL_INTERVAL_DAY_TO_MINUTE:
                return "INTERVAL_DAY_TO_MINUTE";
                break;
            case SQL_INTERVAL_DAY_TO_SECOND:
                return "INTERVAL_DAY_TO_SECOND";
                break;
            case SQL_INTERVAL_HOUR_TO_MINUTE:
                return "INTERVAL_HOUR_TO_MINUTE";
                break;
            case SQL_INTERVAL_HOUR_TO_SECOND:
                return "INTERVAL_HOUR_TO_SECOND";
                break;
            case SQL_INTERVAL_MINUTE_TO_SECOND:
                return "INTERVAL_MINUTE_TO_SECOND";
                break;
            case SQL_GUID:
                return "GUID";
                break;
            default:
                return "UNKNOWN";
        }
    }

    static string getSQLNullableString(int nullable)
    {
        return nullable == 0 ? "NOT NULLABLE" : "NULLABLE";
    }
};