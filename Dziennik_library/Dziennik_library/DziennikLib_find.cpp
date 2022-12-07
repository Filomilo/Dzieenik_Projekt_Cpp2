#include "DziennikLib.h"
std::vector<student> DziennikLib::findStudentByPesel(std::string pesel)
{
	std::vector<student> studentRecords;
	std::cout << "Grades table:" << std::endl << std::endl;
	std::string sqlCommand = "SELECT * FROM Students \n WHERE Pesel = '" + pesel + "'";
	studentRecords = executeGetStudent(sqlCommand.c_str());
	return studentRecords;
}

std::vector<student> DziennikLib::findSstudentAll()
{
	std::vector<student> studentRecords;
	std::string sqlCommand = "SELECT * FROM Students ORDER BY Surname DESC, Name";
	studentRecords = executeGetStudent(sqlCommand.c_str());
	return studentRecords;
}

std::vector<grade>  DziennikLib::findGradesAll()
{
	std::vector<grade> gradesRecords;
	std::string sqlCommand = "SELECT * FROM Grades";
	gradesRecords = executeGetGrade(sqlCommand.c_str());
	return gradesRecords;
}

std::vector<grade>  DziennikLib::findGradesByStudentId(std::string pesel)
{
	std::vector<grade> gradesRecords;
	std::string sqlCommand = "SELECT * FROM Grades \n WHERE Student_id = '" + pesel + "' \n ORDER BY Subject_id";
	gradesRecords = executeGetGrade(sqlCommand.c_str());
	return gradesRecords;
}

std::vector<grade>  DziennikLib::findGradesByStudentIdAndSubject(std::string pesel, int subjectId)
{
	std::vector<grade> gradesRecords;
	std::string sqlCommand = "SELECT * FROM Grades \n WHERE Student_id = '" + pesel + "' \n ORDER BY Subject_id";
	gradesRecords = executeGetGrade(sqlCommand.c_str());
	return gradesRecords;
}

int DziennikLib::findMaxGradesFromSubjectByStudentId(std::string pesel)
{
	int maxGrades;
	std::string sqlCommand = "SELECT max(counter) FROM (SELECT Subject_id, count(Grade) counter FROM Grades GROUP BY Subject_id HAVING Student_id=\'"+pesel+"\')";
	maxGrades = executeSqlValue(sqlCommand.c_str());
	return maxGrades;
}


std::vector<attendance>  DziennikLib::findAttandanceAll()
{
	std::vector<attendance> attendancesRecords;
	std::string sqlCommand = "SELECT * FROM Attendacne ORDER BY Date";
	attendancesRecords = executeGetAttendace(sqlCommand.c_str());
	return attendancesRecords;
}

std::vector<attendance>  DziennikLib::findAttandanceByDate(std::string date)
{
	std::vector<attendance> attendancesRecords;
	std::string sqlCommand = "SELECT * FROM Attendacne WHERE DATE = '" + date + "' ORDER BY Date";
	std::cout<<sqlCommand<<std::endl;
	attendancesRecords = executeGetAttendace(sqlCommand.c_str());
	return attendancesRecords;
}

std::vector<attendance>  DziennikLib::findAttandanceByDateAndPesel(std::string date,std::string pesel)
{
	std::vector<attendance> attendancesRecords;
	std::string sqlCommand = "SELECT * FROM Attendacne WHERE DATE = '"+ date+"' And Student_id = '"+ pesel +"' ";
	std::cout<<sqlCommand<<std::endl;
	attendancesRecords = executeGetAttendace(sqlCommand.c_str());
	return attendancesRecords;
}



std::vector<subject>  DziennikLib::findSubjectsAll()
{
	std::vector<subject> subjectsRecords;
	std::string sqlCommand = "SELECT * FROM Subjects";
	subjectsRecords = executeGetSubject(sqlCommand.c_str());
	return subjectsRecords;
}
std::vector<teacher>  DziennikLib::findTeacherstAll()
{
	std::vector<teacher> teachersRecords;
	std::string sqlCommand = "SELECT * FROM Teachers";
	teachersRecords = executeGetTeacher(sqlCommand.c_str());
	return teachersRecords;
}

std::vector<teacher> DziennikLib::findTeachersByPesel(std::string pesel)
{
	std::vector<teacher> teachersRecords;
	std::string sqlCommand = "SELECT * FROM Teachers \n WHERE Pesel = '" + pesel + "'";
	teachersRecords = executeGetTeacher(sqlCommand.c_str());
	return teachersRecords;
}

std::vector<user>  DziennikLib::findUsersAll()
{
	std::vector<user> usersRecords;
	std::string sqlCommand = "SELECT * FROM Users";
	usersRecords = executeGetUser(sqlCommand.c_str());
	return usersRecords;
}


std::vector<user> DziennikLib::findUserbyNickbyPass(std::string nick, std::string pass)
{
	std::vector<user> usersRecords;
	std::string sqlCommand = "SELECT * FROM Users WHERE Nick = '" + nick + "' AND  Password = '" + encrypt(pass) + "';";
	usersRecords = executeGetUser(sqlCommand.c_str());
	return usersRecords;
}

std::vector<user>  DziennikLib::findUsersById(int UserId)
{
	std::vector<user> usersRecords;
	std::string sqlCommand = "SELECT * FROM Users WHERE User_Id = '" + std::to_string(UserId) + "';";
	usersRecords = executeGetUser(sqlCommand.c_str());
	return usersRecords;
}

	std::vector<subject>  DziennikLib::findSubjectsById(int SubjectId)
	{
    std::vector<subject> subjectsRecords;
	std::string sqlCommand = "SELECT * FROM Subjects  WHERE Suvject_id=" +std::to_string(SubjectId)+";" ;
	subjectsRecords = this->executeGetSubject(sqlCommand.c_str());
	return subjectsRecords;
	}
