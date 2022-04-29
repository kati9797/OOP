#include "Event.h"

// Копираща функция 

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
	reservedPass = new MyString[capacity];
	for (int i = 0; i < reservedSize; i++)
	{
		reservedSeats[i] = other.reservedSeats[i];
		reservedPass[i] = other.reservedPass[i];
	}
}

// Освобождаване на динамично заделената памет

void Event::free()
{
	delete[] name;
	delete[] reservedSeats;
	delete[] reservedPass;
}

// Увелечаване на капацитета и копиране на старата информация в новия масив

void Event::resize()
{
	capacity *= 2;
	int* resizedArr = new int[capacity];
	MyString* resizedPass = new MyString[capacity];
	for (int i = 0; i < reservedSize; i++)
	{
		resizedArr[i] = reservedSeats[i];
		resizedPass[i] = reservedPass[i];
	}
	delete[] reservedSeats;
	delete[] reservedPass;
	reservedSeats = resizedArr;
	reservedPass = resizedPass;
}

// Размяна на елементи от тип int

void Event::swap(int& x, int& y)
{
	int temp = x;
	x = y;
	y = temp;
}

// Размяна на елементи от тип MyString

void Event::swapPass(MyString& pass1, MyString& pass2)
{
	MyString temp = pass1;
	pass1 = pass2;
	pass2 = temp;
}

// Сортиране на резервираните места
// Когато разменяме местата при сортирането трябва да разменим и съответните им пароли 

void Event::selectionSort()
{
	int minInd;
	for (int i = 0; i < reservedSize; i++)
	{
		minInd = i;
		for (int j = i + 1; j < reservedSize; j++)
			if (reservedSeats[j] < reservedSeats[minInd])
				minInd = j;

		if (minInd != i) 
		{
			swap(reservedSeats[minInd], reservedSeats[i]);
			swapPass(reservedPass[minInd], reservedPass[i]);
		}
		
	}

}

// Binary Search 
// По подадено място проверява дали то е било резервирано до момента 
// Ако вече е резервирано -> връща индекса, на който се намира в масива
// Ако все още не е резервирано -> връща -1 

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

// Конструктор по подразбиране

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
	reservedPass = new MyString[capacity];
}

// Конструктор с параметри

Event::Event(Date newDate, const char* newName, Hall newHall)
{
	date = newDate;
	setName(newName);
	hall = newHall;

	reservedSize = 0;
	capacity = 2;
	reservedSeats = new int[capacity];
	reservedPass = new MyString[capacity];
}

// Копиращ конструктор

Event::Event(const Event& other)
{
	copyFrom(other);
}

// Оператор "="

Event& Event::operator=(const Event& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

// Деструктор

Event::~Event()
{
	free();
}

// Мутатор за име

void Event::setName(const char* newName)
{
	free();
	nameSize = strlen(newName);
	name = new char[nameSize + 1];
	strcpy(name, newName);
}

// Селектори

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

// Функция за извеждане на представление

void Event::printEvent() const
{
	date.printDate();
	std::cout << name << std::endl;
	hall.printHall();
}

// Добавяне на резервирано място
// Добавяме и паролата за даденото място към масива от пароли 

void Event::addReservation(const Reservation& reservation)
{
	if (reservedSize == capacity)
	{
		resize();
	}
	int seat = ((reservation.getRow() - 1) * reservation.getHall().getSeats()) + reservation.getSeat(); //изчисляване на номера на мястото 
	reservedSeats[reservedSize] = seat;
	reservedPass[reservedSize] = reservation.getPass();
	reservedSize++;
}

// Премахване на резервирано място и паролата за съответното място
// Създаваме два нови масива със същия капацитет и с дължина един елемент по-малко от старите масиви
// При копирането на старата информация в новите масиви прескачаме индекса, на който се е намирало мястото, което трябва да премахнем

void Event::removeReservation(const Reservation& res)
{
	selectionSort();
	int seat = ((res.getRow() - 1) * res.getHall().getSeats()) + res.getSeat();
	int indexOfReservation = findReservation(seat);

	if (indexOfReservation != -1)
	{
		int* newArr = new int[capacity];
		MyString* passArr = new MyString[capacity];
		for (int i = 0; i < indexOfReservation; i++)
		{
			newArr[i] = reservedSeats[i];
			passArr[i] = reservedPass[i];
		}
		for (int i = indexOfReservation + 1; i < reservedSize; i++)
		{
			newArr[i - 1] = reservedSeats[i];
			passArr[i - 1] = reservedPass[i];
		}
		reservedSize = reservedSize - 1;
		delete[] reservedSeats;
		delete[] reservedPass;
		reservedPass = passArr;
		reservedSeats = newArr;
	}
}

// Функция за извеждане на масива от резервирани места за представлението

void Event::printReservedSeats() const
{
	for (int i = 0; i < reservedSize; i++)
	{
		std::cout << reservedSeats[i] << " ";
		std::cout << reservedPass[i].getString() << std::endl;
	}
}
