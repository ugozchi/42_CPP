#include "Fixed.hpp"
#include <iostream>
#include <cmath>

/*
	.   -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'   .
	|                         Constructors / Destructor                         |
	'   -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'   '
*/
Fixed::Fixed() : _rawBits( 0 ) {}

Fixed::Fixed( const int in ) : _rawBits( in << _fractionalBits ) {}

Fixed::Fixed( const float fl ) : _rawBits( roundf(fl * (1 << _fractionalBits))) {}

Fixed::Fixed( const Fixed& src ) {
    _rawBits = src.getRawBits();
}

Fixed::~Fixed() {}


/*
	.   -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'   .
	|                          Assignment Operator                              |
	'   -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'   '
*/
Fixed& Fixed::operator=( const Fixed& src )
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &src)
        this->_rawBits = src.getRawBits();
    return (*this);
}


/*
    .   -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'   .
    |                         Comparison Operators                              |
    '   -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'   '
*/
bool    Fixed::operator>( const Fixed& src ) const {
    return (this->getRawBits() > src.getRawBits());
}

bool    Fixed::operator<( const Fixed& src ) const {
    return (this->getRawBits() < src.getRawBits());
}

bool    Fixed::operator>=( const Fixed& src ) const {
    return (this->getRawBits() >= src.getRawBits());
}

bool    Fixed::operator<=( const Fixed& src ) const { 
    return (this->getRawBits() <= src.getRawBits());
}

bool    Fixed::operator==( const Fixed& src ) const {
    return (this->getRawBits() == src.getRawBits());
}

bool    Fixed::operator!=( const Fixed& src ) const {
    return (this->getRawBits() != src.getRawBits());
}



/*
	.   -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'   .
	|                         Artihmetic Operators                              |
	'   -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'   '
*/
Fixed   Fixed::operator+( const Fixed& src ) const {
    return (Fixed( this->toFloat() + src.toFloat() ));
}

Fixed   Fixed::operator-( const Fixed& src ) const {
    return (Fixed( this->toFloat() - src.toFloat() ));
}

Fixed   Fixed::operator*( const Fixed& src ) const {
    return (Fixed( this->toFloat() * src.toFloat() ));
}

Fixed   Fixed::operator/( const Fixed& src ) const {
    return (Fixed( this->toFloat() / src.toFloat() ));
}


/*
	.   -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'   .
	|                       (In/De)crement Operators                            |
	'   -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'   '
*/
Fixed&  Fixed::operator++( void ) {
    _rawBits++;
    return (*this);
}

Fixed&  Fixed::operator--( void ) {
    _rawBits--;
    return (*this);
}

Fixed  Fixed::operator++( int ) {
    Fixed   tmp = *this;

    _rawBits++;
    return (tmp);
}

Fixed  Fixed::operator--( int ) {
    Fixed   tmp = *this;

    _rawBits--;
    return (tmp);
}


/*
	.   -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'   .
	|                         Min and Max Operators                             |
	'   -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'   '
*/
Fixed&          Fixed::min( Fixed& a, Fixed& b ) {
    if (a.getRawBits() <= b.getRawBits())
        return (a);
    else
        return (b);
}

const Fixed&    Fixed::min( const Fixed& a, const Fixed& b ) {
    if (a.getRawBits() <= b.getRawBits())
        return (a);
    else
        return (b);
}

Fixed&          Fixed::max( Fixed& a, Fixed& b ) {
    if (a.getRawBits() >= b.getRawBits())
        return (a);
    else
        return (b);
}

const Fixed&    Fixed::max( const Fixed& a, const Fixed& b ) {
    if (a.getRawBits() >= b.getRawBits())
        return (a);
    else
        return (b);    
}

/*
	.   -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'   .
	|                           Member functions                                |
	'   -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'   '
*/
int     Fixed::getRawBits( void ) const {
    return (_rawBits);
}

void    Fixed::setRawBits( int const raw ) { 
    _rawBits = raw;
}

float   Fixed::toFloat( void ) const { return ((float)_rawBits / (1 << _fractionalBits)); }

int     Fixed::toInt( void ) const { return (_rawBits >> _fractionalBits); }


/*
	.   -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'   .
	|                           Display operator                                |
	'   -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'   '
*/

std::ostream& operator<<(std::ostream & os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return os;
}