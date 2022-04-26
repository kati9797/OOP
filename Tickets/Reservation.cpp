#include "Reservation.h"

// Копираща функция
void Reservation::copyFrom(const Reservation& other)
{
	hall = other.hall;
	row = other.row;
	seat = other.seat;
	sizePass = other.sizePass;
	password = new char[sizePass + 1];
	strcpy(password, other.password);
	strcpy(note, other.note);
}

// Освобождаване на динамично заделената памет
void Reservation::free()
{
	delete[] password;
}

// Конструктор по подразбиране
Reservation::Reservation()
{
	hall = Hall();
	row = 0;
	seat = 0;
	password = nullptr;
	sizePass = 0;
	strcpy(note, "\0");
}

// Конструктор с параметри
Reservation::Reservation(int newRow, int newSeat, const char* pass)
{
	hall = Hall();
	row = newRow;
	seat = newSeat;
	setPass(pass);
}

//Копиращ конструктор
Reservation::Reservation(const Reservation& other)
{
	copyFrom(other);
}

//Оператор "="
Reservation& Reservation::operator=(const Reservation& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

// Деструктор
Reservation::~Reservation()
{
	free();
}

// Мутатори
void Reservation::setPass(const char* pass)
{
	if (password != nullptr)
	{
		free();
	}
	sizePass = strlen(pass);
	password = new char[sizePass + 1];
	strcpy(password, pass);
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
char* Reservation::getPass() const
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
	std::cout << row << " " << seat << " " << password << " " << note;
}
