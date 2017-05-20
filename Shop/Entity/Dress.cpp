#pragma once
#include<iostream>
#include<string>
#include"Dress.h"


using namespace std;

Dress::Dress():ProductClothes()
{
	type = "dress";
	color = "red";
}

Dress::Dress(string id):ProductClothes(id)
{
	type = "dress";
	color = "red";
}

Dress::Dress(const ProductClothes& clothes, string color) : ProductClothes(clothes)
{
	this->color = color;
}

Dress::Dress(const Dress &dress) : ProductClothes(dress), color(dress.color)
{
	//this->color = dress.color;
}

string Dress::getFieldsName()
{
	string str = ProductClothes::getFieldsName();
	str += ", color, material";
	return str;
}
void Dress::addItem()
{
	ProductClothes::addItem();
	cout << "Enter color:" << endl;
	cin >> color;
}
void Dress::input(istream& is)
{
	ProductClothes::input(is);
	is >> color >> materail;
}

void Dress::print(ostream& os) const
{
	ProductClothes::print(os);
	os << " " << color << " " << materail;
}

bool Dress::operator==(const Dress& dress)
{
	return this->sex == dress.sex && this->size == dress.size
		&&this->color == dress.color;
}
