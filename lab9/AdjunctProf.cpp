
#include "AdjunctProf.h"
#include <iostream>

AdjunctProf::AdjunctProf() {
	degree = '?';
	assistant_count = 0;
	course_count = 0;
}

std::string AdjunctProf::degree_name(char degree) const {
	switch (degree) {
		case 'B':
			return "Bachelors";
		case 'M':
			return "Masters";
		case 'P':
			return "PhD";
		default:
			return "Unknown";
	}
}

void AdjunctProf::print() const {
	std::cout << "AdjunctProf { name: "
			  << get_name()
			  << ", email: "
			  << get_email()
			  << ", id: "
			  << get_id()
			  << ", degree: "
			  << degree_name(get_degree())
			  << ", assistant_count: "
			  << get_assistant_count()
			  << ", course_count: "
			  << get_course_count()
			  << " }"
			  << std::endl;
}

float AdjunctProf::find_salary() const {
	switch (degree) {
		case 'B':
			return assistant_count * 1500 + course_count * 3000;
		case 'M':
			return assistant_count * 2000 + course_count * 4000;
		case 'P':
			return assistant_count * 2500 + course_count * 5000;
		default:
			return 0.0f;
	}
}

char AdjunctProf::get_degree() const {
	return degree;
}

int AdjunctProf::get_assistant_count() const {
	return assistant_count;
}

int AdjunctProf::get_course_count() const {
	return course_count;
}

void AdjunctProf::set_degree(char degree) {
	this->degree = degree;
}

void AdjunctProf::set_assistant_count(int assistant_count) {
	this->assistant_count = assistant_count;
}

void AdjunctProf::set_course_count(int course_count) {
	this->course_count = course_count;
}
