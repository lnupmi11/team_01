#pragma once
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

int ProductClothes::getAmount()
{
	return amount;
}
