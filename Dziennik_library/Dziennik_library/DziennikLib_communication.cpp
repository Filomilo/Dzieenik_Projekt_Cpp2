#include "DziennikLib.h"

bool DziennikLib::errorHandler(const char* warrningMessage)
{
	//TODO: adjust error handler to wx widget

	std::cout << "ERROR:" << std::endl << warrningMessage << std::endl << std::endl;
	return true;
}

bool DziennikLib::warrningHandler(const char* warrningMessage)
{
	//TODO: adjust warring handler to wx widget
	std::cout << "warrning:" << std::endl << warrningMessage << std::endl << std::endl;
	return true;
}

void DziennikLib::actionMessage(std::string message)
{
	std::cout << std::endl << message << std::endl;
}
