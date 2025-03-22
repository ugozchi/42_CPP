#include "Brain.hpp"


Brain::Brain() : _index( 0 ) {
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain( const Brain& src ) {
	for (size_t i = 0; i < 100; i++)
			_ideas[i] = src._ideas[i];
	std::cout << "Brain copy constructor called" << std::endl;
}

Brain& Brain::operator=( const Brain &src ) {
	if (this != &src) {
		for (size_t i = 0; i < 100; i++)
			_ideas[i] = src._ideas[i];
	}
	std::cout << "Brain assignment operator used" << std::endl;
	return (*this);
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}

std::string	Brain::getIdea( size_t index ) const { return _ideas[index]; }
void		Brain::setIdea( std::string idea ) { _ideas[_index++] = idea; }