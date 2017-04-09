#pragma once
#include"ProductClothes.h"

class Bag : public ProductClothes
{
private:
	string brand;
public:
	Bag();
	Bag(const ProductClothes& clothes, string brand);
	Bag(const Bag &dress);

	string getFieldsName();
	void input(istream& is);
	void print(ostream& os) const;

	bool operator==(const Bag& bag);
};