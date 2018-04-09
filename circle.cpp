
#include<iomanip>
using std::ios;
using std::setiosflags;
using std::setprecision;
#include "circle.h"
Circle::Circle( double r, int a, int b ) 
	: Point( a, b ) 
{ 
	setRadius( r ); 
} 
void Circle::setRadius( double r ) 
{ 
	radius = ( r >= 0 ? r : 0 ); 
}
double Circle::getRadius() const
{ 
	return radius;
}
double Circle::area() const
{ 
	return 3.14159 * radius * radius; 
}
ostream &operator<<( ostream &output, const Circle &c )
{
	output << "Circle with enter = "<< static_cast< Point > ( c )
	<< "; Radius = " 
	<< setiosflags( ios::fixed| ios::showpoint )
	<< setprecision(1) << c.radius
	<< "; Area = "
	<< setprecision(4) <<c.area();
	
	return output;  // enables cascaded calls
} // end operator<< function
