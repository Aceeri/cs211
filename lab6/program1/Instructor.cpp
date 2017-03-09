
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Instructor.h"
using namespace std;

Instructor::Instructor() { }

Instructor::Instructor(string employee, string office_id, vector<Course> course_list) {
	employee_id = stol(employee);
	office = office_id;
	courses = course_list;
}

long Instructor::get_employee_id() const {
	return employee_id;
}

string Instructor::get_office_id() const {
	return office;
}

vector<Course> Instructor::get_courses() const {
	return courses;
}

void Instructor::display() const {
	cout << "Instructor { employee_id: " << get_employee_id() << ", office_id: " << get_office_id() << ", courses: ";
	
	vector<Course> courses = get_courses();
	for (int i = 0; i < courses.size(); i++) {
		courses[i].display();
		cout << ", ";
	}
	cout << "}";
}
