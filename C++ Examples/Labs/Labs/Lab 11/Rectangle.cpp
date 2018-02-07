#include "Rectangle.h"
#include <iostream>
#include <vector>
#include <memory>
#include <sstream>
#include "ShapeFactory.h"
#include "Shape.h"
using namespace std;

Rectangle::Rectangle(istream& is) {
	is >> v1_ >> v2_;
	if (!is) {
		throw "Rectangle::Rectangle(const std::string&)";
	}
}

void 
Rectangle::draw() const {
	cout << "[R: " << v1_ << ", " << v2_ << "]" << endl; 
}

void 
Rectangle::save(ostream& os) const {
	
}

int main(int argc, char* argv[]) {
	string line;
	vector<std::shared_ptr<Shape>>  v;
	shared_ptr<Shape>               s;
	while (1) {
		if (!getline(cin, line)) {
			cin.clear();
			break;
		}
		istringstream iss(line);
		ShapeFactory sf(iss);
		s = sf.create();
		v.push_back(s);
	}
	for (vector<std::shared_ptr<Shape>>::size_type i = 0, sz = v.size(); 
	i < sz; i++) {
		v[i]->draw();
	}
}


