#include "DziennikLib.h"

void DziennikLib::executeSqlInsert(std::string sqlCommand)
{
	char* errorMsg;
	if (sqlite3_exec(this->db, sqlCommand.c_str(), NULL, NULL, &errorMsg) != SQLITE_OK)
	{
		warrningHandler(errorMsg);
	}

}

void DziennikLib::executeSqlPrint(std::string sqlCommand)
{
	char* errorMsg;

	if (sqlite3_exec(this->db, sqlCommand.c_str(), callbackPrint, NULL, &errorMsg) != SQLITE_OK)
	{
		warrningHandler(errorMsg);
	}

}

int DziennikLib::executeSqlAmount(std::string sqlCommand)
{
	char* errorMsg;
	int amount;
	if (sqlite3_exec(this->db, sqlCommand.c_str(), callbackGetAmount, (void*)(&amount), &errorMsg) != SQLITE_OK)
	{
		warrningHandler(errorMsg);
	}
	return amount;
}

std::vector<student> DziennikLib::executeGetStudent(std::string sqlCommand)
{
	char* errorMsg;
	std::vector<student> studentRecords;
	if (sqlite3_exec(this->db, sqlCommand.c_str(), callbackGetStudent, (void*)(&studentRecords), &errorMsg) != SQLITE_OK)
	{
		warrningHandler(errorMsg);
	}
	return studentRecords;
}