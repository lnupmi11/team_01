#pragma once
#include<fstream>
#include"../Entity/ProductClothes.h"

vector<ProductClothes> LoadProductClothes(string fileName);

void SaveProductsToFile(vector<ProductClothes> clothes, string fileName);

void saveProductToFile(ProductClothes clothtes, string filename);
