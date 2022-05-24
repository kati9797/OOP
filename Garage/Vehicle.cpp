#include <iostream>
#include "Vehicle.h"
#pragma warning (disable:4996)

void Vehicle::copyFrom(const Vehicle& other)
{
	brand = new char[strlen(other.brand) + 1];
	strcpy(brand, other.brand);
	speed = other.speed;
}

void Vehicle::free()
{
	delete[] brand;
}

Vehicle::Vehicle()
{
	brand = nullptr;
	speed = 0;
}

Vehicle::Vehicle(const char* newBrand)
{
	brand = new char[strlen(newBrand) + 1];
	strcpy(brand, newBrand);
	speed = 0;
}

Vehicle::Vehicle(const Vehicle& other)
{
	copyFrom(other);
}

Vehicle& Vehicle::operator=(const Vehicle& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

Vehicle::~Vehicle()
{
	free();
}

const char* Vehicle::getBrand() const
{
	return brand;
}
