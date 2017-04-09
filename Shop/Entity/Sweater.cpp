#include"Sweater.h"

Sweater::Sweater()
{
	type = "sweater";
	color = "blue";
	type = "jumper";
}

Sweater::Sweater(ProductClothes &p, string aColor):ProductClothes(p)
{
	color = aColor;
}
void Sweater::setColor(string aColor)
{
	color = aColor;
}

string Sweater::getColor()
{
	return color;
}

string Sweater::getFieldsName()
{
	string str = ProductClothes::getFieldsName();
	str += ", color";
	return str;
}

void Sweater::input(istream& is)
{
	ProductClothes::input(is);
	is >> color;
}

void Sweater::print(ostream& os) const
{
	ProductClothes::print(os);
	os << color ;
}

bool Sweater::operator==(const Sweater& sweater)
{
	return this->sex == sweater.sex && this->size == sweater.size
		&&this->color == sweater.color && this->type == sweater.type;
}

