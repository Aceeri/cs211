
#include "TenureTrackProf.h"
#include <iostream>

TenureTrackProf::TenureTrackProf() {
	rank = '?';
	years_experience = 0;
}

std::string TenureTrackProf::rank_name(char rank) const {
	switch (rank) {
		case 'A':
			return "Assistant";
		case 'S':
			return "Associate";
		case 'F':
			return "Full";
		default:
			return "Unknown";
	}
}

void TenureTrackProf::print() const {
	std::cout << "TenureTrackProf { name: "
			  << get_name()
			  << ", email: "
			  << get_email()
			  << ", id: "
			  << get_id()
			  << ", rank: "
			  << rank_name(get_rank())
			  << ", years_experience: "
			  << get_years_experience()
			  << " }"
			  << std::endl;
}

float TenureTrackProf::find_salary() const {
	switch (rank) {
		case 'A':
			return 65000 + (1500 * years_experience);
		case 'S':
			return 80000 + (1500 * years_experience);
		case 'F':
			return 90000 + (1500 * years_experience);
		default:
			return 0.0f;
	}
}

char TenureTrackProf::get_rank() const {
	return rank;
}

int TenureTrackProf::get_years_experience() const {
	return years_experience;
}

void TenureTrackProf::set_rank(char rank) {
	this->rank = rank;
}

void TenureTrackProf::set_years_experience(int years) {
	this->years_experience = years;
}
