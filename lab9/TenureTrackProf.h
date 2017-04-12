#ifndef TENURETRACKPROF_H_
#define TENURETRACKPROF_H_

#include "CompSciProfessor.h"

class TenureTrackProf: public CompSciProfessor {
private:
	char rank; // 'A' = assistant, 'S' = associate, 'F' = full
	int years_experience;
public:
	TenureTrackProf();

	std::string rank_name(char) const;

	void print() const;
	float find_salary() const;

	char get_rank() const;
	int get_years_experience() const;

	void set_rank(char);
	void set_years_experience(int);

};

#endif
