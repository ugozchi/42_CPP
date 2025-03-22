#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain
{
private:
    std::string     _ideas[100];
    size_t          _index;

public:
	Brain();
	Brain( const Brain& src );
	Brain& operator=( const Brain &src );
	~Brain();

    std::string	getIdea( size_t index ) const;
	void		setIdea( std::string idea );
};

#endif