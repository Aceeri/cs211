
#include <iostream>
#include <fstream>
#include "FlightReservation.h"
#include "Passenger.h"

bool FlightReservation::failure = false;
bool FlightReservation::success = true;

FlightReservation::FlightReservation() { }

FlightReservation::FlightReservation(std::vector<Flight> n_flights, std::vector<Passenger> n_passengers) {
	for (int i = 0; i < n_flights.size(); i++) {
		flights.push_back(n_flights[i]);
	}

	for (int i = 0; i < n_passengers.size(); i++) {
		passengers.push_back(n_passengers[i]);
	}
}

int FlightReservation::find_passenger(std::string id) const {
	for (int i = 0; i < passengers.size(); i++) {
		if (passengers[i].get_person().get_id() == id) {
			return i;
		}
	}
	return -1;
}

int FlightReservation::find_flight(long id) const {
	for (int i = 0; i < flights.size(); i++) {
		if (flights[i].get_id() == id) {
			return i;
		}
	}
	return -1;
}

bool FlightReservation::create_passenger(std::string id, std::string first, std::string last, char gender, int age, std::string assistance, std::string meal) {
	if (find_passenger(id) == -1) {
		Person person(id, first, last, gender, age);
		Preference preference(assistance, meal);
		passengers.push_back( Passenger(person, preference) );
		return true;
	}

	return false;
}

bool FlightReservation::create_flight(std::string depart, std::string arrival, std::string date, std::string time, float duration, int cap) {
	Flight flight(Flight(depart, arrival, date, time, duration, cap, std::vector<std::string>()));
	flights.push_back(flight);
	return true;
}

bool FlightReservation::add_passenger(long flight_id, std::string passenger_id) {
	int index = find_flight(flight_id);

	if (index >= 0) {
		return flights[index].add_passenger(passenger_id);
	}
	
	return false;
}

bool FlightReservation::remove_passenger(long flight_id, std::string passenger_id) {
	int index = find_flight(flight_id);

	if (index >= 0) {
		return flights[index].remove_passenger(passenger_id);
	}
	
	return false;
}

bool FlightReservation::is_flight_full(long flight_id) const {
	int index = find_flight(flight_id);

	if (index >= 0) {
		return flights[index].is_full();
	}
	
	return false;
}

void FlightReservation::print_passengers() const {
	if (passengers.size() == 0) {
		std::cout << "There are currently no passengers registered for flights." << std::endl;
	}

	for (int i = 0; i < passengers.size(); i++) {
		std::cout << passengers[i] << std::endl;
	}
}

void FlightReservation::print_flights() const {

}

std::vector<std::string> split(const std::string& str) {
	std::vector<std::string> words;
	int start = 0; // sub std::string start position, negative means it is currently whitespace
	
	for (int i = 0; i < str.size(); i++) {
		char c = str.at(i);
		
		if (c == ' ') {
			if (start >= 0) { // The start index exists so this is the end of a word.
				std::string word = str.substr(start, i - start);
				words.push_back(word);
			}

			start = -1;
		}
		else if (start < 0) { // If the word hasn't already been started, so indicate the start.
			start = i;
		}
	}

	if (start >= 0) { // If a word exists at the end.
		std::string word = str.substr(start, str.size() - start);
		words.push_back(word);
	}

	return words;
}

bool FlightReservation::process_transactions(std::string filename) {
	std::ifstream file;
	file.open(filename.c_str());

	std::string line;
	while (getline(file, line)) {
		std::vector<std::string> args = split(line);
		
		if (args.size() == 0) {
			std::cout << "No command" << std::endl;
		}
		else if (args[0] == "CreateNewPassenger") {
			if (args.size() < 8) {
				std::cout << "Not enough arguments for command `CreateNewPassenger`" << std::endl;
			}

			create_passenger(args[3], args[1], args[2], args[4].at(0), atoi(args[5].c_str()), args[6], args[7]);
			std::cout << "CURRENT PASSENGERS: " << std::endl;
			print_passengers();
		}
		else if (args[0] == "PrintAllPassengers") {
			print_passengers();
		}
	}
}
