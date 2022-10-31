#pragma once
#pragma once
#include <string>
#include <iostream>
#include "DziennikLib.h"

class attendance
{
private:
	int Attendacne_id;
	std::string Date;
	int Lesson_num;
	std::string Teacher_id;
	std::string Student_id;
	int Status;

	friend class DziennikLib;

	void setAttendacne_id(int attendacne_id)
	{
		Attendacne_id = attendacne_id;
	}

	void setAttendacne_id(std::string attendacne_id)
	{
		setAttendacne_id(std::stoi(attendacne_id));
	}

	void setLessonNum(int lesson_num)
	{
		Lesson_num = lesson_num;
	}

	void setLessonNum(std::string lesson_num)
	{
		setLessonNum(std::stoi(lesson_num));
	}

	void setStatus(int status)
	{
		Status = status;
	}

	void setStatus(std::string status)
	{
		setStatus(std::stoi(status));
	}

	void setDate(std::string date)
	{
		Date = date;
	}

	void setTeacherId(std::string teacher_id)
	{
		Teacher_id = teacher_id;
	}
	void setStudentId(std::string student_id)
	{
		Student_id = student_id;
	}




public:

	int getAttendacneId()
	{
		return Attendacne_id;
	}

	int getLessonNum()
	{
		return Lesson_num;
	}


	int getStatus()
	{
		return Status;
	}

	std::string getDate()
	{
		return Date;
	}

	std::string getTeacherId()
	{
		return Teacher_id;
	}

	std::string getStudentId()
	{
		return Student_id;
	}



	friend std::ostream& operator<<(std::ostream& os, const attendance& element)
	{
		os << "------------------------------" << std::endl;
		os << "Attendacne_id: \t\t" << element.Attendacne_id << std::endl;
		os << "Date: \t\t" << element.Date << std::endl;
		os << "Lesson_num: \t\t" << element.Lesson_num << std::endl;
		os << "Teacher_id: \t\t" << element.Teacher_id << std::endl;
		os << "Student_id: \t\t" << element.Student_id << std::endl;
		os << "Status: \t\t" << element.Status << std::endl;
		os << "------------------------------" << std::endl << std::endl;
		return os;
	}

};

