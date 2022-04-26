#ifndef RESERVATION_H
#define RESERVATION_H
#include <iostream>
#include "Hall.h"
#pragma warning ( disable : 4996 )

// Клас Резервация
class Reservation
{
private:

	// Зала ( за достъп до броя на редовете и броя местата на ред в залата )
	Hall hall;
	// Ред за резервация
	int row;
	// Място от указания ред за резервация
	int seat;
	// Парола за резервация ( с произволна дължина )
	char* password;
	// Дължина на паролата
	int sizePass;
	// Бележка към резервацията 
	char note[1024];

	// Копираща функция от друга резервация
	void copyFrom(const Reservation&);
	// Освобождаване на динамично заделената памет
	void free();

public:

	// Конструктори
	Reservation();
	Reservation(int, int, const char*);
	Reservation(const Reservation&);
	// Оператор за присвояване
	Reservation& operator=(const Reservation&);
	// Деструктор
	~Reservation();

	// Мутатори
	void setPass(const char*);
	void setNote(char*);
	void setHall(const Hall&);
	// Селектори
	char* getPass() const;
	int getRow() const;
	int getSeat() const;
	Hall getHall() const;
	// Функция за извеждане на резервация
	void printReservation() const;
};

#endif
