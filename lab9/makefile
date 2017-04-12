
prof: AdjunctProf.o TenureTrackProf.o CompSciProfessor.o
	g++ main.cpp *.o -o prof
	make clean

AdjunctProf.o:
	g++ -c AdjunctProf.cpp

TenureTrackProf.o:
	g++ -c TenureTrackProf.cpp

CompSciProfessor.o:
	g++ -c CompSciProfessor.cpp

clean:
	rm *.o
