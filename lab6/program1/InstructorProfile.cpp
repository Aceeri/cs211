
#include <iostream>
#include "InstructorProfile.h"
using namespace std;

InstructorProfile::InstructorProfile() { }

InstructorProfile::InstructorProfile(const vector<string>& entry) {
	personal = Person(entry[0], entry[1], entry[2], entry[3]);
	
	vector<Course> courses;
	for (int i = 6; i < entry.size(); i += 3) {
		courses.push_back(Course(entry[i], entry[i + 1], entry[i + 2]));
	}

	instructor = Instructor(entry[4], entry[5], courses);
}

Person InstructorProfile::get_person() const {
	return personal;
}

Instructor InstructorProfile::get_instructor() const {
	return instructor;
}

void InstructorProfile::display() const {
	cout << "InstructorProfile { person: ";
	get_person().display();
	cout << ", instructor: ";
	get_instructor().display();
	cout << "}";
}
