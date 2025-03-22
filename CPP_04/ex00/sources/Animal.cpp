#include "Animal.hpp"

Animal::Animal( void ) : _type( "Animal" ) {
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal( std::string type ) : _type(type) {
    std::cout << "Animal constructor called for " << _type << std::endl;
}

Animal::Animal( const Animal& src ) : _type(src._type) {
    std::cout << "Animal copy constructor called" << std::endl;
}

Animal& Animal::operator=( const Animal& src ) {
    if (this!=&src)
        _type = src._type;
    std::cout << "Animal assignment operator used" << std::endl;
    return (*this);
}

Animal::~Animal() {
    std::cout << "Animal destructor called" << std::endl;
}

std::string		Animal::getType( void ) const { return _type; }

void	Animal::makeSound( void ) const {
	std::cout << "Unknown sound" << std::endl;
}