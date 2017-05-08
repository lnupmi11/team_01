#pragma once
#include<vector>
#include"../Entity/Bag.h"
#include"../Entity/Dress.h"
#include"../Entity/Shirt.h"
#include"../Entity/Sweater.h"
#include"ShopProductData.h"

ProductClothes* addClothe(ifstream& file)
{
	string type;

	file >> type;

	ProductClothes *data;
	if (type == "dress")
	{
		data = new Dress();
	}
	else if (type == "bag")
	{
		data = new Bag();
	}
	else if (type == "shirt")
	{
		data = new Shirt();
	}
	else if (type == "sweater")
	{
		data = new Sweater();
	}
	else
	{
		data = new ProductClothes();
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

void saveProductToFile(ProductClothes* clothes, string filename)
{
	ofstream output;
	output.open("User\\" + filename + ".txt", ios_base::app);
	output << *clothes;
	output.close();
}