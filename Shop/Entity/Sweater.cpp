#include"Sweater.h"

Sweater::Sweater()
{
	color = "blue";
	type = "jumper";
}

Sweater::Sweater(ProductClothes &p, string aColor, string aType):ProductClothes(p)
{
	color = aColor;
	type = aType;
}
void Sweater::setColor(string aColor)
{
	color = aColor;
}

void Sweater::setType(string aType)
{
	type = aType;
}

string Sweater::geteColor()
{
	return color;
}

string Sweater::getType()
{
	return type;
}
