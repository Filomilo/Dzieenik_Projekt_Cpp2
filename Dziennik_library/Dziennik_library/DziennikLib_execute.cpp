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


std::vector<user> DziennikLib::executeGetUser(std::string sqlCommand)
{
	char* errorMsg;
	std::vector<user> userRecords;
	if (sqlite3_exec(this->db, sqlCommand.c_str(), callbackGetUser, (void*)(&userRecords), &errorMsg) != SQLITE_OK)
	{
		warrningHandler(errorMsg);
	}
	return userRecords;
}

std::vector<teacher> DziennikLib::executeGetTeacher(std::string sqlCommand)
{
	char* errorMsg;
	std::vector<teacher> teacherRecords;
	if (sqlite3_exec(this->db, sqlCommand.c_str(), callbackGetTeacher, (void*)(&teacherRecords), &errorMsg) != SQLITE_OK)
	{
		warrningHandler(errorMsg);
	}
	return teacherRecords;
}

std::vector<subject> DziennikLib::executeGetSubject(std::string sqlCommand)
{
	char* errorMsg;
	std::vector<subject> subjectRecords;
	if (sqlite3_exec(this->db, sqlCommand.c_str(), callbackGetSubject, (void*)(&subjectRecords), &errorMsg) != SQLITE_OK)
	{
		warrningHandler(errorMsg);
	}
	return subjectRecords;
}

std::vector<grade> DziennikLib::executeGetGrade(std::string sqlCommand)
{
	char* errorMsg;
	std::vector<grade> gradeRecords;
	if (sqlite3_exec(this->db, sqlCommand.c_str(), callbackGetGrade, (void*)(&gradeRecords), &errorMsg) != SQLITE_OK)
	{
		warrningHandler(errorMsg);
	}
	return gradeRecords;
}

std::vector<attendance> DziennikLib::executeGetAttendace(std::string sqlCommand)
{
	char* errorMsg;
	std::vector<attendance> attendanceRecords;
	if (sqlite3_exec(this->db, sqlCommand.c_str(), callbackGetAttendacne, (void*)(&attendanceRecords), &errorMsg) != SQLITE_OK)
	{
		warrningHandler(errorMsg);
	}
	return attendanceRecords;
}