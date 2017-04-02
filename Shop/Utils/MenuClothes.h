#pragma once
#include<iostream>
#include<string>
#include<vector>
#include"../Entity/ProductClothes.h"
#include"../DTO/ShopProductData.h"

using namespace std;

class MenuClothes
{
private:
	vector<ProductClothes> arrClothes;
public:
	MenuClothes();
	MenuClothes(const MenuClothes &menu);

	/* clothes menu*/
	void clothesMenu();
	void printMenuClothesHeader();
	ProductClothes addClothe();

	void loadClothes();
	void saveClothes();
	void update();
	void deleteClothe();
	void printClothes();
	
};
