#include "DziennikLib.h"
#include <vector>
#include "student.h"
void DziennikLib::printStudents()
{
	std::cout << "Students table:" << std::endl << std::endl;
	const char* sqlCommand = "SELECT * FROM Students";
	std::vector<student> students;
	students= executeGetStudent(sqlCommand);
	for (auto it = students.begin(); it != students.end(); it++)
	{
		std::cout << *it << std::endl;
	}
	std::cout << std::endl;
}

void DziennikLib::printTeachers()
{
	std::cout << "Teachers table:" << std::endl << std::endl;
	const char* sqlCommand = "SELECT * FROM Teachers";
	std::vector<user> users;
	executeSqlPrint(sqlCommand);
	std::cout << std::endl;
}

void DziennikLib::printUsers()
{
	std::cout << "Users table:" << std::endl << std::endl;
	const char* sqlCommand = "SELECT * FROM Users";
	executeSqlPrint(sqlCommand);
	std::vector<user> users;
	users = executeGetUser(sqlCommand);
	for (auto it = users.begin(); it != users.end(); it++)
	{
		std::cout << *it << std::endl;
	}
	std::cout << std::endl;
}

void DziennikLib::printGrades()
{
	std::cout << "Grades table:" << std::endl << std::endl;
	const char* sqlCommand = "SELECT * FROM Grades";
	executeSqlPrint(sqlCommand);
	std::cout << std::endl;
}

void DziennikLib::printAttendacne()
{
	std::cout << "Attendacne table:" << std::endl << std::endl;
	const char* sqlCommand = "SELECT * FROM Attendacne";
	executeSqlPrint(sqlCommand);
	std::cout << std::endl;
}

void DziennikLib::printSubjects()
{
	std::cout << "Subjects table:" << std::endl << std::endl;
	const char* sqlCommand = "SELECT * FROM Subjects";
	executeSqlPrint(sqlCommand);
	std::cout << std::endl;
}

void DziennikLib::printDataBase()
{
	printStudents();
	printTeachers();
	printUsers();
	printGrades();
	printSubjects();
	printAttendacne();
}
