#pragma once
#include <sqlite3.h>
#include <iostream>
#include <fstream>
#include<string>
#include <openssl/sha.h>


class DziennikLib
{
private:
	sqlite3* db=NULL;
	std::string DataBaseDir;


	bool errorHandler(const char* warrningMessage)
	{
		//TODO: adjust error handler to wx widget

		std::cout << "ERROR:" << std::endl << warrningMessage << std::endl << std::endl;
		return true;
	}

	bool warrningHandler(const char* warrningMessage)
	{
		//TODO: adjust warring handler to wx widget
		std::cout << "warrning:" << std::endl << warrningMessage << std::endl << std::endl;
		return true;
	}



	void actionMessage(const char* message)
	{
		std::cout << std::endl << message << std::endl;
	}

	void executeSqlInsert(std::string sqlCommand)
	{
		char* errorMsg;
		if (sqlite3_exec(this->db, sqlCommand.c_str(), NULL, NULL, &errorMsg) != SQLITE_OK)
		{
			warrningHandler(errorMsg);
		}
		
	}

	

	void executeSqlPrint(std::string sqlCommand)
	{
		char* errorMsg;

		if (sqlite3_exec(this->db, sqlCommand.c_str(), callbackPrint, NULL, &errorMsg) != SQLITE_OK)
		{
			warrningHandler(errorMsg);
		}

	}

	static int callbackPrint(void* data, int argc, char** argv, char** azColName) {
		int i;
		for (i = 0; i < argc; i++) {
			printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
		}
		printf("\n");
		return 0;
	}

	void createBasictables()
	{
		std::ifstream file;
		file.open("res/BasicDataBaseTemplate.sql", std::ios_base::in);
		std::string sqlCommand = "";
		std::string buffer;
		
		while(std::getline(file, buffer))
		{
			if (buffer == "--END")
			{
				executeSqlInsert(sqlCommand);
				sqlCommand.clear();
			}
			else
			sqlCommand += buffer + "\n";
		}
		file.close();
	}

	void removeDataBaseFile()
	{
		
		if (std::remove(DataBaseDir.c_str()) < 0)
		{
			warrningHandler("could not remove prevoius dataBase");
			perror("_unlink");
		}
	}

	bool isDataBaseExist()
	{
		return isFileExist((char *)this->DataBaseDir.c_str());
	}





public:

	enum Account_types{ADMIN, TEACHER, STUDNET};

	bool login(std::string nick, std::string password)
	{
		
		std::string encryprtedPass= encrypt(password);
		std::cout << "password: " << password << std::endl << "encrypted: " << encryprtedPass << std::endl;
		return true;
	}

	//insert to DataBase
	void insertIntoStudnets(std::string pesel, std::string name, std::string surname, std::string birthday);
	void insertIntoGrades(std::string Student_id, std::string Subject_id, std::string Grade);
	void insertIntoAttendacne(std::string Date, std::string Lesson_num, std::string Teacher_id, std::string Student_id, std::string Status);
	void insertIntoSubjects(std::string Name);
	void insertIntoTeachers(std::string pesel, std::string name, std::string surname, std::string birthday, std::string Subject_id);
	void insertIntoUsers(std::string nick, std::string Password, std::string Account_type, std::string Id_in_db);
	void insertIntoUsers(std::string nick, std::string Password, std::string Account_type);

	//printDataBase
	void printStudents();
	void printTeachers();
	void printUsers();
	void printGrades();
	void printAttendacne();
	void printSubjects();
	void printDataBase();



	std::string encrypt(std::string text)
	{
		unsigned char* txt = (unsigned char*)text.c_str();
		unsigned char encryprtedTxt[SHA256_DIGEST_LENGTH+1];
		memset(encryprtedTxt, 0, sizeof(encryprtedTxt));
		SHA256(txt, strlen((const char*)txt), encryprtedTxt);
		return std::string((char*)encryprtedTxt)+"\0";
	}



	void createNewDataBase(char* fileDir)
	{
		do
		{
			this->DataBaseDir = std::string(fileDir);
		actionMessage("checing if data abse alrady exist");
		if (this->isDataBaseExist())
		{
			if (warrningHandler("Data Base alrady exist")==false)
			{
				break;
			}
			actionMessage("removing previous dataBase");
			removeDataBaseFile();
			
		}
		actionMessage("opening DataBase");
		if (sqlite3_open(DataBaseDir.c_str(), &this->db))
		{
			errorHandler("could not open data base");
		}
		}while(0);
		
		createBasictables();
	}


	//testing methods
	void insertDefaultData();



	//utilities
	static bool isFileExist(char* fileDir)
	{
		std::ifstream file(fileDir);
		if (!file.is_open()) {
			return false;
		}
		file.close();
		return true;
	}
};

