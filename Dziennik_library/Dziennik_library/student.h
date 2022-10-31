#pragma once
#include <string>
#include <iostream>
#include "RecordBaseClass.h"

class student : public RecordBaseClass
{
private:
	std::string Pesel;
	std::string  Name;
	std::string Surname;
		std::string Birthday;
public:
	std::string getPesel()
	{
		return Pesel;
	}

	std::string getName()
	{
		return Name;
	}

	std::string getSurname()
	{
		return Name;
	}
	std::string getBirthday()
	{
		return Name;
	}

	

	void setPesel(std::string pesel)
	{
		Pesel = pesel;
	}

	void setName(std::string name)
	{
		Name = name;
	}

	void setSurname(std::string surname)
	{
		Name = surname;
	}

	void setBirthday(std::string birthday)
	{
		Birthday = birthday;
	}

	friend std::ostream& operator<<( std::ostream& os, const student& element)
	{
		os << element.Pesel << std::endl;
		return os;
	}

};

