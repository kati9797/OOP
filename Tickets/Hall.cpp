#include "Hall.h"

// Конструктор по подразбиране 

Hall::Hall()
{
	number = 0;
	rows = 0;
	seats = 0;
	strcpy(hall, "\0");

	allSeats = 0;
}

// Конструктор с параметри

Hall::Hall(int num, int rows, int seats)
{
	setNumber(num);
	setRows(rows);
	setSeats(seats);
	strcpy(hall, "\0");

	allSeats = rows * seats;
}

// Конструктор с параметър char*
// Променяме допълнителната член-данна hall само ако като параметър се подаде "ALL"

Hall::Hall(const char* newHall)
{
	number = 0;
	rows = 0;
	seats = 0;
	allSeats = 0;
	strcpy(hall, "\0");

	if (strcmp(newHall, "ALL") == 0)
		strcpy(hall, newHall);
}

// Мутатори

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

// Селектори

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

// Функция, която проверява дали залата е зададена чрез "ALL"

bool Hall::allHalls() const
{
	return (strcmp(hall, "ALL") == 0);
}

// Функция за извеждане

void Hall::printHall() const
{
	std::cout << "Number: " << number << ", Rows: " << rows << ", Seats: " << seats << std::endl;
}
