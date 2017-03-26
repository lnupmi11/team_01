#pragma once
#include "../Shop/ProductClothes.h"
class Sweater: public ProductClothes
{
protected:
	string color;
	string type;
public:
	Sweater();
	Sweater(ProductClothes &p, string aColor, string aType) :ProductClothes(p), color(aColor), type(aType) {};

	void setColor(string aColor);
	void setType(string aType);
	string geteColor();
	string getType();
};