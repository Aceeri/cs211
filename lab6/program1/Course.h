#ifndef COURSE_H_
#define COURSE_H_

#include <string>
using namespace std;

class Course {
private:
	long id;
	string name;
	int credits;
public:
	Course(string, string, string);
	
	long get_id() const;
	string get_name() const;
	int get_credits() const;

	void display() const;
};

#endif
