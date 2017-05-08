#pragma once
#include<iostream>
#include<string>
#include<vector>
#include"../Entity/Clothes.h"
#include"../DTO/ShopProductData.h"
#include"../DTO/User_DTO.h"
#include"../Entity/User.h"
#include"../BL/BL.h"

using namespace std;

class MenuClothes
{
protected:
	vector<Clothes*> stock;
public:
	MenuClothes();
	MenuClothes(const MenuClothes &menu);

	//start menu
	void startMenu();
	void printStartMenu();

	/* clothes menu*/
	void adminMenu();
	void printAdminMenu();
	void printUserMenu();
	Clothes* addClothes();

	void loadClothes(string filename);
	void saveClothes();
	void update();
	void deleteClothe();
	void printClothes();

	//users menu
	void userMenu(User& user);
};
