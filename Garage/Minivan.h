#pragma once
#include "Car.h"
const int maxSpeedVan = 160;
const int minSpeedVan = 120;

class Minivan : public Vehicle
{
private:
	int speed;

public:
	Minivan() = default;
	Minivan(const char*, int);

	void setSpeed(int);
	int getSpeed() const;
	void print() const;
};
