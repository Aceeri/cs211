
CC=g++ -std=c++11
include=./include
src=./src

pack: cpp
	$(CC) -I $(include) main.cpp *.o -o pack
	make clean

cpp:
	$(CC) -I $(include) -c $(src)/*.cpp

clean:
	rm *.o
