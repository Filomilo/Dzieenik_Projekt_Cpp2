#include <stdio.h>
#include <sqlite3.h>
#include "DziennikLib.h"
#include <string>
#include <locale>

int main()
{
    
    std::setlocale(LC_ALL, "");

    DziennikLib *db = new DziennikLib;
    char* databaseName = (char*) "..\\..\\Dziennik_gui\\Dziennik-Gui\\exampple.dznk";
    db->loadDataBase(databaseName);
   //db->createNewDataBase(databaseName);
   
    //std::cout << "creting data base: " << databaseName << std::endl;
    //sqlite3* db;
   // sqlite3_open(databaseName, & db);

    //std::cout <<std::endl<< db->encrypt("admin");
db->createNewDataBase(databaseName);
    //db->insertDefaultData();
    db->createBasictables();
db->insertDefaultData();
db->printDataBase();
//db->printAttendacne();
//db->updateAttandance("1", "7");
//db->printAttendacne();

//std::cout<<"stuednt:\n"<<db->findStudentByPesel("78032008893");
    /*
   db->printDataBase();
   db-> addStudent("pesle","name","surname","bbirta");
   db->addAttendacne("dara",3,"pasoa","studne",DziennikLib::Attendance_types::ABSENT);
   db->addGrade("stuednt pesl",4,3);
   db->addSubject("przedmiot");
   db->addTeacher("pesle", "name", "surname", "bbirta",3);
   db->addUser("cnik","password", DziennikLib::Account_types::TEACHER, "pesle");
   db->addUser("adsadasda", "password", DziennikLib::Account_types::ADMIN);
   db->printDataBase();
   */
    
}