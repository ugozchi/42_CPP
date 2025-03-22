#include "Cat.hpp"
#include <new>

Cat::Cat() : Animal(), _brain(nullptr) {
	_type = "Cat";
	try {
		_brain = new Brain();
	} catch (const std::bad_alloc& e) {
		std::cerr << "Cat: Failed to allocate Brain: " << e.what() << std::endl;
		throw;
	}
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat& src) : Animal(src), _brain(nullptr) {
	_type = src._type;
	if (src._brain) {
		try {
			_brain = new Brain(*src._brain);
		} catch (const std::bad_alloc& e) {
			std::cerr << "Cat: Failed to copy Brain: " << e.what() << std::endl;
			throw;
		}
	}
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& src) {
	if (this != &src) {
		_type = src._type;
		if (_brain)
			delete _brain;
		if (src._brain) {
			try {
				_brain = new Brain(*src._brain);
			} catch (const std::bad_alloc& e) {
				std::cerr << "Cat: Failed to assign Brain: " << e.what() << std::endl;
				throw;
			}
		} else {
			_brain = nullptr;
		}
	}
	std::cout << "Cat assignment operator used" << std::endl;
	return *this;
}

Cat::~Cat() {
	delete _brain;
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "Meow 🐾" << std::endl;
}
