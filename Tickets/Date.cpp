#include "Date.h"
#include <iostream>

// Конструктор по подразбиране

Date::Date()
{
	day = 1;
	month = 1;
	year = 1;
	strcpy(date, "\0");
}

// Конструктор с параметри

Date::Date(int newDay, int newMonth, int newYear)
{
	setMonth(newMonth);
	setDay(newDay);
	setYear(newYear);
	strcpy(date, "\0");
}

// Конструктор с параметър char*
// Променяме допълнителната член-данна date само ако като параметър се подаде "ALL"

Date::Date(const char* newDate)
{
	day = 1;
	month = 1;
	year = 1;
	strcpy(date, "\0");

	if (strcmp(newDate, "ALL") == 0)
	strcpy(date, newDate);
}

// Мутатори

void Date::setDay(int newDay)
{
	if (newDay <= 0 || newDay > maxDays[month - 1])
	{
		throw std::logic_error("Inavalid day!");
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
		throw std::logic_error("Inavalid month!");
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
		throw std::logic_error("Inavalid year!");
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

// Функция която проверява дали дата е между други две дати

bool Date::isBetweenDates(const Date& firstDate, const Date& secondDate)
{
	return ((year >= firstDate.getYear() && year <= secondDate.getYear() && month > firstDate.getMonth() && month < secondDate.getMonth())
		|| (year >= firstDate.getYear() && year <= secondDate.getYear() && month == firstDate.getMonth() && month < secondDate.getMonth() && day >= firstDate.getDay())
		|| (year >= firstDate.getYear() && year <= secondDate.getYear() && month > firstDate.getMonth() && month == secondDate.getMonth() && day <= secondDate.getDay())
		|| (year >= firstDate.getYear() && year <= secondDate.getYear() && month == firstDate.getMonth() && month == secondDate.getMonth() && day >= firstDate.getDay() && day <= secondDate.getDay()));
}

// Функция, която проверява дали датата е зададена чрез "ALL"

bool Date::allDates() const
{
	return (strcmp(date,"ALL") == 0);
}

// Функция за извеждане 

void Date::printDate() const
{
	if (!(strcmp(date, "ALL") == 0))
	{
		std::cout << day << "." << month << "." << year << std::endl;
	}
	else
	{
		std::cout << "ALL";
	}
}

// Оператор "==" за сравнение на дати

bool operator==(const Date& date1, const Date& date2)
{
	return (date1.getDay() == date2.getDay() && date1.getMonth() == date2.getMonth() && date1.getYear() == date2.getYear());
}
