
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

int main() {
	const string MONTHS[12] = {
		"January", "February", "March",
		"April", "May", "June", "July",
		"August", "September", "October",
		"November", "December",
	};

	std::string input;
	while (cin >> input) {
		int index = atoi(input.substr(0, 2).c_str()) - 1;
		string month = MONTHS[index];
		int day = atoi(input.substr(3, 2).c_str());
		string year = input.substr(6, 4);
		cout << month << " " << day << ", " << year << endl;
	}
	return 0;
}
