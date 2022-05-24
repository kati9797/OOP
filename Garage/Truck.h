#include "Truck.h"

Truck::Truck()
{
	speed = minSpeedTruck;
}

Truck::Truck(const char* brand, int speed) : Vehicle(brand)
{
	setSpeed(speed);
}

Vehicle* Truck::clone() const
{
	Vehicle* newObj = new Truck(*this);
	return newObj;
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

int Truck::getMaxSpeed() const
{
	return maxSpeedTruck;
}

void Truck::print() const
{
	std::cout << "Truck with speed " << speed << std::endl;
}
