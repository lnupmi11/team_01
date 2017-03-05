#include<iostream>
#include<string>
#include<fstream>
#include"ProductClothes.h"

using namespace std;


ProductClothes::ProductClothes()
{
	type = "T-Shirt";
	sex = "man";
	size = 40;
	price = 100;
};
ProductClothes::ProductClothes(string typeVal, string sexVal, int sizeVal, double priceVal)
{
	type = typeVal;
	sex = sexVal;
	size = sizeVal;
	price = priceVal;
};
void ProductClothes::setType(string newType)
{
	type = newType;
};
void ProductClothes::setSize(int sizeVal)
{
	size = sizeVal;
};
void ProductClothes::setPrice(double priceVal)
{
	price = priceVal;
};
string ProductClothes::getType()
{
	return type;
};
string ProductClothes::getSex()
{
	return sex;
};
int ProductClothes::getSize()
{
	return size;
};
double ProductClothes::getPrice()
{
	return price;
};
 istream& operator >> (istream&is, ProductClothes&x)
{
	is >> x.type >> x.sex >> x.size >> x.price;
	return is;
};
 ifstream& operator >> (ifstream&is, ProductClothes&x)
{
	is >> x.type >> x.sex >> x.size >> x.price;
	return is;
};
 ostream& operator<<(ostream&os, const ProductClothes&x)
{
	os << x.type << " " << x.sex << " " << x.size << " " << x.price << endl;
	return os;
};
ofstream& operator<<(ofstream&os, const ProductClothes&x)
{
	os << x.type << " " << x.sex << " " << x.size << " " << x.price << endl;
	return os;
};
