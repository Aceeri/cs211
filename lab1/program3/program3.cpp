
#include <iostream>
#include <iomanip>
#include <fstream>

void read_array(int data[]) {
	std::ifstream input_file;
	input_file.open("data.txt");

	int integer;
	int counter = 0;
	while (input_file >> integer) {
		data[counter] = integer;
		counter++;
	}

	input_file.close();
}

void reverse_array(const int data[], int reversed[], const int length) {
	for (int i = 0; i < length; i++) {
		reversed[length - 1 - i] = data[i];
	}
}

void print_array(const int array[], const int length) {
	std::cout << "[";
	for (int i = 0; i < length; i++) {
		std::cout << array[i];
		
		if (i < length - 1) {
			std::cout << " ";
		}
	}
	std::cout << "]" << std::endl;
}

int find_range(const int array[], const int length, const int min, const int max) {
	int found = 0;
	for (int i = 0; i < length; i++) {
		if (array[i] >= min && array[i] <= max) {
			found++;
		}
	}
	return found;
}

int find_div(const int array[], const int length, const int divisible) {
	int found = 0;
	for (int i = 0; i < length; i++) {
		if (array[i] % divisible == 0) {
			found++;
		}
	}
	return found;
}

double array_average(const int array[], const int length) {
	double sum = 0.0;
	for (int i = 0; i < length; i++) {
		sum += double(array[i]);
	}
	return sum / length;
}

int array_minimum(const int array[], const int length) {
	int min = 0x7FFFFFFF; // maximum value for a signed integer.
	for (int i = 0; i < length; i++) {
		if (array[i] < min) {
			min = array[i];
		}
	}
	return min;
}

bool key_search(const int array[], const int length, const int key) {
	for (int i = 0; i < length; i++) {
		if (array[i] == key) {
			return true;
		}
	}
	return false;
}

int main() {
	int data[10];
	read_array(data);

	std::cout << "data.txt: ";
	print_array(data, 10);

	int reversed[10];
	reverse_array(data, reversed, 10);

	std::cout << "reversed: ";
	print_array(reversed, 10);
	
	std::cout << "amount in range: " << find_range(data, 10, 80, 100) << std::endl;
	std::cout << "amount divisible: " << find_div(data, 10, 5) << std::endl;
	std::cout << "average: " << array_average(data, 10) << std::endl;
	std::cout << "minimum: " << array_minimum(data, 10) << std::endl;
	
	int input = 0;
	while (std::cout << "input key: " && std::cin >> input) {
		if (key_search(data, 10, input)) {
			std::cout << "contains key" << std::endl;
		}
		else {
			std::cout << "does not contain key" << std::endl;
		}
	}
}

