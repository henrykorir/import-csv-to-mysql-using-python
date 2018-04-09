#include<iomanip>
using std::ios;
using std::setiosflags;
using std::setprecision;
#include "cylinder.h"
Cylinder::Cylinder( double h, double r, int x, int y )
	: Circle( r, x, y )  
{ 
	setHeight( h );
}
void Cylinder::setHeight( double h ) 
{ 
	height = ( h >= 0 ? h : 0 ); 
}
double Cylinder::getHeight() const 
{ 
	return height; 
}
double Cylinder::area() const
{
	return ((2 * Circle::area()) + (2 *3.14159* radius * height));
} 
double Cylinder::volume() const
{ 
	return Circle::area() * height; 
}
ostream &operator<<( ostream &output, const Cylinder &c )
{
	output << static_cast< Circle >( c )
	<< "; Height = " << c.height
	<< "; Volume = " 
	<< setiosflags( ios::fixed| ios::showpoint )
	<< setprecision(1)
	<<c.volume();
	return output;  
} 
