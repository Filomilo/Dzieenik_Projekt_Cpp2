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
    /*
	unsigned char* txt = (unsigned char*)text.c_str();
	unsigned char encryprtedTxt[SHA256_DIGEST_LENGTH + 1];
	memset(encryprtedTxt, 0, sizeof(encryprtedTxt));
	SHA256(txt, strlen((const char*)txt), encryprtedTxt);
	return std::string((char*)encryprtedTxt) + "\0";
	*/
	return text;
}

bool DziennikLib::isUserLogged()
{
	if (this->LoginId < 0)
	{
		return false;
	}
	return true;
}
std::string  DziennikLib::getUserNick()
{
	if (this->isUserLogged())
	{
	user userAccount = findUsersById(this->LoginId)[0];
	return userAccount.Nick;
	}
	return "NULL";
}
int  DziennikLib::getUserAccountType()
{
	if (this->isUserLogged())
	{
		user userAccount = findUsersById(this->LoginId)[0];
		return userAccount.Acccount_Type;
	}
	return -1;
}
bool  DziennikLib::isUserAdmin()
{
	if (this->isUserLogged())
	{
		user userAccount = findUsersById(this->LoginId)[0];
		return userAccount.Acccount_Type==DziennikLib::Account_types::ADMIN;
	}
	return false;
}
bool  DziennikLib::isUserTeacher()
{
	if (this->isUserLogged())
	{
		user userAccount = findUsersById(this->LoginId)[0];
		return userAccount.Acccount_Type == DziennikLib::Account_types::TEACHER;
	}
	return false;
}

bool  DziennikLib::isUserStudent()
{
	if (this->isUserLogged())
	{
		user userAccount = findUsersById(this->LoginId)[0];
		return userAccount.Acccount_Type == DziennikLib::Account_types::STUDNET;
	}
	return false;
}
std::string  DziennikLib::getUserIdInDb()
{
	if (this->isUserLogged() && !(this->isUserAdmin()))
	{
		user userAccount = findUsersById(this->LoginId)[0];
		return userAccount.Id_in_db;
	}
	return "NULL";
}
student  DziennikLib::getUserStudentProfile()
{
		if (this->isUserLogged() && (this->isUserStudent()))
	{
		user userAccount = findUsersById(this->LoginId)[0];
		return findStudentByPesel(userAccount.getIdInDb())[0];
	}
	return student ();
}
teacher  DziennikLib::getUserTeacherProfile()
{
	if (this->isUserLogged() && (this->isUserTeacher()))
	{
		user userAccount = findUsersById(this->LoginId)[0];
		return findTeachersByPesel(userAccount.getIdInDb())[0];
	}
	return teacher();
}
void DziennikLib::logout()
{
    this->LoginId=-1;
}
