#ifndef ADJUNCTPROF_H_
#define ADJUNCTPROF_H_

#include "CompSciProfessor.h"

class AdjunctProf: public CompSciProfessor {
private:
	char degree; // 'B' = Bachelors, 'M' = Masters, 'P' = PhD
	int assistant_count;
	int course_count;
public:
	AdjunctProf();

	void print() const;
	float find_salary() const;

	std::string degree_name(char) const;

	char get_degree() const;
	int get_assistant_count() const;
	int get_course_count() const;

	void set_degree(char);
	void set_assistant_count(int);
	void set_course_count(int);
};

#endif
