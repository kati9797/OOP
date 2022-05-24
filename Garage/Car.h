#pragma once
#include "Vehicle.h"
const int maxSpeedCar = 240;
const int minSpeedCar = 180;

class Car : public Vehicle
{
private:
	
	int speed;

public:
	Car() = default;
	Car(const char*, int);

	void setSpeed(int);
	int getSpeed() const;
	void print() const;
};
