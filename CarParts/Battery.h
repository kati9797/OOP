#pragma once
#include "CarPart.h"

class Battery : public CarPart
{
private:
	unsigned short amperHours;
	MyString batteryId;
public:
	Battery();
	Battery(MyString, MyString, MyString, unsigned short, MyString);

	unsigned short getAmperHours() const;
	const MyString& getBatteryId() const;
};
