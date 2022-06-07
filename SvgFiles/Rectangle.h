#pragma once
#include "Shape.h"
#include "MyString.h"

class Rectangle : public Shape
{
private:
	unsigned width;
	unsigned height;
	MyString fill;

public:
	Rectangle();
	Rectangle(int x, int y, unsigned width, unsigned height, MyString fill);
	unsigned getWidth() const;
	unsigned getHeight() const;
	const MyString& getFill() const;
};
