#pragma once
#include<iostream>
#include<string>
#include"ProductClothes.h"

using namespace std;

class Footwear : public ProductClothes
{
protected:
	string color;
	string brand;
public:
	Footwear();
	Footwear(string id);
	Footwear(ProductClothes&  one, string col, string br);

	void setColor(string aColor);
	void setBrand(string aBrand);

	string getColor();
	string getBrand();

	string getFieldsName();
	void input(istream& is);
	void print(ostream& os) const;

	bool operator==(const Footwear& footwear);
};