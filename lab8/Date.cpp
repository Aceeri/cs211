
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
	this->month = month;
	this->day = day;
	this->year = year;
	concatenate();
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

	std::cout << "Input day: ";
	is >> date.day;

	std::cout << "Input year: ";
	is >> date.year;
}

bool operator>(Date& d1, Date& d2) {
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

int operator-(Date& d1, Date& d2) {
	int sum = 0;

	sum += std::abs(d1.day - d2.day);
	sum += std::abs(d1.year - d2.year) * 365;

	int lower = std::min(d1.month, d2.month);
	int higher = std::max(d1.month, d2.month);
	for (int i = lower; i < higher; i++) {
		sum += MONTH_LENGTH[i];
	}

	return sum;
}
