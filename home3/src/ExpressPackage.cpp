
#include <iostream>

#include "ExpressPackage.h"

ExpressPackage::ExpressPackage() {
	fee = 0.0;
}

ExpressPackage::ExpressPackage(Information sender, Information recipient, std::string label, std::string date, double weight, double cost, Insurance insurance, double fee): Package(sender, recipient, label, date, weight, cost, insurance) {
	if (fee < 0.0) {
		std::cout << "Negative fee value: " << fee << std::endl;
		fee = 0.0;
	}
	this->fee = fee;
}
