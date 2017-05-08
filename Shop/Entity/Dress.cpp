#pragma once
#include"Dress.h"
#include<iostream>
Dress::Dress()
{
	style = "";
}

Dress::Dress(string aSex, string aSize, string aColor, double aPrice, string aId, string aStyle, string aMaterial)
{
	sex = aSex;
	size = aSize;
	color = aColor;
	price = aPrice;
	id = aId;
	style = aStyle;
	material = aMaterial;
}

string Dress::getStyle()
{
	return style;
}

istream& operator>>(istream& is, Dress* &obj)
{
	is >> obj->sex;
	is >> obj->size;
	is >> obj->color;
	is >> obj->price;
	is >> obj->id;
	is >> obj->style;
	is >> obj->material;
	return is;
}

istream& operator>>(istream& is, Dress &obj)
{
	is >> obj.sex;
	is >> obj.size;
	is >> obj.color;
	is >> obj.price;
	is >> obj.id;
	is >> obj.style;
	is >> obj.material;
	return is;
}

void Dress::print()
{
	cout << "Dress " + this->id << endl;
	cout << "Info:" << endl;
	cout << "sex: " << this->sex << endl;
	cout << "size: " << this->size << endl;
	cout << "color: " << this->color << endl;
	cout << "price: " << this->price << endl;
	cout << "style: " << this->style << endl;
	cout << "material: " << this->material << endl;
}

ostream& operator<<(ostream& os, Dress* &obj)
{
	os << "Dress" << endl;
	os << obj->sex << endl;
	os << obj->size << endl;
	os << obj->color << endl;
	os << obj->price << endl;
	os << obj->id << endl;
	os << obj->style << endl;
	os << obj->material << endl;
	return os;
}

ostream& operator<<(ostream& os, Dress &obj)
{
	os << "Dress" << endl;
	os << obj.sex << endl;
	os << obj.size << endl;
	os << obj.color << endl;
	os << obj.price << endl;
	os << obj.id << endl;
	os << obj.style << endl;
	os << obj.material << endl;
	return os;
}

Clothes* Dress::input()
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
	cout << "Enter style" << endl;
	string style;
	cin >> style;
	cout << "Enter material" << endl;
	string material;
	cin >> material;
	Dress* dress = new Dress(sex, size, color, price, id, style, material);
	return dress;
}
