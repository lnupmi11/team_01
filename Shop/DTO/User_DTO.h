#pragma once
#include<iostream>
#include <iomanip>
#include <fstream>
#include "../Entity/User.h"

bool existenceLogin(string login);
void saveNewUser(User object);
bool checkLogin(string log, string password);
void printInfo(User& user);

