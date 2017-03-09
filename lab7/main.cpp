
#include <iostream>
#include "Student.h"
using namespace std;

int main() {
	Student student1;
	student1.print();

	Student student2("unknown", "PHYS", "graduate", 0);
	student2.get_data();
	set_tuition(student2);
	student2.print();

	return 0;
}
