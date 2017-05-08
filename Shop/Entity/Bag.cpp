#pragma once
#include"Bag.h"
#include<iostream>
Bag::Bag()
{
	brand = "";
}

Bag::Bag(string aSex, string aSize, string aColor, double aPrice, string aId, string aBrand, string aMaterial)
{
	sex = aSex;
	size = aSize;
	color = aColor;
	price = aPrice;
	id = aId;
	brand = aBrand;
	material = aMaterial;
}

string Bag::getBrand()
{
	return brand;
}

istream& operator>>(istream& is, Bag* &obj)
{
	is >> obj->sex;
	is >> obj->size;
	is >> obj->color;
	is >> obj->price;
	is >> obj->id;
	is >> obj->brand;
	is >> obj->material;
	return is;
}

istream& operator>>(istream& is, Bag &obj)
{
	is >> obj.sex;
	is >> obj.size;
	is >> obj.color;
	is >> obj.price;
	is >> obj.id;
	is >> obj.brand;
	is >> obj.material;
	return is;
}

void Bag::print()
{
	cout << "Bag " + this->id << endl;
	cout << "Info:" << endl;
	cout << "sex: " << this->sex << endl;
	cout << "size: " << this->size << endl;
	cout << "color: " << this->color << endl;
	cout << "price: " << this->price << endl;
	cout << "brand: " << this->brand << endl;
	cout << "material: " << this->material << endl;
}

ostream& operator<<(ostream& os, Bag* &obj)
{
	os << "Bag" << endl;
	os << obj->sex << endl;
	os << obj->size << endl;
	os << obj->color << endl;
	os << obj->price << endl;
	os << obj->id << endl;
	os << obj->brand << endl;
	os << obj->material << endl;
	return os;
}

ostream& operator<<(ostream& os, Bag &obj)
{
	os << "Bag" << endl;
	os << obj.sex << endl;
	os << obj.size << endl;
	os << obj.color << endl;
	os << obj.price << endl;
	os << obj.id << endl;
	os << obj.brand << endl;
	os << obj.material << endl;
	return os;
}

Clothes* Bag::input()
{
	cout << "Enter sex" << endl;
	string sex;
	cin >> sex;
	cout << "Enter size" << endl;
	string size;
	cin >> size;
	cout << "Enter color" << endl;
	string color;
	cin >> color;
	cout << "Enter price" << endl;
	double price;
	cin >> price;
	cout << "Enter id" << endl;
	string id;
	cin >> id;
	cout << "Enter brand" << endl;
	string brand;
	cin >> brand;
	cout << "Enter material" << endl;
	string material;
	cin >> material;
	Bag* bag = new Bag(sex, size, color, price, id, brand, material);
	return bag;
}