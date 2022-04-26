#ifndef RESERVATION_H
#define RESERVATION_H
#include <iostream>
#include "Hall.h"
#pragma warning ( disable : 4996 )

// ���� ����������
class Reservation
{
private:

	// ���� ( �� ������ �� ���� �� �������� � ���� ������� �� ��� � ������ )
	Hall hall;
	// ��� �� ����������
	int row;
	// ����� �� �������� ��� �� ����������
	int seat;
	// ������ �� ���������� ( � ���������� ������� )
	char* password;
	// ������� �� ��������
	int sizePass;
	// ������� ��� ������������ 
	char note[1024];

	// �������� ������� �� ����� ����������
	void copyFrom(const Reservation&);
	// ������������� �� ��������� ���������� �����
	void free();

public:

	// ������������
	Reservation();
	Reservation(int, int, const char*);
	Reservation(const Reservation&);
	// �������� �� �����������
	Reservation& operator=(const Reservation&);
	// ����������
	~Reservation();

	// ��������
	void setPass(const char*);
	void setNote(char*);
	void setHall(const Hall&);
	// ���������
	char* getPass() const;
	int getRow() const;
	int getSeat() const;
	Hall getHall() const;
	// ������� �� ��������� �� ����������
	void printReservation() const;
};

#endif