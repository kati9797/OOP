#pragma once
#include "CarPart.h"

class Tire : public CarPart 
{
private:
	unsigned short width;
	unsigned short profile;
	unsigned short diameter;

public:
	Tire();
	Tire(MyString, MyString, MyString, unsigned short, unsigned short, unsigned short);

	unsigned short getWidth() const;
	unsigned short getProfile() const;
	unsigned short getDiameter() const;
};
