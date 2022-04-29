#ifndef TIMETABLE_H
#define TIMETABLE_H
#include "Hall.h"
#include "Date.h"
#include "Event.h"
#include "Reservation.h"

// Клас Разписание
class TimeTable
{
private:

	// Масив от събития(представления) с произволна дължина
	Event* list;
	// Дължина на мсива от събития
	int size;
	// Капацитет на масива от събития
	int capacity;

	// Копираща функция
	void copyFrom(const TimeTable&);
	// Освобождаване на динамично заделената памет
	void free();
	// Функция, която ще променя капацитета на масива от събития ( при нужда )
	void resize();

public:

	// Конструктори
	TimeTable();
	TimeTable(const Event*, int);
	TimeTable(const TimeTable&);
	// Оператор за присвояване
	TimeTable& operator=(const TimeTable&);
	// Деструктор
	~TimeTable();

	// Мутатор
	void setList(const Event*, int);
	// Функция за извеждане на разписание
	void printTimeTable() const;

	// Добавяне на събитие
	void addEvent(const Event&);
	// Свободни места в залата за представление ( по подадена дата и име на представлението ) 
	int freeSeats(const Date&, const char*);
	// Запазване на билет за представление ( по подадена дата, име на представлението и данни за резервация )
	void saveTicket(const Date&, const char*, Reservation&);
	// Отмяна на резервация ( по подадена дата, име на представлението и данни за резервация)
	void removeSavedTicket(const Date&, const char*, Reservation&);
	// Закупуване на билет за представление
	void buyTicket(const Date&, const char*, Reservation&);
};
#endif
