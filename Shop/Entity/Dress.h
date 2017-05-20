#pragma once
#include<iostream>
#include<string>
#include"ProductClothes.h"


using namespace std;

class Dress : public ProductClothes
{
private:
	string color;
	string materail;
public:
	Dress();
	Dress(string id);
	Dress(const ProductClothes& clothes, string color);
	Dress(const Dress &dress);

	string getFieldsName();
	void input(istream& is);
	void print(ostream& os) const;
	void addItem();

	bool operator==(const Dress& dress);
};
