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
			std::cout << "Error!"<<std::endl;
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
		if (list[i].getDate() == date && strcmp(list[i].getName(),name) == 0)
		{
			return list[i].getHall().getFreeSeats();
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
	}
}
