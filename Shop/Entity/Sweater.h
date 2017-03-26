#pragma once
#include "ProductClothes.h"
class Sweater: public ProductClothes
{
protected:
	string color;
	string type;
public:
	Sweater();
	Sweater(ProductClothes &p, string aColor, string aType);

	void setColor(string aColor);
	void setType(string aType);
	string geteColor();
	string getType();
};