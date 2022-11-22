#pragma once
#include <string>
#include <iostream>
#include "DziennikLib.h"

class teacher
{
private:
	std::string Pesel;
	std::string  Name;
	std::string Surname;
	std::string Birthday;
	int Subject_id;

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

	void setSubjectId(int subject_id)
	{
		Subject_id = subject_id;
	}
	void setSubjectId(std::string subject_id)
	{
		setSubjectId(stoi(subject_id));
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
		return Surname;
	}
	std::string getBirthday()
	{
		return Birthday;
	}

    	int getBirthdayYear()
	{
	    std::string year=getBirthday().substr(0, 4);
		return stoi(year);
	}

	 	int getBirthdayMonth()
	{
	    std::string month=getBirthday().substr(5, 7);
		return stoi(month);
	}
	
		int getBirthdayDay()
	{
	    std::string day=getBirthday().substr(8, 10);
		return stoi(day);
	}

	int getSubjectId()
	{
		return Subject_id;
	}

	friend std::ostream& operator<<(std::ostream& os, const teacher& element)
	{
		os << "------------------------------" << std::endl;
		os << "Pesel: \t\t" << element.Pesel << std::endl;
		os << "Name: \t\t" << element.Name << std::endl;
		os << "Surname: \t" << element.Surname << std::endl;
		os << "Birthday: \t" << element.Birthday << std::endl;
		os << "Subject_id: \t" << element.Subject_id << std::endl;
		os << "------------------------------" << std::endl << std::endl;
		return os;
	}

};

