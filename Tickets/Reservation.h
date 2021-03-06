#ifndef RESERVATION_H
#define RESERVATION_H
#include <iostream>
#include "Hall.h"
#include "MyString.h"
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
	// Парола за резервация 
	MyString password;
	// Бележка към резервацията 
	MyString note;

public:

	// Конструктори
	Reservation();
	Reservation(int, int, const MyString&);
	Reservation(int, int);

	// Мутатори
	void setPass(const MyString&);
	void setNote(const MyString&);
	void setHall(const Hall&);

	// Селектори
	const MyString& getPass() const;
	int getRow() const;
	int getSeat() const;
	const MyString& getNote() const;
	const Hall& getHall() const;

	// Функция за извеждане на резервация
	void printReservation() const;
};

#endif
