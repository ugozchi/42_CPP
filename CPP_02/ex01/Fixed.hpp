#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
private:
    int                 _rawBits;
    static const int    _fractionalBits = 8;

public:
    Fixed();
    Fixed( const int in );
    Fixed( const float fl );
    Fixed( const Fixed& src );
	Fixed& operator=( const Fixed& src);
    ~Fixed();

    int     getRawBits( void ) const;
    void    setRawBits( int const raw );
    float   toFloat( void ) const;
    int     toInt( void ) const;
};

#endif