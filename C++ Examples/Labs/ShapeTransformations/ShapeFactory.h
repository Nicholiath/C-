#ifndef SHAPEFACTORY_H
#define SHAPEFACTORY_H
#include <iostream>
#include <string>
#include <memory>
#include "Shape.h"
#include "Circle.h"
#include "Triangle.h"

class ShapeFactory {
public:
  ShapeFactory(std::istream& is): in_(&is) {}
  std::unique_ptr<Shape> create() {
    std::string  type;

    if (!(*in_ >> type))
      return std::unique_ptr<Shape>();
    if (type == "C")
      return std::unique_ptr<Shape>(new Circle(*in_));
    if (type == "T")
      return std::unique_ptr<Shape>(new Triangle(*in_));

    return std::unique_ptr<Shape>();  // if it's not one of the valid types
  }

private:
  std::istream  *in_;  
};
#endif
