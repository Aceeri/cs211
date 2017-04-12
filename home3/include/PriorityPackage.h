#ifndef PRIORITYPACKAGE_H_
#define PRIORITYPACKAGE_H_

#include "Package.h"

enum PriorityType {
	Letter,
	Envelope,
	Box,
};

class PriorityPackage: public Package {
private:
	PriorityType type;
	double width;
	double length;
	double height;
public:
	PriorityPackage();
};

#endif
