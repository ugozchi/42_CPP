#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : _rawBits( 0 ) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const int in ) : _rawBits( in << _fractionalBits ) {
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( const float fl ) : _rawBits( roundf(fl * (1 << _fractionalBits))) {
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed( const Fixed& src ) {
    std::cout << "Copy constructor called" << std::endl;
    _rawBits = src.getRawBits();
}

Fixed& Fixed::operator=( const Fixed& src )
{
    std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->_rawBits = src.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}



/*************************/

int     Fixed::getRawBits( void ) const {
    std::cout << "getRawBits member function called" << std::endl;
    return (_rawBits);
}

void    Fixed::setRawBits( int const raw ) { 
    std::cout << "setRawBits member function called" << std::endl;
    _rawBits = raw;
}

float   Fixed::toFloat( void ) const { return ((float)_rawBits / (1 << _fractionalBits)); }

int     Fixed::toInt( void ) const { return (_rawBits >> _fractionalBits); }


/*************************/

std::ostream& operator<<(std::ostream & os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return os;
}