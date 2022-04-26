#include "Hall.h"

// ����������� �� ������������ 

Hall::Hall()
{
	number = 0;
	rows = 0;
	seats = 0;

	allSeats = 0;
	freeSeats = 0;
}

// ����������� � ���������

Hall::Hall(int num, int rows, int seats)
{
	setNumber(num);
	setRows(rows);
	setSeats(seats);

	allSeats = rows * seats;
	freeSeats = allSeats;
}

// ��������

void Hall::setNumber(int num)
{
	if (num < 0)
	{
		number = 0;
	}
	else
	{
		number = num;
	}
}

void Hall::setRows(int rows)
{
	if (rows < 0)
	{
		this->rows = 0;
	}
	else 
	{
		this->rows = rows;
	}
}

void Hall::setSeats(int seats)
{
	if (seats < 0)
	{
		this->seats = 0;
	}
	else
	{
		this->seats = seats;
	}
}

// ���������

int Hall::getNumber() const
{
	return number;
}

int Hall::getRows() const
{
	return rows;
}

int Hall::getSeats() const
{
	return seats;
}

int Hall::getAllSeats() const
{
	return allSeats;
}

int Hall::getFreeSeats() const
{
	return freeSeats;
}

// ������� �� ���������

void Hall::printHall() const
{
	std::cout << "Number: " << number << ", Rows: " << rows << ", Seats: " << seats << std::endl;
}


