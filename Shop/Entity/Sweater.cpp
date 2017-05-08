#include"Sweater.h"
#include<iostream>

Sweater::Sweater()
{
	type = "";
}

Sweater::Sweater(string aSex, string aSize, string aColor, double aPrice, string aId,string aType,string aMaterial)
{
	sex = aSex;
	size = aSize;
	color = aColor;
	price = aPrice;
	id = aId;
	type = aType;
	material = aMaterial;
}

string Sweater::getType()
{
	return type;
}

istream& operator>>(istream& is, Sweater* &obj)
{
	is >> obj->sex;
	is >> obj->size;
	is >> obj->color;
	is >> obj->price;
	is >> obj->id;
	is >> obj->type;
	is >> obj->material;
	return is;
}

istream& operator>>(istream& is, Sweater &obj)
{
	is >> obj.sex;
	is >> obj.size;
	is >> obj.color;
	is >> obj.price;
	is >> obj.id;
	is >> obj.type;
	is >> obj.material;
	return is;
}

void Sweater::print()
{
	cout << "Sweater " + this->id << endl;
	cout << "Info:" << endl;
	cout << "sex: " << this->sex << endl;
	cout << "size: " << this->size << endl;
	cout << "color: " << this->color << endl;
	cout << "price: " << this->price << endl;
	cout << "style: " << this->type << endl;
	cout << "material: " << this->material << endl;
}

ostream& operator<<(ostream& os, Sweater* &obj)
{
	os << "Sweater" << endl;
	os << obj->sex << endl;
	os << obj->size << endl;
	os << obj->color << endl;
	os << obj->price << endl;
	os << obj->id << endl;
	os << obj->type << endl;
	os << obj->material << endl;
	return os;
}

ostream& operator<<(ostream& os, Sweater &obj)
{
	os << "Sweater" << endl;
	os << obj.sex << endl;
	os << obj.size << endl;
	os << obj.color << endl;
	os << obj.price << endl;
	os << obj.id << endl;
	os << obj.type << endl;
	os << obj.material << endl;
	return os;
}

Clothes* Sweater::input()
{
	cout << "Enter sex" << endl;
	string sex;
	cin >> sex;
	cout << "Enter size" << endl;
	string size;
	cin >> size;
	cout << "Enter color" << endl;
	string color;
	cin >> color;
	cout << "Enter price" << endl;
	double price;
	cin >> price;
	cout << "Enter id" << endl;
	string id;
	cin >> id;
	cout << "Enter type" << endl;
	string type;
	cin >> type;
	cout << "Enter material" << endl;
	string material;
	cin >> material;
	Sweater* sweater = new Sweater(sex, size, color, price, id, type, material);
	return sweater;
}
