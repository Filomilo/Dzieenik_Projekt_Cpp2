#include "DziennikLib.h"
#include "user.h"

 int DziennikLib::callbackPrint(void* data, int argc, char** argv, char** azColName) {
	int i;
	for (i = 0; i < argc; i++) {
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}
	printf("\n");
	return 0;
}

 int DziennikLib::callbackGetAmount(void* data, int argc, char** argv, char** azColName) {

	int* amount = (int*)data;
	*amount = argc;
	return 0;
}

 int DziennikLib::callbackGetStudent(void* data, int argc, char** argv, char** azColName) {
	 std::vector<student>* studentRecords = (std::vector<student>*)data;
	 int i;
	 int rows = 4;
	 for (i = 0; i < argc; i += rows) {
		 student studentRecord;
		 studentRecord.setPesel(argv[i%rows]);
		 studentRecord.setName(argv[(i+1)%rows]);
		 studentRecord.setSurname(argv[(i + 2) % rows]);
		 studentRecord.setBirthday(argv[(i + 3) % rows]);
		 studentRecords->push_back(studentRecord);
	 }
	 return 0;
 }

 int DziennikLib::callbackGetUser(void* data, int argc, char** argv, char** azColName) {
	 std::vector<user>* userRecords = (std::vector<user>*)data;
	 int i;

	 int rows = 5;
	 for (i = 0; i < argc; i += rows) {
		 user userRecord;

		 userRecord.setUserId(argv[(i) % rows]);
		 userRecord.setNick(argv[(i + 1) % rows]);
		 userRecord.setPassword(argv[(i + 2) % rows]);
		 userRecord.setAccountType(argv[(i + 3) % rows]);
		 userRecord.setIdInDb(argv[(i + 4) % rows] ? argv[(i + 4) % rows] : "NULL");
	
		 userRecords->push_back(userRecord);
	 }
	 return 0;
 }