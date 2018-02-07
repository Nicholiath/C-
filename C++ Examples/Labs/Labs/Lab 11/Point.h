#ifndef POINT_H
#define POINT_H
#include <iostream>

// Note: you may need to add more operations for transformations
class Point {
public:
  explicit Point(int x = 0, int y = 0): x_(x), y_(y) {}

  friend std::istream& operator>>(std::istream& is, Point& pt);
  friend std::ostream& operator<<(std::ostream& os, const Point& pt); 

private:
  int x_, y_;
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
