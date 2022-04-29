#include "MyString.h"
#pragma warning(disable : 4996)

// Копираща функция

void MyString::copyFrom(const MyString& other)
{
	string = new char[strlen(other.string) + 1];
	strcpy(string, other.string);

	size = other.size;
}

// Освобождаване на динамично заделената памет

void MyString::free()
{
	delete[] string;
}

// Конструктор по подразбиране

MyString::MyString()
{
	string = new char[1];
	string[0] = '\0';
	size = 0;
}

// Конструктор с параметър

MyString::MyString(const char* str)
{
	string = new char[strlen(str) + 1];
	strcpy(string, str);

	size = strlen(str);
}

// Копиращ конструктор

MyString::MyString(const MyString& other)
{
	copyFrom(other);
}

// Оператор "="

MyString& MyString::operator=(const MyString& str)
{
	if (this != &str)
	{
		free();
		copyFrom(str);
	}
	return *this;
}

// Деструктор

MyString::~MyString()
{
	free();
}

// Селектори

int MyString::getSize()
{
	return size;
}

char* MyString::getString() const
{
	return string;
}

// Конкатенираща функция

void MyString::concat(const MyString& other)
{
	char* newString = new char[size + other.size + 1];
	strcpy(newString, string);
	strcat(newString, other.string);
	free();
	string = newString;
	size = size + other.size;
}

// Оператори за сравнение

bool operator>(const MyString& str1, const MyString& str2)
{
	return (strcmp(str1.getString(), str2.getString()) > 0);
}

bool operator<(const MyString& str1, const MyString& str2)
{
	return (strcmp(str1.getString(), str2.getString()) < 0);
}

bool operator==(const MyString& str1, const MyString& str2)
{
	return (strcmp(str1.getString(), str2.getString()) == 0);
}
