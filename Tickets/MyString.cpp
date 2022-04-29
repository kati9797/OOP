#include "MyString.h"
#pragma warning(disable : 4996)

// �������� �������

void MyString::copyFrom(const MyString& other)
{
	string = new char[strlen(other.string) + 1];
	strcpy(string, other.string);

	size = other.size;
}

// ������������� �� ��������� ���������� �����

void MyString::free()
{
	delete[] string;
}

// ����������� �� ������������

MyString::MyString()
{
	string = new char[1];
	string[0] = '\0';
	size = 0;
}

// ����������� � ���������

MyString::MyString(const char* str)
{
	string = new char[strlen(str) + 1];
	strcpy(string, str);

	size = strlen(str);
}

// ������� �����������

MyString::MyString(const MyString& other)
{
	copyFrom(other);
}

// �������� "="

MyString& MyString::operator=(const MyString& str)
{
	if (this != &str)
	{
		free();
		copyFrom(str);
	}
	return *this;
}

// ����������

MyString::~MyString()
{
	free();
}

// ���������

int MyString::getSize()
{
	return size;
}

char* MyString::getString() const
{
	return string;
}

// ������������� �������

void MyString::concat(const MyString& other)
{
	char* newString = new char[size + other.size + 1];
	strcpy(newString, string);
	strcat(newString, other.string);
	free();
	string = newString;
	size = size + other.size;
}

// ��������� �� ���������

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
