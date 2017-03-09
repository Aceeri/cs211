#ifndef INSTRUCTORPROFILE_H_
#define INSTRUCTORPROFILE_H_

#include <string>
#include <vector>
#include "Person.h"
#include "Instructor.h"
using namespace std;

class InstructorProfile {
private:
	Person personal;
	Instructor instructor;
public:
	InstructorProfile();
	InstructorProfile(const vector<string>&);

	Person get_person() const;
	Instructor get_instructor() const;

	void display() const;
};

#endif
