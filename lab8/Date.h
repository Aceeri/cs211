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
	bool is_leap(int year) const;
	int get_length(int month, int year) const;

	int get_month() const;
	int get_day() const;
	int get_year() const;

	void set(int month, int day, int year);
	void set_month(int month);
	void set_day(int day);
	void set_year(int year);

	friend Date& operator++(Date& date);
	friend Date& operator--(Date& date, int dummy);
	friend std::ostream& operator<<(std::ostream& os, Date& date);
	friend std::istream& operator>>(std::istream& os, Date& date);
	friend bool operator>(const Date& d1, const Date& d2);
	friend int operator-(const Date& d1, const Date& d2);
};

#endif
