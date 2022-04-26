#ifndef TIMETABLE_H
#define TIMETABLE_H
#include "Hall.h"
#include "Date.h"
#include "Event.h"
#include "Reservation.h"

// ���� ����������
class TimeTable
{
private:

	// ����� �� �������(�������������) � ���������� �������
	Event* list;
	// ������� �� ����� �� �������
	int size;
	// ��������� �� ������ �� �������
	int capacity;

	// �������� �������
	void copyFrom(const TimeTable&);
	// ������������� �� ��������� ���������� �����
	void free();
	// �������, ����� �� ������� ���������� �� ������ �� ������� ( ��� ����� )
	void resize();

public:

	// ������������
	TimeTable();
	TimeTable(const Event*,int);
	TimeTable(const TimeTable&);
	// �������� �� �����������
	TimeTable& operator=(const TimeTable&);
	// ����������
	~TimeTable();

	// �������
	void setList(const Event*, int);
	// ������� �� ��������� �� ����������
	void printTimeTable() const;

	// �������� �� �������
	void addEvent(const Event&);
	// �������� ����� � ������ �� ������������� ( �� �������� ���� � ��� �� ��������������� ) 
	int freeSeats(const Date&, const char*);
	// ��������� �� ����� �� ������������� ( �� �������� ����, ��� �� ��������������� � ����� �� ���������� )
	void saveTicket(const Date&, const char*, Reservation&);
	// ������ �� ���������� ( �� �������� ����, ��� �� ��������������� � ����� �� ����������)
	void removeSavedTicket(const Date&, const char*, Reservation&);
};
#endif
