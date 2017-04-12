
#include "CompSciProfessor.h"

CompSciProfessor::CompSciProfessor() {
	name = "Unknown";
	email = "Unknown";
	id = 0;
}

std::string CompSciProfessor::get_name() const {
	return name;
}

std::string CompSciProfessor::get_email() const {
	return email;
}

long CompSciProfessor::get_id() const {
	return id;
}

void CompSciProfessor::set_name(std::string name) {
	this->name = name;
}

void CompSciProfessor::set_email(std::string email) {
	this->email = email;
}

void CompSciProfessor::set_id(long id) {
	this->id = id;
}
