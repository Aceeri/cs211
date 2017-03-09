#ifndef MORTGAGE_H
#define MORTGAGE_H

class Mortgage {
private:
	double loan;
	double rate;
	double years;
public:
	Mortgage();

	void set_loan(double);
	void set_rate(double);
	void set_years(double);
	void display_loan() const;
	void display_rate() const;
	void display_years() const;

	double compute_monthly() const;
	double compute_total() const;
};

#endif
