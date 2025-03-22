#include "Cat.hpp"

Cat::Cat() : Animal() { 
	_type = "Cat";
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat( const Cat& src ) : Animal( src ) {
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=( const Cat& src) {
	if (this != &src)
		_type = src._type;
	std::cout << "Cat assignment operator used" << std::endl;
	return (*this);
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
}

void	Cat::makeSound( void ) const {
	std::cout << "Meow 🐾" << std::endl;
}
