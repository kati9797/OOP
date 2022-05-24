#include "Garage.h"

void Garage::copyFrom(const Garage& other)
{
	capacity = other.capacity;
	size = other.size;
	garage = new Vehicle * [capacity];
	for (int i = 0; i < size; i++)
	{
		garage[i] = other.garage[i]->clone();
	}
}

void Garage::free()
{
	for (int i = 0; i < size; i++)
	{
		delete garage[i];
	}
	delete[] garage;
}

Garage::Garage()
{
	capacity = 4;
	size = 0;
	garage = new Vehicle * [capacity];
}

Garage::Garage(unsigned newCapacity)
{
	capacity = newCapacity;
	size = 0;
	garage = new Vehicle*[capacity];
}

Garage::Garage(const Garage& other)
{
	copyFrom(other);
}

Garage& Garage::operator=(const Garage& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

Garage::~Garage()
{
	free();
}

void Garage::addVechicle(const Vehicle& obj)
{
	if (size < capacity)
	{
		garage[size++] = obj.clone();
	}
	else 
	{
		throw std::logic_error("Garage is full!");
	}
}


int Garage::posibleOrders(double highwayKm, double speedRoadKm, double thirdClassRoadKm, double hours) const
{
	int count = 0;
	if (size == 0)
	{
		throw std::logic_error("There is no vehicles!");
	}

	for (int i = 0; i < size; i++)
	{
		if (garage[i]->getMaxSpeed() == maxSpeedCar)
		{
			if (highwayKm / garage[i]->getSpeed() <= hours && speedRoadKm / garage[i]->getSpeed() <= hours && thirdClassRoadKm / garage[i]->getSpeed() <= hours)
			{
				count++;
			}
		}
		else if (garage[i]->getMaxSpeed() == maxSpeedVan)
		{
			if (highwayKm / garage[i]->getSpeed() <= hours && speedRoadKm / (garage[i]->getSpeed()/2) <= hours && thirdClassRoadKm / (garage[i]->getSpeed()/3) <= hours)
			{
				count++;
			}
		}
		else if (garage[i]->getMaxSpeed() == maxSpeedTruck)
		{
			if (highwayKm / (garage[i]->getSpeed()/2) <= hours && speedRoadKm / (garage[i]->getSpeed()/4) <= hours && thirdClassRoadKm / 10 <= hours)
			{
				count++;
			}
		}
	}
	return count;
}

