#include "DziennikLib.h"
#include <vector>
#include "student.h"
void DziennikLib::printStudents()
{
	std::cout << "Students table:" << std::endl << std::endl;
	std::vector<student> students=this->findSstudentAll();
	for (auto it = students.begin(); it != students.end(); it++)
	{
		std::cout << *it << std::endl;
	}
	std::cout << std::endl;
}

void DziennikLib::printTeachers()
{
	std::cout << "Teachers table:" << std::endl << std::endl;
	std::vector<teacher> teachers = this->findTeacherstAll();
	for (auto it = teachers.begin(); it != teachers.end(); it++)
	{
		std::cout << *it << std::endl;
	}
	std::cout << std::endl;
}

void DziennikLib::printUsers()
{
	std::cout << "Users table:" << std::endl << std::endl;
	std::vector<user> users = this->findUsersAll();
	for (auto it = users.begin(); it != users.end(); it++)
	{
		std::cout << *it << std::endl;
	}
	std::cout << std::endl;
}

void DziennikLib::printGrades()
{
	std::cout << "Grades table:" << std::endl << std::endl;
	std::vector<grade> grades = this->findGradesAll();
	for (auto it = grades.begin(); it != grades.end(); it++)
	{
		std::cout << *it << std::endl;
	}
	std::cout << std::endl;
}

void DziennikLib::printAttendacne()
{
	
	std::cout << "Attendacne table:" << std::endl << std::endl;
	std::vector<attendance> attendances = this->findAttandanceAll();
	for (auto it = attendances.begin(); it != attendances.end(); it++)
	{
		std::cout << *it << std::endl;
	}
	std::cout << std::endl;
	
}

void DziennikLib::printSubjects()
{
	std::cout << "Subjects table:" << std::endl << std::endl;
	std::vector<subject> subjects = this->findSubjectsAll();
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
