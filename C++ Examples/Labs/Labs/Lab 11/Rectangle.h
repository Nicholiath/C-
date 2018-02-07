#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <iostream>
#include <string>
#include "Shape.h"
#include "Point.h"

class Rectangle: public Shape {
public:
	explicit Rectangle(std::istream& is);
	virtual void draw() const override;
	virtual void save() const;
private:
	Point  v1_, v2_;  // 2 vertices
};
#endif
