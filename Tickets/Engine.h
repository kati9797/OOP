#pragma once
#include "TimeTable.h"

const char file[] = "tickets_file.txt";
const char report[] = "report.txt"; // не е реализирано името, което се изисква 

// Клас, който ще използваме за тестване на програмата 

class Engine
{
private:

	TimeTable list;

	// Добавяне на събитие
	void addInList(const Hall&);
	// Резервация
	void save();
	// Премахване на резервация
	void remove();
	// Продажба на билет
	void buy();
	// Свободни места
	void free();
	// Справка за резервираните места
	void makeReportReservedTickets();
	// Справка за продадените билети
	void makeReportPurchasedTickets(const Hall&);
public:

	Engine();
	void run();
};
