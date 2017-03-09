
#include "Person.h"
#include <iomanip>

Person::Person(std::string n_id, std::string n_first, std::string n_last, char n_gender, int n_age) {
	id = n_id;
	gender = n_gender;
	first = n_first;
	last = n_last;
	age = n_age;
}

std::string Person::get_id() const {
	return id;
}

std::string Person::get_first() const {
	return first;
}

std::string Person::get_last() const {
	return last;
}

char Person::get_gender() const {
	return gender;
}

int Person::get_age() const {
	return age;
}

std::ostream& operator<<(std::ostream& os, const Person& person) {
	os << std::left
	   << std::setw(12) << person.first
	   << std::setw(12) << person.last
	   << std::setw(8) << person.gender
	   << std::setw(5) << person.age;

	return os;
}

