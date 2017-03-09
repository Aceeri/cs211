
#include "Preference.h"

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
	os << "Assistance: " << preference.assistance
	   << ", Meal: " << preference.meal;
	return os;
}
