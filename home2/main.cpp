
#include <iostream>
#include "FlightReservation.h"

int main() {
	FlightReservation reservation;
	reservation.process_transactions("transactions.txt");

	return 0;
}
