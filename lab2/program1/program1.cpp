
#include <iostream>
#include <fstream>
#include <vector>

std::vector<int> read_file(const std::string name);
void print_vector(const std::vector<int> vector);
void sort_vector(std::vector<int>& vector);
bool contains(const std::vector<int> vector, const int key);

int main() {
	std::vector<int> data = read_file("data.txt");
	print_vector(data);
	sort_vector(data);
	print_vector(data);

	int input = 0;
	while (std::cin >> input) {
		std::cout << contains(data, input) << std::endl;

	}
	
	return 0;
}

std::vector<int> read_file(std::string name) {
	std::fstream input_file;
	std::vector<int> data;

	input_file.open("data.txt");

	int input = 0;
	while (input_file >> input) {
		data.push_back(input);
	}

	return data;
}

void print_vector(std::vector<int> vector) {
	std::cout << "[";
	for (int i = 0; i < vector.size(); i++) {
		std::cout << vector[i];

		if (i < vector.size() - 1) {
			std::cout << " ";
		}
	}
	std::cout << "]" << std::endl;
}

void sort_vector(std::vector<int>& vector) {
	bool flagged = true;
	while (flagged) {
		flagged = false;
		for (int i = 0; i < vector.size() - 1; i++) {
			if (vector[i] > vector[i + 1]) {
				flagged = true;
				int temp = vector[i]; // swap
				vector[i] = vector[i + 1];
				vector[i + 1] = temp;
			}
		}
	}
}

/*
bool contains(std::vector<int> vector, int key) {
	int size = vector.size();
	int offset = 0;
	while (size > 0) {
		int half = size / 2;
		int index = half + offset;
		std::cout << "half: " << index << std::endl;
		
		if (vector[index] == key) {
			return true;
		}
		else if (vector[index] > key) {
			size /= 2;
		}
		else if (vector[index] < key) {
			offset = half;
			size /= 2;
		}
	}
	return false;
}
*/

bool contains(std::vector<int> vector, int key) { 
	for (int i = 0; i < vector.size(); i++) {
		if (vector[i] == key) {
			return true;
		}
	}
	return false;
}
