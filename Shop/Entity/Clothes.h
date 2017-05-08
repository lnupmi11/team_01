#pragma once
#include<string>
using namespace std;

class Clothes
{
protected:
	string sex;
	string size;
	string color;
	double price;
	string material;
	string id;

public:
	Clothes();
	Clothes(string aSex, string aSize, string aColor, double aPrice, string aMaterial, string aId);
	Clothes(const Clothes &obj);

	string getSex();
	string getSize();
	string getColor();
	double getPrice();
	string getMaterial();
	string getId();

	virtual Clothes* input() = 0;
	virtual void print() = 0;

	friend ostream& operator<<(ostream& os, Clothes* &obj);

	bool operator==(const Clothes* &clothes);
	bool operator==(const Clothes &clothes);
};