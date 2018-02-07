#ifndef CIRCLE_H
#define CIRCLE_H
#include <iostream>
#include <string>
#include "Shape.h"
#include "Point.h"

class Circle: public Shape {
public:
	explicit Circle(std::istream& is);
	virtual void draw() const override; 
	virtual void translate(const Point& delta) override;
	virtual void invert_translate(const Point& delta) override;
	virtual void xreflect() override;
	virtual void yreflect() override;
private:
  Point  centre_;
  int    radius_;
};
#endif
