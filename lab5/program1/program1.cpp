
#include <iostream>
#include <iomanip>
#include "Mortgage.h"
using namespace std;

int main() {
	Mortgage m;
	double loan, rate, years;
	
	cout << "Input loan amount: ";
	cin >> loan;
	if (loan < 0) {
		cout << "Loan amount was negative" << endl;
		return 1;
	}

	cout << "Input rate amount: ";
	cin >> rate;
	if (rate < 0) {
		cout << "Rate amount was negative" << endl;
		return 1;
	}

	cout << "Input years: ";
	cin >> years;
	if (years < 0) {
		cout << "Year amount was negative" << endl;
		return 1;
	}

	m.set_loan(loan);
	m.set_rate(rate);
	m.set_years(years);

	cout << "Monthly payment: $" << m.compute_monthly() << endl;
	cout << "Total payback: $" << fixed << setprecision(2) << m.compute_total() << endl;

	return 0;
}
