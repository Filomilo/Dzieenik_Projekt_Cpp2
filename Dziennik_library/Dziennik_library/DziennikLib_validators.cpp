#include "DziennikLib.h"

bool DziennikLib::validateLogin(std::string nick, std::string password)
{
	if (getAmountOfLogin(nick, password) > 1)
	{
		return true;
	}
	return false;
}

bool DziennikLib::validateNick(std::string nick)
{
    if(this->findamountOfUserByNikc(nick)>0)
        return false;
    return true;
}
