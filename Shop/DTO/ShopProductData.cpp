#pragma once
#include<vector>
#include"../Entity/Bag.h"
#include"../Entity/Dress.h"
#include"../Entity/Shirt.h"
#include"../Entity/Sweater.h"
#include"ShopProductData.h"

ProductClothes* addClothe(ifstream& file)
{
	string id, type;
	file >> id >> type;

	ProductClothes *data;
	if (type == "dress")
	{
		data = new Dress(id);
	}
	else if (type == "bag")
	{
		data = new Bag(id);
	}
	else if (type == "shirt")
	{
		data = new Shirt(id);
	}
	else if (type == "sweater")
	{
		data = new Sweater(id);
	}
	else
	{
		data = new ProductClothes(id);
	}

	file >> *data;
	return data;
}

vector<ProductClothes*> LoadProductClothes(string fileName)
{
	ifstream file(fileName);
	int n;
	file >> n;
	vector<ProductClothes*> clothes;
	for (int i = 0; i < n; i++)
	{
		ProductClothes* clothe = addClothe(file);
		clothes.push_back(clothe);
	}
	return clothes;
}


void SaveProductsToFile(vector<ProductClothes*> clothes, string fileName)
{
	ofstream fileOut(fileName);
	fileOut << clothes.size() << endl;
	for (int i = 0; i < clothes.size(); i++)
	{
		fileOut << *clothes[i];
	}
	fileOut.close();
}

vector<BasketItem*> LoadUserBasket(string userLogin)
{
	vector<BasketItem*> basketItems;
	ifstream file("Data\\Baskets\\" + userLogin + ".txt");
	int n;
	file >> n;
	for (int i = 0; i < n; i++)
	{
		BasketItem* basketItem = new BasketItem();
		file >> *basketItem;
		basketItems.push_back(basketItem);
	}
	return basketItems;
}

void SaveUserBasketToFile(vector<BasketItem*> basketItems, string userLogin)
{
	ofstream fileOut("Data\\Baskets\\" + userLogin + ".txt");
	fileOut << basketItems.size() << endl;
	for (int i = 0; i < basketItems.size(); i++)
	{
		fileOut << *basketItems[i];
	}
	fileOut.close();
}

void saveProductToFile(ProductClothes* clothes, string filename)
{
	ofstream output;
	output.open("User\\" + filename + ".txt", ios_base::app);
	output << *clothes;
	output.close();
}