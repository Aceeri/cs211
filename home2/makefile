
flight: FlightReservation.o Flight.o Passenger.o Person.o Preference.o
	g++ main.cpp FlightReservation.o Flight.o Passenger.o Person.o Preference.o -o flight
	make clean

FlightReservation.o:
	g++ -c FlightReservation.cpp

Flight.o:
	g++ -c Flight.cpp

Passenger.o:
	g++ -c Passenger.cpp

Person.o:
	g++ -c Person.cpp

Preference.o:
	g++ -c Preference.cpp

.PHONY: clean

clean:
	rm *.o

