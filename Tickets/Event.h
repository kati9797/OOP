#ifndef EVENT_H
#define EVENT_H
#include "Hall.h"
#include "Date.h"
#include "Reservation.h"
#pragma warning ( disable : 4996 )

// Клас Събитие
class Event
{
private:

	// Дата
	Date date;
	// Име на представление
	char* name;
	// Допълнителна променлива за дължината на името ( понеже то е с произволна дължина )
	int nameSize; 
	// Зала
	Hall hall;
	
	// Масив от резервираните места за представлението
	int* reservedSeats;
	// Дължина на масива от резервирани места
	int reservedSize;
	// Капацитет на масива от резервирани места ( понеже ще се наложи да добавяме/да премахваме елементи от масива )
	int capacity;
	// Функция, която ще променя капацитета на масива от резервирани места ( при нужда )
	void resize();

	// Функция за копиране на информация от друго представление 
	void copyFrom(const Event&);
	// Освобождаване на динамично заделената памет
	void free();

	// Функция за размяна на елементи ( при сортирането )
	void swap(int&,int&);
	// Сортиране на масива от резервирани места
	void selectionSort();
	// Функция, която проверява дали дадено място е вече резервирано ( ако е резервирано, връща индекса, на който се намира ) 
	int findReservation(int);

public:

	// Конструктори
	Event();
	Event(Date,const char*, Hall);
	Event(const Event&);
	// Оператор за присвояване 
	Event& operator=(const Event&);
	// Деструктор
	~Event();

	// Мутатор за името на представлението
	void setName(const char*);
	// Селектори
	Date getDate() const;
	char* getName() const;
	Hall getHall() const;
	// Функция за извеждане на представление
	void printEvent() const;

	// Добавяне на резервирано място в масива от резервирани места
	void addReservation(const Reservation&);
	// Премахване на резервирано място от масива от резервирани места
	void removeReservation(const Reservation&);
	// Помощна функция, която извежда масива от резервирани места
	void printReservedSeats() const;
};
#endif // !HALL_H
