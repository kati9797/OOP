#pragma once
#include <iostream> 

class Vehicle
{
private:
	char* brand;
	int speed;

	void copyFrom(const Vehicle&);
	void free();
public:
	Vehicle();
	Vehicle(const char*);
	Vehicle(const Vehicle&);
	Vehicle& operator=(const Vehicle&);
	virtual ~Vehicle();

	const char* getBrand() const;
	virtual Vehicle* clone() const = 0;  // copy object
	virtual int getSpeed() const = 0;
	virtual int getMaxSpeed() const = 0;
	virtual void print() const = 0;
};
