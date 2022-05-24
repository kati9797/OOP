#include "Minivan.h"

Minivan::Minivan()
{
	speed = minSpeedVan;
}

Minivan ::Minivan(const char* brand, int speed) : Vehicle(brand)
{
	setSpeed(speed);
}

Vehicle* Minivan::clone() const
{
	Vehicle* newObj = new Minivan(*this);
	return newObj;
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

int Minivan::getMaxSpeed() const
{
	return maxSpeedVan;
}

void Minivan::print() const
{
	std::cout << "Minivan with speed " << speed << std::endl;
}
