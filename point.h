
#ifndef POINT_H
#define POINT_H
#include<iostream>
using std::ostream;
class Point {
	friend ostream &operator<<( ostream &, const Point & );
	public:
		Point( int a = 0, int b = 0 );  // default constructor
		void setPoint( int a, int b);  // set coordinates
		int getX() const; 
		int getY() const; 
	protected:  // accessible to derived classes
		int x, y; 
};
#endif
