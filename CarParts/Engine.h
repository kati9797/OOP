#pragma once
#include "CarPart.h"

class Engine : public CarPart
{
private:
	unsigned short horsepower;
public:
	Engine();
	Engine(MyString, MyString, MyString, unsigned short);

	unsigned short getHorsePower() const;
};
