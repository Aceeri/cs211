#ifndef FLIGHTRESERVATION_H_
#define FLIGHTRESERVATION_H_

#include <vector>
#include <map>
#include "Flight.h"
#include "Passenger.h"

class FlightReservation {
private:
	std::vector<Flight> flights;
	std::vector<Passenger> passengers;
	static bool failure;
	static bool success;
public:
	FlightReservation();
	FlightReservation(std::vector<Flight>, std::vector<Passenger>);

	// Finds and returns the index of the passenger with the given id. -1 signifies no passenger with id.
	int find_passenger(std::string passenger_id) const;
	// Finds and returns the index of the flight with the given id. -1 signifies no flight with id.
	int find_flight(long flight_id) const;

	// Adds a person to the flight registry.
	bool create_passenger(std::string id, std::string first, std::string last, char gender, int age, std::string assistance, std::string meal);
	// Creates a new flight for a destination.
	bool create_flight(std::string depart, std::string arrival, std::string date, std::string time, float duration, int cap);
	// Adds a passenger to a flight.
	bool add_passenger(long flight_id, std::string passenger_id);
	// Removes a passenger from a flight.
	bool remove_passenger(long flight_id, std::string passenger_id);
	// Prints all passengers.
	void print_passengers() const;
	// Prints all flights.
	void print_flights() const;

	// Returns whether the flight was full or not.
	bool is_flight_full(long id) const;
	// Takes in a file name and processes the commands in the file.
	bool process_transactions(std::string);

	// Takes a vector of passengers and prints them out in a table.
	void print_passenger_list(const std::vector<Passenger>& passengers) const;
	// Takes a vector of flights and pritns them out in a table.
	void print_flight_list(const std::vector<Flight>& flights) const;
};

#endif
