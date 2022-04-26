#ifndef DATE_H
#define DATE_H

class Date
{
private:
	int day;
	int month;
	int year;

	int maxDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
public:
	Date();
	Date(int, int, int);
	void setDay(int);
	void setMonth(int);
	void setYear(int);
	int getDay() const;
	int getMonth() const;
	int getYear() const;
	void printDate() const;
};

bool operator==(const Date&, const Date&);
#endif