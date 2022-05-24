#include "Minivan.h"

Minivan ::Minivan(const char* brand, int speed) : Vehicle(brand)
{
	setSpeed(speed);
}

void Minivan::setSpeed(int speed)
{
	if (speed >= minSpeedVan && speed <= maxSpeedVan)
	{
		this->speed = speed;
	}
	else
	{
		this->speed = minSpeedVan;
	}
}

int Minivan::getSpeed() const
{
	return speed;
}

void Minivan::print() const
{
	std::cout << "Minivan with speed " << speed << std::endl;
}
