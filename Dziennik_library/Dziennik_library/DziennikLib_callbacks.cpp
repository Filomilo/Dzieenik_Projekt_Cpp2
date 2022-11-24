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


 int DziennikLib::callbackGetValue(void* data, int argc, char** argv, char** azColName) {

	int* amount = (int*)data;
	*amount = atoi(argv[0]);
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

 int DziennikLib::callbackGetTeacher(void* data, int argc, char** argv, char** azColName) {
	 std::vector<teacher>* teacherRecords = (std::vector<teacher>*)data;
	 int i;
	 int rows = 5;
	 for (i = 0; i < argc; i += rows) {
		 teacher teacherRecord;
		 teacherRecord.setPesel(argv[i % rows]);
		 teacherRecord.setName(argv[(i + 1) % rows]);
		 teacherRecord.setSurname(argv[(i + 2) % rows]);
		 teacherRecord.setBirthday(argv[(i + 3) % rows]);
		 teacherRecord.setSubjectId(argv[(i + 4) % rows]);
		 teacherRecords->push_back(teacherRecord);
	 }
	 return 0;
 }

 int DziennikLib::callbackGetAttendacne(void* data, int argc, char** argv, char** azColName) {
	 std::vector<attendance>* attendanceRecords = (std::vector<attendance>*)data;
	 int i;
	 int rows = 6;
	 for (i = 0; i < argc; i += rows) {
		 attendance attendanceRecord;
		 attendanceRecord.setAttendacne_id(argv[i % rows]);
		 attendanceRecord.setDate(argv[(i + 1) % rows]);
		 attendanceRecord.setLessonNum(argv[(i + 2) % rows]);
		 attendanceRecord.setTeacherId(argv[(i + 3) % rows]);
		 attendanceRecord.setStudentId(argv[(i + 4) % rows]);
		 attendanceRecord.setStatus(argv[(i + 5) % rows]);
		 attendanceRecords->push_back(attendanceRecord);
	 }
	 return 0;
 }

 int DziennikLib::callbackGetGrade(void* data, int argc, char** argv, char** azColName) {
	 std::vector<grade>* gradeRecords = (std::vector<grade>*)data;
	 int i;
	 int rows = 4;
	 for (i = 0; i < argc; i += rows) {
		 grade gradeRecord;
		 std::cout << "grade found: " << argv[i % rows] << std::endl;
		 gradeRecord.setGradeId(argv[i % rows]);
		 gradeRecord.setStudentId(argv[(i + 1) % rows]);
		 gradeRecord.setSubjectId(argv[(i + 2) % rows]);
		 gradeRecord.setGrade(argv[(i + 3) % rows]);
		 gradeRecords->push_back(gradeRecord);
	 }
	 return 0;
 }

 int DziennikLib::callbackGetSubject(void* data, int argc, char** argv, char** azColName) {
	 std::vector<subject>* subjectRecords = (std::vector<subject>*)data;
	 int i;
	 int rows = 2;
	 for (i = 0; i < argc; i += rows) {
		 subject subjectRecord;
		 subjectRecord.setSubjectId(argv[i % rows]);
		 subjectRecord.setName(argv[(i + 1) % rows]);
		 subjectRecords->push_back(subjectRecord);
	 }
	 return 0;
 }
