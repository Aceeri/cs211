
#include <iostream>

#include "Package.h"
#include "ExpressPackage.h"
#include "PriorityPackage.h"
#include "InternationalPackage.h"

int main() {
	auto package = Package(Information(), Information(), "Something", "01/01/1970", -5.0, -1.0, Insurance::None);

	auto express = ExpressPackage(Information(), Information(), "Something", "02/02/2017", 10.0, 5.0, Insurance::None, -5.0);

	return 0;
}
