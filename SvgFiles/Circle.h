#include "Shape.h"
#include "MyString.h"

class Circle : public Shape
{
private:
	unsigned radius;
	MyString fill;

public:
	Circle();
	Circle(int x, int y, unsigned rad, MyString fill);
	unsigned getRadius() const;
	const MyString& getFill() const;
};
