#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>
#include <limits.h>

class Fixed
{
private:
    int                 _rawBits;
    static const int    _fractionalBits = 8;

public:
    /*Constructors & Destructor*/
    Fixed();
    Fixed( const int in );
    Fixed( const float fl );
    Fixed( const Fixed& src );
    ~Fixed();
    
    /*Assignment Operator*/
	Fixed&  operator=( const Fixed& src );

    /*Comparison Operators*/
    bool                operator>( const Fixed& src ) const;
    bool                operator<( const Fixed& src ) const;
    bool                operator>=( const Fixed& src ) const;
    bool                operator<=( const Fixed& src ) const;
    bool                operator==( const Fixed& src ) const;
    bool                operator!=( const Fixed& src ) const;

    /*Artihmetic Operators*/
    Fixed               operator+( const Fixed& src ) const;
    Fixed               operator-( const Fixed& src ) const;
    Fixed               operator*( const Fixed& src ) const;
    Fixed               operator/( const Fixed& src ) const;

    /*(In/De)crement Operators*/
    Fixed&              operator++( void );
    Fixed&              operator--( void );
    Fixed               operator++( int );
    Fixed               operator--( int );

    /*Min and Max Operators*/
    static Fixed&       min( Fixed& a, Fixed& b );
    static const Fixed& min( const Fixed& a, const Fixed& b);
    static Fixed&       max( Fixed& a, Fixed& b );
    static const Fixed& max( const Fixed& a, const Fixed& b);

    /*Member functions*/
    int                 getRawBits( void ) const;
    void                setRawBits( int const raw );
    float               toFloat( void ) const;
    int                 toInt( void ) const;
};

/*Display operator*/
std::ostream& operator<<(std::ostream & os, const Fixed& fixed);

#endif