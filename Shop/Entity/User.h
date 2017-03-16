#pragma once
#include<string>

using namespace std;

class User
{
private:
	string firstName;
	string lastName;
	string login;
	string password;
public:
	User();
	User(string firstName, string lastName, string login, string password);
	User(const User& user);
	string getLogin();
	string getPassword();
};