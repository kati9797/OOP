#include <iostream>
#ifndef HALL_H
#define HALL_H

// Клас Зала
class Hall
{
private:

	// Номер на зала
	int number;
	//Брой редове в залата
	int rows;
	// Брой места на един ред
	int seats;
	
	// Допълнителна член-променлива за общия брой места в залата
	int allSeats;
	// Допълнителна член-променлива за свобободните места в залата
	int freeSeats;

public:

	// Конструктори
	Hall();
	Hall(int, int, int);

	// Мутатори
	void setNumber(int);
	void setRows(int);
	void setSeats(int);

	// Селектори
	int getNumber() const;
	int getRows() const;
	int getSeats() const;
	int getAllSeats() const;
	int getFreeSeats() const;

	// Функция за извеждане
	void printHall() const;
};
