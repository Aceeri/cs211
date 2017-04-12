
#include "PackageInventory.h"
#include "Package.h"
#include "ExpressPackage.h"
#include "PriorityPackage.h"
#include "InternationalPackage.h"

#include <iostream>
#include <fstream>

PackageInventory::PackageInventory() { }

void PackageInventory::create_package(const Package& package) {
	packages.push_back(Package(package));
}

void PackageInventory::create_exprses(const ExpressPackage& package) {
	packages.push_back(ExpressPackage(package));
}

void PackageInventory::create_priority(const PriorityPackage& package) {
	packages.push_back(PriorityPackage(package));
}

void PackageInventory::create_international(const InternationalPackage& package) {
	packages.push_back(InternationalPackage(package));
}

void PackageInventory::print_packages() const {
	for (auto package : this->packages) {
		package.print();
	}
}

void PackageInventory::print_priority() const {
	for (auto package : this->priority_packages) {
		package.print();
	}
}

void PackageInventory::print_express() const {
	for (auto package : this->express_packages) {
		package.print();
	}
}

void PackageInventory::print_international() const {
	for (auto package : this->international_packages) {
		package.print();
	}
}

void PackageInventory::print_shipped_on_year(int year) const {
	
}

void PackageInventory::calculate_total_cost() const {

}

void PackageInventory::process_transaction_file(std::string file_name) {
	std::ifstream file;
	file.open(file_name.c_str());
	
}

