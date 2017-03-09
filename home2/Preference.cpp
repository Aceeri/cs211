
#include "Preference.h"
#include <iomanip>

Preference::Preference(std::string assistance_type, std::string meal_type) {
	assistance = assistance_type;
	meal = meal_type;
}

std::string Preference::get_assistance() const {
	return assistance;
}

std::string Preference::get_meal() const {
	return meal;
}

std::ostream& operator<<(std::ostream& os, const Preference& preference) {
	os << std::left
	   << std::setw(15) << preference.assistance
	   << std::setw(15) << preference.meal;
	return os;
}
