
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void insert(std::vector<std::string>& transactions, const std::string& word, int index);
void print(const std::vector<std::string>& transactions);
void delete_transaction(std::vector<std::string>& transactions, int index);

int main() {
	std::vector<std::string> transactions;
	std::ifstream input_file;

	input_file.open("data.txt");

	std::string current_input;
	while (input_file >> current_input) {
		if (current_input == "Insert") {
			std::string word;
			int index;

			input_file >> word;
			input_file >> index;

			insert(transactions, word, index);
		}
		else if (current_input == "Print") {
			print(transactions);

		}
		else if (current_input == "Delete") {
			int index;
			input_file >> index;

			delete_transaction(transactions, index);
		}
	}

}

void insert(std::vector<std::string>& transactions, const std::string& word, int index) {
	if (index < 0 || index > transactions.size()) {
		std::cout << "Cannot insert at index: " << index << std::endl;
		return;
	}
	transactions.insert(transactions.begin() + index, word);
}

void print(const std::vector<std::string>& transactions) {
	std::cout << "[";
	for (int i = 0; i < transactions.size(); i++) {
		std::cout << transactions[i];

		if (i < transactions.size() - 1) {
			std::cout << ", ";
		}

	}
	std::cout << "]" << std::endl;
}

void delete_transaction(std::vector<std::string>& transactions, int index) {
	if (index < 0 || index > transactions.size() - 1) {
		std::cout << "Cannot delete at index: " << index << std::endl;
		return;
	}
	transactions.erase(transactions.begin() + index);
}
