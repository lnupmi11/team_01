#pragma once
#include"Bag.h"

Bag::Bag() :ProductClothes()
{
	this->type = "bag";
	this->brand = "gucci";
}
Bag::Bag(const ProductClothes& clothes, string brand) : ProductClothes(clothes)
{
	this->brand = brand;
}

Bag::Bag(const Bag &bag) : ProductClothes(bag), brand(bag.brand)
{
	//this->color = dress.color;
}

string Bag::getFieldsName()
{
	string str = ProductClothes::getFieldsName();
	str += ", brand";
	return str;
}

void Bag::input(istream& is)
{
	ProductClothes::input(is);
	is >> brand;
}

void Bag::print(ostream& os) const
{
	ProductClothes::print(os);
	os << brand;
}

bool Bag:: operator==(const Bag& bag)
{
	return this->sex == bag.sex && this->size == bag.size
		&&this->brand == bag.brand;
}