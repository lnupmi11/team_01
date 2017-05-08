#pragma once
#include "Clothes.h"
class Sweater: public Clothes
{
protected:
	string type;
public:
	Sweater();
	Sweater(string aSex, string aSize, string aColor, double aPrice, string aId, string aType, string aMaterial);

	string getType();

	friend istream& operator>>(istream& is, Sweater* &obj);
	friend istream& operator>>(istream& is, Sweater &obj);
	friend ostream& operator<<(ostream& os, Sweater* &obj);
	friend ostream& operator<<(ostream& os, Sweater &obj);
	Clothes* input();
	void print();
};