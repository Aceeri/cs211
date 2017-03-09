#ifndef INSTRUCTOR_H_
#define INSTRUCTOR_H_

#include <string>
#include <vector>
#include "Course.h"
using namespace std;

class Instructor {
private:
	long employee_id;
	string office;
	vector<Course> courses;
public:
	Instructor();
	Instructor(string, string, vector<Course>);

	long get_employee_id() const;
	string get_office_id() const;
	vector<Course> get_courses() const;

	void display() const;
};

#endif
