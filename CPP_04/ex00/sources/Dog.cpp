#include "Dog.hpp"

Dog::Dog() : Animal()  { 
	_type = "Dog";
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog( const Dog& src ) : Animal( src ) {
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=( const Dog& src) {
	if (this != &src)
		_type = src._type;
	std::cout << "Dog assignment operator used" << std::endl;
	return (*this);
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
}

void	Dog::makeSound( void ) const {
	std::cout << "Wouaf Wouaf" << std::endl;
}