#include "DziennikLib.h"

void DziennikLib::insertDefaultData()
{
	insertIntoSubjects("angielski");	//1
	insertIntoSubjects("polski");		//2
	insertIntoSubjects("matematyka");	//3
	insertIntoSubjects("informatyka");	//4
	insertIntoSubjects("biologia");		//5
	insertIntoSubjects("historia");		//6
	insertIntoSubjects("w-f");			//7
	insertIntoSubjects("geografia");	//8

	insertIntoStudnets("78032008893", "Jan", "Kowalski", "2003-08-11");
	insertIntoStudnets("85043075127", "Kamil", "Nowak", "2001-11-15");
	insertIntoStudnets("97080905532", "Zbigniew", "Jagie³³o", "2004-04-30");
	insertIntoStudnets("82011833851", "Kamil", "Mieszko", "2002-12-28");
	insertIntoStudnets("86121110824", "Andrzej", "Kaczñski", "2000-01-25");

	insertIntoTeachers("98072068558", "Marzena", "Miko³ajaczyk", "1998-02-18", "1");
	insertIntoTeachers("2657245624", "Zbigniew", "Borowski", "1969-11-01", "2");
	insertIntoTeachers("65246524442", "Krystian", "Król", "1967-12-11", "3");
	insertIntoTeachers("78112917806", "Klaudia", "Dudek", "1978-11-29", "4");
	insertIntoTeachers("64081176966", "Feliksa", "Jakubowska", "1964-08-11", "5");
	insertIntoTeachers("73101234713", "Serhii", "Kaczmarczyk", "1973-10-12", "6");
	insertIntoTeachers("94101061338", "Krystian", "Ziêba", "1994-10-10", "7");


	insertIntoGrades("78032008893", "1", "3");
	insertIntoGrades("78032008893", "5", "1");
	insertIntoGrades("78032008893", "2", "3");
	insertIntoGrades("78032008893", "3", "5");
	insertIntoGrades("78032008893", "1", "3");
	insertIntoGrades("78032008893", "7", "2");

	insertIntoGrades("85043075127", "3", "1");
	insertIntoGrades("85043075127", "3", "2");
	insertIntoGrades("85043075127", "5", "5");
	insertIntoGrades("85043075127", "1", "3");
	insertIntoGrades("85043075127", "3", "6");
	insertIntoGrades("85043075127", "6", "4");

	insertIntoGrades("97080905532", "1", "2");
	insertIntoGrades("97080905532", "3", "4");
	insertIntoGrades("97080905532", "4", "5");
	insertIntoGrades("97080905532", "2", "6");
	insertIntoGrades("97080905532", "5", "3");
	insertIntoGrades("97080905532", "6", "2");

	insertIntoGrades("82011833851", "3", "1");
	insertIntoGrades("82011833851", "2", "2");
	insertIntoGrades("82011833851", "5", "4");
	insertIntoGrades("82011833851", "6", "5");
	insertIntoGrades("82011833851", "7", "2");
	insertIntoGrades("82011833851", "6", "5");

	insertIntoGrades("86121110824", "1", "1");
	insertIntoGrades("86121110824", "2", "2");
	insertIntoGrades("86121110824", "4", "4");
	insertIntoGrades("86121110824", "6", "3");
	insertIntoGrades("86121110824", "7", "5");
	insertIntoGrades("86121110824", "2", "3");

	insertIntoAttendacne("2022-08-20", "1", "98072068558", "78032008893", "2");
	insertIntoAttendacne("2022-08-20", "1", "98072068558", "85043075127", "1");
	insertIntoAttendacne("2022-08-20", "1", "98072068558", "97080905532", "2");
	insertIntoAttendacne("2022-08-20", "1", "98072068558", "82011833851", "0");
	insertIntoAttendacne("2022-08-20", "1", "98072068558", "86121110824", "1");

	insertIntoAttendacne("2022-08-20", "2", "64081176966", "78032008893", "0");
	insertIntoAttendacne("2022-08-20", "2", "64081176966", "85043075127", "3");
	insertIntoAttendacne("2022-08-20", "2", "64081176966", "97080905532", "2");
	insertIntoAttendacne("2022-08-20", "2", "64081176966", "82011833851", "1");
	insertIntoAttendacne("2022-08-20", "2", "64081176966", "86121110824", "0");


	insertIntoAttendacne("2022-08-20", "3", "65246524442", "78032008893", "1");
	insertIntoAttendacne("2022-08-20", "3", "65246524442", "85043075127", "3");
	insertIntoAttendacne("2022-08-20", "3", "65246524442", "97080905532", "2");
	insertIntoAttendacne("2022-08-20", "3", "65246524442", "82011833851", "1");
	insertIntoAttendacne("2022-08-20", "3", "65246524442", "86121110824", "1");

	insertIntoAttendacne("2022-08-20", "4", "78112917806", "78032008893", "0");
	insertIntoAttendacne("2022-08-20", "4", "78112917806", "85043075127", "3");
	insertIntoAttendacne("2022-08-20", "4", "78112917806", "97080905532", "2");
	insertIntoAttendacne("2022-08-20", "4", "78112917806", "82011833851", "1");
	insertIntoAttendacne("2022-08-20", "4", "78112917806", "86121110824", "0");

	insertIntoUsers("ADMIN", encrypt("ADMIN"), "0");
	insertIntoUsers("TEACHER", encrypt("TEACHER"), "1", "98072068558");
	insertIntoUsers("STUDENT", encrypt("STUDENT"), "2", "82011833851");


}



