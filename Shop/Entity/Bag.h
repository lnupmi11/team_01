#pragma once
#include"Clothes.h"
class Bag : public Clothes
{
private:
	string brand;
public:
	Bag();
	Bag(string aSex, string aSize, string aColor, double aPrice, string aId, string aBrand, string aMaterial);

	string getBrand();

	friend istream& operator>>(istream& is, Bag* &obj);
	friend istream& operator>>(istream& is, Bag &obj);
	friend ostream& operator<<(ostream& os, Bag* &obj);
	friend ostream& operator<<(ostream& os, Bag &obj);
	Clothes* input();
	void print();
};