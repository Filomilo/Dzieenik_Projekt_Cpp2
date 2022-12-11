#include "DziennikLib.h"

   void DziennikLib::removeSubject(int subjectId)
   {
		std::string sqlCode = "DELETE FROM Subjects \n WHERE Suvject_id = " + std::to_string(subjectId) + ";";
	std::cout << std::endl << sqlCode;
	executeSqlInsert(sqlCode);
   }

   void DziennikLib::removeTeacher(std::string teacherPesel)
   {
	 	std::string sqlCode = "DELETE FROM Teachers \n WHERE Pesel = \'" + teacherPesel + "\';";
	std::cout << std::endl << sqlCode;
	executeSqlInsert(sqlCode);
   }
   void DziennikLib::removeStudent(std::string studentPesel)
   {
	 	std::string sqlCode = "DELETE FROM Students \n WHERE Pesel = \'" + studentPesel + "\';";
	std::cout << std::endl << sqlCode;
	executeSqlInsert(sqlCode);
   }

   void DziennikLib::removeAttendanceByDate(std::string date)
   {
   std::string sqlCode = "DELETE FROM Attendacne \n WHERE Date = \'" + date + "\';";
	std::cout << std::endl << sqlCode;
	executeSqlInsert(sqlCode);
   }
