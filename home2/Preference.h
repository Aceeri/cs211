#ifndef PREFERENCE_H_
#define PREFERENCE_H_

#include <string>
#include <iostream>

class Preference {
private:
	std::string assistance;
	std::string meal;
public:
	Preference(std::string = "none", std::string = "none");

	// Getters for members.
	std::string get_assistance() const;
	std::string get_meal() const;

	// Prints object.
	friend std::ostream& operator<<(std::ostream& os, const Preference& preference);
};

#endif
