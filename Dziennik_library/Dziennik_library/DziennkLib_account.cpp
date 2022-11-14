#include "DziennikLib.h"

bool DziennikLib::login(std::string nick, std::string password)
{
	bool loginResult= validateLogin(nick, password);
	if (loginResult)
	{
		user loggedUser = this->findUserbyNickbyPass(nick, password)[0];
		this->actionMessage("succesfuly looged as " + loggedUser.getNick());
		this->LoginId = loggedUser.getUserId();
	}
	else
	{
		this->actionMessage("invalid login data priveded");
	}
	return loginResult;
}

int DziennikLib::getAmountOfLogin(std::string nick, std::string password)
{
	std::string sqlCommand = "SELECT * FROM Users WHERE Nick = '" + nick + "' AND  Password = '" + encrypt(password) + "';";

	return executeSqlAmount(sqlCommand);
}

std::string DziennikLib::encrypt(std::string text)
{
	unsigned char* txt = (unsigned char*)text.c_str();
	unsigned char encryprtedTxt[SHA256_DIGEST_LENGTH + 1];
	memset(encryprtedTxt, 0, sizeof(encryprtedTxt));
	SHA256(txt, strlen((const char*)txt), encryprtedTxt);
	return std::string((char*)encryprtedTxt) + "\0";
}


