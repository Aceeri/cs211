
#include "Flight.h"

long Flight::next_id = 100;

/*Flight::Flight(): id(Flight::next_id += 10), capacity(0) {
	departure_airport = "Unknown";
	arrival_airport = "Unknown";
	date = "Unknown";
	time = "Unknown";
	duration = 0.0;
}*/

Flight::Flight(std::string departure, std::string arrival, std::string n_date, std::string n_time, float n_duration, int cap, std::vector<std::string> passenger_ids):
	id(Flight::next_id += 10), capacity(cap) {
	departure_airport = departure;
	arrival_airport = arrival;
	date = n_date;
	time = n_time;
	duration = n_duration;
	passengers = passenger_ids;
}

bool Flight::add_passenger(std::string id) {
	for (int i = 0; i < passengers.size(); i++) {
		if (passengers[i] == id) {
			return false;
		}
	}

	passengers.push_back(id);
	return true;
}

bool Flight::remove_passenger(std::string id) {
	for (int i = 0; i < passengers.size(); i++) {
		if (passengers[i] == id) {
			passengers.erase(passengers.begin() + i);
			return true;
		}
	}

	return false;
}

bool Flight::is_full() const {
	return passengers.size() >= capacity;
}

long Flight::get_id() const {
	return id;
}
