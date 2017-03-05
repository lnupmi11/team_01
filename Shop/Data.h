#include<fstream>
#include"ProductClothes.h"

ProductClothes* LoadProductClothes(string fileName)
{
	ifstream file(fileName);
	int n;
	file >> n;
	ProductClothes* array = new ProductClothes[n];

	for (int i = 0; i < n; i++)
	{
		file >> array[i];
	}

	return array;
}
void SaveProductsToFile(ProductClothes* array, string fileName)
{
	//int size = sizeof(array) / sizeof(array[0]);//size of array
	ofstream fileOut(fileName);
	for (int i = 0; i < 3; i++)
	{
		fileOut << array[i];
	}
	fileOut.close();
}