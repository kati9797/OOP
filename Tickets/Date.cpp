#include "Date.h"
#include <iostream>

// Конструктор по подразбиране

Date::Date()
{
	day = 1;
	month = 1;
	year = 1;
}

// Конструктор с параметри

Date::Date(int newDay, int newMonth, int newYear)
{
	setMonth(newMonth);
	setDay(newDay);
	setYear(newYear);
}

//  Мутатори

void Date::setDay(int newDay)
{
	if (newDay <= 0 || newDay > maxDays[month - 1])
	{
		day = 1;
		//std::cout << "Invalid day!" << std::endl;
	}
	else
	{
		day = newDay;
	}
}

void Date::setMonth(int newMonth)
{
	if (newMonth <= 0 || newMonth > 12)
	{
		month = 1;
		//std::cout << "Invalid month!"<<std::endl;
	}
	else
	{
		month = newMonth;
	}
}

void Date::setYear(int newYear)
{
	if (newYear <= 0)
	{
		year = 1;
		//std::cout << "Invalid year!" << std::endl;
	}
	else
	{
		year = newYear;
	}
}

// Селектори

int Date::getDay() const
{
	return day;
}

int Date::getMonth() const
{
	return month;
}

int Date::getYear() const
{
	return year;
}

// Функция за извеждане

void Date::printDate() const
{
	std::cout << "Day: " << day << ", Month: " << month << ", Year: " << year << std::endl;
}

// Оператор "==" за сравнение на дати

bool operator==(const Date& date1, const Date& date2)
{
	return (date1.getDay() == date2.getDay() && date1.getMonth() == date2.getMonth() && date1.getYear() == date2.getYear());
}
