
#include <iostream>

int multiply(int, int);
bool is_member(int[], int, int);
bool is_palindrome(std::string word, int index, int right, int left);

int main() {
	std::cout << "multiply: " << multiply(20, 4) << std::endl;

	int numbers[10] = { 2, 4, 6, 8, 10, 12, 14, 16, 18, 20 };

	for (int x = 0; x <= 20; x++) {
		if (is_member(numbers, x, 10)) {
			std::cout << x << " is found in the array.\n";
		}
		else {
			std::cout << x << " is not found in the array.\n";
		}
	}

	std::string sentences[5];
	sentences[0] = "Able was I, ere I saw Elba";
	sentences[1] = "A man, a plan, a canal, Panama";
	sentences[2] = "Desserts, I stressed";
	sentences[3] = "Kayak";
	sentences[4] = "Not a palindrome";

	for (int i = 0; i < 5; i++) {
		if (is_palindrome(sentences[i], 0, 0, 0)) {
			std::cout << sentences[i] << ": palindrome" << std::endl;
		}
		else {
			std::cout << sentences[i] << ": not a palindrome" << std::endl;
		}
	}

	return 0;
}

int multiply(int x, int y) {
	if (x > 1) {
		return multiply(x - 1, y) + y;
	}
	return y;
}

bool is_member(int numbers[], int key, int index) {
	if (numbers[index] == key) {
		return true;
	}
	else if (index == 0) {
		return false;
	}
	return is_member(numbers, key, index - 1);
}

char concatenate(char character) {
	if (character >= 97 && character <= 122) {
		(char) ( (int) character - 32);
	}
}

bool is_palindrome(std::string word, int index, int right, int left) {
	char lower = concatenate(word[index + left]);
	char higher = concatenate(word[word.length() - index + right - 1]);

	if (lower < 60 || lower > 90) {
		return is_palindrome(word, index, right, left + 1);
	}
	else if (higher < 60 || higher > 90) {
		return is_palindrome(word, index, right + 1, left);
	}
	else {
		if (lower != higher) {
			return false;
		}

		if (index == word.length() / 2) {
			return true;
		}

		return true;
	}
}

