
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

int main() {
	const double TAX = 0.085;
	const double DISCOUNT = 0.35;

	ifstream input_file;
	ofstream output_file;
	int serial;
	double price;
	
	input_file.open("shoes.txt");
	output_file.open("shoeSale.txt");

	while (input_file >> serial && input_file >> price) {
		double sale_price = price * (1.0 - DISCOUNT);
		double final = sale_price + (sale_price * TAX);
		output_file << fixed << setprecision(2);
		output_file << serial << right << setw(10) << final << endl;
	}

	input_file.close();
	output_file.close();

	return 0;
}
