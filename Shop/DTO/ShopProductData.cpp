#pragma once
#include<vector>
#include"../Entity/Bag.h"
#include"../Entity/Dress.h"
#include"../Entity/Shirt.h"
#include"../Entity/Sweater.h"
#include"../Entity/Footwear.h"
#include"ShopProductData.h"

ProductClothes addClothe(ifstream& file)
{
	string type;

	file >> type;

	if (type == "dress")
	{
		Dress dress;
		file >> dress;
		return dress;
	}
	if (type == "bag")
	{
		Bag bag;
		file >> bag;
		return bag;
	}

	if (type == "shirt")
	{
		Shirt shirt;
		file >> shirt;
		return shirt;
	}

	if (type == "sweater")
	{
		Sweater sweater;
		file >> sweater;
		return sweater;
	}


	if (type == "footwear")
	{
		Sweater footwear;
		file >> footwear;
		return footwear;
	}
}

vector<ProductClothes> LoadProductClothes(string fileName)
{
	ifstream file(fileName);
	int n;
	file >> n;
	vector<ProductClothes> clothes;
	for (int i = 0; i < n; i++)
	{
		ProductClothes clothe = addClothe(file);
		clothes.push_back(clothe);
	}
	return clothes;
}


void SaveProductsToFile(vector<ProductClothes> clothes, string fileName)
{
	ofstream fileOut(fileName);
	for (int i = 0; i < clothes.size(); i++)
	{
		fileOut << clothes[i];
	}
	fileOut.close();
}

void saveProductToFile(ProductClothes clothes, string filename)
{
	ofstream output;
	output.open("User\\" + filename + ".txt", ios_base::app);
	output << clothes;
	output.close();
}
