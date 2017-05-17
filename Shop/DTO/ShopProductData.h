#pragma once
#include<fstream>
#include"../Entity/Basket.h"
#include"../Entity/ProductClothes.h"

vector<ProductClothes*> LoadProductClothes(string fileName);
void SaveProductsToFile(vector<ProductClothes*> clothes, string fileName);
void saveProductToFile(ProductClothes* clothes, string filename);

vector<BasketItem*> LoadUserBasket(string userLogin);
void SaveUserBasketToFile(vector<BasketItem*> basketItems, string userLogin);

bool checkId(string filename, string id);

