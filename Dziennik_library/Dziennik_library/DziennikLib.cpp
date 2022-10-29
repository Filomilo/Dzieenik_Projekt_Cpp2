#include "DziennikLib.h"

//insert to dat aBase
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



//update Grade

//print Functioons

void DziennikLib::printStudents()
{
	std::cout << "Students table:" << std::endl << std::endl;
	const char* sqlCommand = "SELECT * FROM Students";
	executeSqlPrint(sqlCommand);
	std::cout << std::endl;
}

void DziennikLib::printTeachers()
{
	std::cout << "Teachers table:" << std::endl << std::endl;
	const char* sqlCommand = "SELECT * FROM Teachers";
	executeSqlPrint(sqlCommand);
	std::cout << std::endl;
}

void DziennikLib::printUsers()
{
	std::cout << "Users table:" << std::endl << std::endl;
	const char* sqlCommand = "SELECT * FROM Users";
	executeSqlPrint(sqlCommand);
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



//testing methods
void DziennikLib::insertDefaultData()
{
	insertIntoSubjects("angielski");	//1
	insertIntoSubjects("polski");		//2
	insertIntoSubjects("matematyka");	//3
	insertIntoSubjects("informatyka");	//4
	insertIntoSubjects("biologia");		//5
	insertIntoSubjects("historia");		//6
	insertIntoSubjects("w-f");			//7
	insertIntoSubjects("geografia");	//8

	insertIntoStudnets("78032008893", "Jan", "Kowalski", "2003-08-11");
	insertIntoStudnets("85043075127", "Kamil", "Nowak", "2001-11-15");
	insertIntoStudnets("97080905532", "Zbigniew", "Jagie³³o", "2004-04-30");
	insertIntoStudnets("82011833851", "Kamil", "Mieszko", "2002-12-28");
	insertIntoStudnets("86121110824", "Andrzej", "Kaczñski", "2000-01-25");

	insertIntoTeachers("98072068558", "Marzena", "Miko³ajaczyk", "1998-02-18", "1");
	insertIntoTeachers("2657245624", "Zbigniew", "Borowski", "1969-11-01", "2");
	insertIntoTeachers("65246524442", "Krystian", "Król", "1967-12-11", "3");
	insertIntoTeachers("78112917806", "Klaudia", "Dudek", "1978-11-29", "4");
	insertIntoTeachers("64081176966", "Feliksa", "Jakubowska", "1964-08-11", "5");
	insertIntoTeachers("73101234713", "Serhii", "Kaczmarczyk", "1973-10-12", "6");
	insertIntoTeachers("94101061338", "Krystian", "Ziêba", "1994-10-10", "7");


	insertIntoGrades("78032008893", "1", "3");
	insertIntoGrades("78032008893", "5", "1");
	insertIntoGrades("78032008893", "2", "3");
	insertIntoGrades("78032008893", "3", "5");
	insertIntoGrades("78032008893", "1", "3");
	insertIntoGrades("78032008893", "7", "2");

	insertIntoGrades("85043075127", "3", "1");
	insertIntoGrades("85043075127", "3", "2");
	insertIntoGrades("85043075127", "5", "5");
	insertIntoGrades("85043075127", "1", "3");
	insertIntoGrades("85043075127", "3", "6");
	insertIntoGrades("85043075127", "6", "4");

	insertIntoGrades("97080905532", "1", "2");
	insertIntoGrades("97080905532", "3", "4");
	insertIntoGrades("97080905532", "4", "5");
	insertIntoGrades("97080905532", "2", "6");
	insertIntoGrades("97080905532", "5", "3");
	insertIntoGrades("97080905532", "6", "2");

	insertIntoGrades("82011833851", "3", "1");
	insertIntoGrades("82011833851", "2", "2");
	insertIntoGrades("82011833851", "5", "4");
	insertIntoGrades("82011833851", "6", "5");
	insertIntoGrades("82011833851", "7", "2");
	insertIntoGrades("82011833851", "6", "5");

	insertIntoGrades("86121110824", "1", "1");
	insertIntoGrades("86121110824", "2", "2");
	insertIntoGrades("86121110824", "4", "4");
	insertIntoGrades("86121110824", "6", "3");
	insertIntoGrades("86121110824", "7", "5");
	insertIntoGrades("86121110824", "2", "3");

	insertIntoAttendacne("2022-08-20", "1", "98072068558", "78032008893", "spóŸninie");
	insertIntoAttendacne("2022-08-20", "1", "98072068558", "85043075127", "obecny");
	insertIntoAttendacne("2022-08-20", "1", "98072068558", "97080905532", "obecny");
	insertIntoAttendacne("2022-08-20", "1", "98072068558", "82011833851", "obecny");
	insertIntoAttendacne("2022-08-20", "1", "98072068558", "86121110824", "spóŸninie");

	insertIntoAttendacne("2022-08-20", "2", "64081176966", "78032008893", "spóŸninie");
	insertIntoAttendacne("2022-08-20", "2", "64081176966", "85043075127", "obecny");
	insertIntoAttendacne("2022-08-20", "2", "64081176966", "97080905532", "nieobecny");
	insertIntoAttendacne("2022-08-20", "2", "64081176966", "82011833851", "nieobecny");
	insertIntoAttendacne("2022-08-20", "2", "64081176966", "86121110824", "nieobecny");


	insertIntoAttendacne("2022-08-20", "3", "65246524442", "78032008893", "spóŸninie");
	insertIntoAttendacne("2022-08-20", "3", "65246524442", "85043075127", "obecny");
	insertIntoAttendacne("2022-08-20", "3", "65246524442", "97080905532", "spóŸninie");
	insertIntoAttendacne("2022-08-20", "3", "65246524442", "82011833851", "obecny");
	insertIntoAttendacne("2022-08-20", "3", "65246524442", "86121110824", "nieobecny");

	insertIntoAttendacne("2022-08-20", "4", "78112917806", "78032008893", "nieobecny");
	insertIntoAttendacne("2022-08-20", "4", "78112917806", "85043075127", "obecny");
	insertIntoAttendacne("2022-08-20", "4", "78112917806", "97080905532", "spóŸninie");
	insertIntoAttendacne("2022-08-20", "4", "78112917806", "82011833851", "nieobecny");
	insertIntoAttendacne("2022-08-20", "4", "78112917806", "86121110824", "obecny");

	insertIntoUsers("admin",encrypt("admin"), "0");
	insertIntoUsers("Marzena", encrypt("haslo"), "1" ,"98072068558");
	insertIntoUsers("Kamin", encrypt("1234"), "2", "82011833851");

	
}

//utilities

