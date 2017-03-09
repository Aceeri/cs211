
#include <iostream>
#include "Person.h"
using namespace std;

Person::Person() { }

Person::Person(string first, string last, string g, string social) {
	// Remove non-digits from ssn
	string num_ssn;
	for (int i = 0; i < social.length(); i++) {
		if (isdigit(social[i])) {
			num_ssn += social[i];
		}
	}

	first_name = first;
	last_name = last;
	gender = g[0];
	ssn = atol(num_ssn.c_str());
}

string Person::get_first() const {
	return first_name;
}

string Person::get_last() const {
	return last_name;
}

char Person::get_gender() const {
	return gender;
}

long Person::get_ssn() const {
	return ssn;
}

void Person::display() const {
	cout << "Person { first_name: " << get_first() << ", last_name: " << get_last() << ", gender: " << get_gender() << ", ssn: " << get_ssn();
}
