#pragma once
#include<iostream>
#include<string>
#include<vector>
#include"../Entity/ProductClothes.h"
#include"../DTO/ShopProductData.h"
#include"../DTO/User_DTO.h"
#include"../Entity/User.h"
#include"../Entity/Basket.h"
#include"../BL/BL.h"

using namespace std;

class MenuClothes
{
protected:
	vector<ProductClothes*> arrClothes;
	Basket* basket;
public:
	MenuClothes();
	MenuClothes(const MenuClothes &menu);

	//start menu
	void startMenu();
	void printStartMenu();

	/* clothes menu*/
	void adminMenu(User& user);
	void printAdminMenu();
	void printUserMenu();
	ProductClothes* addClothe();

	void loadClothes(string filename);
	void saveClothes();
	void update();
	void deleteClothe();
	void printClothes();
	ProductClothes* findClothe(string id);

	//users menu
	void userMenu(User& user);
	void addToBasket();
	void saveBasket(string userLogin);
	void printBasket();
};
