#pragma once
#include <string>
#include <iostream>
#include "DziennikLib.h"

class student 
{
private:
	std::string Pesel;
	std::string  Name;
	std::string Surname;
	std::string Birthday;

	friend class DziennikLib;

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
		Surname = surname;
	}

	void setBirthday(std::string birthday)
	{
		Birthday = birthday;
	}

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

	


	friend std::ostream& operator<<( std::ostream& os, const student& element)
	{
		os << "------------------------------" << std::endl;
		os << "Pesel: \t\t" << element.Pesel << std::endl;
		os << "Name: \t\t" << element.Name << std::endl;
		os << "Surname: \t" << element.Surname << std::endl;
		os << "Birthday: \t" << element.Birthday << std::endl ;
		os << "------------------------------" << std::endl << std::endl;
		return os;
	}

};

