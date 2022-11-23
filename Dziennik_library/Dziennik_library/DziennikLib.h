#pragma once
#include <sqlite3.h>
#include <iostream>
#include <fstream>
#include<string>
//#include <openssl/sha.h>
#include <vector>

#include "student.h"
#include "user.h"
#include "grade.h"
#include "attendance.h"
#include "teacher.h"
#include "subject.h"


class DziennikLib
{
private:

	//*********************************************************    Varaibles
	sqlite3* db = NULL;
	std::string DataBaseDir;
	int LoginId = -1;

	//*********************************************************    Constants
	//TODO: change using sql from file to const
	const char* sqlCommadCreateStudents;
	const char* sqlCommadCreateAttendacne;
	const char* sqlCommadCreatePesel;
	const char* sqlCommadCreateGrades;
	const char* sqlCommadCreateSubjects;
	const char* sqlCommadCreateTeachers;
	const char* sqlCommadCreateUsers;

	//*********************************************************    callbacks
	static int callbackPrint(void* data, int argc, char** argv, char** azColName);
	static int callbackGetAmount(void* data, int argc, char** argv, char** azColName);
	static int callbackGetStudent(void* data, int argc, char** argv, char** azColName);
	static int callbackGetUser(void* data, int argc, char** argv, char** azColName);
	static int callbackGetTeacher(void* data, int argc, char** argv, char** azColName);
	static int callbackGetAttendacne(void* data, int argc, char** argv, char** azColName);
	static int callbackGetGrade(void* data, int argc, char** argv, char** azColName);
	static int callbackGetSubject(void* data, int argc, char** argv, char** azColName);


	//*********************************************************    communication
	bool errorHandler(const char* warrningMessage);
	bool warrningHandler(const char* warrningMessage);
	void actionMessage(std::string message);

	//*********************************************************    execute
	void executeSqlInsert(std::string sqlCommand);
	void executeSqlPrint(std::string sqlCommand);
	int executeSqlAmount(std::string sqlCommand);
	std::vector<student> executeGetStudent(std::string sqlCommand);
	std::vector<user> executeGetUser(std::string sqlCommand);
	std::vector<teacher> executeGetTeacher(std::string sqlCommand);
	std::vector<subject> executeGetSubject(std::string sqlCommand);
	std::vector<attendance> executeGetAttendace(std::string sqlCommand);
	std::vector<grade> executeGetGrade(std::string sqlCommand);


	//*********************************************************    find
	std::vector<user>  findUserbyNickbyPass(std::string nick, std::string pass);

	//*********************************************************    insert
	void insertIntoStudnets(std::string pesel, std::string name, std::string surname, std::string birthday);
	void insertIntoGrades(std::string Student_id, std::string Subject_id, std::string Grade);
	void insertIntoAttendacne(std::string Date, std::string Lesson_num, std::string Teacher_id, std::string Student_id, std::string Status);
	void insertIntoSubjects(std::string Name);
	void insertIntoTeachers(std::string pesel, std::string name, std::string surname, std::string birthday, std::string Subject_id);
	void insertIntoUsers(std::string nick, std::string Password, std::string Account_type, std::string Id_in_db);
	void insertIntoUsers(std::string nick, std::string Password, std::string Account_type);

	//*********************************************************    manager
	void createBasictables();
	void removeDataBaseFile();

	//*********************************************************    print

	//*********************************************************    testing

	//*********************************************************    tools

	//*********************************************************    update
	void updateGrade(std::string gradeId, std::string newGrade);
	void updateAttandance(std::string attandanceId, std::string newStatus);

	//*********************************************************    validators
	bool validateLogin(std::string nick, std::string password);

	//*********************************************************    account
	int getAmountOfLogin(std::string nick, std::string password);


	//*********************************************************    friends
	friend class student;
	friend class teacher;
	friend class grade;
	friend class attendance;
	friend class subject;



public:

	//*********************************************************    Varaibles

	//*********************************************************    Constants
	enum Account_types { ADMIN, TEACHER, STUDNET };
	enum Attendance_types { PRESENT, ABSENT, LATE, EXCUSED };

	//*********************************************************    callbacks

	//*********************************************************    communication

	//*********************************************************    execute

	//*********************************************************    find
	std::vector<student>  findStudentByPesel(std::string pesel);
	std::vector<student>  findSstudentAll();
	std::vector<grade>  findGradesAll();
	std::vector<attendance>  findAttandanceAll();
	std::vector<subject>  findSubjectsAll();
	std::vector<subject>  findSubjectsById(int id);
	std::vector<teacher>  findTeacherstAll();
	std::vector<teacher>  findTeachersByPesel(std::string pesel);
	std::vector<user>  findUsersAll();
	std::vector<user>  findUsersById(int id);
	std::vector<grade>findGradesByStudentId(std::string pesel);

    //*********************************************************    remove
    void removeSubject(int subjectId);
	void removeTeacher(std::string teacherPesel);
	void removeStudent(std::string studentPesel);

	//*********************************************************    insert


	//*********************************************************    manager
	void createNewDataBase(char* fileDir);
	void createNewDataBase(std::string fileDir);
	void createNewDataBase(std::string fileDir,std::string adminLogin, std::string adminPass);
	void loadDataBase(char* fileDir);
	void loadDataBase(std::string fileDir);

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
	void updateSubject(int subjectId,std::string Name);
	void updateTeacher(std::string Pesel, std::string Name, std::string Surname, std::string Birthday, int subject_id);
	void updateStudent(std::string Pesel, std::string Name, std::string Surname, std::string Birthday);


	//*********************************************************    validators

	//*********************************************************    adders
	void addStudent(std::string Pesel, std::string Name, std::string Surname, std::string Birthday);
	void addAttendacne(std::string Date, int Lesson_num, std::string Teacher_pesel, std::string Sudent_pesel, int Status );
	void addGrade(std::string Sudent_pesel, int Subject_id, int grade);
	void addSubject(std::string Name);
	void addTeacher(std::string Pesel, std::string Name, std::string Surname, std::string Birthday, int subject_id);
	void addUser(std::string Nick, std::string Passowrd, int Account_Type, std::string Id_in_db);
	void addUser(std::string Nick, std::string Passowrd, int Account_Type);



	//*********************************************************    account
	bool login(std::string nick, std::string password);
	std::string encrypt(std::string text);
	bool isUserLogged();
	std::string getUserNick();
	int getUserAccountType();
	bool isUserAdmin();
	bool isUserTeacher();
	bool isUserStudent();
	std::string getUserIdInDb();
	student getUserStudentProfile();
	teacher getUserTeacherProfile();
};

