#include "DziennikLib.h"

   void DziennikLib::removeSubject(int subjectId)
   {
		std::string sqlCode = "DELETE FROM Subjects \n WHERE Suvject_id = " + std::to_string(subjectId) + ";";
	std::cout << std::endl << sqlCode;
	executeSqlInsert(sqlCode);
   }