#include "Timetable.h"

// Копираща функция

void TimeTable::copyFrom(const TimeTable& other)
{
	size = other.size;
	capacity = other.capacity;
	list = new Event[capacity];
	for (int i = 0; i < size; i++)
	{
		list[i] = other.list[i];
	}
}

// Освобождаване на динамично заделената памет

void TimeTable::free()
{
	delete[] list;
}

// Увелечаване на капацитета и копиране на старата информация в новия масив

void TimeTable::resize()
{
	capacity *= 2;
	Event* resizedList = new Event[capacity];
	for (int i = 0; i < size; i++)
	{
		resizedList[i] = list[i];
	}
	free();
	list = resizedList;
}

// Конструктор по подразбиране

TimeTable::TimeTable()
{
	size = 0;
	capacity = 2;
	list = new Event[capacity];
}

// Конструктор с параметри

TimeTable::TimeTable(const Event* newList, int newSize)
{
	setList(newList, newSize);
}

// Копиращ конструктор

TimeTable::TimeTable(const TimeTable& other)
{
	copyFrom(other);
}

// Оператор "="

TimeTable& TimeTable::operator=(const TimeTable& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

// Деструктор

TimeTable::~TimeTable()
{
	free();
}

// Мутатор

void TimeTable::setList(const Event* newList, int newSize)
{
	free();
	size = newSize;
	capacity = size * 2;
	list = new Event[capacity];
	for (int i = 0; i < size; i++)
	{
		list[i] = newList[i];
	}
}

// Функция за извеждане на разписание

void TimeTable::printTimeTable() const
{
	for (int i = 0; i < size; i++)
	{
		list[i].printEvent();
	}
}

// Добавяне на събитие
// Проверяваме дали вече има събитие на същата дата и в същата зала
// Ако открием съвпадение -> извеждаме съобщение за грешка, в противен случай -> добавяме събитието

void TimeTable::addEvent(const Event& ev)
{
	bool foundSameDate = false;
	for (int i = 0; i < size; i++)
	{
		if ((list[i].getDate() == ev.getDate()) && (list[i].getHall().getNumber() == ev.getHall().getNumber()))
		{
			foundSameDate = true;
			std::cout << "Error!" << std::endl;
		}
	}

	if (!foundSameDate)
	{
		if (capacity == size)
		{
			resize();
		}
		list[size++] = ev;
	}
}

// Функция, която връща броя на свободните места за дадено представление ( по подадена дата и име на представлението )
// Ако не е намерено такова представление в разписанието -> връща, че няма свободни места

int TimeTable::freeSeats(const Date& date, const char* name)
{

	for (int i = 0; i < size; i++)
	{
		if (list[i].getDate() == date && strcmp(list[i].getName(), name) == 0)
		{
			return list[i].freeSeatsForEvent();
		}
	}
	return 0;
}

// Запазване на билет за представление по подадени дата, име на представление и данни за резервацията
// Ако в разписанито не е намерено такова представление, не правим нищо

void TimeTable::saveTicket(const Date& date, const char* name, Reservation& res)
{
	for (int i = 0; i < size; i++)
	{
		if (list[i].getDate() == date && strcmp(list[i].getName(), name) == 0)
		{
			res.setHall(list[i].getHall());
			list[i].addReservation(res);
		}
		//list[i].printReservedSeats();
	}
}

// Отмяна на резервация за представление по подадени дата, име на представление и данни за резервацията
// Ако в разписанито не е намерено такова представление, не правим нищо

void TimeTable::removeSavedTicket(const Date& date, const char* name, Reservation& res)
{
	for (int i = 0; i < size; i++)
	{
		if (list[i].getDate() == date && strcmp(list[i].getName(), name) == 0)
		{
			list[i].removeReservation(res);
		}
		//list[i].printReservedSeats();
	}
}

// Закупуване на билет за представление

void TimeTable::buyTicket(const Date& date, const char* name, Reservation& res)
{
	bool foundEvent = false;
	for (int i = 0; i < size; i++)
	{
		if (list[i].getDate() == date && strcmp(list[i].getName(), name) == 0) // събитието е намерено
		{
			res.setHall(list[i].getHall());
			list[i].addPurchase(res);
			foundEvent = true;
		}
	}

	if (!foundEvent)
	{
		std::cout << "This event was not found!" << std::endl;
	}
}

// Справка за запазените, но неплатени места

void TimeTable::reportReservedTickets(const Date& date, const char* name, const char* fileName)
{
	std::ofstream stream(fileName, std::ios::out | std::ios::trunc);
	if (!stream.is_open())
	{
		std::cout << "Error!" << std::endl;
	}

	if (date.allDates()) // представления на всички дати
	{
		for (int i = 0; i < size; i++)
		{
			std::cout << "Reserved seats for event " << '"' << list[i].getName() << '"' << " on date ";
			list[i].getDate().printDate();
			stream<< "Reserved seats for event " << '"' << list[i].getName() << '"' << " on date " << list[i].getDate().getDay() << '.' << list[i].getDate().getMonth() << '.' << list[i].getDate().getYear()<<std::endl; // file
			list[i].printReportReservedConsole();
			list[i].printReportReserved(stream); // file
		}
	}
	else if ((!date.allDates()) && name == "ALL") // всички представления на конкретна дата
	{
		std::cout<< "Events on date: ";
		date.printDate();
		stream << "Events on date " << date.getDay() << '.' << date.getMonth() << '.' << date.getYear() << std::endl; // file
		for (int i = 0; i < size; i++)
		{
			if (list[i].getDate() == date)
			{
				std::cout << "Reserved seats for event " << '"'<< list[i].getName() << '"' << ":" << std::endl;
				list[i].printReportReservedConsole();
				stream << "Reserved seats for event " << '"' << list[i].getName() << '"' << ":" << std::endl; // file
				list[i].printReportReserved(stream); // file
			}
		}
	}
	else // представление с конкретно име и дата 
	{
		bool foundEvent = false;
		for (int i = 0; i < size; i++)
		{
			if (list[i].getDate() == date && strcmp(list[i].getName(), name) == 0)
			{
				foundEvent = true;
				std::cout << "Reserved seats for event " << '"' << name << '"' << " on date:"; 
				date.printDate();
				list[i].printReportReservedConsole();
				stream<< "Reserved seats for event " << '"' << name << '"' << " on date "<< list[i].getDate().getDay() << '.' << list[i].getDate().getMonth() << '.' << list[i].getDate().getYear() << std::endl; // file
				list[i].printReportReserved(stream); // file
			}
		}

		if (!foundEvent)
		{
			std::cout << "The event was not found!" << std::endl;
			stream << "The event was not found!" << std::endl; // file
		}
	}

	stream.close();
}

// Справка за закупени места в даден период за определена зала ( извеждат се представленията и броя закупени места )

void TimeTable::reportPurchasedTickets(const Date& firstDate, const Date& secondDate, const Hall& hall)
{
	for (int i = 0; i < size; i++)
	{
		if (hall.allHalls() && list[i].getDate().isBetweenDates(firstDate, secondDate))
		{
			std::cout << "Purchased seats for event " << '"' << list[i].getName() << '"' << ": " << list[i].getPurchasedSize() << std::endl;
		}
		if (list[i].getHall().getNumber() == hall.getNumber() && list[i].getDate().isBetweenDates(firstDate, secondDate))
		{
			std::cout << "Purchased seats for event " << '"' << list[i].getName() << '"' << "in hall number "<< hall.getNumber()<< ": " << list[i].getPurchasedSize()<<std::endl;
		}
	}
}

