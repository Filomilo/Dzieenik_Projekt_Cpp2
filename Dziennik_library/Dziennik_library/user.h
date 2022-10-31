#pragma once
#include <string>
#include <iostream>
#include "DziennikLib.h"

class user
{
private:
	int User_id;
	std::string  Nick;
	std::string Password;
	int Acccount_Type;
	std::string Id_in_db;

	friend class DziennikLib;

	void setUserId(std::string user_id)
	{
		User_id = std::stoi(user_id);
	}

	void setNick(std::string nick)
	{
		Nick = nick;
	}

	void setPassword(std::string password)
	{
		Password = password;
	}

	void setAccountType(std::string account_type)
	{
		Acccount_Type = std::stoi(account_type);
	}

	void setAccountType(int account_type)
	{
		Acccount_Type = account_type;
	}

	void setIdInDb(std::string id_in_db)
	{
		Id_in_db = id_in_db;
	}

public:
	std::string getNick()
	{
		return Nick;
	}

	int getUserId()
	{
		return User_id;
	}

	int getAccountType()
	{
		return Acccount_Type;
	}

	std::string getPassword()
	{
		return Password;
	}

	std::string getIdInDb()
	{
		return Id_in_db;
	}

	friend std::ostream& operator<<(std::ostream& os, const user& element)
	{
		os << "------------------------------" << std::endl;
		os << "User_Id: \t" << element.User_id << std::endl;
		os << "Nick: \t\t" << element.Nick << std::endl;
		os << "Password: \t" << element.Password << std::endl;
		os << "Acccount_Type: \t" << element.Acccount_Type << std::endl;
		os << "Id_in_db: \t" << element.Id_in_db << std::endl;
		os << "------------------------------" << std::endl << std::endl;
		return os;
	}

};

