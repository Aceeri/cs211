
#include "Passenger.h"

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
	os << "Passenger: ";
	Person person = passenger.person;

	//std::cout << person;
	//os << passenger.get_person();
	//os << passenger.get_person() << ", " << passenger.get_preference();
}

