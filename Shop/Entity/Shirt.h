#pragma once
#include"Clothes.h"
using namespace std;

class Shirt : public Clothes
{
protected:
	string style;
public:
	Shirt();
	Shirt(string aSex, string aSize, string aColor, double aPrice, string aMaterial, string aId, string aStyle);

	string getStyle();

	friend istream& operator>>(istream& is, Shirt* &obj);
	friend istream& operator>>(istream& is, Shirt &obj);
	friend ostream& operator<<(ostream& os, Shirt* &obj);
	friend ostream& operator<<(ostream& os, Shirt &obj);
	Clothes* input();
	void print();
};