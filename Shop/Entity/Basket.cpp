#pragma once
#include<iostream>
#include<string>
#include"Basket.h"


using namespace std;

Basket::Basket(vector<BasketItem*> items)
{
	this->items = items;
}

void Basket::addItem(ProductClothes* clothe)
{
	for (int i = 0; i<items.size(); i++)
	{
		if (items[i]->id == clothe->getId())
		{
			items[i]->count++;
			return;
		}
	}
	BasketItem* newItem= new BasketItem(clothe->getId());
	items.push_back(newItem);
}

vector<BasketItem*> Basket::getItems()
{
	return this->items;
}

void Basket::deleteItem(string id)
{
	for (int i = 0; i < items.size(); i++)
	{
		if (items[i]->id == id)
		{
			if (items[i]->count > 1)
			{
				items[i]->count--;
				return;
			}
			else
			{
				items.erase(items.begin() + i);
				return;
			}
			
		}
	}
}

