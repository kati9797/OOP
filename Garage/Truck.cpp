#include "Truck.h"

Truck::Truck(const char* brand, int speed) : Vehicle(brand)
{
	setSpeed(speed);
}

void Truck::setSpeed(int speed)
{
	if (speed >= minSpeedTruck && speed <= maxSpeedTruck)
	{
		this->speed = speed;
	}
	else
	{
		this->speed = minSpeedTruck;
	}
}

int Truck::getSpeed() const
{
	return speed;
}

void Truck::print() const
{
	std::cout << "Truck with speed " << speed << std::endl;
}
