#include "DziennikLib.h"

void DziennikLib::insertIntoTeachers(std::string pesel, std::string name, std::string surname, std::string birthday, std::string Subject_id)
{
	std::string sqlCommand = "INSERT INTO Teachers (Pesel,Name,Surname,Birthday,Subject_id)\nVALUES('" + pesel + "','" + name + "','" + surname + "','" + birthday + "','" + Subject_id + "');";
	std::cout << sqlCommand << std::endl;
	executeSqlInsert(sqlCommand);
}

void DziennikLib::insertIntoSubjects(std::string Name)
{
	std::string sqlCommand = "INSERT INTO Subjects (Name)\nVALUES('" + Name + "');";
	std::cout << sqlCommand << std::endl;
	executeSqlInsert(sqlCommand);
}

void DziennikLib::insertIntoAttendacne(std::string Date, std::string Lesson_num, std::string Teacher_id, std::string Student_id, std::string Status)
{
	std::string sqlCommand = "INSERT INTO Attendacne (Date,Lesson_num,Teacher_id,Student_id,Status)\nVALUES('" + Date + "'," + Lesson_num + +",'" + Teacher_id + "','" + Student_id + "','" + Status + "');";
	std::cout << sqlCommand << std::endl;
	executeSqlInsert(sqlCommand);
}

void DziennikLib::insertIntoGrades(std::string Student_id, std::string Subject_id, std::string Grade)
{
	std::string sqlCommand = "INSERT INTO Grades (Student_id,Subject_id,Grade)\nVALUES('" + Student_id + "'," + Subject_id + "," + Grade + ");";
	std::cout << sqlCommand << std::endl;
	executeSqlInsert(sqlCommand);
}

void DziennikLib::insertIntoStudnets(std::string pesel, std::string name, std::string surname, std::string birthday)
{
	std::string sqlCommand = "INSERT INTO Students (Pesel,Name,Surname,Birthday)\nVALUES('" + pesel + "','" + name + "','" + surname + "','" + birthday + "');";
	std::cout << sqlCommand << std::endl;
	executeSqlInsert(sqlCommand);
}

void DziennikLib::insertIntoUsers(std::string nick, std::string Password, std::string Account_type, std::string Id_in_db)
{
	std::string sqlCommand = "INSERT INTO Users (Nick,Password,Acccount_Type,Id_in_db)\nVALUES('" + nick + "','" + Password + "'," + Account_type + ",'" + Id_in_db + "');";
	std::cout << sqlCommand << std::endl;
	executeSqlInsert(sqlCommand);
}

void DziennikLib::insertIntoUsers(std::string nick, std::string Password, std::string Account_type)
{
	std::string sqlCommand = "INSERT INTO Users (Nick,Password,Acccount_Type)\nVALUES('" + nick + "',\"" + Password + "\"," + Account_type + ");";
	std::cout << sqlCommand << std::endl;
	executeSqlInsert(sqlCommand);
}

