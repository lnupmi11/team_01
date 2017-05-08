#include"Clothes.h"
#include"Sweater.h"
#include"Shirt.h"
#include"Dress.h"
#include"Bag.h"
#include"Jacket.h"

Clothes::Clothes()
{
	sex = "";
	size = "";
	color = "";
	price = 0;
	id = "";
};

Clothes::Clothes(string aSex, string aSize, string aColor, double aPrice, string aMaterial, string aId)
{
	sex = aSex;
	size = aSize;
	color = aColor;
	price = aPrice;
	material = aMaterial;
	id = aId;
};

Clothes::Clothes(const Clothes & obj)
{
	sex = obj.sex;
	size = obj.size;
	color = obj.color;
	price = obj.price;
	material = obj.material;
	id = obj.id;
}

string Clothes::getSex()
{
	return sex;
};

string Clothes::getSize()
{
	return size;
};

string Clothes::getColor()
{
	return color;
};

double Clothes::getPrice()
{
	return price;
};

string Clothes::getId()
{
	return id;
}

string Clothes::getMaterial()
{
	return material;
}

ostream& operator<<(ostream& os, Clothes* &obj)
{
	if (dynamic_cast<Sweater*>(obj))
	{
		Sweater* sweater = dynamic_cast<Sweater*>(obj);
		os << sweater<<endl;
		os << "------------" << endl;
	}
	if (dynamic_cast<Shirt*>(obj))
	{
		Shirt* shirt = dynamic_cast<Shirt*>(obj);
		os << shirt<<endl;
		os << "------------" << endl;
	}
	return os;
	if (dynamic_cast<Dress*>(obj))
	{
		Dress* dress = dynamic_cast<Dress*>(obj);
		os << dress << endl;
		os << "------------" << endl;
	}
	if (dynamic_cast<Bag*>(obj))
	{
		Bag* bag = dynamic_cast<Bag*>(obj);
		os << bag << endl;
		os << "------------" << endl;
	}
	return os;
	if (dynamic_cast<Jacket*>(obj))
	{
		Jacket* jacket = dynamic_cast<Jacket*>(obj);
		os << jacket << endl;
		os << "------------" << endl;
	}
	return os;
}

bool Clothes::operator==(const Clothes* &clothes)
{
	return this->id == clothes->id;
}

bool Clothes::operator==(const Clothes &clothes)
{
	return this->id == clothes.id;
}