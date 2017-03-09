#ifndef PERSON_H_
#define PERSON_H_

#include <string>
using namespace std;

class Person {
private:
	string first_name;
	string last_name;
	char gender;
	long ssn;
public:
	Person();
	Person(string, string, string, string);

	string get_first() const;
	string get_last() const;
	char get_gender() const;
	long get_ssn() const;

	void display() const;
};

#endif
