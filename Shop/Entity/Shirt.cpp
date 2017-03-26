#pragma once
#include"Shirt.h"

Shirt::Shirt()
{
	color = "white";
	style = "none";
}

Shirt::Shirt(ProductClothes&  obj, string aColor, string aStyle):ProductClothes(obj)
{
	color = aColor;
	style = aStyle;
}

void Shirt::setColor(string aColor)
{
	color = aColor;
}

void Shirt::setStyle(string aStyle)
{
	style = aStyle;
}

string Shirt::getColor()
{
	return color;
}

string Shirt::getStyle()
{
	return style;
}