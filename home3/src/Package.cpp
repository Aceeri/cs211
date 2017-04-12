
#include <iostream>

#include "Package.h"

Package::Package() {
	sender = Information();
	recipient = Information();

	label = "Unknown";
	date = "Unknown";
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
