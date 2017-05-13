#pragma once
#include"ProductClothes.h"
#include<string>


struct BasketItem 
{
	string id;
	int count;

	BasketItem()
	{
		id = "";
		count = 1;
	}

	BasketItem(string id)
	{
		this->id = id;
		this->count = 1;
	}

	friend istream&operator>>(istream&is,  BasketItem&x)
	{
		is >> x.id >> x.count;
		return is;
	}

	friend ostream&operator<<(ostream&os, const BasketItem&x)
	{
		os << x.id << " " << x.count << endl;
		return os;
	}
};