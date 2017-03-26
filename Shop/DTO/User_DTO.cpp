#include "User_DTO.h"

void saveNewUser(User object)
{
	ofstream input;
	input.open("User\\users.txt", ios_base::app);
	input << object.getLogin() << " " << object.getPassword() << "\n";
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