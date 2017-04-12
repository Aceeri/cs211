
#include <iostream>
#include <stdlib.h>

#include "Package.h"

Package::Package() {
	sender = Information();
	recipient = Information();

	label = "Unknown";
	date = "01/01/0000";
	weight = 0.0;
	cost = 0.0;
	insurance = Insurance::None;
}

Package::Package(Information sender, Information recipient, std::string label, std::string date, double weight, double cost, Insurance insurance) {
	this->sender = sender;
	this->recipient = recipient;
	this->label = label;
	this->date = date;

	if (weight < 0) {
		std::cout << "Negative weight value: " << weight << std::endl;
		weight = 0.0;
	}

	if (cost < 0) {
		std::cout << "Negative cost value: " << cost << std::endl;
		cost = 0.0;
	}

	this->weight = weight;
	this->cost = cost;
	this->insurance = insurance;
}

void Package::print_information(const Information& information) const {
	std::cout << "Information {"
		  << " name: " << information.name
		  << ", address: " << information.address
		  << ", city: " << information.city
		  << ", state: " << information.state
		  << ", zip_code: " << information.zip_code
		  << " }";
}

void Package::print_insurance(const Insurance& insurance) const {
	std::string insurance_type;
	switch (insurance) {
	case Insurance::UpTo100:
		insurance_type = "UpTo100";
		break;
	case Insurance::UpTo1000:
		insurance_type = "UpTo1000";
		break;
	case Insurance::UpTo5000:
		insurance_type = "UpTo5000";
		break;
	default:
		insurance_type = "None";
		break;
	}
	std::cout << "Insurance::" << insurance_type;
}

void Package::print() const {
	std::cout << "Package {"
		  << " sender: ";
	print_information(this->sender);
	std::cout << ", recipient: ";
	print_information(this->recipient);
	std::cout << ", label: " << this->label
		  << ", date: " << this->date
		  << ", weight: " << this->weight
		  << ", cost: " << this->cost
		  << ", insurance: ";
	print_insurance(this->insurance);
	std::cout << " }";
}

int Package::get_year() const {
	return atoi(this->date.substr(6, 4).c_str());
}
