#pragma once
#include "MenuClothes.h"
#include "../Entity/Bag.h"
#include "../Entity/Dress.h"
#include "../Entity/Shirt.h"
#include "../Entity/Sweater.h"
#include "../Entity/Footwear.h"

MenuClothes::MenuClothes()
{
	string filename = "DataShop.txt";
	loadClothes(filename);
}

MenuClothes::MenuClothes(const MenuClothes &menu)
{
	arrClothes = menu.arrClothes;
}


void MenuClothes::loadClothes(string filename)
{
	arrClothes = LoadProductClothes(filename);
}

void MenuClothes::saveClothes()
{
	SaveProductsToFile(arrClothes, "DataShopOutPut.txt");
}

void MenuClothes:: startMenu()
{
	int choose;
	printStartMenu();
	cin >> choose;
	switch (choose)
	{
	case 1:
	{
		User user = login();
		if (user.getFirstName() != "")
		{
			cout << "Your login is successful !\n";
			if (user.getAdmin())
			{
				adminMenu();
			}
			else
			{

				userMenu(user);
			}
			
		}
		else
		{
			cout << "You entered invalid data! \n";
			startMenu();
		}
		break;
	}
	case 2:
	{
		User user = createNewUser();
		userMenu(user);
	}
	default:
		return;
		break;
	}
}


void MenuClothes::printStartMenu()
{
	cout << "1: Login" << endl;
	cout << "2: Create account" << endl;
	cout << "0: Exit" << endl;
}

void MenuClothes::adminMenu()
{
	int choose;
	printAdminMenu();
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
		printAdminMenu();
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
	cout << "5: footwear type" << endl;

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

	case 5:
	{
		Sweater footwear;
		cin >> footwear;
		return footwear;
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
void MenuClothes::printAdminMenu()
{
	cout << endl;
	cout << "1: input clothe" << endl;
	cout << "2: list clothes" << endl;
	cout << "3: delete clothe" << endl;
	cout << "4: update" << endl;
	cout << "0: exit" << endl;
}

void MenuClothes::printUserMenu()
{
	cout << endl;
	cout << "1: View list of clothes" << endl;
	cout << "2:Add clothes to cart" << endl;
	cout << "3:View my info" << endl;
	cout << "0:exit" << endl;
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

bool MenuClothes::isClothesAvailable(ProductClothes clothes)
{
	string typeOfClothe;
	for (int i = 0; i < arrClothes.size(); i++)
	{
		if (typeOfClothe == arrClothes[i].getType())
		{
			if (clothes == arrClothes[i])
			{
				return true;
			}
		}
	}
	return false;
}

void MenuClothes::addToCart(ProductClothes product,  User& user)
{
	saveProductToFile(product, user.getLogin());
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

void MenuClothes::userMenu( User& user)
{
	int choose;
	printUserMenu();
	cin >> choose;
	while (choose != 0)
	{
		switch (choose)
		{
		case 1: 
		{
			printClothes();
			break;
		}
		case 2: 
		{
			ProductClothes clothes = addClothe();
			if (isClothesAvailable(clothes))
			{
				addToCart(clothes, user);
			}
			else
			{
				cout << "Sorry, we don't have this item." << endl;
			}
			break;
		}
		case 3:
		{
			printInfo(user);
			break;
		}
		default:
			cout << "Wrong choise!!! Try again" << endl;
			break;
		}
		printUserMenu();
		cin >> choose;
	}
}