
#include "Passenger.h"
#include <iomanip>

Passenger::Passenger() {
	person = Person();
	preferences = Preference();
}

Passenger::Passenger(Person n_person, Preference n_preferences) {
	person = n_person;
	preferences = n_preferences;
}

Person Passenger::get_person() const {
	return person;
}

Preference Passenger::get_preference() const {
	return preferences;
}

std::ostream& operator<<(std::ostream& os, const Passenger& passenger) {
	os << passenger.person << passenger.preferences;
	return os;
}

