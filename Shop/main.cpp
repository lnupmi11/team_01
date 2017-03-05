#include<iostream>
#include<string>
#include"Data.h"

using namespace std;

void main()
{
	ProductClothes* products = LoadProductClothes("ProductClothes.txt");

	SaveProductsToFile(products, "ProductClothesOut.txt");
	system("pause");
}