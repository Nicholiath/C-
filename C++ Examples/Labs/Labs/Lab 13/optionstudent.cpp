#include "optionstudent.h"

using namespace std;

size_t OptionStudent::count_ = 0;

OptionStudent::OptionStudent(const string& id,const string& first,const string& last,const int& t,const string& o) : Student(id, first, last), term_(t), option_(o) {
	count_++;
}

OptionStudent::OptionStudent(const OptionStudent& src)
: Student(src), term_(src.term_), option_(src.option_) {
	count_++;
}

OptionStudent::~OptionStudent() {
	count_--;
}

void OptionStudent::display(ostream& os) const {
	Student::display(os);
	os << "Term: " << term_ << "\r\n";
	os << "Option: " << option_ << "\r\n";
}

void OptionStudent::print(ostream& os) const {
	Student::print(os);
	os << term_ << ' ' << option_ << ' ' << "\r\n";
}