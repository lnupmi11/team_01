#pragma once
#include<fstream>
#include"../Entity/Clothes.h"

vector<Clothes*> LoadClothesFromFile(string fileName);

void SaveProductsToFile(vector<Clothes*> &clothes, string fileName);

void SaveClothesToUser(Clothes* &clothes, string fileName);
