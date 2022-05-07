#include <iostream>
#ifndef HALL_H
#define HALL_H
#pragma warning (disable: 4996)

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
	// Допълнителна член променлива, за да можем да подаваме зала и чрез "ALL"
	char hall[1024];

	// Допълнителна член-променлива за общия брой места в залата
	int allSeats;

public:

	// Конструктори
	Hall();
	Hall(int, int, int);
	Hall(const char*);

	// Мутатори
	void setNumber(int);
	void setRows(int);
	void setSeats(int);

	// Селектори
	int getNumber() const;
	int getRows() const;
	int getSeats() const;
	int getAllSeats() const;

	// Функция, която проверява дали залата е зададена чрез "ALL"
	bool allHalls() const;
	// Функция за извеждане
	void printHall() const;
};


#endif // !HALL_H
