
#include <iomanip>
#include "Flight.h"

long Flight::next_id = 100;

Flight::Flight(std::string departure, std::string arrival, std::string n_date, std::string n_time, float n_duration, int cap, std::vector<std::string> passenger_ids):
	id(Flight::next_id), capacity(cap) {
	departure_airport = departure;
	arrival_airport = arrival;
	date = n_date;
	time = n_time;
	duration = n_duration;
	passengers = passenger_ids;

	Flight::next_id += 10;
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

std::string Flight::get_departure() const {
	return departure_airport;
}

std::string Flight::get_arrival() const {
	return arrival_airport;
}

std::string Flight::get_date() const {
	return date;
}

float Flight::get_duration() const {
	return duration;
}

int Flight::get_capacity() const {
	return capacity;
}

std::vector<std::string> Flight::get_passengers() const {
	return passengers;
}

std::ostream& operator<<(std::ostream& os, const Flight& flight) {
	os << std::left
	   << std::setw(6) << flight.id
	   << std::setw(10) << flight.departure_airport
	   << std::setw(10) << flight.arrival_airport
	   << std::setw(15) << flight.date
	   << std::setw(10) << flight.time
	   << std::setw(9) << flight.duration
	   << std::setw(8) << flight.capacity;
	return os;
}
