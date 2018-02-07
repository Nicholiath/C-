#include "Circle.h"
using namespace std;

Circle::Circle(istream& is) {
  is >> centre_ >> radius_; 
  if (!is)
    throw "Circle::Circle(const std::string&)";
}  

void 
Circle::draw() const {
  cerr << "[C: " << centre_ << ", " << radius_ << "]" << endl; 
} 

void Circle::translate(const Point& delta) {
	centre_.translatex(delta.getx());
	centre_.translatey(delta.gety());
}

void Circle::invert_translate(const Point& delta) {
	centre_.itranslatex(delta.getx());
	centre_.itranslatey(delta.gety());
}

void Circle::xreflect() {
	centre_.invertx();
}

void Circle::yreflect() {
	centre_.inverty();
}