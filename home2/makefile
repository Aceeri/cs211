
CC := g++

flight: FlightReservation.o Flight.o Passenger.o Person.o Preference.o
	$(CC) main.cpp FlightReservation.o Flight.o Passenger.o Person.o Preference.o -o flight
	make clean

FlightReservation.o:
	$(CC) -c FlightReservation.cpp

Flight.o:
	$(CC) -c Flight.cpp

Passenger.o:
	$(CC) -c Passenger.cpp

Person.o:
	$(CC) -c Person.cpp

Preference.o:
	$(CC) -c Preference.cpp

.PHONY: clean

clean:
	rm *.o

