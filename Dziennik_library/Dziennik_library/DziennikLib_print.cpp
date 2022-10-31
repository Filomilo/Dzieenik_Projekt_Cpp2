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
	std::vector<teacher> teachers;
	teachers = executeGetTeacher(sqlCommand);
	for (auto it = teachers.begin(); it != teachers.end(); it++)
	{
		std::cout << *it << std::endl;
	}
	std::cout << std::endl;
}

void DziennikLib::printUsers()
{
	std::cout << "Users table:" << std::endl << std::endl;
	const char* sqlCommand = "SELECT * FROM Users";
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
	std::vector<grade> grades;
	grades = executeGetGrade(sqlCommand);
	for (auto it = grades.begin(); it != grades.end(); it++)
	{
		std::cout << *it << std::endl;
	}
	std::cout << std::endl;
}

void DziennikLib::printAttendacne()
{
	
	std::cout << "Attendacne table:" << std::endl << std::endl;
	const char* sqlCommand = "SELECT * FROM Attendacne";
	std::vector<attendance> attendances;
	attendances = executeGetAttendace(sqlCommand);
	for (auto it = attendances.begin(); it != attendances.end(); it++)
	{
		std::cout << *it << std::endl;
	}
	std::cout << std::endl;
	
}

void DziennikLib::printSubjects()
{
	std::cout << "Subjects table:" << std::endl << std::endl;
	const char* sqlCommand = "SELECT * FROM Subjects";
	
	std::vector<subject> subjects;
	
	subjects = executeGetSubject(sqlCommand);
	
	
	for (auto it = subjects.begin(); it != subjects.end(); it++)
	{
		std::cout << *it << std::endl;
	}
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
