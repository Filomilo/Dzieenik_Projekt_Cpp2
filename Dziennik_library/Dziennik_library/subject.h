#pragma once
#pragma once
#include <string>
#include <iostream>
#include "DziennikLib.h"

class subject
{
private:
	int Subject_id;
	std::string  Name;

	friend class DziennikLib;

	void setSubjectId(int subject_id)
	{
		Subject_id = subject_id;
	}

	void setSubjectId(std::string subject_id)
	{
		setSubjectId(std::stoi(subject_id));
	}

	void setName(std::string name)
	{
		Name = name;
	}

	

public:
	int getSubjectId()
	{
		return Subject_id;
	}

	std::string getName()
	{
		return Name;
	}

	friend std::ostream& operator<<(std::ostream& os, const subject& element)
	{
		os << "------------------------------" << std::endl;
		os << "Subject_id: \t\t" << element.Subject_id << std::endl;
		os << "Name: \t\t" << element.Name << std::endl;
		os << "------------------------------" << std::endl << std::endl;
		return os;
	}

};

