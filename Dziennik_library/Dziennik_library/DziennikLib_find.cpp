#include "DziennikLib.h"


student DziennikLib::findStudentByPesel(std::string pesel)
{
	std::vector<student> studentRecords;
	std::cout << "Grades table:" << std::endl << std::endl;
	std::string sqlCommand = "SELECT * FROM Students \n WHERE Pesel = '" + pesel + "'";
	studentRecords = executeGetStudent(sqlCommand.c_str());
	return *studentRecords.begin();
}