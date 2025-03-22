#include "WrongDog.hpp"


WrongDog::WrongDog() : WrongAnimal() { 
	type = "WrongDog";
	std::cout << "WrongDog constructor called" << std::endl;
}

WrongDog::WrongDog( const WrongDog& src ) : WrongAnimal( src ) {
	std::cout << "WrongDog copy constructor called" << std::endl;
}

WrongDog& WrongDog::operator=( const WrongDog& src) {
	if (this != &src)
		type = src.type;
	std::cout << "WrongDog assignment operator used" << std::endl;
	return (*this);
}

WrongDog::~WrongDog() {
	std::cout << "WrongDog destructor called" << std::endl;
}

void	WrongDog::makeSound( void ) const {
	std::cout << "Fake wouaf wouaf" << std::endl;
}