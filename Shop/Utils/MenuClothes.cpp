#pragma once
#include "MenuClothes.h"
#include "../Entity/Bag.h"
#include "../Entity/Dress.h"
#include "../Entity/Shirt.h"
#include "../Entity/Sweater.h"

MenuClothes::MenuClothes()
{
	loadClothes();
}

MenuClothes::MenuClothes(const MenuClothes &menu)
{
	arrClothes = menu.arrClothes;
}

void MenuClothes::loadClothes()
{
	string fileName="DataShop.txt";
	arrClothes = LoadProductClothes(fileName);
}

void MenuClothes::saveClothes()
{
	SaveProductsToFile(arrClothes, "DataShopOutPut.txt");
}

void MenuClothes::clothesMenu()
{
	int choose;
	printMenuClothesHeader();
	cin >> choose;
	while (choose != 0)
	{
		switch (choose)
		{
		case 1: {
			ProductClothes clothe = addClothe();
			arrClothes.push_back(clothe);
			saveClothes();
			break;
		}

		case 2: {
			printClothes();
			break;
		}
		case 3:
		{
			deleteClothe();
			saveClothes();
			break;
		}
		case 4:
		{
			update();
			saveClothes();
			break;
		}
		default:
			cout << "Wrong choise!!! Try again" << endl;
			break;
		}
		printMenuClothesHeader();
		cin >> choose;
	}
}

ProductClothes MenuClothes::addClothe()
{
	int type;

	cout << "1: dress type" << endl;
	cout << "2: bag type" << endl;
	cout << "3: shirt type" << endl;
	cout << "4: sweater type" << endl;

	cin >> type;
	switch (type)
	{
	case 1: 
	{
		Dress dress;
		cin >> dress;
		return dress;
		break;
	}
	case 2:
	{
		Bag bag;
		cin >> bag;
		return bag;
		break;
	}
	case 3:
	{
		Shirt shirt;
		cin >> shirt;
		return shirt;
		break;
	}
	case 4:
	{
		Sweater sweater;
		cin >> sweater;
		return sweater;
		break;
	}

	default:
	{
		ProductClothes clothe;
		cin >> clothe;
		return clothe;
		break;
	}

	}
}

void MenuClothes::printMenuClothesHeader()
{
	cout << endl;
	cout << "1: input clothe" << endl;
	cout << "2: list clothes" << endl;
	cout << "3: delete clothe" << endl;
	cout << "4: update" << endl;
	cout << "0: exit" << endl;
}

void MenuClothes::deleteClothe()
{
	string typeOfClothe;
	cout << "input type of clothe" << endl;
	cin >> typeOfClothe;
	for (int i = 0; i < arrClothes.size(); i++)
	{
		if (typeOfClothe == arrClothes[i].getType())
		{
			arrClothes.erase(arrClothes.begin() + i);
			return;
		}
	}
	cout << "Not found this clothe" << endl;

}

void MenuClothes::update()
{
	string typeOfClothe;
	cout << "input type of clothe, which you want to update" << endl;
	cin >> typeOfClothe;
	for (int i = 0; i < arrClothes.size(); i++)
	{
		if (typeOfClothe == arrClothes[i].getType())
		{
			cout << "Please, input new values for " << arrClothes[i].getType() << endl;
			cin >> arrClothes[i];
			return;
		}
	}
	cout << "Not found this clothe" << endl;
}
void MenuClothes::printClothes()
{
	if (this->arrClothes.size() == 0)
	{
		cout << "List is empty" << endl;;
	}
	for (int i = 0; i < this->arrClothes.size(); i++)
	{
		cout << this->arrClothes[i];
	}
}