#include "Garage.h"

unsigned Garage::size = 0;

Garage::Garage()
{
	capacity = 0;
	cars = Vector<Car>();
	minivans = Vector<Minivan>();
	trucks = Vector<Truck>();
}

Garage::Garage(unsigned newCapacity)
{
	capacity = newCapacity;
	cars = Vector<Car>();
	minivans = Vector<Minivan>();
	trucks = Vector<Truck>();
}

const Vector<Car>& Garage::getCars() const
{
	return cars;
}

const Vector<Minivan>& Garage::getVans() const
{
	return minivans;
}

const Vector<Truck>& Garage::getTrucks() const
{
	return trucks;
}

void Garage::pushCarInGarage(const Car& car)
{
	if (size < capacity)
	{
		cars.push(car);
		size++;
	}
	else throw std::logic_error("Garage is full!");
}

void Garage::pushMinivanInGarage(const Minivan& minivan)
{
	if (size < capacity)
	{
		minivans.push(minivan);
		size++;
	}
	else throw std::logic_error("Garage is full!");
}

void Garage::pushTruckInGarage(const Truck& truck)
{
	if (size < capacity)
	{
		trucks.push(truck);
		size++;
	}
	else throw std::logic_error("Garage is full!");
}

int Garage::posibleOrders(double highwayKm, double speedRoadKm, double thirdClassRoadKm, double hours) const
{
	int count = 0;
	if (size == 0)
	{
		throw std::logic_error("There is no vehicles!");
	}

	for (int i = 0; i < cars.getSize(); i++)
	{
		if (highwayKm / cars[i].getSpeed() <= hours && speedRoadKm / cars[i].getSpeed() <= hours && thirdClassRoadKm / cars[i].getSpeed() <= hours)
		{
			count++;
		}
	}

	for (int i = 0; i < minivans.getSize(); i++)
	{
		if (highwayKm / minivans[i].getSpeed() <= hours && speedRoadKm / (minivans[i].getSpeed()/2) <= hours && thirdClassRoadKm / (minivans[i].getSpeed()/3) <= hours)
		{
			count++;
		}
	}

	for (int i = 0; i < trucks.getSize(); i++)
	{
		if (highwayKm / (trucks[i].getSpeed()/2) <= hours && speedRoadKm / (trucks[i].getSpeed()/4) <= hours && thirdClassRoadKm / 10 <= hours)
		{
			count++;
		}
	}

	return count;
}
