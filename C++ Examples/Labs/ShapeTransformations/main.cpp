// an sample program showing how to use a ShapeFactory
#include <iostream>
#include <vector>
#include <memory>
#include <fstream>
#include "ShapeFactory.h"
#include "Shape.h"
#include "Command.h"
#include "DrawApp.h"
/// 'Undefined reference' without including these:
#include "Command.cpp"
#include "DrawApp.cpp"
#include "Circle.cpp"
#include "Triangle.cpp"
using namespace std;

int main(int argc, char* argv[]) {
	/*vector<std::shared_ptr<Shape>>  v;
	shared_ptr<Shape>               s;
	ShapeFactory                    sf(cin);*/
	shared_ptr<Shape> s;
	fstream data(argv[1]);
	ShapeFactory sf(data);
	DrawApp drawApp;
	while ((s = sf.create())) {
		drawApp.addShape(s);
		//v.push_back(s);
	}
	drawApp.run();
	/*for (vector<std::shared_ptr<Shape>>::size_type i = 0, sz = v.size(); i < sz; i++) {
		v[i]->draw();
	}*/
}
