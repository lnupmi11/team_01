#pragma once
#include "MenuClothes.h"
#include "../Entity/Bag.h"
#include "../Entity/Dress.h"
#include "../Entity/Shirt.h"
#include "../Entity/Sweater.h"
#include<iomanip>
#include <cctype>
#include "../Entity/Footwear.h"

bool checkInputF(string s)
{
	for (int i = 0; i < s.length(); i++)
	{
		if (!isdigit(s[i]))
		{
			return false;
		}
	}
}

MenuClothes::MenuClothes()
{
	basket = nullptr;
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
	SaveProductsToFile(arrClothes, "DataShop.txt");
}

void MenuClothes::startMenu()
{
	bool checkInput = false;
	string input;
	int choose;
	while (!checkInput)
	{
		printStartMenu();
		cin >> input;
		if (checkInputF(input))
		{
			choose = stoi(input);
		}
		else
		{
			choose = 100;
		}
		
		switch (choose)
		{
		case 1:
		{
			system("cls");
			User user = login();
			system("cls");
			if (user.getFirstName() != "")
			{
				cout << "Your login is successful !\n";
				if (user.getAdmin())
				{
					adminMenu(user);
				}
				else
				{
					basket = new Basket(LoadUserBasket(user.getLogin()));
					userMenu(user);
				}

			}
			else
			{
				cout << "You entered invalid data! \n";
			}
			break;
		}
		
		case 0:
		{
			checkInput = true;
			return;
			break;
		}
		case 2:
		{
			system("cls");
			User user;
			
			user = createNewUser();
			if (user.getFirstName() != "")
			{
				userMenu(user);
			}
			break;
		}
		default:
			system("cls");
		}
	}
}



void MenuClothes::printStartMenu()
{
	cout << "1: Login" << endl;
	cout << "2: Create account" << endl;
	cout << "0: Exit" << endl;
}

void MenuClothes::adminMenu(User& user)
{
	bool checkInput = false;
	string input;
	int choose;
	while (!checkInput)
	{
		
		printAdminMenu();
		cin >> input;
		if (checkInputF(input))
		{
			choose = stoi(input);
		}
		else
		{
			choose = 100;
		}
		system("cls");
		switch (choose)
		{
		case 1: {
			
			ProductClothes* clothe = addClothe();
			system("cls");
			if (checkId("DataShop.txt", clothe->getId()))
			{
				
				cout << "Item with that id already exist!" << endl;
			}
			else
			{
				cout << "You have added product successfully!" << endl;
				arrClothes.push_back(clothe);
				saveClothes();
			}
			break;
		}

		case 2: {
			
			printClothes();
			saveClothes();
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
		case 5:
		{
		
			printInfo(user);
			break;
		}
		case 0:
		{
			
			return;
		}
		default:
			system("cls");
			cout << "Wrong choise!!! Try again" << endl;
			break;
		}
	}
}

ProductClothes* MenuClothes::addClothe()
{
	int type;

	cout << "1: dress type" << endl;
	cout << "2: bag type" << endl;
	cout << "3: shirt type" << endl;
	cout << "4: sweater type" << endl;
	cout << "5: footwear type" << endl;

	cin >> type;
	ProductClothes *data;
	if (type == 1)
	{
		data = new Dress();
	}
	else if (type == 2)
	{
		data = new Bag();
	}
	else if (type == 3)
	{
		data = new Shirt();
	}
	else if (type == 4)
	{
		data = new Sweater();
	}
	else if (type == 5)
	{
		data = new Footwear();
	}
	else
	{
		data = new ProductClothes();
	}
	cin >> *data;
	return data;
}

void MenuClothes::printAdminMenu()
{
	cout << endl;
	cout << "1: input clothe" << endl;
	cout << "2: list clothes" << endl;
	cout << "3: delete clothe" << endl;
	cout << "4: update" << endl;
	cout << "5: view info" << endl;
	cout << "0: exit" << endl;
}

void MenuClothes::printUserMenu()
{
	cout << endl;
	cout << "1: View list of clothes" << endl;
	cout << "2: Add clothes to basket" << endl;
	cout << "3: View my basket" << endl;
	cout << "4: Delete item from basket" << endl;
	cout << "5: View my info" << endl;
	cout << "0: Exit" << endl;
}

void MenuClothes::deleteClothe()
{
	string id;
	
	printClothes();
	cout << "input id of clothe" << endl;
	cin >> id;
	system("cls");
	for (int i = 0; i < arrClothes.size(); i++)
	{
		if (id == arrClothes[i]->getId())
		{
			cout << "You have deleted successfully!" << endl;
			arrClothes.erase(arrClothes.begin() + i);
			return;
		}
	}
	cout << "Not found this clothe" << endl;

}

void MenuClothes::update()
{
	string id;
	printClothes();
	cout << "input id of clothe, which you want to update" << endl;
	cin >> id;
	system("cls");
	for (int i = 0; i < arrClothes.size(); i++)
	{
		if (id == arrClothes[i]->getId())
		{
			cout << "Please, input new values for: " << endl << *arrClothes[i] << endl;
			cin >> *arrClothes[i];
			system("cls");
			cout << "You have updated clothes successfully";
			return;
		}
	}
	cout << "Not found this clothe" << endl;
}

void MenuClothes::printClothes()
{
	cout << "///////////////////////////List of clothes//////////////////////////// \n";
	if (this->arrClothes.size() == 0)
	{
		cout << "List is empty" << endl;;
	}
	for (int i = 0; i < this->arrClothes.size(); i++)
	{
		cout << *this->arrClothes[i];
	}
	cout << "\n";
}

void MenuClothes::userMenu(User& user)
{
	bool inputCheck = false;
	string input;
	int choose;
	while (!inputCheck)
	{
		printUserMenu();
		cin >> input;
		if (checkInputF(input))
		{
			choose = stoi(input);
		}
		else
		{
			choose = 100;
		}
		system("cls");
			switch (choose)
			{
			case 1:
			{
				
				printClothes();
				break;
			}
			case 2:
			{
				printClothes();
				addToBasket();
				saveBasket(user.getLogin());
				break;
			}
			case 3:
			{
				
				printBasket();
				break;
			}
			case 4:
			{
				printBasket();
				string id;
				cout << "Input id of clothe , which you want to delete" << endl;
				cin >> id;
				basket->deleteItem(id);
				saveBasket(user.getLogin());
				break;
			}
			case 5:
			{
				
				printInfo(user);
				break;
			}
			case 0:
			{
				
				return;
			}
			default:
				cout << "Wrong choise!!! Try again" << endl;
				break;
			}
		
	}
}

void MenuClothes::addToBasket()
{
	string id;
	cout << "Input id" << endl;
	cin >> id;
	ProductClothes* product = findClothe(id);
	system("cls");
	if (product != nullptr)
	{
		basket->addItem(product);
		cout << "Product was added successfully" << endl;
		return;
	}
	else
	{
		cout << "Not find product for this id" << endl;
	}
}

ProductClothes* MenuClothes::findClothe(string id)
{
	ProductClothes* product = nullptr;
	for (int i = 0; i < arrClothes.size(); i++)
	{
		if (arrClothes[i]->getId() == id)
		{
			product = arrClothes[i];
			break;
		}
	}
	return product;
}

void MenuClothes::printBasket()
{
	vector<BasketItem*> items = basket->getItems();
	if (items.size() != 0)
	{
		double totalPrice = 0;
		cout << "id" << setw(7) << "type" << setw(25) << "price*count=total price" << endl;
		for (int i = 0; i < items.size(); i++)
		{
			ProductClothes* product = findClothe(items[i]->id);
			cout << product->getId() << setw(7) << product->getType() << setw(5) << product->getPrice() << "*" << items[i]->count << "=" << product->getPrice() *items[i]->count << endl;
			totalPrice += product->getPrice() *items[i]->count;
		}
		cout << "total price:" << totalPrice << endl;
	}
	else
	{
		cout << "Basket is empty" << endl;
	}
}


void MenuClothes::saveBasket(string userLogin)
{
	SaveUserBasketToFile(basket->getItems(), userLogin);
}

