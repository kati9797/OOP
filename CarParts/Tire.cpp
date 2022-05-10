#include "Tire.h"

Tire::Tire()
{
	width = 0;
	profile = 0;
	diameter = 0;
}

Tire::Tire(MyString id, MyString name, MyString description, unsigned short newWidth, unsigned short newProfile, unsigned short newDiameter) : CarPart(id,name,description)
{
	width = newWidth;
	profile = newProfile;
	diameter = newDiameter;
}

unsigned short Tire::getWidth() const
{
	return width;
}

unsigned short Tire::getProfile() const
{
	return profile;
}

unsigned short Tire::getDiameter() const
{
	return diameter;
}
