#include "Rectangle.h"

Rectangle::Rectangle() : Shape()
{
	width = 0;
	height = 0;
	fill = "No fill";
}

Rectangle::Rectangle(int x, int y, unsigned width, unsigned height, MyString fill) : Shape(x,y)
{
	this->width = width;
	this->height = height;
	this->fill = fill;
}

unsigned Rectangle::getWidth() const
{
	return width;
}

unsigned Rectangle::getHeight() const
{
	return height;
}

const MyString& Rectangle::getFill() const
{
	return fill;
}

