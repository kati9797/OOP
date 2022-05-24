#pragma once
#include "Minivan.h"
const int maxSpeedTruck = 140;
const int minSpeedTruck = 80;

class Truck : public Vehicle
{
private:
	int speed;

public:
	Truck();
	Truck(const char*, int);

	Vehicle* clone() const override;

	void setSpeed(int);
	int getSpeed() const override;
	int getMaxSpeed() const override;
	void print() const override;
};
