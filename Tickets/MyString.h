#include <iostream>
#ifndef MYSTRING_HEADER
#define MYSTRING_HEADER

// ���� ������
// ������������� ������������� �� �������� Word Collection

class MyString
{
private:

	char* string;
	int size;

	// �������� �������
	void copyFrom(const MyString&);
	// ������������� �� ��������� ���������� �����
	void free();

public:

	// ������������
	MyString();
	MyString(const char*);
	MyString(const MyString&);
	// �������� �� �����������
	MyString& operator=(const MyString&);
	// ����������
	~MyString();

	// ���������
	int getSize();
	char* getString() const;

	// ������������� �������
	void concat(const MyString&);
};

// ��������� �� ���������
bool operator >(const MyString&, const MyString&);
bool operator <(const MyString&, const MyString&);
bool operator ==(const MyString&, const MyString&);

#endif 
