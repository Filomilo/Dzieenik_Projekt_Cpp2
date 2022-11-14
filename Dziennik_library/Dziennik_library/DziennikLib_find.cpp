#include "DziennikLib.h"


std::vector<student> DziennikLib::findStudentByPesel(std::string pesel)
{
	std::vector<student> studentRecords;
	std::cout << "Grades table:" << std::endl << std::endl;
	std::string sqlCommand = "SELECT * FROM Students \n WHERE Pesel = '" + pesel + "'";
	studentRecords = executeGetStudent(sqlCommand.c_str());
	return studentRecords;
}

std::vector<student> DziennikLib::findSstudentAll()
{
	std::vector<student> studentRecords;
	std::cout << "Grades table:" << std::endl << std::endl;
	std::string sqlCommand = "SELECT * FROM Students";
	studentRecords = executeGetStudent(sqlCommand.c_str());
	return studentRecords;
}

std::vector<grade>  DziennikLib::findGradesAll()
{
	std::vector<grade> gradesRecords;
	std::cout << "Grades table:" << std::endl << std::endl;
	std::string sqlCommand = "SELECT * FROM Grades";
	gradesRecords = executeGetGrade(sqlCommand.c_str());
	return gradesRecords;
}
std::vector<attendance>  DziennikLib::findAttandanceAll()
{
	std::vector<attendance> attendancesRecords;
	std::cout << "Grades table:" << std::endl << std::endl;
	std::string sqlCommand = "SELECT * FROM Attendacne";
	attendancesRecords = executeGetAttendace(sqlCommand.c_str());
	return attendancesRecords;
}
std::vector<subject>  DziennikLib::findSubjectsAll()
{
	std::vector<subject> subjectsRecords;
	std::cout << "Grades table:" << std::endl << std::endl;
	std::string sqlCommand = "SELECT * FROM Subjects";
	subjectsRecords = executeGetSubject(sqlCommand.c_str());
	return subjectsRecords;
}
std::vector<teacher>  DziennikLib::findTeacherstAll()
{
	std::vector<teacher> teachersRecords;
	std::cout << "Grades table:" << std::endl << std::endl;
	std::string sqlCommand = "SELECT * FROM Teachers";
	teachersRecords = executeGetTeacher(sqlCommand.c_str());
	return teachersRecords;
}
std::vector<user>  DziennikLib::findUsersAll()
{
	std::vector<user> usersRecords;
	std::string sqlCommand = "SELECT * FROM Users";
	usersRecords = executeGetUser(sqlCommand.c_str());
	return usersRecords;
}