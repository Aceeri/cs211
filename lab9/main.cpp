
#include <iostream>
#include "AdjunctProf.h"
#include "TenureTrackProf.h"

int main() {
	AdjunctProf adjunct;
	adjunct.set_name("Adam Smith");
	adjunct.set_id(12345);
	adjunct.set_email("asmith@csusm.edu");
	adjunct.set_degree('M');
	adjunct.set_course_count(1);
	adjunct.set_assistant_count(2);
	std::cout << "Adjunct Salary: " << adjunct.find_salary() << std::endl;
	adjunct.print();

	TenureTrackProf tenure;
	tenure.set_name("Jim Anderson");
	tenure.set_id(54321);
	tenure.set_email("janderson@csusm.edu");
	tenure.set_rank('S');
	tenure.set_years_experience(8);
	std::cout << "Tenure Salary: " << tenure.find_salary() << std::endl;
	tenure.print();
}
