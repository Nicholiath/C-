#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <iostream>
#include <string>
#include "Shape.h"
#include "Point.h"

class Triangle: public Shape {
public:
	explicit Triangle(std::istream& is);
	virtual void draw() const override;
	virtual void translate(const Point& delta) override; 
	virtual void invert_translate(const Point& delta) override; 
	virtual void xreflect() override;
	virtual void yreflect() override;
	
private:
  Point  v1_, v2_, v3_;  // 3 vertices
};
#endif
