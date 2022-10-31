#pragma once
#pragma once
#include <string>
#include <iostream>
#include "DziennikLib.h"

class grade
{
private:
	int Grade_id;
	std::string  Student_id;
	int Subject_id;
	int Grade;

	friend class DziennikLib;

	void setSubjectId(int subject_id)
	{
		Subject_id = subject_id;
	}

	void setSubjectId(std::string subject_id)
	{
		setSubjectId(std::stoi(subject_id));
	}

	void setGrade(int subject_id)
	{
		Subject_id = subject_id;
	}

	void setGrade(std::string subject_id)
	{
		setGrade(std::stoi(subject_id));
	}

	void setGradeId(int grade_id)
	{
		Grade_id = grade_id;
	}

	void setGradeId(std::string grade_id)
	{
		setGrade(std::stoi(grade_id));
	}

	void setStudentId(std::string student_id)
	{
		Student_id = student_id;
	}



public:
	int getSubjectId()
	{
		return Subject_id;
	}

	int getGradeId()
	{
		return Grade_id;
	}

	int getGrade()
	{
		return Grade;
	}

	std::string getStudentId()
	{
		return Student_id;
	}

	

	friend std::ostream& operator<<(std::ostream& os, const grade& element)
	{
		os << "------------------------------" << std::endl;
		os << "Grade_Id: \t\t" << element.Grade_id << std::endl;
		os << "Student_id: \t\t" << element.Student_id << std::endl;
		os << "Subject_id: \t\t" << element.Subject_id << std::endl;
		os << "Grade: \t\t" << element.Grade << std::endl;

		os << "------------------------------" << std::endl << std::endl;
		return os;
	}

};

