#pragma once
#include"Footwear.h"

Footwear::Footwear()
{
	color = "white";
	brand = "Christian Louboutin";
}

Footwear::Footwear(ProductClothes&  obj, string aColor, string aBrand) :ProductClothes(obj)
{
	color = aColor;
	brand = aBrand;
}

void Footwear::setColor(string aColor)
{
	color = aColor;
}

void Footwear::setBrand(string aBrand)
{
	brand = aBrand;
}


string Footwear::getColor()
{
	return color;
}

string Footwear::getBrand()
{
	return brand;
}


string Footwear::getFieldsName()
{
	string str = ProductClothes::getFieldsName();
	str += ", color, brand";
	return str;
}

void Footwear::input(istream& is)
{
	ProductClothes::input(is);
	is >> color >> brand;
}

void Footwear::print(ostream& os) const
{
	ProductClothes::print(os);
	os << color << brand;
}

bool Footwear::operator==(const Footwear& shirt)
{
	return this->sex == footwear.sex && this->size == footwear.size
		&&this->color == footwear.color && this->brand == footwear.brand;
}