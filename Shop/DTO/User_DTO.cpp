#include "User_DTO.h"

void saveNewUser(User object)
{
	ofstream input;
	input.open("User\\users.txt", ios_base::app);
	input << object.getLogin() << " " << object.getPassword() << "\n";
	input.close();
	input.open("User\\" + object.getLogin() + ".txt", ios_base::app);
	input << object.getFirstName() << endl;
	input << object.getLastName() << endl;
	input << (bool)object.getAdmin() << endl;
	input.close();
}

bool existenceLogin(string login)
{
	ifstream input("User\\users.txt");
	for (string line; getline(input, line); )
	{
		int i = 0;
		string text;
		while (line[i] != ' ')
		{
			text += line[i];
			i++;
		}
		if (login == text)
		{
			return false;
		}
	}
	return true;
}

bool checkLogin(string log, string password)
{
	string addition = log;
	addition += ' ';
	addition += password;
	ifstream input("User\\users.txt");
	for (string line; getline(input, line); )
	{
		if (addition == line)
		{
			return true;
		}
	}

	return false;
}

void printInfo(User& user)
{
	ifstream is;
	is.open("User\\" + user.getLogin() + ".txt");
	string line;
	while (!is.eof())
	{
		getline(is, line);
		cout << line << endl;
	}
}

