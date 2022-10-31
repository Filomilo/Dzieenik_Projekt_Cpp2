#include "DziennikLib.h"


 bool DziennikLib::isFileExist(char* fileDir)
{
	std::ifstream file(fileDir);
	if (!file.is_open()) {
		return false;
	}
	file.close();
	return true;
}