#include <stdio.h>
#include <sqlite3.h>
#include "DziennikLib.h"
#include <string>
#include <locale>

int main()
{
    std::setlocale(LC_ALL, "");
    DziennikLib *db = new DziennikLib;
    char* databaseName = (char*) "dataBsse.db";
    db->createNewDataBase(databaseName);
    //std::cout <<std::endl<< db->encrypt("admin");

db->insertDefaultData();
db->printAttendacne();
db->updateAttandance("1", "7");
db->printAttendacne();
}