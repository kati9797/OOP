#include <iostream>
#ifndef MYSTRING_HEADER
#define MYSTRING_HEADER
#pragma warning(disable : 4996)

// Клас Стринг
// Показван на упражнения
// https://github.com/Angeld55/Object-oriented_programming_FMI/tree/master/Sem.%2007/MyStringon

class MyString
{
private:

	char* string;
	int size;

	// Копираща функция
	void copyFrom(const MyString&);
	// Освобождаване на динамично заделената памет
	void free();

public:

	// Конструктори
	MyString();
	MyString(const char*);
	MyString(const MyString&);
	// Оператор за присвояване
	MyString& operator=(const MyString&);
	// Деструктор
	~MyString();

	// Селектори
	int getSize() const;
	char* getString() const;

	// Конкатенираща функция
	void concat(const MyString&);
	// Оператор за извеждане
	friend std::ostream& operator<<(std::ostream&, const MyString&);
	// Оператор за четене
	friend std::istream& operator>>(std::istream&, MyString&);
};

// Оператори за сравнение
bool operator >(const MyString&, const MyString&);
bool operator <(const MyString&, const MyString&);
bool operator ==(const MyString&, const MyString&);

#endif 

