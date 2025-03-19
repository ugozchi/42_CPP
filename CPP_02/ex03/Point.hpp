#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
private:
    const Fixed     _x;
    const Fixed     _y;

public:
    Point();
    Point( const float x, const float y );
    Point( const Point& src );
    Point&	operator=( const Point& src );
    ~Point();

    Fixed   getX( void ) const;
    Fixed   getY( void ) const;
};

#endif