#ifndef PERSON_H_
#define PERSON_H_

#include <string>
#include <iostream>

class Person {
private:
	std::string id;
	std::string first;
	std::string last;
	char gender;
	int age;
public:
	Person(std::string = "Unknown", std::string = "Unknown", std::string = "Unknown", char = '?', int = 0);

	std::string get_id() const;
	std::string get_first() const;
	std::string get_last() const;
	char get_gender() const;
	int get_age() const;

	friend std::ostream& operator<<(std::ostream& os, const Person& person);
};

#endif
