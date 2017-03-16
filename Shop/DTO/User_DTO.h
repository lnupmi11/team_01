#pragma once
#include <fstream>
#include "../Entity/User.h"

void saveNewUser(User object)
{
	ofstream input;
	input.open("User\\users.txt", ios_base::app);
	input << object.getLogin() << " " << object.getPassword() << "\n";
	input.close();
}