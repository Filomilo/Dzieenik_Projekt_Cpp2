#include "DziennikLib.h"

void DziennikLib::updateGrade(std::string gradeId, std::string newGrade)
{
	std::string sqlCode = "UPDATE Grades \n SET Grade = " + newGrade + "\n WHERE `Grade_Id` = " + gradeId + ";";
	std::cout << std::endl << sqlCode;
	executeSqlInsert(sqlCode);
}

void DziennikLib::updateAttandance(std::string attandanceId, std::string newStatus)
{
	std::string sqlCode = "UPDATE Attendacne \n SET Status = " + newStatus + "\n WHERE `Attendacne_id` = " + attandanceId + ";";
	std::cout << std::endl << sqlCode;
	executeSqlInsert(sqlCode);
}

void DziennikLib::updateAttandanceIterate(std::string attandanceId)
{
	std::string sqlCode = "UPDATE Attendacne \n SET Status = (status+1)%4 \n WHERE Attendacne_id = " + attandanceId + ";";
	std::cout << std::endl << sqlCode;
	executeSqlInsert(sqlCode);
}

void DziennikLib::updateAttandanceIterate(int id)
{
updateAttandanceIterate(std::to_string(id));
}

void  DziennikLib::updateSubject(int subjectId,std::string Name)
{
		std::string sqlCode = "UPDATE Subjects \n SET Name = \"" + Name + "\"\n WHERE Suvject_id = " + std::to_string(subjectId) + ";";
	std::cout << std::endl << sqlCode;
	executeSqlInsert(sqlCode);
}

void DziennikLib::updateTeacher(std::string Pesel, std::string Name, std::string Surname, std::string Birthday, int subject_id)
{
		std::string sqlCommand = "UPDATE Teachers\n SET ";
		sqlCommand+="Name = \'"+ Name+ "\', \n";
		sqlCommand+="Surname = \'"+ Surname+ "\', \n";
		sqlCommand+="Birthday = \'"+ Birthday+ "\', \n";
		sqlCommand+="Subject_id = \'"+ std::to_string(subject_id)+ "\' \n";
		sqlCommand+="WHERE  Pesel=\'" + Pesel+ "\'\;";
	std::cout << sqlCommand << std::endl;
	executeSqlInsert(sqlCommand);
}

	void DziennikLib::updateStudent(std::string Pesel, std::string Name, std::string Surname, std::string Birthday)
	{
		std::string sqlCommand = "UPDATE Students\n SET ";
		sqlCommand+="Name = \'"+ Name+ "\', \n";
		sqlCommand+="Surname = \'"+ Surname+ "\', \n";
		sqlCommand+="Birthday = \'"+ Birthday+ "\' \n";
		sqlCommand+="WHERE  Pesel=\'" + Pesel+ "\'\;";
	std::cout << sqlCommand << std::endl;
	executeSqlInsert(sqlCommand);
	}

	void DziennikLib::updateUser(int id, std::string nick, std::string pass)
	{
	    		std::string sqlCommand = "UPDATE Users\n SET ";
		sqlCommand+="Nick = \'"+ nick+ "\', \n";
		sqlCommand+="Password = \'"+ pass+ "\' \n";
		sqlCommand+="WHERE  User_Id=\'" + std::to_string(id)+ "\'\;";
	std::cout << sqlCommand << std::endl;
	executeSqlInsert(sqlCommand);
	}
