#ifndef FLIGHT_H_
#define FLIGHT_H_

#include <string>
#include <vector>

class Flight {
private:
	const long id;
	std::string departure_airport;
	std::string arrival_airport;
	std::string date;
	std::string time;
	float duration;
	const int capacity;
	std::vector<std::string> passengers;

	static long next_id;
public:
	Flight(std::string depart = "Unknown", std::string arrival = "Unknown", std::string date = "Unknown", std::string time = "Unknown", float duration = 0.0, int cap = 0, std::vector<std::string> passengers = std::vector<std::string>());

	// Adds a passenger id to the flight, returns false if there was a duplicate entry.
	bool add_passenger(std::string id);
	// Removes a passenger id if it exists, returns whether it existed.
	bool remove_passenger(std::string id);

	bool is_full() const;
	long get_id() const;
};

#endif
