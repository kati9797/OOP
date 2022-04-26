#include "Timetable.h"

// �������� �������
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

// ������������� �� ��������� ���������� �����
void TimeTable::free()
{
	delete[] list;
}

// ����������� �� ���������� � �������� �� ������� ���������� � ����� �����
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

// ����������� �� ������������
TimeTable::TimeTable()
{
	size = 0;
	capacity = 2;
	list = new Event[capacity];
}

// ����������� � ���������
TimeTable::TimeTable(const Event* newList, int newSize)
{
	setList(newList, newSize);
}

// ������� �����������
TimeTable::TimeTable(const TimeTable& other)
{
	copyFrom(other);
}

// �������� "="
TimeTable& TimeTable::operator=(const TimeTable& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

// ����������
TimeTable::~TimeTable()
{
	free();
}

// �������
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

// ������� �� ��������� �� ����������
void TimeTable::printTimeTable() const
{
	for (int i = 0; i < size; i++)
	{
		list[i].printEvent();
	}
}

// �������� �� �������
// ����������� ���� ���� ��� ������� �� ������ ���� � � ������ ����
// ��� ������� ���������� -> ��������� ��������� �� ������, � �������� ������ -> �������� ���������
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

// �������, ����� ����� ���� �� ���������� ����� �� ������ ������������� ( �� �������� ���� � ��� �� ��������������� )
// ��� �� � �������� ������ ������������� � ������������ -> �����, �� ���� �������� �����
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

// ��������� �� ����� �� ������������� �� �������� ����, ��� �� ������������� � ����� �� ������������
// ��� � ����������� �� � �������� ������ �������������, �� ������ ����
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

// ������ �� ���������� �� ������������� �� �������� ����, ��� �� ������������� � ����� �� ������������
// ��� � ����������� �� � �������� ������ �������������, �� ������ ����
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
