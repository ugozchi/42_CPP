#include "Fixed.hpp"

Fixed::Fixed() : _rawBits( 0 ) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const int in ) : _rawBits( in << _fractionalBits ) {
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( const float fl ) {

}

Fixed::Fixed( const Fixed& src ) {
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
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

int     Fixed::getRawBits( void ) const {
    std::cout << "getRawBits member function called" << std::endl;
    return (_rawBits);
}

void    Fixed::setRawBits( int const raw ) { 
    std::cout << "setRawBits member function called" << std::endl;
    _rawBits = raw;
}