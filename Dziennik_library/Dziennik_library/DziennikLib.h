#pragma once
#include <sqlite3.h>
#include <iostream>
#include <fstream>
#include<string>


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

	void removeDataBase()
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
			removeDataBase();
			
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

