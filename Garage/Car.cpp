#include "Car.h"

Car::Car(const char* brand, int speed) : Vehicle(brand)
{
	setSpeed(speed);
}

void Car::setSpeed(int speed)
{
	if (speed >= minSpeedCar && speed <= maxSpeedCar)
	{
		this->speed = speed;
	}
	else 
	{
		this->speed = minSpeedCar;
	}
}

int Car::getSpeed() const
{
	return speed;
}

void Car::print() const
{
	std::cout << "Car with speed " << speed << std::endl;
}
