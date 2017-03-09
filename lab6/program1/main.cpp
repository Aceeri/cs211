
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "InstructorProfile.h"
using namespace std;

// Split a string into words.
vector<string> split(const string& str);

int main() {
	ifstream file;
	vector<InstructorProfile> directory;
	string entry;

	file.open("directory");
	while (getline(file, entry)) {
		InstructorProfile instructor(split(entry));
		instructor.display();
		cout << endl;
		directory.push_back(instructor);
	}

	return 0;
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
