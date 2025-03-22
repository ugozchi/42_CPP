#include "WrongCat.hpp"


WrongCat::WrongCat() : WrongAnimal() { 
	type = "WrongCat";
	std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat( const WrongCat& src ) : WrongAnimal( src ) {
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator=( const WrongCat& src) {
	if (this != &src)
		type = src.type;
	std::cout << "WrongCat assignment operator used" << std::endl;
	return (*this);
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called" << std::endl;
}

void	WrongCat::makeSound( void ) const {
	std::cout << "Fake meow 🐾" << std::endl;
}