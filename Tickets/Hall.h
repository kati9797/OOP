#include <iostream>
#ifndef HALL_H
#define HALL_H

// ���� ����
class Hall
{
private:

	// ����� �� ����
	int number;
	//���� ������ � ������
	int rows;
	// ���� ����� �� ���� ���
	int seats;
	
	// ������������ ����-���������� �� ����� ���� ����� � ������
	int allSeats;
	// ������������ ����-���������� �� ������������ ����� � ������
	int freeSeats;

public:

	// ������������
	Hall();
	Hall(int, int, int);

	// ��������
	void setNumber(int);
	void setRows(int);
	void setSeats(int);

	// ���������
	int getNumber() const;
	int getRows() const;
	int getSeats() const;
	int getAllSeats() const;
	int getFreeSeats() const;

	// ������� �� ���������
	void printHall() const;
};


#endif // !HALL_H


