#include "BL.h"
#include <iostream>

User createNewUser()
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
	User user(firstName, lastName, login, password, 0);
	system("cls");
	if (existenceLogin(login))
	{
		cout << "Registration is Successful!\n";
		ofstream fileOut("Data\\Baskets\\" + login + ".txt");
		fileOut.close();
		saveNewUser(user);
		return user;
	}
	else
	{
		
		cout<< "Error! This login already exist\n";
		return User();
	}
}

User login()
{
	cout << "Enter login" << endl;
	string log;
	cin >> log;
	cout << "Enter password" << endl;
	string password;
	cin >> password;
	if (checkLogin(log, password))
	{
		ifstream is;
		is.open("User\\" + log + ".txt");
		string fname;
		getline(is, fname);
		string lname;
		getline(is, lname);
		string isAdmin;
		getline(is, isAdmin);
		is.close();
		bool temp = false;
		if (isAdmin == "1")
		{
			temp = true;
		}
		return User(fname, lname, log, password, temp);
	}
	return User();
}