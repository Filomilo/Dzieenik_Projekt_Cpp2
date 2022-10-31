#include "DziennikLib.h"

bool DziennikLib::validateLogin(std::string nick, std::string password)
{
	if (getAmountOfLogin(nick, password) > 1)
	{
		return true;
	}
	return false;
}