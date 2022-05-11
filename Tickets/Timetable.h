ifndef TIMETABLE_H
#define TIMETABLE_H
#include "Event.h"

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
	int freeSeats(const Date&, const MyString&) const;
	// Запазване на билет за представление ( по подадена дата, име на представлението и данни за резервация )
	void saveTicket(const Date&, const MyString&, Reservation&);
	// Отмяна на резервация ( по подадена дата, име на представлението и данни за резервация)
	void removeSavedTicket(const Date&, const MyString&, const Reservation&);
	// Закупуване на билет за представление
	void buyTicket(const Date&, const MyString&, Reservation&);
	// Справка за запазените, но неплатени места
	void reportReservedTickets(const Date&, const MyString&, const char*) const;
	// Справка за закупени места в даден период за определена зала ( извеждат се представленията и броя закупени места )
	void reportPurchasedTickets(const Date&, const Date&, const Hall&) const;
	// Записва информацията за представленията в текстов файл
	void saveToFile(const char*) const;
		
};
