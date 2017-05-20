#pragma once
#include "ProductClothes.h"
#include<iostream>

using namespace std;

class Sweater: public ProductClothes
{
protected:
	string color;
public:
	Sweater();
	Sweater(string id);
	Sweater(ProductClothes &p, string aColor);

	void setColor(string aColor);
	string getColor();

	string getFieldsName();
	void input(istream& is);
	void print(ostream& os) const;
	void addItem();

	bool operator==(const Sweater& sweater);
};