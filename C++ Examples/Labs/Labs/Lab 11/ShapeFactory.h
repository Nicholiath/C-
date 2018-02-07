#ifndef SHAPEFACTORY_H
#define SHAPEFACTORY_H
#include <iostream>
#include <string>
#include <memory>
#include "Shape.h"
#include "Rectangle.h"

class ShapeFactory {
public:
	ShapeFactory(std::istream& is): in_(&is) {}
	std::unique_ptr<Shape> create() {
		return std::unique_ptr<Shape>(new Rectangle(*in_));
	}
private:
  std::istream  *in_;  
};
#endif
