
#include <iostream>
#include <cmath>
#include "Mortgage.h"
using namespace std;

Mortgage::Mortgage() {
	loan = 0.0;
	rate = 0.0;
	years = 0;
}

void Mortgage::set_loan(double l) {
	loan = l;
}

void Mortgage::set_rate(double r) {
	rate = r;
}

void Mortgage::set_years(double y) {
	years = y;
}

void Mortgage::display_loan() const {
	cout << loan;
}

void Mortgage::display_rate() const {
	cout << rate;
}

void Mortgage::display_years() const {
	cout << years;
}

double Mortgage::compute_monthly() const {
	double term = pow(1 + rate / 12, 12 * years);
	return (loan * term * rate / 12) / (term - 1);
}

double Mortgage::compute_total() const {
	double monthly = compute_monthly();
	return monthly * 12.0 * years;
}
