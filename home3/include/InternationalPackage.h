#ifndef INTERNATIONALPACKAGE_H_
#define INTERNATIONALPACKAGE_H_

#include "Package.h"

enum Country {
	Canada,
	Mexico,
	France,
	England,
	China,
	India,
};

class InternationalPackage: public Package {
private:
	Country country;	
public:
	InternationalPackage();	
	InternationalPackage(Information sender, Information recipient, std::string label, std::string date, double weight, double cost, Insurance insurance, Country country);
};

#endif
