#include "Penguin.h"

Penguin::Penguin(size_t prise) : Award(prise,50)
{}

void Penguin::visualize() const
{
	std::ifstream stream("penguin.txt");

	if (!stream.is_open())
	{
		std::cout << "Error!" << std::endl;
		return;
	}

	while (!stream.eof())
	{
		char buff[1024];
		stream.getline(buff, 1024);
		std::cout << buff << std::endl;
	}
	stream.close();
}
