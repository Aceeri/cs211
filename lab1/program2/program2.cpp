
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

void process_row(const int grades[], int& minimum, int& maximum, double& average) {
	int sum = 0;
	minimum = 100;
	maximum = 0;
	for (int i = 0; i < 3; i++) {
		int grade = grades[i];
		sum += grade;

		if (grade < minimum) {
			minimum = grade;
		}

		if (grade > maximum) {
			maximum = grade;
		}
	}	

	average = double(sum) / 3.0;
}

double process_overall(double sum, int amount) {
	return sum / amount;
}

int main() {
	std::ifstream input_file;
	std::string name;
	int test1, test2, test3;

	input_file.open("input.txt");

	int width = 15;
	std::cout << std::left << std::fixed << std::setprecision(2);
	std::cout << std::setw(width) << "Name" << std::setw(width) << "Minimum" << std::setw(width) << "Maximum" << std::setw(width) << "Average" << std::endl;
	for (int i = 0; i <= width * 4; i++) {
		std::cout << '-';
	}
	std::cout << std::endl;

	double sum = 0.0;
	int amount = 0;
	while (input_file >> name >> test1 >> test2 >> test3) {
		int grades[3] = { test1, test2, test3 };
		int min, max;
		double average;
		process_row(grades, min, max, average);
		sum += average;
		amount++;
		
		std::cout << std::setw(width) << name << std::setw(width) << min << std::setw(width) << max << std::setw(width) << average << std::endl;
	}

	for (int i = 0; i <= width * 4; i++) {
		std::cout << '-';
	}

	std::cout << std::endl;
	double overall = process_overall(sum, amount);

	std::cout << "Overall Average: " << overall << std::endl;

	return 0;
}
