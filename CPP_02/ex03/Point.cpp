#include "Point.hpp"


/*
	.   -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'   .
	|             Constructors / Assignement Operator / Destructor              |
	'   -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'   '
*/
Point::Point( void ) : _x( Fixed(0) ), _y( Fixed(0) ) {};

Point::Point( const float x, const float y ) : _x( Fixed(x) ), _y( Fixed(y) ) {};

Point::Point( const Point& src ) : _x( src.getX() ), _y( src.getY() ) {};

Point&  Point::operator=( const Point& src) {
    if (this != &src) {
        ( Fixed )_x = src.getX();
        ( Fixed )_y = src.getY();
    }
    return (*this);
}

Point::~Point( void ) {};

Fixed   Point::getX( void ) const { return (_x); }

Fixed   Point::getY( void ) const { return (_y); }