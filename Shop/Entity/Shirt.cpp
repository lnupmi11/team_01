#pragma once
#include"Shirt.h"

Shirt::Shirt()
{
	type = "shirt";
	color = "white";
	style = "none";
}

Shirt::Shirt(string id) : ProductClothes(id)
{
	type = "shirt";
	color = "white";
	style = "none";
}

Shirt::Shirt(ProductClothes&  obj, string aColor, string aStyle):ProductClothes(obj)
{
	color = aColor;
	style = aStyle;
}

void Shirt::setColor(string aColor)
{
	color = aColor;
}

void Shirt::setStyle(string aStyle)
{
	style = aStyle;
}

string Shirt::getColor()
{
	return color;
}

string Shirt::getStyle()
{
	return style;
}

string Shirt::getFieldsName()
{
	string str = ProductClothes::getFieldsName();
	str += ", color, style";
	return str;
}

void Shirt::input(istream& is)
{
	ProductClothes::input(is);
	is >> color >> style;
}
void Shirt::addItem()
{
	ProductClothes::addItem();
	cout << "Enter color:" << endl;
	cin >> color;
	cout << "Enter style:" << endl;
	cin >> style;
}
void Shirt::print(ostream& os) const
{
	ProductClothes::print(os);
	os << " " << color << " " << style;
}

bool Shirt::operator==(const Shirt& shirt)
{
	return this->sex == shirt.sex && this->size == shirt.size
		&&this->color == shirt.color && this->style == shirt.style;
}