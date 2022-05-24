#pragma once
#include "Vehicle.h"
#include "Vector.hpp"
#include "Car.h"
#include "Minivan.h"
#include "Truck.h"

class Garage
{
private:
	Vector<Car> cars;
	Vector<Minivan> minivans;
	Vector<Truck> trucks;

	static unsigned size;
	unsigned capacity;
public:
	Garage();
	Garage(unsigned);
	const Vector<Car>& getCars() const;
	const Vector<Minivan>& getVans() const;
	const Vector<Truck>& getTrucks() const;

	void pushCarInGarage(const Car&);
	void pushMinivanInGarage(const Minivan&);
	void pushTruckInGarage(const Truck&);
	int posibleOrders(double, double, double, double) const;
};
