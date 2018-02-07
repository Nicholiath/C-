#include <iostream>
#include <sstream>
#include <cstring>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <map>
#include <cstdio>
#include "student.h"
using namespace std;

bool Student::isValidId(const string& id) {
	if(id.length() == 9) {
		if(id[0] == 'a' || id[0] == 'A')
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}
bool Student::isValidName( const Name& name ) {
	if (name.first != "") {
		for(string::size_type i = 0; i < name.first.length(); i++) {
			if(name.first[i] == ' ')
			{
				return false;
			}
		}
	} else {
		return false;
	}
	if (name.second != "") {
		for(string::size_type i = 0; i < name.second.length(); i++) {
			if(name.second[i] == ' ') {
				return false;
			}
		}
	} else {
		return false;
	}
	return true;
}


Student::Student(const string& id, const string& first, const string& last) : id_(id), name_(make_pair(first, last)) {
	
	if (!isValidId(id_)) {
		
		throw "Invalid ID";
	}
	if (!isValidName(name_)) {
		throw "Invalid name";
	}
}

void Student::display(ostream& os) const {
	os << "ID:" << id_ << "\r\n";
	os << "Name: " << name_.first << ' ' << name_.second << "\r\n";
}

void Student::print(ostream& os) const {
	os << id_ << ' ' << name_.first << ' ' << name_.second;
}

Student::Student(const Student& src) {}