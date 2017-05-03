#include"User.h"

User::User()
{
	this->firstName = "";
	this->lastName = "";
	this->login = "";
	this->password = "";
	this->isAdmin = false;
}
User::User(string firstName, string lastName, string login, string password, bool admin)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->login = login;
	this->password = password;
	this->isAdmin = admin;
}
User::User(const User& user)
{
	this->firstName = user.firstName;
	this->lastName = user.lastName;
	this->login = user.login;
	this->password = user.password;
	this->isAdmin = user.isAdmin;
}
string User::getFirstName()
{
	return this->firstName;
}
string User::getLastName()
{
	return this->lastName;
}
string User::getLogin()
{
	return this->login;
}
string User::getPassword()
{
	return this->password;
}
bool User::getAdmin()
{
	return this->isAdmin;
}