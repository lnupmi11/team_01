#pragma once
#include<vector>
#include"../Entity/Bag.h"
#include"../Entity/Dress.h"
#include"../Entity/Shirt.h"
#include"../Entity/Sweater.h"
#include"../Entity/Jacket.h"
#include"ShopProductData.h"
Clothes* addItems(ifstream& file, string type)
{
	if (type == "Dress")
	{
		Dress* dress = new Dress();
		file >> dress;
		return dress;
	}
	
	if (type == "Bag")
	{
		Bag* bag = new Bag();
		file >> bag;
		return bag;
	}
	if (type == "Shirt")
	{
		Shirt* shirt = new Shirt();
		file >> shirt;
		return shirt;
	}

	if (type == "Sweater")
	{
		Sweater* sweater = new Sweater();
		file >> sweater;
		return sweater;
	}
	if (type == "Jacket")
	{
		Jacket* jacket = new Jacket();
		file >> jacket;
		return jacket;
	}
}

vector<Clothes*> LoadClothesFromFile(string fileName)
{
	ifstream file;
	file.open(fileName, ios::in);
	vector<Clothes*> stock;
	string type;
	file >> type;
	while (type.size()!= 0)
	{
		Clothes* clothes = addItems(file, type);
		stock.push_back(clothes);
		type = "";
		file >> type;
	}
	file.close();
	return stock;
}


void SaveProductsToFile(vector<Clothes*> &stock, string fileName)
{
	ofstream fileOut(fileName);
	for (int i = 0; i < stock.size(); i++)
	{
		if (dynamic_cast<Sweater*>(stock[i]))
		{
			Sweater* sweater = dynamic_cast<Sweater*>(stock[i]);
			fileOut << sweater;
		}
		if (dynamic_cast<Shirt*>(stock[i]) )
		{
			Shirt* shirt = dynamic_cast<Shirt*>(stock[i]);
			fileOut << shirt;
		}
		if (dynamic_cast<Dress*>(stock[i]))
		{
			Dress* dress = dynamic_cast<Dress*>(stock[i]);
			fileOut << dress;
		}
		if (dynamic_cast<Bag*>(stock[i]))
		{
			Bag* bag = dynamic_cast<Bag*>(stock[i]);
			fileOut << bag;
		}
		if (dynamic_cast<Jacket*>(stock[i]))
		{
			Jacket* jacket = dynamic_cast<Jacket*>(stock[i]);
			fileOut << jacket;
		}
	}
	fileOut.close();
}

void SaveClothesToUser(Clothes* &clothes, string fileName)
{
	ofstream file;
	file.open("User\\" + fileName + ".txt", ios::app);
	if (dynamic_cast<Sweater*>(clothes))
	{
		Sweater* sweater = dynamic_cast<Sweater*>(clothes);
		file << sweater;
		file << "********" << endl;
	}
	if (dynamic_cast<Shirt*>(clothes))
	{
		Shirt* shirt = dynamic_cast<Shirt*>(clothes);
		file << shirt;
		file << "********" << endl;
	}
	if (dynamic_cast<Dress*>(clothes))
	{
		Dress* dress = dynamic_cast<Dress*>(clothes);
		file << dress;
		file << "********" << endl;
	}
	if (dynamic_cast<Bag*>(clothes))
	{
		Bag* bag = dynamic_cast<Bag*>(clothes);
		file << bag;
		file << "********" << endl;
	}
	if (dynamic_cast<Jacket*>(clothes))
	{
		Jacket* jacket = dynamic_cast<Jacket*>(clothes);
		file << jacket;
		file << "********" << endl;
	}
	file.close();
}