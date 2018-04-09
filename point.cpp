#include "point.h"
int Point::getX() const 
{ 
	return x; 
}
int Point::getY() const 
{ 
	return y; 
}
Point::Point( int a, int b ){
	setPoint( a, b ); 
}
void Point::setPoint( int a, int b)
{
	x = a;
	y = b;
} 
ostream &operator<<( ostream &output, const Point &p )
{
	output << "Point at ("<< p.x <<", " << p.y << ")";
	return output;  
} 
