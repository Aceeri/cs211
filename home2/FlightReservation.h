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

	bool create_passenger(std::string id, std::string first, std::string last, char gender, int age, std::string assistance, std::string meal);
	bool create_flight(std::string depart, std::string arrival, std::string date, std::string time, float duration, int cap);
	bool add_passenger(long flight_id, std::string passenger_id);
	bool remove_passenger(long flight_id, std::string passenger_id);
	//void print_assistance(int, std::string);
	void print_passengers() const;
	void print_flights() const;

	bool is_flight_full(long id) const;
	bool process_transactions(std::string);
};

#endif
