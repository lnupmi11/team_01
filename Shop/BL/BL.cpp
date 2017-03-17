#include "BL.h"
#include <iostream>

void createNewUser()
{
	string firstName;
	string lastName;
	string login;
	string password;
	cout << "Enter first name\n";
	cin >> firstName;
	cout << "Enter last name\n";
	cin >> lastName;
	cout << "Enter login\n";
	cin >> login;
	cout << "Enter password\n";
	cin >> password;
	User user(firstName, lastName, login, password);
	if (existenceLogin(login))
	{
		saveNewUser(user);
	}
	else
	{
		cout << "Error! This login already exist\n";
	}
}