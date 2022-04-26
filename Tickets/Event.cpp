#include "Event.h"

// �������� ������� 
void Event::copyFrom(const Event& other)
{
	date = other.date;
	hall = other.hall;
	nameSize = other.nameSize;
	name = new char[nameSize + 1];
	strcpy(name, other.name);

	reservedSize = other.reservedSize;
	capacity = other.capacity;
	reservedSeats = new int[capacity];
	for (int i = 0; i < reservedSize; i++)
	{
		reservedSeats[i] = other.reservedSeats[i];
	}
}

// ������������� �� ��������� ���������� �����
void Event::free()
{
	delete[] name;
	delete[] reservedSeats;
}

// ����������� �� ���������� � �������� �� ������� ���������� � ����� �����
void Event::resize()
{
	capacity *= 2;
	int* resizedArr = new int[capacity];
	for (int i = 0; i < reservedSize; i++)
	{
		resizedArr[i] = reservedSeats[i];
	}
	delete[] reservedSeats;
	reservedSeats = resizedArr;
}

// ������� �� ��������
void Event::swap(int& x, int& y)
{
	int temp = x;
	x = y;
	y = temp;
}

// ��������� �� ������������� �����
void Event::selectionSort()
{
	int minInd;
	for (int i = 0; i < reservedSize; i++)
	{
		minInd = i;
		for (int j = i + 1; j < reservedSize; j++)
			if (reservedSeats[j] < reservedSeats[minInd])
				minInd = j;

		swap(reservedSeats[minInd], reservedSeats[i]);
	}

}

// Binary Search 
// �� �������� ����� ��������� ���� �� � ���� ����������� �� ������� 
// ��� ���� � ����������� -> ����� �������, �� ����� �� ������ � ������
// ��� ��� ��� �� � ����������� -> ����� -1 
int Event::findReservation(int seat)
{
	int startInd = 0;
	int endInd = reservedSize - 1;

	while (startInd <= endInd)
	{
		int minInd = startInd + (endInd - startInd) / 2;
		if (reservedSeats[minInd] == seat)
		{
			return minInd;
		}
		else if (reservedSeats[minInd] < seat)
		{
			startInd = minInd + 1;
		}
		else
		{
			endInd = minInd - 1;
		}
	}
	return -1;
}

// ����������� �� ������������
Event::Event()
{
	date = Date();
	char defName[] = "Unknown";
	nameSize = strlen(defName);
	name = new char[nameSize + 1];
	strcpy(name, defName);
	hall = Hall();

	reservedSize = 0;
	capacity = 2;
	reservedSeats = new int[capacity];
}

// ����������� � ���������
Event::Event(Date newDate, const char* newName, Hall newHall)
{
	date = newDate;
	setName(newName);
	hall = newHall;

	reservedSize = 0;
	capacity = 2;
	reservedSeats = new int[capacity];
}

// ������� �����������
Event::Event(const Event& other)
{
	copyFrom(other);
}

// �������� "="
Event& Event::operator=(const Event& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

// ����������
Event::~Event()
{
	free();
}

// ������� �� ���
void Event::setName(const char* newName)
{
	free();
	nameSize = strlen(newName);
	name = new char[nameSize + 1];
	strcpy(name, newName);
}

// ���������
Date Event::getDate() const
{
	return date;
}

char* Event::getName() const
{
	return name;
}

Hall Event::getHall() const
{
	return hall;
}

// ������� �� ��������� �� �������������
void Event::printEvent() const
{
	date.printDate();
	std::cout << name << std::endl;
	hall.printHall();
}

// �������� �� ����������� �����
void Event::addReservation(const Reservation& reservation)
{
	if (reservedSize == capacity)
	{
		resize();
	}
	int seat = ((reservation.getRow() - 1) * reservation.getHall().getSeats()) + reservation.getSeat(); //����������� �� ������ �� ������� 
	reservedSeats[reservedSize++] = seat;
}

// ���������� �� ����������� ����� 
// ��������� ��� ����� ��� ����� ��������� � � ������� ���� ������� ��-����� �� ������ �����
// ��� ���������� �� ������� ���������� � ����� ����� ���������� �������, �� ����� �� � �������� �������, ����� ������ �� ���������
void Event::removeReservation(const Reservation& res)
{
	selectionSort();
	int seat = ((res.getRow() - 1) * res.getHall().getSeats()) + res.getSeat();
	int indexOfReservation = findReservation(seat);

	if (indexOfReservation != -1)
	{
		int* newArr = new int[capacity];
		for (int i = 0; i < indexOfReservation; i++)
		{
			newArr[i] = reservedSeats[i];
		}
		for (int i = indexOfReservation + 1; i < reservedSize; i++)
		{
			newArr[i - 1] = reservedSeats[i];
		}
		reservedSize = reservedSize - 1;
		delete[] reservedSeats;
		reservedSeats = newArr;
	}
}

// ������� �� ��������� �� ������ �� ����������� ����� �� ���������������
void Event::printReservedSeats() const
{
	for (int i = 0; i < reservedSize; i++)
	{
		std::cout << reservedSeats[i] << " ";
	}
}
