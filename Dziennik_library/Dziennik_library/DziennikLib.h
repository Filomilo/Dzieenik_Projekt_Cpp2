#pragma once
#include <sqlite3.h>
#include <iostream>
#include <fstream>
#include<string>
#include <openssl/sha.h>


class DziennikLib
{
private:




	sqlite3* db;
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

	void executeSql(std::string sqlCommand)
	{
		char* errorMsg;
		if (sqlite3_exec(this->db, sqlCommand.c_str(), NULL, NULL, &errorMsg) != SQLITE_OK)
		{
			warrningHandler(errorMsg);
		}
		
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
				executeSql(sqlCommand);
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

	std::string encrypt(std::string text)
	{	
		unsigned char* txt = (unsigned char*)text.c_str();
		unsigned char encryprtedTxt[100];
		SHA1(txt, strlen((const char*)txt), encryprtedTxt);
		return std::string((char *)encryprtedTxt);

	}
	

public:

	bool login(std::string nick, std::string password)
	{
		
		std::string encryprtedPass= encrypt(password);
		std::cout << "password: " << password << std::endl << "encrypted: " << encryprtedPass << std::endl;
		return true;
	}

	void insertIntoStudnets(std::string pesel, std::string name, std::string surname, std::string birthday)
	{
		std::string sqlCommand = "INSERT INTO Students (Pesel,Name,Surname,Birthday)\nVALUES('" + pesel + "','" + name + "','" + surname + "','" + birthday + "');";
		std::cout << sqlCommand << std::endl;
		executeSql(sqlCommand);
	}

	void insertIntoGrades(std::string Student_id, std::string Subject_id, std::string Grade)
	{
		std::string sqlCommand = "INSERT INTO Grades (Student_id,Subject_id,Grade)\nVALUES('" + Student_id + "'," + Subject_id + "," + Grade + ");";
		std::cout << sqlCommand << std::endl;
		executeSql(sqlCommand);
	}

	void insertIntoAttendacne(std::string Date, std::string Lesson_num, std::string Teacher_id, std::string Student_id, std::string Status)
	{
		std::string sqlCommand = "INSERT INTO Attendacne (Date,Lesson_num,Teacher_id,Student_id,Status)\nVALUES('" + Date + "'," + Lesson_num + + ",'" + Teacher_id + "','" + Student_id +"','"+ Status+ "');";
		std::cout << sqlCommand << std::endl;
		executeSql(sqlCommand);
	}
	
	void insertIntoSubjects(std::string Name)
	{
		std::string sqlCommand = "INSERT INTO Subjects (Name)\nVALUES('" + Name +"');";
		std::cout << sqlCommand << std::endl;
		executeSql(sqlCommand);
	}

	void insertIntoTeachers(std::string pesel, std::string name, std::string surname, std::string birthday, std::string Subject_id)
	{
		std::string sqlCommand = "INSERT INTO Teachers (Pesel,Name,Surname,Birthday,Subject_id)\nVALUES('" + pesel + "','" + name + "','" + surname + "','" + birthday + "','" + Subject_id +"');";
		std::cout << sqlCommand << std::endl;
		executeSql(sqlCommand);
	}

	static bool isFileExist(char* fileDir)
	{
		std::ifstream file(fileDir);
		if (!file.is_open()) {
			return false;
		}
		file.close();
		return true;
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

};

