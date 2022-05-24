#pragma once
#include <iostream> 

class Vehicle
{
private:
	char* brand;

	void copyFrom(const Vehicle&);
	void free();
public:
	Vehicle();
	Vehicle(const char*);
	Vehicle(const Vehicle&);
	Vehicle& operator=(const Vehicle&);
	virtual ~Vehicle();

	const char* getBrand() const;
	virtual void print() const = 0;
};
