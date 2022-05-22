#pragma once
#include <iostream>
#include <fstream>

class Award
{
private:
	size_t prise;
	size_t points;

public:
	Award();
	Award(size_t, size_t);
	virtual void visualize() const = 0;
};
