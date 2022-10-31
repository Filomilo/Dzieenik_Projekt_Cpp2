#pragma once
#include <sqlite3.h>
#include <iostream>
#include <fstream>
#include<string>
#include <openssl/sha.h>
#include "student.h"
#include <vector>


class DziennikLib
{
private:

	//*********************************************************    Varaibles
	sqlite3* db = NULL;
	std::string DataBaseDir;
	int LoginId = -1;

	//*********************************************************    Constants

	//*********************************************************    callbacks
	static int callbackPrint(void* data, int argc, char** argv, char** azColName);
	static int callbackGetAmount(void* data, int argc, char** argv, char** azColName);
	static int callbackGetStudent(void* data, int argc, char** argv, char** azColName);
	
	//*********************************************************    communication
	bool errorHandler(const char* warrningMessage);
	bool warrningHandler(const char* warrningMessage);
	void actionMessage(const char* message);

	//*********************************************************    execute
	void executeSqlInsert(std::string sqlCommand);
	void executeSqlPrint(std::string sqlCommand);
	int executeSqlAmount(std::string sqlCommand);
	std::vector<student> executeGetStudent(std::string sqlCommand);

	//*********************************************************    find
	
	//*********************************************************    insert
	
	//*********************************************************    manager
	void createBasictables();
	void removeDataBaseFile();
	
	//*********************************************************    print
	
	//*********************************************************    testing

	//*********************************************************    tools
	
	//*********************************************************    update
	
	//*********************************************************    validators
	bool validateLogin(std::string nick, std::string password);
	
	//*********************************************************    account
	int getAmountOfLogin(std::string nick, std::string password);


public:

	//*********************************************************    Varaibles

	//*********************************************************    Constants
	enum Account_types { ADMIN, TEACHER, STUDNET };
	enum Attendance_types { PRESENT, ABSENT, LATE, EXCUSED };

	//*********************************************************    callbacks

	//*********************************************************    communication

	//*********************************************************    execute

	//*********************************************************    find
	student findStudentByPesel(std::string pesel);

	//*********************************************************    insert
	void insertIntoStudnets(std::string pesel, std::string name, std::string surname, std::string birthday);
	void insertIntoGrades(std::string Student_id, std::string Subject_id, std::string Grade);
	void insertIntoAttendacne(std::string Date, std::string Lesson_num, std::string Teacher_id, std::string Student_id, std::string Status);
	void insertIntoSubjects(std::string Name);
	void insertIntoTeachers(std::string pesel, std::string name, std::string surname, std::string birthday, std::string Subject_id);
	void insertIntoUsers(std::string nick, std::string Password, std::string Account_type, std::string Id_in_db);
	void insertIntoUsers(std::string nick, std::string Password, std::string Account_type);

	//*********************************************************    manager
	void createNewDataBase(char* fileDir);
	void loadDataBase(char* fileDir);
	bool isDataBaseExist();

	//*********************************************************    print
	void printStudents();
	void printTeachers();
	void printUsers();
	void printGrades();
	void printAttendacne();
	void printSubjects();
	void printDataBase();

	//*********************************************************    testing
	void insertDefaultData();

	//*********************************************************    tools
	static bool isFileExist(char* fileDir);

	//*********************************************************    update
	void updateGrade(std::string gradeId, std::string newGrade);
	void updateAttandance(std::string attandanceId, std::string newStatus);

	//*********************************************************    validators

	//*********************************************************    account
	bool login(std::string nick, std::string password);
	std::string encrypt(std::string text);

};

