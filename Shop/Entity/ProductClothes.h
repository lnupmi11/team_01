#pragma once
#include<string>
using namespace std;

class ProductClothes
{
protected:
	string id;
	string type;
	string sex;
	string size;
	double price;
	int amount;
public:
	ProductClothes();
	ProductClothes(string id);
	ProductClothes(string id, string sex, string size, double price, int amount);
	ProductClothes(const ProductClothes &obj);

	void setType(string newType);
	void setSize(string aSize);
	void setPrice(double aPrice);
	void setSex(string aSex);
	void setAmount(int aAmount);
	
	string getId();
	string getType();
	string getSex();
	string getSize();
	double getPrice();
	int getAmount();

	virtual string getFieldsName();
	virtual void input(istream& is);
	virtual void print(ostream& os) const;
	virtual void addItem();

	friend istream& operator >> (istream&is, ProductClothes&x);
	friend ostream& operator<<(ostream&os, const ProductClothes&x);
	
	bool operator==(const ProductClothes& pr);
};

