#include<iostream>
#include<string>
#include<fstream>

using namespace std;

class ProductClothes
{
private:
	string type;
	string sex;
	int size;
	double price;
public:
	ProductClothes();
	ProductClothes(string typeVal, string sexVal, int sizeVal, double priceVal);

	void setType(string newType);
	void setSize(int sizeVal);
	void setPrice(double priceVal);
	string getType();
	string getSex();
	int getSize();
	double getPrice();

	friend istream& operator >> (istream&is, ProductClothes&x);
	friend ifstream& operator >> (ifstream&is, ProductClothes&x);
	friend ostream& operator<<(ostream&os, const ProductClothes&x);
	friend ofstream& operator<<(ofstream&os, const ProductClothes&x);
};

