
#include "InternationalPackage.h"

InternationalPackage::InternationalPackage() {
	country = Country::Canada;
}

InternationalPackage::InternationalPackage(Information sender, Information recipient, std::string label, std::string date, double weight, double cost, Insurance insurance, Country country): Package(sender, recipient, label, date, weight, cost, insurance) {
	this->country = country;
}

