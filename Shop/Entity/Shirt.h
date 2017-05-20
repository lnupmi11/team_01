#pragma once
#include"ProductClothes.h"
#include<iostream>

using namespace std;

class Shirt : public ProductClothes
{
protected:
	string color;
	string style;
public:
	Shirt();
	Shirt(string id);
	Shirt(ProductClothes&  one, string c, string s);

	void setColor(string aColor);
	void setStyle(string aStyle);

	string getColor();
	string getStyle();

	string getFieldsName();
	void input(istream& is);
	void print(ostream& os) const;
	void addItem();

	bool operator==(const Shirt& shirt);
};