#ifndef STUDENT_H_
#define STUDENT_H_

#include <string>
using namespace std;

class Student {
	friend void set_tuition(Student&);
private:
	string name;
	const long student_id;
	string major;
	string classification;
	int units;
	float tuition;
	static int total_students;
	static long next_id;
public:
	Student();
	Student(string s_name, string s_major, string s_class, int s_units);
	~Student();

	void print() const;
	void get_data();
};

#endif
