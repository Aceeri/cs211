
#include <iostream>
#include "Student.h"
using namespace std;

int Student::total_students = 0;
long Student::next_id = 10000;

void set_tuition(Student& student) {
	if (student.classification == "graduate") {
		student.tuition = student.units * 1000;
	}
	else if (student.classification == "undergraduate") {
		student.tuition = student.units * 700;
	}
}

Student::Student() : student_id(Student::next_id++) {
	name = "Unknown";
	major = "CS";
	classification = "undergraduate";
	units = 12;
	tuition = 0;

	Student::total_students += 1;
}

Student::Student(string s_name, string s_major, string s_classification, int s_units) : student_id(Student::next_id++) {
	name = s_name;
	major = s_major;
	classification = s_classification;
	units = s_units;
	tuition = 0;

	Student::total_students += 1;
}

Student::~Student() {
	Student::total_students -= 1;
}

void Student::print() const {
	cout << "Student {\n\tname: " << name
		 << ",\n\tmajor: " << major
		 << ",\n\tclassification: " << classification
		 << ",\n\tunits: " << units
		 << ",\n\ttuition: " << tuition
		 << ",\n\tstudent_id: " << student_id
		 << ",\n\ttotal_students: " << Student::total_students
		 << ",\n\tnext_id: " << Student::next_id
		 << "\n}" << endl;
}

void Student::get_data() {
	cout << "Name: ";
	getline(cin, name);

	cout << "Major: ";
	cin >> major;

	bool valid = false;
	while (!valid) {
		cout << "Classification: ";
		cin >> classification;

		if (classification != "graduate" && classification != "undergraduate") {
			cout << "Invalid classification" << endl;
		}
		else {
			valid = true;
		}
	}

	cout << "Units: ";
	cin >> units;
}
