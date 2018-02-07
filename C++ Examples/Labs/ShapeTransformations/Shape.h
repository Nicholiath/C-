#ifndef SHAPE_H
#define SHAPE_H
#include "Point.h"

class Shape {  // ABC
public:
  virtual ~Shape() {}
  virtual void draw() const = 0;

	/* this section is "commented" out so that the sample main program compiles;
	 you need to remove the #if 0/#endif for your final program */

	/*** transformations ***/

	// translate by amount delta, e.g. if delta is (1,2), the point (3,4)
	// is transformed to (4,6)
	virtual void translate(const Point& delta) = 0;
	/// un executes a translation
	virtual void invert_translate(const Point& delta) = 0;
	// reflection about x-axis, e.g. (1,2) -> (1,-2)
	virtual void xreflect() = 0;

	// reflection about y-axis, e.g. (1,2) -> (-1,2)
	virtual void yreflect() = 0;

};
#endif
