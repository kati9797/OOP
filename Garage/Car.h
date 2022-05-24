#pragma once
#include "Vehicle.h"
const int maxSpeedCar = 240;
const int minSpeedCar = 180;

class Car : public Vehicle
{
private:
	int speed;

public:
	Car();
	Car(const char*, int);
	
	Vehicle* clone() const override;

	void setSpeed(int);
	int getSpeed() const override;
	int getMaxSpeed() const override;
	void print() const override;
};
