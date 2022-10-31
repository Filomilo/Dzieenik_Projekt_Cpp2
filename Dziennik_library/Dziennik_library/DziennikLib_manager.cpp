#include "DziennikLib.h"
#include <sqlite3.h>

void DziennikLib::loadDataBase(char* fileDir)
{
	this->DataBaseDir = std::string(fileDir);
	actionMessage("opening DataBase");
	if (sqlite3_open(DataBaseDir.c_str(), &this->db))
	{
		errorHandler("could not open data base");
	}
}

void DziennikLib::createNewDataBase(char* fileDir)
{
	do
	{
		this->DataBaseDir = std::string(fileDir);
		actionMessage("checing if data abse alrady exist");
		if (this->isDataBaseExist())
		{
			if (warrningHandler("Data Base alrady exist") == false)
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
		createBasictables();
	} while (0);
}

	void DziennikLib::createBasictables()
	{
		std::ifstream file;
		file.open("res/BasicDataBaseTemplate.sql", std::ios_base::in);
		std::string sqlCommand = "";
		std::string buffer;

		while (std::getline(file, buffer))
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


void DziennikLib::removeDataBaseFile()
{

	if (std::remove(DataBaseDir.c_str()) < 0)
	{
		warrningHandler("could not remove prevoius dataBase");
		perror("_unlink");
	}
}

bool DziennikLib::isDataBaseExist()
{
	return isFileExist((char*)this->DataBaseDir.c_str());
}