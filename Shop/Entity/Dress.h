#pragma once
#include"Clothes.h"
class Dress : public Clothes
{
private:
	string style;
public:
	Dress();
	Dress(string aSex, string aSize, string aColor, double aPrice, string aId, string aStyle, string aMaterial);

	string getStyle();

	friend istream& operator>>(istream& is, Dress* &obj);
	friend istream& operator>>(istream& is, Dress &obj);
	friend ostream& operator<<(ostream& os, Dress* &obj);
	friend ostream& operator<<(ostream& os, Dress &obj);
	Clothes* input();
	void print();
};
