
#include <iostream>
#include "Course.h"
using namespace std;

Course::Course(string course_id, string course_name, string course_credits) {
	id = atoi(course_id.c_str());
	name = course_name;
	credits = atoi(course_credits.c_str());
}

long Course::get_id() const {
	return id;
}

string Course::get_name() const {
	return name;
}

int Course::get_credits() const {
	return credits;
}

void Course::display() const {
	cout << "Course: { id: " << get_id() << ", name: " << get_name() << ", credits: " << get_credits() << " }";
}
