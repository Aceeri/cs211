#ifndef FLIGHT_H_
#define FLIGHT_H_

#include <iostream>
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
	Flight();
	Flight(std::string depart, std::string arrival, std::string date, std::string time, float duration, int cap, std::vector<std::string> passengers = std::vector<std::string>());
	Flight(const Flight&);

	// Adds a passenger id to the flight, returns false if there was a duplicate entry.
	bool add_passenger(std::string id);
	// Removes a passenger id if it exists, returns whether it existed.
	bool remove_passenger(std::string id);
	// Returns whether the flight was full or not.
	bool is_full() const;

	// Getters to members
	long get_id() const;
	std::string get_departure() const;
	std::string get_arrival() const;
	std::string get_date() const;
	std::string get_time() const;
	float get_duration() const;
	int get_capacity() const;
	std::vector<std::string> get_passengers() const;

	// Printing of object.
	friend std::ostream& operator<<(std::ostream& os, const Flight& flight);
	Flight& operator=(const Flight&);
};

#endif
