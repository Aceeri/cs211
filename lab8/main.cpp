
#include <iostream>

#include "Date.h"

int main() {
	Date d1(2, 2, 2006);
	Date d2(11, 10, 2003);
	
	std::cout << "Difference: " << std::endl;
	std::cout << "d1: " << d1 << std::endl;
	std::cout << "d2: " << d2 << std::endl;
	std::cout << (d1 - d2) << std::endl;

	std::cout << "Increment: " << std::endl;
	std::cout << "before d1: " << d1 << std::endl;
	++d1;
	std::cout << "after d1: " << d1 << std::endl;

	std::cout << "Wrapping next year: " << std::endl;
	d1.set(12, 31, d1.get_year());
	std::cout << "before d1: " << d1 << std::endl;
	++d1;
	std::cout << "after d1: " << d1 << std::endl;

	std::cout << "Decrement: " << std::endl;
	d1.set(7, 10, 2003);
	std::cout << "before d1: " << d1 << std::endl;
	d1--;
	std::cout << "after d1: " << d1 << std::endl;

	std::cout << "Wrapping last year: " << std::endl;
	d1.set(1, 1, 2004);
	std::cout << "before d1: " << d1 << std::endl;
	d1--;
	std::cout << "after d1: " << d1 << std::endl;

	std::cin >> d1;
	std::cout << "d1: " << d1 << std::endl;

	return 0;
}
