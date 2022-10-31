#include "DziennikLib.h"


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
	 for (i = 0; i < argc; i += 4) {
		 student studentRecord;
		 studentRecord.setPesel(argv[0]);
		 studentRecord.setName(argv[1]);
		 studentRecord.setSurname(argv[2]);
		 studentRecord.setBirthday(argv[3]);
		 studentRecords->push_back(studentRecord);
	 }
	 return 0;
 }