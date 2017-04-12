
#include "Date.h"
#include <cmath>

const std::string MONTHS[12] = { 
	"January", "February", "March", "April",
	"May", "June", "July", "August", "September",
	"October", "November", "December",
};

const int MONTH_LENGTH[12] = {
	31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
};

Date::Date(int month, int day, int year) {
	this->month = month - 1;
	this->day = day;
	this->year = year;
	concatenate();
}

bool Date::is_leap(int year) const {
	if (year % 4 == 0) {
		if (year % 100 == 0) {
			if (year % 400 == 0) {
				return true;
			}
			return false;
		}
		return true;
	}
	return false;
}

int Date::get_length(int month, int year) const {
	if (month == 1 && is_leap(year)) {
		return 29;
	}
	return MONTH_LENGTH[month];
}

void Date::concatenate() {
	year += month / 12;
	month = month % 12;

	if (month < 0) {
		month += 12;
	}
	
	int flip = 1;
	if (day <= 0) {
		flip = -1;
	}

	while (day > MONTH_LENGTH[month] || day <= 0) {
		day -= MONTH_LENGTH[month] * flip;
		month += flip;
		
		if (month >= 12) {
			year += 1;
			month = 0;
		}
		else if (month < 0) {
			year -= 1;
			month = 11;
		}
	}
}

Date& operator++(Date& date) {
	date.day += 1;
	date.concatenate();
	return date;
}

Date& operator--(Date& date, int dummy) {
	date.day -= 1;
	date.concatenate();
	return date;
}

std::ostream& operator<<(std::ostream& os, Date& date) {
	os << MONTHS[date.month] << " " << date.day << ", " << date.year;
}

std::istream& operator>>(std::istream& is, Date& date) {
	std::cout << "Input month: ";
	is >> date.month;
	date.month -= 1;

	std::cout << "Input day: ";
	is >> date.day;

	std::cout << "Input year: ";
	is >> date.year;
}

bool operator>(const Date& d1, const Date& d2) {
	if (d1.year > d2.year) {
		return true;
	}
	else if (d1.year == d2.year) {
		if (d1.month > d2.month) {
			return true;
		}
		else if (d1.month == d2.month) {
			return d1.day > d2.day;
		}
	}

	return false;
}

int operator-(const Date& d1, const Date& d2) {
	int sum = 0;

	Date lower, higher;
	if (d1 > d2) {
		lower = d2;
		higher = d1;
	}
	else {
		lower = d1;
		higher = d2;
	}
	
	int r_day = abs(higher.day - lower.day);
	int r_month = abs(higher.month - lower.month);
	int r_year = higher.year - lower.year;

	if (r_year > 0) {
		// If the difference between years is greater than 0 then find the
		// amount of days from the lower month to the end of the year plus
		// the amount of days from the start of the year to the higher month
		// plus the amount of days in the years in between.

		sum += lower.get_length(lower.month, lower.year) - lower.day;
		sum += higher.day;

		for (int i = lower.month + 1; i < 12; i++) {
			sum += lower.get_length(i, lower.year);
		}

		for (int i = 0; i < higher.month; i++) {
			sum += higher.get_length(i, higher.year);
		}

		for (int i = lower.year; i < higher.year - 1; i++) {
			if (lower.is_leap(i)) {
				sum += 366;
			}
			else {
				sum += 365;
			}
		}
	}
	else if (r_month > 0) {
		sum += lower.get_length(lower.month, lower.year) - lower.day;
		sum += higher.day;

		for (int i = lower.month; i < higher.month - 1; i++) {
			sum += lower.get_length(i, lower.year);
		}
	}
	else {
		sum += r_day;
	}

	return sum;
}

int Date::get_day() const {
	return day;
}

int Date::get_month() const {
	return month;
}

int Date::get_year() const {
	return year;
}

void Date::set(int month, int day, int year) {
	this->month = month - 1;
	this->day = day;
	this->year = year;
	concatenate();
}

void Date::set_day(int day) {
	this->day = day;
	concatenate();
}

void Date::set_month(int month) {
	this->month = month;
	concatenate();
}

void Date::set_year(int year) {
	this->year = year;
	concatenate();
}
