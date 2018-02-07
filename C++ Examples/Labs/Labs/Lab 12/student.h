#include <iostream>
#include <sstream>
#include <cstring>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <map>
#include <cstdio>
typedef std::pair<std::string, std::string> Name;
using namespace std;
class Student {
public:
	explicit Student(const string& id, const string& first, const string& last);
	Student() {}
	Student(const Student& src);
	virtual ~Student() {};
 	friend std::ostream& operator<<(std::ostream& os, const Student& s);
 	friend std::istream& operator>>(std::istream& is, Student& s);
 	friend bool operator<(const Student& s1, const Student& s2);

private:
	std::string id_;
	Name name_;
	
	static bool isValidId(const std::string& id);
	static bool isValidName(const Name& name);
};

inline std::ostream& operator<<(std::ostream& os, const Student& s)
{
	os << s.id_ << ' ' <<  s.name_.first << ' ' <<  s.name_.second;
	return os;
}

inline std::istream& operator>>(std::istream& is, Student& s)
{
	is >> s.id_ >> s.name_.first >> s.name_.second;
	return is;
}
 inline bool operator<(const Student& s1, const Student& s2)
 {
 	return s1.id_ < s2.id_;
 }