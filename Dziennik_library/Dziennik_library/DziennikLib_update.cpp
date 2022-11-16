#include "DziennikLib.h"

void DziennikLib::updateGrade(std::string gradeId, std::string newGrade)
{
	std::string sqlCode = "UPDATE Grades \n SET Grade_Id = " + newGrade + "\n WHERE `Id` = " + gradeId + ";";
	std::cout << std::endl << sqlCode;
	executeSqlInsert(sqlCode);
}

void DziennikLib::updateAttandance(std::string attandanceId, std::string newStatus)
{
	std::string sqlCode = "UPDATE Attendacne \n SET Status = " + newStatus + "\n WHERE `Attendacne_id` = " + attandanceId + ";";
	std::cout << std::endl << sqlCode;
	executeSqlInsert(sqlCode);
}

void  DziennikLib::updateSubject(int subjectId,std::string Name)
{
		std::string sqlCode = "UPDATE Subjects \n SET Name = \"" + Name + "\"\n WHERE Suvject_id = " + std::to_string(subjectId) + ";";
	std::cout << std::endl << sqlCode;
	executeSqlInsert(sqlCode);
}
