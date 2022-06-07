#pragma once
#include <iostream>

class Shape
{
private:
	int x;
	int y;

public:
	Shape();
	Shape(int x, int y);
	int getX() const;
	int getY() const;
	//virtual void print() const = 0;
	virtual ~Shape() = default;
};
