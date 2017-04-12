#ifndef EXPRESSPACKAGE_H_
#define EXPRESSPACKAGE_H_

#include "Package.h"

class ExpressPackage: public Package {
private:
	double fee; // fee per ounce
public:
	ExpressPackage();
	ExpressPackage(const Package& package, double fee);
	ExpressPackage(Information sender, Information recipient, std::string label, std::string date, double weight, double cost, Insurance insurance, double fee);
};

#endif
