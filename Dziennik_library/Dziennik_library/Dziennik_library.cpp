#include <stdio.h>
#include <sqlite3.h>
#include "DziennikLib.h"
#include <string>
#include <locale>

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
    std::setlocale(LC_ALL, "");
    DziennikLib *db = new DziennikLib;
    char* databaseName = (char*) "dataBsse.db";
db->createNewDataBase(databaseName);
//std::cout <<std::endl<< db->encrypt("admin");

db->insertDefaultData();

db->printDataBase();
}