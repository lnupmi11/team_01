#include"User.h"

User::User()
{
	this->firstName = "";
	this->lastName = "";
	this->login = "";
	this->password = "";
}
User::User(string firstName, string lastName, string login, string password)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->login = login;
	this->password = password;
}
User::User(const User& user)
{
	this->firstName = user.firstName;
	this->lastName = user.lastName;
	this->login = user.login;
	this->password = user.password;
}
string User::getLogin()
{
	return this->login;
}
string User::getPassword()
{
	return this->password;
}