#pragma once
#include<vector>
#include"../Entity/Bag.h"
#include"../Entity/Dress.h"
#include"../Entity/Shirt.h"
#include"../Entity/Sweater.h"
#include"../Entity/Footwear.h"
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
	else if (type == "footwear")
	{
		data = new Footwear(id);
	}
	else
	{
		data = new ProductClothes(id);
	}

	file >> *data;
	return data;
}

bool checkId(string filename, string id)
{
	ifstream file("Data\\" + filename);
	int n;
	file >> n;
	for (int i = 0; i < n; i++)
	{
		string tmpId;
		file>>tmpId;
		if (tmpId == id)
		{
			return true;
		}
		getline(file, tmpId);
	}
	file.close();
	return false;
}
vector<ProductClothes*> LoadProductClothes(string fileName)
{
	ifstream file("Data\\" + fileName);
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
	ofstream fileOut("Data\\" + fileName);
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
	if (file.good())
	{
		int n;
		file >> n;
		for (int i = 0; i < n; i++)
		{
			BasketItem* basketItem = new BasketItem();
			file >> *basketItem;
			basketItems.push_back(basketItem);
		}
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
