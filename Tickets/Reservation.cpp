#include "Reservation.h"

// Конструктор по подразбиране

Reservation::Reservation()
{
	hall = Hall();
	row = 0;
	seat = 0;
	password = "Unknown";
}

// Конструктор с параметри

Reservation::Reservation(int newRow, int newSeat, const MyString& pass)
{
	hall = Hall();
	row = newRow;
	seat = newSeat;
	setPass(pass);
}

// Конструктор с два параметъра ( ред и място )
// Резервация, която ще бъде закупена

Reservation::Reservation(int newRow, int newSeat)
{
	hall = Hall();
	row = newRow;
	seat = newSeat;
	password = "No password";
}

// Мутатори

void Reservation::setPass(const MyString& pass)
{
	password = pass;
}

void Reservation::setNote(const MyString& newNote)
{
	note = newNote;
}

void Reservation::setHall(const Hall& newHall)
{
	hall = newHall;
}

// Селектори

const MyString& Reservation::getPass() const
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

const MyString& Reservation::getNote() const
{
	return note;
}

const Hall& Reservation::getHall() const
{
	return hall;
}

// Функция за извеждане на резервация

void Reservation::printReservation() const
{
	std::cout << row << " " << seat << " " << password << std::endl;
}
