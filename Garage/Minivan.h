#pragma once
#include "Car.h"
const int maxSpeedVan = 160;
const int minSpeedVan = 120;

class Minivan : public Vehicle
{
private:
	int speed;

public:
	Minivan();
	Minivan(const char*, int);

	Vehicle* clone() const override;

	void setSpeed(int);
	int getSpeed() const override;
	int getMaxSpeed() const override;
	void print() const override;
};
