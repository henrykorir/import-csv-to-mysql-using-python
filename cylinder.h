
#ifndef CYLINDER_H
#define CYLINDER_H
#include <iostream>
using std::ostream;
#include "circle.h"
class Cylinder : public Circle {
	friend ostream &operator<<( ostream &output, const Cylinder & c);
	public:
		Cylinder( double h = 0.0, double r = 0.0, int x = 0, int y = 0);
		void setHeight( double h);
		double getHeight() const;  
		double area() const;  
		double volume() const;  
	protected: 
		double height;  
}; 
#endif
