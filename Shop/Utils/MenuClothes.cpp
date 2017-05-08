#pragma once
#include "MenuClothes.h"
#include "../Entity/Bag.h"
#include "../Entity/Dress.h"
#include "../Entity/Shirt.h"
#include "../Entity/Sweater.h"
#include "../Entity/Jacket.h"

MenuClothes::MenuClothes()
{
	string filename = "DataShop.txt";
	loadClothes(filename);
}

MenuClothes::MenuClothes(const MenuClothes &menu)
{
	stock = menu.stock;
}

void MenuClothes::loadClothes(string filename)
{
	stock = LoadClothesFromFile(filename);
}

void MenuClothes::saveClothes()
{
	SaveProductsToFile(stock, "DataShop.txt");
}

void MenuClothes::printStartMenu()
{
	cout << "1: Login" << endl;
	cout << "2: Create account" << endl;
	cout << "0: Exit" << endl;
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

void MenuClothes::printAdminMenu()
{
	cout << endl;
	cout << "1: Add new item" << endl;
	cout << "2: Print list of items" << endl;
	cout << "3: Delete item" << endl;
	cout << "4: Update item" << endl;
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
			Clothes* item = addClothes();
			stock.push_back(item);
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
			cout << "Please, try again" << endl;
			break;
		}
		printAdminMenu();
		cin >> choose;
	}
}

Clothes* MenuClothes::addClothes()
{
	int type;

	cout << "1: Dress" << endl;
	cout << "2: Bag" << endl;
	cout << "3: Shirt" << endl;
	cout << "4: Sweater" << endl;
	cout << "5: Jacket" << endl;
	POINT:cin >> type;
	switch (type)
	{
	case 1: 
	{
		Dress dress;
		return dress.input();
	}
	case 2:
	{
		Bag bag;
		return bag.input();
	}
	case 3:
	{
		Shirt shirt;
		return shirt.input();
	}
	case 4:
	{
		Sweater sweater;
		return sweater.input();
	}
	case 5:
	{
		Jacket jacket;
		return jacket.input();
	}
	default:
	{
		cout << "Please, try again" << endl;
		goto POINT;
		break;
	}
	}
}

void MenuClothes::printUserMenu()
{
	cout << endl;
	cout << "1: View list of clothes" << endl;
	cout << "2: Add clothes to cart" << endl;
	cout << "3: View my info" << endl;
	cout << "0: Exit" << endl;
}

void MenuClothes::deleteClothe()
{
	string id;
	cout << "Eneter id of item to delete" << endl;
	cin >> id;
	for (int i = 0; i < stock.size(); i++)
	{
		if (stock[i]->getId()==id)
		{
			stock.erase(stock.begin() + i);
			saveClothes();
			cout << "Operation is completed" << endl;
			return;
		}
	}
	cout << "No items with such id exist" << endl;
}

void MenuClothes::update()
{
	string id;
	cout << "Enter id of item to update" << endl;
	cin >> id;
	for (int i = 0; i < stock.size(); i++)
	{
		if (stock[i]->getId()==id)
		{
			cout << "Please, enter new values for item"<< endl;
			stock[i] = stock[i]->input();
			saveClothes();
			cout << endl << "Operation is completed" << endl;
			return;
		}
	}
	cout << "No item with such id exist" << endl;
}

void MenuClothes::printClothes()
{
	if (this->stock.size() == 0)
	{
		cout << "List is empty" << endl;;
	}
	for (int i = 0; i < this->stock.size(); i++)
	{
		if (dynamic_cast<Sweater*>(stock[i]))
		{
			Sweater* sweater = dynamic_cast<Sweater*>(stock[i]);
			sweater->print();
			cout << endl;
			cout<< "------------" << endl;
		}
		if (dynamic_cast<Shirt*>(stock[i]))
		{
			Shirt* shirt = dynamic_cast<Shirt*>(stock[i]);
			shirt->print();
			cout << endl;
			cout << "------------" << endl;
		}
		if (dynamic_cast<Dress*>(stock[i]))
		{
			Dress* dress = dynamic_cast<Dress*>(stock[i]);
			dress->print();
			cout << endl;
			cout << "------------" << endl;
		}
		if (dynamic_cast<Bag*>(stock[i]))
		{
			Bag* bag = dynamic_cast<Bag*>(stock[i]);
			bag->print();
			cout << endl;
			cout << "------------" << endl;
		}
		if (dynamic_cast<Jacket*>(stock[i]))
		{
			Jacket* jacket = dynamic_cast<Jacket*>(stock[i]);
			jacket->print();
			cout << endl;
			cout << "------------" << endl;
		}
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
			cout << "Enter id of item to buy" << endl;
			string id;
			cin >> id;
			bool isCompleted = false;
			for (int i = 0; i < stock.size(); ++i)
			{
				if (stock[i]->getId() == id)
				{
					SaveClothesToUser(stock[i], user.getLogin());
					stock.erase(stock.begin() + i);
					saveClothes();
					cout << "Operation is completed" << endl;
					isCompleted = true;
					break;
				}
			}
			if (!isCompleted)
			{
				cout << "Sorry, there is no item with such id" << endl;
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