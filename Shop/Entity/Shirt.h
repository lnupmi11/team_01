#pragma once
#include"ProductClothes.h"

using namespace std;

class Shirt : public ProductClothes
{
protected:
	string color;
	string style;
public:
	Shirt();
	Shirt(ProductClothes&  one, string c, string s);

	void setColor(string aColor);
	void setStyle(string aStyle);

	string getColor();
	string getStyle();

	string getFieldsName();
	void input(istream& is);
	void print(ostream& os) const;

};