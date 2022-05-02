#ifndef DATE_H
#define DATE_H
#pragma warning (disable: 4996)

// Клас Дата
class Date
{
private:

	int day;
	int month;
	int year;
	// Допълнителна член променлива, за да можем да подаваме дата и чрез "ALL"
	char date[1024];

	// Масив, пазещ максималния брой дни за всеки месец от годината
	int maxDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

public:

	// Конструктори
	Date();
	Date(int, int, int);
	Date(const char*);

	// Мутатори
	void setDay(int);
	void setMonth(int);
	void setYear(int);

	// Селектори
	int getDay() const;
	int getMonth() const;
	int getYear() const;

	// Функция, която проверява дали датата е зададена чрез "ALL"
	bool allDates() const;
	// Функция за извеждане
	void printDate() const;
};

// Оператор за сравнение на дати
bool operator==(const Date&, const Date&);

#endif
