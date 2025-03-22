#include "Dog.hpp"
#include <new>

Dog::Dog() : Animal(), _brain(NULL) {
	_type = "Dog";
	try {
		_brain = new Brain();
	} catch (const std::bad_alloc& e) {
		std::cerr << "Dog: Failed to allocate Brain: " << e.what() << std::endl;
		throw; // laisse l'exception remonter
	}
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog& src) : Animal(src), _brain(nullptr) {
	_type = src._type;
	if (src._brain) {
		try {
			_brain = new Brain(*src._brain);
		} catch (const std::bad_alloc& e) {
			std::cerr << "Dog: Failed to copy Brain: " << e.what() << std::endl;
			throw;
		}
	}
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& src) {
	if (this != &src) {
		_type = src._type;
		if (_brain)
			delete _brain;
		if (src._brain) {
			try {
				_brain = new Brain(*src._brain);
			} catch (const std::bad_alloc& e) {
				std::cerr << "Dog: Failed to assign Brain: " << e.what() << std::endl;
				throw;
			}
		} else {
			_brain = nullptr;
		}
	}
	std::cout << "Dog assignment operator used" << std::endl;
	return *this;
}

Dog::~Dog() {
	delete _brain;
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "Wouaf Wouaf" << std::endl;
}
