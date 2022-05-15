#include "Engine.h"

void Engine::addInList(const Hall& hall)
{
	// Подава се дата и име на представлението

	std::cout << "Adding new event" << std::endl;
 	int day, month, year;
	std::cout << "Enter date: (day-month-year)" << std::endl;
	std::cin >> day;
	std::cin >> month;
	std::cin >> year;
	Date date(day, month, year);

	MyString name;
	std::cout << "Enter name of event: ";
	std::cin >> name;
		
	Event event(date, name, hall);
	list.addEvent(event);
}

void Engine::save()
{
	// Подава се дата, име и резервация чрез ред, място и парола

	std::cout << "Make a reservation on date: (day-month-year)" << std::endl;
	int day, month, year;
	std::cin >> day;
	std::cin >> month;
	std::cin >> year;
	Date date(day, month, year);

	MyString name;
	std::cout << "Enter name of event: ";
	std::cin >> name;

	int row, seat;
	MyString pass;
	std::cout << "Reservation for row: ";
	std::cin >> row;
	std::cout << "Reservation for seat: ";
	std::cin >> seat;
	std::cout << "Enter password for reservation: ";
	std::cin >> pass;
	Reservation res(row, seat, pass);

	list.saveTicket(date, name, res);
}

void Engine::remove()
{
	// Подава се дата, име и резервация чрез ред и място

	std::cout << "Remove a reservation on date: (day-month-year)" << std::endl;
	int day, month, year;
	std::cin >> day;
	std::cin >> month;
	std::cin >> year;
	Date date(day, month, year);

	MyString name;
	std::cout << "Enter name of event: ";
	std::cin >> name;

	int row, seat;
	MyString pass;
	std::cout << "Remove reservation for row: ";
	std::cin >> row;
	std::cout << "Remove reservation for seat: ";
	std::cin >> seat;
	Reservation res(row, seat);

	list.removeSavedTicket(date, name, res);
}

void Engine::buy()
{
	// Подава се дата, име и резервация чрез ред и място (и парола, ако е нужно)

	std::cout << "Buy a reservation on date: (day-month-year)" << std::endl;
	int day, month, year;
	std::cin >> day;
	std::cin >> month;
	std::cin >> year;
	Date date(day, month, year);

	MyString name;
	std::cout << "Enter name of event: ";
	std::cin >> name;

	int row, seat;
	MyString pass;
	std::cout << "Buy reservation for row: ";
	std::cin >> row;
	std::cout << "Buy reservation for seat: ";
	std::cin >> seat;
	Reservation res(row, seat);

	list.buyTicket(date, name, res);
}

void Engine::free()
{
	// Подава се дата и име

	std::cout << "Free seats on date: (day-month-year)" << std::endl;
	int day, month, year;
	std::cin >> day;
	std::cin >> month;
	std::cin >> year;
	Date date(day, month, year);

	MyString name;
	std::cout << "Enter name of event: ";
	std::cin >> name;

	list.freeSeats(date,name);
}

void Engine::makeReportReservedTickets()
{
	// Подава се дата и име

	std::cout << "Making a report for reserved seats" << std::endl;
	std::cout << "Event on date: (day-month-year)" << std::endl;
	int day, month, year;
	std::cin >> day;
	std::cin >> month;
	std::cin >> year;
	Date date(day, month, year);

	//char allDates[1024];
	//std::cin >> allDates;
	//Date date(allDates);

	MyString name;
	std::cout << "Enter name of event: ";
	std::cin >> name;

	list.reportReservedTickets(date, name, report);
}

void Engine::makeReportPurchasedTickets(const Hall& hall)
{
	// Подават се две дати (пъравата е преди втората)

	std::cout << "Making a report for purchased seats in period of time: " << std::endl;
	std::cout << "From date: (day-month-year)" << std::endl;
	int day, month, year;
	std::cin >> day;
	std::cin >> month;
	std::cin >> year;
	Date firstDate(day, month, year);
	std::cout << "To date: (day-month-year)" << std::endl;
	std::cin >> day;
	std::cin >> month;
	std::cin >> year;
	Date secondDate(day, month, year);

	list.reportPurchasedTickets(firstDate, secondDate, hall);
}

Engine::Engine()
{
	list = TimeTable();
}

void Engine::run()
{
	// Залите са предварително зададени
    	// номер - редове - места (на ред)
	Hall h1(8, 12, 7);
	Hall h2(6, 11, 9);
	Hall h3(9, 10, 15);

	addInList(h1);
	addInList(h1);
	addInList(h2);
	addInList(h3);
	save();
	save();
	remove();
	buy();
	makeReportReservedTickets();
	makeReportPurchasedTickets(h2);
	list.saveToFile(file);
}
