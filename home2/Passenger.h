#ifndef PASSENGER_H_
#define PASSENGER_H_

#include "Person.h"
#include "Preference.h"
#include <iostream>

class Passenger {
private:
	Person person;
	Preference preferences;
public:
	Passenger();
	Passenger(Person, Preference);

	// Getters for members.
	Person get_person() const;
	Preference get_preference() const;

	// Prints object.
	friend std::ostream& operator<<(std::ostream& os, const Passenger& passenger);
};

#endif
