#pragma once
#include "Vehicle.h"
#include "Car.h"
#include "Minivan.h"
#include "Truck.h"

class Garage
{
private:
	Vehicle** garage;
	unsigned size;
	unsigned capacity;

	void copyFrom(const Garage&);
	void free();
public:
	Garage();
	Garage(unsigned);
	Garage(const Garage&);
	Garage& operator=(const Garage&);
	~Garage();

	void addVechicle(const Vehicle&);
	int posibleOrders(double, double, double, double) const;
};
