
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

// Load the data into the registry.
void load_registry(vector<string>& registry, const string& file_name);
// Save the registry to a file.
void save_registry(const vector<string>& registry, const string& file_name);
// Parse the transaction file to add/remove/sort/etc. from the registry.
void parse_transactions(vector<string>& registry, const string& file_name);
// Prints out the registry. Width defines how wide each column will be.
void print_registry(const vector<string>& registry, const int width);
// adds an entry to the registry, returns whether it was successfully added.
bool add_record(vector<string>& registry, const string& first, const string& last, const string& number);
// Removes an entry from the registry, returns whether the entry existed.
bool delete_record(vector<string>& registry, const string& key);
// Updates an entry with new information.
bool update_record(vector<string>& registry, const string& from, const string& to);
// Sorts registry by last name, if last names are same then sorts by first name.
void sort_registry(vector<string>& registry);
// Finds entries that contain the key.
vector<int> find_key(const vector<string>& registry, const string& key);
// Splits a string into words by spaces. e.g. "Some string  of words" will become ["Some", "string", "of", "words"].
vector<string> split(const string& str);
// Utility function for outputting expected arguments for a command.
void expect(const string& command, const string& expect);

// How long the separator lines should be.
const static int SEPARATOR = 50;
// How wide the registry print columns should be. (Should be at least 13 so the phone number can fit properly)
const static int COLUMN = 13;

int main() {
	vector<string> registry;
	string file_name;
	cout << "Enter the transaction file: ";
	cin >> file_name;

	// Load in the data from the file.
	load_registry(registry, "data.txt");

	// Parse the commads from the transactions file.
	parse_transactions(registry, file_name);

	return 0;
}

void load_registry(vector<string>& registry, const string& file_name) {
	ifstream input_file;
	input_file.open(file_name.c_str());

	string entry;
	while (getline(input_file, entry)) {
		// Verify that first name, last name, and phone number exist and are separated.
		if (split(entry).size() == 3) {
			registry.push_back(entry);
		}
	}
}

void save_registry(const vector<string>& registry, const string& file_name) {
	ofstream output_file;
	output_file.open(file_name.c_str());

	for (int i = 0; i < registry.size(); i++) {
		output_file << registry[i] << endl;
	}
}

void parse_transactions(vector<string>& registry, const string& file_name) {
	ifstream transactions;
	transactions.open(file_name.c_str());

	string command;
	while (getline(transactions, command)) {
		// Separate the commands by a dashed line.
		for (int i = 0; i < SEPARATOR; i++) {
			cout << "-";
		}
		cout << endl;

		vector<string> args = split(command);
		if (args.size() < 1) { // If there was a blank line.
			continue;
		}

		// Check which command the transaction file wants to execute.
		if (args[0] == "display") {
			print_registry(registry, COLUMN);
		}
		else if (args[0] == "add") {
			if (args.size() < 4) {
				expect("add", "firstname lastname phonenumber");
				continue;
			}
			
			cout << "Adding `" << args[1] << " " << args[2] << " " << args[3] << "` to the registry." << endl;
			bool success = add_record(registry, args[1], args[2], args[3]);
			if (success) {
				cout << "The entry was successfully added." << endl;
			}
			else {
				cout << "Phone number `" << args[3] << "` already exists in registry." << endl;
			}
		}
		else if (args[0] == "delete") {
			if (args.size() < 2) {
				expect("delete", "key");
				continue;
			}

			// get the key from the arguments, minus the `delete ` command portion.
			string key = command.substr(7, command.size() - 7);
			cout << "Deleting `" << key << "` entries from the registry." << endl;
			bool success = delete_record(registry, key);
			if (!success) {
				cout << "No entries were found for `" << key << "`." << endl;
			}
		}
		else if (args[0] == "update") {
			if (args.size() < 3) {
				expect("update", "from to");
				continue;
			}
			
			cout << "Updating phone number `" << args[1] << "` to `" << args[2] << "`" << endl;
			bool success = update_record(registry, args[1], args[2]);
			if (success) {
				cout << "Successfully updated the phone number" << endl;
			}
			else {
				cout << "No entries were found containg that phone number." << endl;
			}
		}
		else if (args[0] == "search") {
			if (args.size() < 2) {
				expect("search", "key");
				continue;
			}

			// Get the portion of the command that is the key minus the `search `.
			string key = command.substr(7, command.size() - 7);
			cout << "Searching the registry for `" << key << "`." << endl;
			vector<int> found = find_key(registry, key);

			if (found.size() > 0) {
				for (int i = 0; i < found.size(); i++) {
					cout << "`" << registry[found[i]] << "` was found in the registry." << endl;
				}
			}
			else {
				cout << "No entries for `" << key << "` were found." << endl;
			}
		}
		else if (args[0] == "sort") {
			cout << "Sorting the registry." << endl;
			sort_registry(registry);
		}
		else if (args[0] == "save") {
			string file_name = "output.txt"; // Defaults the file to `output.txt`.
			if (args.size() > 1) { // If the command gives a destination file.
				file_name = args[1];
			}
			save_registry(registry, file_name);
			cout << "Saved registry to `" << file_name << "`." << endl;
		}
	}
}

// Print out columns
void columns(const vector<string>& columns, const int width) {
	for (int i = 0; i < columns.size(); i++) {
		cout << left << setw(width) << ("|" + columns[i]);
		if (i == columns.size() - 1) {
			cout << right << "|" << endl;
		}
	}
}

void print_registry(const vector<string>& registry, const int width) {
	columns({"First name", "Last name", "Phone number"}, width);
	string dash_width;
	for (int i = 0; i < width * 3 + 1; i++) {
		if (i % width == 0) {
			cout << "|";
		}
		else {
			cout << "-";
		}
	}
	cout << endl;

	for (int i = 0; i < registry.size(); i++) {
		vector<string> entry = split(registry[i]);
		columns(entry, width);
	}
}

bool add_record(vector<string>& registry, const string& first, const string& last, const string& number) {
	for (int i = 0; i < registry.size(); i++) {
		vector<string> arguments = split(registry[i]);
		if (arguments.size() == 3 && arguments[2] == number) {
			return false;
		}
	}

	string concatenated = first + " " + last + " " + number;
	registry.push_back(concatenated);

	return true;
}

bool delete_record(vector<string>& registry, const string& key) {
	vector<int> found = find_key(registry, key);
	
	for (int i = 0; i < found.size(); i++) {
		cout << "Deleting `" << registry[found[i]] << "` from registry." << endl;
		registry.erase(registry.begin() + found[i] - i);
	}
	
	return found.size() > 0;
}

bool update_record(vector<string>& registry, const string& from, const string& to) {
	for (int i = 0; i < registry.size(); i++) {
		vector<string> entry = split(registry[i]);
		if (entry[2] == from) { // Check if the entries phone number is the same as the one to convert from.
			string concatenated = entry[0] + " " + entry[1] + " " + to; // Append the new number.
			registry[i] = concatenated;
			return true; // Since there can only be one phone number in the registry, early return.
		}
	}
}

// Selection sort
void sort_registry(vector<string>& registry) {
	for (int i = 0; i < registry.size(); i++) { // Start index.
		int min = i;
		vector<string> min_entry = split(registry[i]);
		for (int j = i + 1; j < registry.size(); j++) {
			vector<string> entry = split(registry[j]);

			if (entry[1] == min_entry[1]) { // If the last names are the same.
				if (entry[0] < min_entry[0]) { // Compare the first names.
					min = j;
					min_entry = entry;
				}
			}
			else if (entry[1] < min_entry[1]) { // Compare the last names.
				min = j;
				min_entry = entry;
			}
		}

		if (min != i) { // If the minimum number is not in the correct spot already, then swap.
			string temp = registry[i];
			registry[i] = registry[min];
			registry[min] = temp;
		}
	}
}

vector<int> find_key(const vector<string>& registry, const string& key) {
	vector<int> indices;
	for (int i = 0; i < registry.size(); i++) {
		if (registry[i].find(key, 0) != string::npos) { // If the search index is not at the end.
			indices.push_back(i);
		}
	}
	return indices;
}

vector<string> split(const string& str) {
	vector<string> words;
	int start = 0; // sub string start position, negative means it is currently whitespace
	
	for (int i = 0; i < str.size(); i++) {
		char c = str.at(i);
		
		if (c == ' ') {
			if (start >= 0) { // The start index exists so this is the end of a word.
				string word = str.substr(start, i - start);
				words.push_back(word);
			}

			start = -1;
		}
		else if (start < 0) { // If the word hasn't already been started, so indicate the start.
			start = i;
		}
	}

	if (start >= 0) { // If a word exists at the end.
		string word = str.substr(start, str.size() - start);
		words.push_back(word);
	}

	return words;
}

void expect(const string& command, const string& expect) {
	cout << "Incorrect number of arguments for `" << command << "`" << endl;
	cout << "Expected: `" << command << " " << expect << "`" << endl;
}
