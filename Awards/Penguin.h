#pragma once
#include "Award.h"

class Penguin : public Award
{
public:
	Penguin(size_t);
	void visualize() const;
};
