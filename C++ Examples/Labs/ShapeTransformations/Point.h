#ifndef POINT_H
#define POINT_H
#include <iostream>

// Note: you may need to add more operations for transformations
class Point {
public:
	explicit Point(int x = 0, int y = 0): x_(x), y_(y) {}
	void invertx() {
		y_ *= -1;
	}
	void inverty() {
		x_ *= -1;
	}
	void translatex(int deltax) {
		x_ += deltax;
	}
	void translatey(int deltay) {
		y_ += deltay;
	} 
	int getx() const {
		return x_;
	}
	int gety() const {
		return y_;
	}
	void itranslatex(int deltax) {
		x_ += deltax * -1;
	}
	void itranslatey(int deltay) {
		y_ += deltay * -1;
	}
	friend std::istream& operator>>(std::istream& is, Point& pt);
	friend std::ostream& operator<<(std::ostream& os, const Point& pt); 

private:
  int x_=0, y_=0;
};

// reads input points of the form (x, y)
inline std::istream&
operator>>(std::istream& is, Point& pt) {
  char  c1, c2, c3;
  int   x, y;

  is >> c1 >> x >> c2 >> y >> c3;
  if (is && c1 == '(' && c2 == ',' && c3 == ')')
    pt.x_ = x, pt.y_ = y;
  else
    is.setstate(std::ios_base::failbit);
  return is;
}

inline std::ostream& 
operator<<(std::ostream& os, const Point& pt) {
  os << '(' << pt.x_ << ',' << pt.y_ << ')';
  return os;
} 
#endif
