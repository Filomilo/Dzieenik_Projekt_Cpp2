#include <stdio.h>
#include <sqlite3.h>
#include "DziennikLib.h"
#include <string>

/*

int main(int argc, char* argv[]) {
    sqlite3* db;
    char* zErrMsg = 0;
    int rc;

    rc = sqlite3_open("test.db", &db);

    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return(0);
    }
    else {
        fprintf(stderr, "Opened database successfully\n");
    }
    sqlite3_close(db);
}*/

int main()
{
    DziennikLib *db = new DziennikLib;
    char* databaseName = (char*) "dataBsse.db";
db->createNewDataBase(databaseName);
db->insertIntoStudnets("Asdasd", "Asdasda", "sadasda", "fdsfdsf");
db->insertIntoGrades("hj", "5", "9");
db->insertIntoGrades("hsadaj", "3", "2");
db->insertIntoSubjects("angielski");
db->insertIntoSubjects("poslki");
db->insertIntoTeachers("Asdasd", "Asdasda", "sadasda", "fdsfdsf", "1");
db->insertIntoAttendacne("25-8-205", "2", "asd", "asda", "nieobecny");
db->login("Test", "Test");
}