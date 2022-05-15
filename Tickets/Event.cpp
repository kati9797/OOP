#include "Event.h"

// Копираща функция 

void Event::copyFrom(const Event& other)
{
	date = other.date;
	hall = other.hall;
	name = other.name;

	reservedSize = other.reservedSize;
	capacity = other.capacity;
	reservedSeats = new int[capacity];
	reservedPass = new MyString[capacity];
	for (int i = 0; i < reservedSize; i++)
	{
		reservedSeats[i] = other.reservedSeats[i];
		reservedPass[i] = other.reservedPass[i];
	}
	
	purchasedSize = other.purchasedSize;
	purchasedCapacity = other.purchasedCapacity;
	purchasedSeats = new int[purchasedCapacity];
	for (int i = 0; i < purchasedSize; i++)
	{
		purchasedSeats[i] = other.purchasedSeats[i];
	}
}

// Освобождаване на динамично заделената памет

void Event::free()
{
	delete[] reservedSeats;
	delete[] reservedPass;
	delete[] purchasedSeats;
}

// Увелечаване на капацитета и копиране на старата информация в новия масив ( резервирани места )

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
		{
			if (reservedSeats[j] < reservedSeats[minInd])
			{
				minInd = j;
			}
		}
			
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

// Увелечаване на капацитета и копиране на старата информация в новия масив ( продадени места )

void Event::resizePurchased()
{
	purchasedCapacity *= 2;
	int* resizedArr = new int[purchasedCapacity];
	for (int i = 0; i < purchasedSize; i++)
	{
		resizedArr[i] = purchasedSeats[i];
	} 
	delete[] purchasedSeats;
	
	purchasedSeats = resizedArr;
}

// Сортиране на масива от продадени места

void Event::selectionSortPurch()
{
	int minInd;
	for (int i = 0; i < purchasedSize; i++)
	{
		minInd = i;
		for (int j = i + 1; j < purchasedSize; j++)
		{
			if (purchasedSeats[j] < purchasedSeats[minInd])
			{
				minInd = j;
			}		
		}
		
		if (minInd != i)
		{
			swap(purchasedSeats[minInd], purchasedSeats[i]);
		}
	}
}

// Проверява дали дадено място вече е било продадено

bool Event::binarySearchPurch(int seat)
{
	int startInd = 0;
	int endInd = purchasedSize - 1;

	while (startInd <= endInd)
	{
		int minInd = startInd + (endInd - startInd) / 2;
		if (purchasedSeats[minInd] == seat)
		{
			return true;
		}
		else if (purchasedSeats[minInd] < seat)
		{
			startInd = minInd + 1;
		}
		else
		{
			endInd = minInd - 1;
		}
	}
	return false;
}

// Конструктор по подразбиране

Event::Event()
{
	date = Date();
	name = "Unknown";
	hall = Hall();

	reservedSize = 0;
	capacity = 2;
	reservedSeats = new int[capacity];
	reservedPass = new MyString[capacity];

	purchasedSize = 0;
	purchasedCapacity = 2;
	purchasedSeats = new int[purchasedCapacity];
}

// Конструктор с параметри

Event::Event(const Date& newDate, const MyString& newName, const Hall& newHall)
{
	date = newDate;
	setName(newName);
	hall = newHall;

	reservedSize = 0;
	capacity = 2;
	reservedSeats = new int[capacity];
	reservedPass = new MyString[capacity];

	purchasedSize = 0;
	purchasedCapacity = 2;
	purchasedSeats = new int[purchasedCapacity];
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

void Event::setName(const MyString& newName)
{
	name = newName;
}

// Селектори

const Date& Event::getDate() const
{
	return date;
}

const MyString& Event::getName() const
{
	return name;
}

const Hall& Event::getHall() const
{
	return hall;
}

int Event::getPurchasedSize() const
{
	return purchasedSize;
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
	if (reservation.getRow() <= reservation.getHall().getRows() && reservation.getSeat() <= reservation.getHall().getSeats())
	{
		int seat = ((reservation.getRow() - 1) * reservation.getHall().getSeats()) + reservation.getSeat(); //изчисляване на номера на мястото 
		selectionSort();
		selectionSortPurch();
		if (findReservation(seat) != -1 || binarySearchPurch(seat))
		{
			std::cout << "Can't add reservation!" << std::endl;
		}
		else
		{
			if (reservedSize == capacity)
			{
				resize();
			}
			reservedSeats[reservedSize] = seat;
			reservedPass[reservedSize] = reservation.getPass();
			reservedSize++;
		}
	}
	else
	{
		std::cout << "Invalid reservation!" << std::endl;
	}
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
		reservedSeats = newArr;
		reservedPass = passArr;
	}
}

// Добавя ново продадено място към масива от продадени места

void Event::pushInPurchasedArr(int seat)
{
	if (purchasedSize == purchasedCapacity)
	{
		resizePurchased();
	}
	purchasedSeats[purchasedSize++] = seat;
}

// Проверява дали продаждабата на дадено място може да се осъществи ( ако е възможно -> покупката се осъществява )

void Event::addPurchase(Reservation& res)
{
	if (res.getRow() <= res.getHall().getRows() && res.getSeat() <= res.getHall().getSeats())
	{
		selectionSort();
		selectionSortPurch(); // сортираме масива от закупени места
		int seat = ((res.getRow() - 1) * res.getHall().getSeats()) + res.getSeat(); // изчисляваме поредното място
		bool isSold = binarySearchPurch(seat); // връща дали мястото е продадено

		if (isSold == true)
		{
			std::cout << "This seat has been already sold!" << std::endl;
		}
		else
		{
			int indexOfSeat = findReservation(seat);
			if (indexOfSeat != -1) // мястото е било резервирано
			{
				std::cout << "Enter password for reservation:" << std::endl;
				char pass[128];
				std::cin >> pass; // въвежда се парола
				if (reservedPass[indexOfSeat]==pass) // паролата е вярна
				{
					// поставяме мястото в масива от купени места
				    pushInPurchasedArr(seat);
					std::cout << "Succesful purchase!" << std::endl;
					removeReservation(res);
				}
				else // грешна парола, мястото не се купува
				{
					std::cout << "Wrong password!" << std::endl;
				}
			}
			else
			{
				// мястото не е резервирано
				pushInPurchasedArr(seat);
				std::cout << "Succesful purchase!" << std::endl;
				removeReservation(res);
			}	
		}
	}
	else
	{
		std::cout << "Invalid reservation!" << std::endl;
	}
	
}

// Брой свободни места за събитие

int Event::freeSeatsForEvent() const
{
	return getHall().getAllSeats() - reservedSize - purchasedSize;
}

// Отпечатва резервираните места (файл)

void Event::printReportReserved(std::ofstream& stream) const
{
	if (reservedSize == 0)
	{
		stream << '-' << std::endl;
	}
	else
	{
		for (int i = 0; i < reservedSize; i++)
		{
			stream << reservedSeats[i] << " ";
		}
		stream << std::endl;
	}
}

// Отпечатва резервирани места (конзола)

void Event::printReportReservedConsole() const
{
	if (reservedSize == 0)
	{
		std::cout << '-' << std::endl;
	}
	else
	{
		for (int i = 0; i < reservedSize; i++)
		{
			std::cout << reservedSeats[i] << " ";
		}
		std::cout << std::endl;
	}
}

// Отпечатва закупените места (файл)

void Event::printPurchasedSeats(std::ofstream& stream) const
{
	if (purchasedSize == 0)
	{
		stream << '-' << std::endl;
	}
	else
	{
		for (int i = 0; i < purchasedSize; i++)
		{
			stream << purchasedSeats[i] << " ";
		}
		stream << std::endl;
	}
}
