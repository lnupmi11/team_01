#pragma once
#include<iostream>
#include <typeinfo>
#include"ProductClothes.h"

ProductClothes::ProductClothes()
{
	 sex="male";
	 size ="L";
	 price=100.50;
	 amount =0;
};

ProductClothes::ProductClothes(string aSex, string aSize, double aPrice, int aAmount)
{
	sex = aSex;
	size = aSize;
	price = aPrice;
	amount = aAmount;
};
ProductClothes::ProductClothes(const ProductClothes & obj)
{
	type = obj.type;
	sex = obj.sex;
	size = obj.size;
	price = obj.price;
	amount = obj.amount;
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
	return "sex, size, price, amount";
};

void ProductClothes::input(istream& is)
{
	is /*>> type*/ >> sex >> size >> price >> amount;
}
void ProductClothes::print(ostream& os) const
{
	os << type << " " << sex << " " << size << " " << price << " " << amount;
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
	return this->sex == pr.sex && this->size == pr.size
		&& this->price == pr.price && this->type == pr.type;
}
