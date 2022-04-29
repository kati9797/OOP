#include "Reservation.h"

// Конструктор по подразбиране

Reservation::Reservation()
{
	hall = Hall();
	row = 0;
	seat = 0;
	password = MyString();
}

// Конструктор с параметри

Reservation::Reservation(int newRow, int newSeat, const MyString pass)
{
	hall = Hall();
	row = newRow;
	seat = newSeat;
	setPass(pass);
}

// Мутатори

void Reservation::setPass(const MyString& pass)
{
	password = pass;
}

void Reservation::setNote(char* newNote)
{
	strcpy(note, newNote);
}

void Reservation::setHall(const Hall& newHall)
{
	hall = newHall;
}

// Селектори

MyString Reservation::getPass() const
{
	return password;
}

int Reservation::getRow() const
{
	return row;
}

int Reservation::getSeat() const
{
	return seat;
}

Hall Reservation::getHall() const
{
	return hall;
}

// Функция за извеждане на резервация

void Reservation::printReservation() const
{
	std::cout << row << " " << seat << " " << password.getString() << std::endl;
}
