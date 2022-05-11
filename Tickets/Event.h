#ifndef EVENT_H
#define EVENT_H
#include "Hall.h"
#include "Date.h"
#include "Reservation.h"
#pragma warning ( disable : 4996 )
#include <fstream>

// Клас Събитие
class Event
{
private:

	// Дата
	Date date;
	// Име на представление
	MyString name;
	// Зала
	Hall hall;

	// Масив от резервираните места за представлението
	int* reservedSeats;
	// Масив от пароли за резервираните места
	MyString* reservedPass;
	// Дължина на масива от резервирани места ( дължина на мсива от пароли )
	int reservedSize;
	// Капацитет на масива от резервирани места ( понеже ще се наложи да добавяме/да премахваме елементи от масива )
	int capacity;
	// Функция, която ще променя капацитета на масива от резервирани места ( при нужда )
	void resize();

	// Функция за размяна на елементи ( при сортирането )
	void swap(int&, int&);
	// Функция за размяна на пароли
	void swapPass(MyString&, MyString&);
	// Сортиране на масива от резервирани места
	void selectionSort();
	// Функция, която проверява дали дадено място е вече резервирано ( ако е резервирано, връща индекса, на който се намира ) 
	int findReservation(int);

	// Масив от продадени места
	int* purchasedSeats;
	// Дължина на масив от продадени места
	int purchasedSize;
	// Капацитет на масив от продадени места
	int purchasedCapacity;
	// Функция, която ще променя капацитета на масива от продадени места ( при нужда )
	void resizePurchased();
	// Сортираща функция за масива от продадени места
	void selectionSortPurch();
	// Функция, която проверява дали дадено място е вече продадено
	bool binarySearchPurch(int);	
	
	// Функция за копиране на информация от друго представление 
	void copyFrom(const Event&);
	// Освобождаване на динамично заделената памет
	void free();

public:

	// Конструктори
	Event();
	Event(const Date&, const MyString&, const Hall&);
	Event(const Event&);
	// Оператор за присвояване 
	Event& operator=(const Event&);
	// Деструктор
	~Event();

	// Мутатор за името на представлението
	void setName(const MyString&);
	// Селектори
	const Date& getDate() const;
	const MyString& getName() const;
	const Hall& getHall() const;
	int getPurchasedSize() const;
	// Функция за извеждане на представление
	void printEvent() const;

	// Добавяне на резервирано място в масива от резервирани места
	void addReservation(const Reservation&);
	// Премахване на резервирано място от масива от резервирани места
	void removeReservation(const Reservation&);
	// Добавя ново продадено място към масива от продадени места
	void pushInPurchasedArr(int);
	// Проверява дали продаждабата на дадено място може да се осъществи ( ако е възможно -> покупката се осъществява )
	void addPurchase(Reservation&);
	// Брой свободни места за събитие
	int freeSeatsForEvent() const;
	// Отпечатва резервираните места (файл)
	void printReportReserved(std::ofstream&) const;
	// Отпечатва резервирани места (конзола)
	void printReportReservedConsole() const;
	// Отпечатва закупените места (файл)
	void printPurchasedSeats(std::ofstream&) const;
};
#endif 
