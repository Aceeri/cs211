
#include <iostream>

#include "PackageInventory.h"

int main() {
	auto inventory = PackageInventory();
	inventory.process_transaction_file("TransactionFile.txt");
	
	auto package = Package();
	std::cout << package.get_year() << std::endl;
	inventory.create_package(package);
	inventory.print_packages();

	return 0;
}
