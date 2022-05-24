#include "Car.h"

Car::Car()
{ 
	speed = minSpeedCar;
}

Car::Car(const char* brand, int speed) : Vehicle(brand)
{
	setSpeed(speed);
}

Vehicle* Car::clone() const
{
	Vehicle* newObj = new Car(*this);
	return newObj;
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

int Car::getMaxSpeed() const
{
	return maxSpeedCar;
}

void Car::print() const
{
	std::cout << "Car with speed " << speed << std::endl;
}
