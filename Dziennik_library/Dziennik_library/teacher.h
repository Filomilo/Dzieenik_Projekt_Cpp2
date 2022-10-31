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
		return Name;
	}
	std::string getBirthday()
	{
		return Name;
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

