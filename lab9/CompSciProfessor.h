#ifndef COMPSCIPROFESSOR_H_
#define COMPSCIPROFESSOR_H_

#include <string>

class CompSciProfessor {
private:
	std::string name;
	std::string email;
	long id;
public:
	CompSciProfessor();

	std::string get_name() const;
	std::string get_email() const;
	long get_id() const;

	void set_name(std::string);
	void set_email(std::string);
	void set_id(long);
};

#endif
