#include<iostream>
#include<string>
using namespace std;

class ProductClothes
{
protected:
	string sex;
	string size;
	double price;
	int amount;
public:
	ProductClothes();
	ProductClothes(string aSex, string aSize, double aPrice, int aAmount);

	void setSize(string aSize);
	void setPrice(double aPrice);
	void setSex(string aSex);
	void setAmount(int aAmount);
	string getSex();
	string getSize();
	double getPrice();
	int getAmount();
};

