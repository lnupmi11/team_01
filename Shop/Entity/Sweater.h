#pragma once
#include "ProductClothes.h"
class Sweater: public ProductClothes
{
protected:
	string color;
public:
	Sweater();
	Sweater(ProductClothes &p, string aColor);

	void setColor(string aColor);
	string getColor();

	string getFieldsName();
	void input(istream& is);
	void print(ostream& os) const;
};