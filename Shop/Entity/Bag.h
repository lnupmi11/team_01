#pragma once
#include"ProductClothes.h"
#include<iostream>

class Bag : public ProductClothes
{
private:
	string brand;
public:
	Bag();
	Bag(string id);
	Bag(const ProductClothes& clothes, string brand);
	Bag(const Bag &dress);

	string getFieldsName();
	void input(istream& is);
	void print(ostream& os) const;
	void addItem();

	bool operator==(const Bag& bag);
};