#pragma once
#include<iostream>
#include <typeinfo>
#include"ProductClothes.h"

ProductClothes::ProductClothes()
{
	this->id = "000";
	this->sex = "male";
	this->size = "L";
	this->price = 100.50;
	this->amount = 0;
};

ProductClothes::ProductClothes(string id)
{
	this->id = id;
	this->sex = "";
	this->size = "";
	this->price = 0;
	this->amount = 0;
}

ProductClothes::ProductClothes(string id, string sex, string size, double price, int amount)
{
	this->id = id;
	this->sex = sex;
	this->size = size;
	this->price = price;
	this->amount = amount;
};
ProductClothes::ProductClothes(const ProductClothes & obj)
{
	this->type = obj.type;
	this->sex = obj.sex;
	this->size = obj.size;
	this->price = obj.price;
	this->amount = obj.amount;
}

void ProductClothes::setType(string newType)
{
	type = newType;
};

void ProductClothes::setSize(string aSize)
{
	size = aSize;
};

void ProductClothes::setPrice(double priceVal)
{
	price = priceVal;
};

void ProductClothes::setSex(string aSex)
{
	sex = aSex;
}

void ProductClothes::setAmount(int aAmount)
{
	amount = aAmount;
}

string ProductClothes::getId()
{
	return id;
};

string ProductClothes::getSex()
{
	return sex;
};

string ProductClothes::getSize()
{
	return size;
};

double ProductClothes::getPrice()
{
	return price;
};

string ProductClothes::getType()
{
	return type;
};

int ProductClothes::getAmount()
{
	return amount;
}

string ProductClothes::getFieldsName()
{
	return "id, sex, size, price, amount";
};

void ProductClothes::input(istream& is)
{
	if (typeid(is) == typeid(istream))
	{
		is >> id;
	}
	is /*id >> type*/ >> sex >> size >> price >> amount;
}
void ProductClothes::print(ostream& os) const
{
	os << id << " " << type << " " << sex << " " << size << " " << price << " " << amount;
}

istream& operator >> (istream&is, ProductClothes&x)
{
	if (typeid(is) == typeid(istream))
	{
		cout << "Input " << x.getFieldsName() << endl;
	}
	x.input(is);
	return is;
};

ostream& operator<<(ostream&os, const ProductClothes&x)
{
	x.print(os);
	os << endl;
	return os;
};

bool ProductClothes::operator==(const ProductClothes& pr)
{
	return this->id == pr.id && this->sex == pr.sex && this->size == pr.size
		&& this->price == pr.price && this->type == pr.type;
}
