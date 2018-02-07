#include "Triangle.h"
using namespace std;

Triangle::Triangle(istream& is) {
  is >> v1_ >> v2_ >> v3_; 
  if (!is)
    throw "Triangle::Triangle(const std::string&)";
}

void 
Triangle::draw() const {
  cerr << "[T: " << v1_ << ", " << v2_ << ", " << v3_ << "]" << endl; 
}

void Triangle::xreflect() {
	v1_.invertx();
	v2_.invertx();
	v3_.invertx();
}

void Triangle::yreflect() {
	v1_.inverty();
	v2_.inverty();
	v3_.inverty();
}

void Triangle::translate(const Point& delta) {
	v1_.translatex(delta.getx());
	v1_.translatey(delta.gety());
	v2_.translatex(delta.getx());
	v2_.translatey(delta.gety());
	v3_.translatex(delta.getx());
	v3_.translatey(delta.gety());
}

void Triangle::invert_translate(const Point& delta) {
	v1_.itranslatex(delta.getx());
	v1_.itranslatey(delta.gety());
	v2_.itranslatex(delta.getx());
	v2_.itranslatey(delta.gety());
	v3_.itranslatex(delta.getx());
	v3_.itranslatey(delta.gety());
}


