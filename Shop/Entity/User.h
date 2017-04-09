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
	bool isAdmin;
public:
	User();
	User(string firstName, string lastName, string login, string password, bool admin);
	User(const User& user);
	string getFirstName();
	string getLastName();
	string getLogin();
	string getPassword();
	bool getAdmin();
};