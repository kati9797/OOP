#ifndef EVENT_H
#define EVENT_H
#include "Hall.h"
#include "Date.h"
#include "Reservation.h"
#pragma warning ( disable : 4996 )

// ���� �������
class Event
{
private:

	// ����
	Date date;
	// ��� �� �������������
	char* name;
	// ������������ ���������� �� ��������� �� ����� ( ������ �� � � ���������� ������� )
	int nameSize; 
	// ����
	Hall hall;
	
	// ����� �� ������������� ����� �� ���������������
	int* reservedSeats;
	// ������� �� ������ �� ����������� �����
	int reservedSize;
	// ��������� �� ������ �� ����������� ����� ( ������ �� �� ������ �� ��������/�� ���������� �������� �� ������ )
	int capacity;
	// �������, ����� �� ������� ���������� �� ������ �� ����������� ����� ( ��� ����� )
	void resize();

	// ������� �� �������� �� ���������� �� ����� ������������� 
	void copyFrom(const Event&);
	// ������������� �� ��������� ���������� �����
	void free();

	// ������� �� ������� �� �������� ( ��� ����������� )
	void swap(int&,int&);
	// ��������� �� ������ �� ����������� �����
	void selectionSort();
	// �������, ����� ��������� ���� ������ ����� � ���� ����������� ( ��� � �����������, ����� �������, �� ����� �� ������ ) 
	int findReservation(int);

public:

	// ������������
	Event();
	Event(Date,const char*, Hall);
	Event(const Event&);
	// �������� �� ����������� 
	Event& operator=(const Event&);
	// ����������
	~Event();

	// ������� �� ����� �� ���������������
	void setName(const char*);
	// ���������
	Date getDate() const;
	char* getName() const;
	Hall getHall() const;
	// ������� �� ��������� �� �������������
	void printEvent() const;

	// �������� �� ����������� ����� � ������ �� ����������� �����
	void addReservation(const Reservation&);
	// ���������� �� ����������� ����� �� ������ �� ����������� �����
	void removeReservation(const Reservation&);
	// ������� �������, ����� ������� ������ �� ����������� �����
	void printReservedSeats() const;
};
#endif // !HALL_H
