#ifndef CIRCLE_H
#define CIRCLE_H
#include <iostream>
using std::ostream;
#include"point.h"
class Circle : public Point {
	friend ostream &operator<<( ostream &output, const Circle & c);
	public:
		Circle( double r = 0.0, int a = 0, int b = 0 );
		void setRadius( double r);  // set radius
		double getRadius() const;  // return radius
		double area() const;  // calculate area
	protected: // accessible to derived classes
		double radius;  // radius of the Circle 
 }; // end class Circle
#endif
