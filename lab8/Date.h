#ifndef DATE_H_
#define DATE_H_

#include <iostream>
#include <string>

class Date {
private:
	int month;
	int day;
	int year;
public:
	Date(int month = 0, int day = 1, int year = 0);
	// Concatenates months into years, days to months, etc.
	void concatenate();

	friend Date& operator++(Date& date);
	friend Date& operator--(Date& date, int dummy);
	friend std::ostream& operator<<(std::ostream& os, Date& date);
	friend std::istream& operator>>(std::istream& os, Date& date);
	friend bool operator>(Date& d1, Date& d2);
	friend int operator-(Date& d1, Date& d2);
};

#endif
