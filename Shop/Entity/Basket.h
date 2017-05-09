#pragma once
#include<iostream>
#include<string>
#include<vector>
#include"BasketItem.h"
#include"ProductClothes.h"
#include"User.h"

class Basket
{
protected:
	vector<BasketItem*> items;
	User user;
public:
	Basket(vector<BasketItem*> items);

	void addItem(ProductClothes* clothe);
	vector<BasketItem*> getItems();
	void deleteItem(string id);
};