#include "Engine.h"

Engine::Engine()
{
	horsepower = 0;
}

Engine::Engine(MyString id, MyString name, MyString description, unsigned short newPower) : CarPart(id,name,description)
{
	horsepower = newPower;
}

unsigned short Engine::getHorsePower() const
{
	return horsepower;
}
