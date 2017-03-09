
#include <iostream>

#include "Date.h"

int main() {
	Date d1(3, 10, 2014);
	Date d2(1, 18, 2014);
	std::cout << d1 << std::endl;
	std::cout << d2 << std::endl;
	std::cout << (d1 - d2) << std::endl;

	return 0;
}
