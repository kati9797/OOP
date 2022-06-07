#include "Circle.h"

Circle::Circle() : Shape()
{
	radius = 0;
	fill = "No fill";
}

Circle::Circle(int x, int y, unsigned rad, MyString fill) : Shape(x,y)
{
	radius = rad;
	this->fill = fill;
}

unsigned Circle::getRadius() const
{
	return radius;
}

const MyString& Circle::getFill() const
{
	return fill;
}
