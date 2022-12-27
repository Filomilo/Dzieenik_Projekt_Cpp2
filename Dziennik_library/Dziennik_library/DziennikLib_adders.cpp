#include "DziennikLib.h"


void DziennikLib::addStudent(std::string Pesel, std::string Name, std::string Surname, std::string Birthday)
{
	this->insertIntoStudnets(Pesel, Name, Surname, Birthday);
	this->addUser(Name + Surname + Birthday.substr(0,4), Pesel,(int)Account_types::STUDNET,Pesel);
}
void DziennikLib::addAttendacne(std::string Date, int Lesson_num, std::string Teacher_pesel, std::string Sudent_pesel, int Status)
{
	std::string lessonNum = std::to_string(Lesson_num);
	std::string status = std::to_string(Status);
	this->insertIntoAttendacne(Date, lessonNum, Teacher_pesel, Sudent_pesel, status);
}
void DziennikLib::addGrade(std::string Sudent_pesel, int Subject_id, int grade)
{
	std::string subjectId = std::to_string(Subject_id);
	std::string Grade = std::to_string(grade);
	this->insertIntoGrades(Sudent_pesel, subjectId, Grade);
}
void DziennikLib::addSubject(std::string Name)
{
	this->insertIntoSubjects(Name);
}
void DziennikLib::addTeacher(std::string Pesel, std::string Name, std::string Surname, std::string Birthday, int subject_id)
{
	std::string subjectId = std::to_string(subject_id);
	this->insertIntoTeachers(Pesel, Name, Surname, Birthday, subjectId);
	this->addUser(Name + Surname + Birthday.substr(0,4), Pesel,(int)Account_types::TEACHER,Pesel);
}
void DziennikLib::addUser(std::string Nick, std::string Passowrd, int Account_Type, std::string Id_in_db)
{
	std::string accountType = std::to_string(Account_Type);
	this->insertIntoUsers(Nick, this->encrypt(Passowrd), accountType, Id_in_db);
}
void DziennikLib::addUser(std::string Nick, std::string Passowrd, int Account_Type)
{
	std::string accountType = std::to_string(Account_Type);
	this->insertIntoUsers(Nick, this->encrypt(Passowrd), accountType);
}





