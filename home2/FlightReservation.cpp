
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include "FlightReservation.h"
#include "Passenger.h"

#define ANSI // If you want color coded output and your terminal supports ANSI escape codes.

#ifdef ANSI
	#define BOLD "\e[1m\e[32m"
	#define UNBOLD "\e[0m\e[39m"
#else
	#define BOLD ""
	#define UNBOLD ""
#endif

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
	Flight flight(depart, arrival, date, time, duration, cap);
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
	else {
		print_passenger_list(passengers);
	}
}

void FlightReservation::print_flights() const {
	if (flights.size() == 0) {
		std::cout << "There are currently no flights registered." << std::endl;
	}
	else {
		print_flight_list(flights);
	}
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


		if (args.size() != 0 && args[0].size() > 0) {
			std::cout << "> "
					  << line
					  << std::endl;
		}
		
		if (args.size() == 0) {
			std::cout << "No command" << std::endl;
		}
		else if (args[0] == "CreateNewPassenger") {
			if (args.size() < 8) {
				std::cout << "Not enough arguments for command `CreateNewPassenger`" << std::endl;
			}

			// Create a new passenger from the arguments.
			// id, first, last, gender, age, assistance, meal
			bool success = create_passenger(args[3], args[1], args[2], args[4].at(0), atoi(args[5].c_str()), args[6], args[7]);

			if (success) {	
				std::cout << "Created passenger: " << passengers[passengers.size() - 1] << std::endl;
			}
			else {
				std::cout << "Failed to create passenger, duplicate id" << std::endl;
			}
		}
		else if (args[0] == "PrintAllPassengers") {
			print_passengers();
		}
		else if (args[0] == "CreateNewFlight") {
			if (args.size() < 7) {
				std::cout << "Not enough arguments for command `CreateNewFlight`" << std::endl;
			}

			// Create a new flight from the arguments.
			// departure, arrival, date, time, duration, capacity
			bool success = create_flight(args[1], args[2], args[3], args[4], atof(args[5].c_str()), atoi(args[6].c_str()));
			
			if (success) {
				std::cout << "Created flight: " << flights[flights.size() - 1] << std::endl;
			}
			else {
				std::cout << "Failed to create flight" << std::endl;
			}
		}
		else if (args[0] == "PrintAllFlights") {
			print_flights();
		}
		else if (args[0] == "PrintSpecificFlights") {
			if (args.size() < 4) {
				std::cout << "Not enough arguments for command `PrintSpecificFlights`" << std::endl;
			}
			
			std::string departure, arrival, date;
			departure = args[1];
			arrival = args[2];
			date = args[3];

			// sequential search through the flights to match arguments.
			std::vector<Flight> list;
			for (int i = 0; i < flights.size(); i++) {
				if (flights[i].get_departure() == args[1]
					&& flights[i].get_arrival() == args[2]
					&& flights[i].get_date() == args[3]) {
					list.push_back(flights[i]);
				}
			}

			if (list.size() == 0) {
				std::cout << "No flights matched the description given." << std::endl;
			}
			else {
				print_flight_list(list);
			}
		}
		else if (args[0] == "AddFlightPassenger") {
			if (args.size() < 3) {
				std::cout << "Not enough arguments for command `AddFlightPassenger`" << std::endl;
			}
			
			// Add a passenger to a flight given arguments.
			long flight_id = atol(args[1].c_str());
			bool success = add_passenger(flight_id, args[2]);
			if (success) {
				std::cout << "Added passenger `" << args[2] << "` to flight `" << flight_id << "`" << std::endl;
			}
			else {
				std::cout << "Unable to add passenger `" << args[2] << "` to flight `" << flight_id << "`" << std::endl;
			}
		}
		else if (args[0] == "RemoveFlightPassenger") {
			if (args.size() < 3) {
				std::cout << "Not enough arguments for command `RemoveFlightPassenger`" << std::endl;
			}
			
			// Remove a passenger from a flight given arguments.
			long flight_id = atol(args[1].c_str());
			bool success = remove_passenger(flight_id, args[2]);
			if (success) {
				std::cout << "Removed passenger `" << args[2] << "` from flight `" << flight_id << "`" << std::endl;
			}
			else {
				std::cout << "Unable to remove passenger `" << args[2] << "` from flight `" << flight_id << "`" << std::endl;
			}
		}
		else if (args[0] == "PrintFlightInfo") {
			if (args.size() < 2) {
				std::cout << "Not enough arguments for command `PrintFlightInfo`" << std::endl;
			}

			long flight_id = atol(args[1].c_str());
			int index = find_flight(flight_id);

			if (index == -1) {
				std::cout << "Flight `" << flight_id << "` does not exist." << std::endl;
			}
			else {
				std::vector<Flight> list;
				list.push_back(flights[index]);
				print_flight_list(list);
			}
		}
		else if (args[0] == "PrintFlightPassengers") {
			if (args.size() < 2) {
				std::cout << "Not enough arguments for command `PrintFlightInfo`" << std::endl;
			}

			long flight_id = atol(args[1].c_str());
			int index = find_flight(flight_id);

			if (index == -1) {
				std::cout << "Flight `" << flight_id << "` does not exist." << std::endl;
			}
			else {
				Flight flight = flights[index];
				std::vector<std::string> ids = flight.get_passengers();
				std::vector<Passenger> list;

				for (int i = 0; i < ids.size(); i++) {
					int index = find_passenger(ids[i]);

					if (index != -1) {
						list.push_back(passengers[index]);		
					}
				}
				print_passenger_list(list);
			}
		}
		else if (args[0] == "IsFlightFull") {
			if (args.size() < 2) {
				std::cout << "Not enough arguments for command `IsFlightFull`" << std::endl;
			}

			long flight_id = atol(args[1].c_str());
			bool full = is_flight_full(flight_id);

			if (full) {
				std::cout << "Flight `" << flight_id << "` is full." << std::endl;
			}
			else {
				std::cout << "Flight `" << flight_id << "` is not full." << std::endl;
			}
		}
		else if (args[0] == "PrintAssistancePassengers") {
			if (args.size() < 3) {
				std::cout << "Not enough arguments for command `PrintAssistancePassengers`" << std::endl;
			}

			long flight_id = atol(args[1].c_str());
			int index = find_flight(flight_id);

			if (index == -1) {
				std::cout << "Flight `" << flight_id << "` does not exist." << std::endl;
			}
			else {
				Flight flight = flights[index];
				std::vector<std::string> ids = flight.get_passengers();
				std::vector<Passenger> list;

				for (int i = 0; i < ids.size(); i++) {
					int index = find_passenger(ids[i]);

					if (index != -1) {
						Preference preference = passengers[index].get_preference();
						if (preference.get_assistance() == args[2] || preference.get_meal() == args[2]) {
							list.push_back(passengers[index]);		
						}
					}
				}

				if (list.size() == 0) {
					std::cout << "No passengers on Flight `" << flight_id << "` have a preference of type `" << args[2] << "`." << std::endl;
				}
				else {
					print_passenger_list(list);
				}
			}
		}
	}
}

void FlightReservation::print_flight_list(const std::vector<Flight>& list) const {
	std::cout << std::left
	   << BOLD 
	   << std::setw(6) << "Id"
	   << std::setw(10) << "Departure"
	   << std::setw(10) << "Arrival"
	   << std::setw(15) << "Date"
	   << std::setw(10) << "Time"
	   << std::setw(9) << "Duration"
	   << std::setw(8) << "Capacity"
	   << UNBOLD 
	   << std::endl;

	for (int i = 0; i < list.size(); i++) {
		std::cout << list[i] << std::endl;
	}
}

void FlightReservation::print_passenger_list(const std::vector<Passenger>& list) const {
	std::cout << std::left
		<< BOLD 
		<< std::setw(8) << "Id"
		<< std::setw(12) << "First"
		<< std::setw(12) << "Last"
		<< std::setw(8) << "Gender"
		<< std::setw(5) << "Age"
		<< std::setw(15) << "Assistance"
		<< std::setw(15) << "Meal"
		<< UNBOLD
		<< std::endl;

	for (int i = 0; i < list.size(); i++) {
		std::cout << list[i] << std::endl;
	}
}

