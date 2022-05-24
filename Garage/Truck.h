#pragma once
#include "Minivan.h"
const int maxSpeedTruck = 140;
const int minSpeedTruck = 80;

class Truck : public Vehicle
{
private:
	int speed;

public:
	Truck() = default;
	Truck(const char*, int);

	void setSpeed(int);
	int getSpeed() const;
	void print() const;
};
