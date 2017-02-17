
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	string input;
	while (cin >> input) {
		char first = input.at(0);
		input.erase(0, 1);
		input.push_back(first);
		input += "ay";
		cout << input << " ";
	}
	
	return 0;
}
