#pragma once
#pragma once
#include "Clothes.h"
class Jacket : public Clothes
{
protected:
	string type;
public:
	Jacket();
	Jacket(string aSex, string aSize, string aColor, double aPrice, string aId, string aType, string aMaterial);

	string getType();

	friend istream& operator>>(istream& is, Jacket* &obj);
	friend istream& operator>>(istream& is, Jacket &obj);
	friend ostream& operator<<(ostream& os, Jacket* &obj);
	friend ostream& operator<<(ostream& os, Jacket &obj);
	Clothes* input();
	void print();
};