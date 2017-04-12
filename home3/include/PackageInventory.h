#ifndef PACKAGEINVENTORY_H_
#define PACKAGEINVENTORY_H_

#include <vector>
#include "Package.h"
#include "PriorityPackage.h"
#include "ExpressPackage.h"
#include "InternationalPackage.h"

class PackageInventory {
private:
	std::vector<Package> packages;
	std::vector<PriorityPackage> priority_packages;
	std::vector<ExpressPackage> express_packages;
	std::vector<InternationalPackage> international_packages;
public:
	PackageInventory();

	// Add new packages
	void create_package(const Package& package);
	void create_exprses(const ExpressPackage& package);
	void create_priority(const PriorityPackage& package);
	void create_international(const InternationalPackage& package);

	// Print details
	void print_packages() const;
	void print_priority() const;
	void print_express() const;
	void print_international() const;
	void print_shipped_on_year(int year) const;
	void calculate_total_cost() const;

	// Load in and read from file.
	void process_transaction_file(std::string file_name);
};

#endif
