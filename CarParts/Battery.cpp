#include "Battery.h"

Battery::Battery()
{
	amperHours = 0;
	batteryId = "Unknown";
}

Battery::Battery(MyString id, MyString name, MyString description, unsigned short newAmperHours, MyString newBatteryId) : CarPart(id, name, description)
{
	amperHours = newAmperHours;
	batteryId = newBatteryId;
}

unsigned short Battery::getAmperHours() const
{
	return amperHours;
}

const MyString& Battery::getBatteryId() const
{
	return batteryId;
}
