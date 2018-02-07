#ifndef OPTIONSTUDENT_H
#define OPTIONSTUDENT_H
#include <string>
#include <iostream>
#include "student.h"

class OptionStudent: public Student {
public:
	explicit OptionStudent(const std::string& id,const std::string& fn,const std::string& ln,const int& t,const std::string& o);
	OptionStudent();
	OptionStudent(const OptionStudent& src);
	virtual ~OptionStudent();
	static size_t getCount() {
		return count_;
	}
	friend std::istream& operator>>(std::istream& is, OptionStudent& os);
	virtual void print(std::ostream& os) const override;
	virtual void display(std::ostream& os) const override;
private:
	int term_;
	std::string option_;
	static size_t count_;
};

inline std::istream& operator>>(std::istream& is, OptionStudent& os) {
	is >> (Student&)os >> os.term_ >> os.option_;
	return is;
}
#endif