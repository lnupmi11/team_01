#pragma once
#include<iostream>
#include<string>
#include<vector>
#include"../Entity/ProductClothes.h"
#include"../DTO/ShopProductData.h"
#include"../DTO/User_DTO.h"
#include"../Entity/User.h"
#include"../BL/BL.h"

using namespace std;

class MenuClothes
{
protected:
	vector<ProductClothes> arrClothes;
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
	ProductClothes addClothe();

	void loadClothes(string filename);
	void saveClothes();
	void update();
	bool isClothesAvailable(ProductClothes cl);
	void deleteClothe();
	void printClothes();

	//users menu
	void userMenu(User& user);
	void addToCart(ProductClothes product, User& user);
};
