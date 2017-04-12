#ifndef PACKAGE_H_
#define PACKAGE_H_

#include <string>

struct Information {
	std::string name = "Unknown";
	std::string address = "Unknown";
	std::string city = "Unknown";
	std::string state = "Unknown";
	unsigned long zip_code = 0;
};

enum Insurance {
	None,
	UpTo100,
	UpTo1000,
	UpTo5000,
};

class Package {
private:
	Information sender;
	Information recipient;
	std::string label;
	std::string date;
	double weight;
	double cost; // per ounces
	Insurance insurance;
public:
	Package();
	Package(Information sender, Information recipient, std::string label, std::string date, double weight, double cost, Insurance insurance);
};

#endif
