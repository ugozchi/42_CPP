#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain*	_brain;

public:
    Cat( void );
    Cat( const Cat& src );
    Cat&    operator=( const Cat& src );
    ~Cat();

    void        makeSound( void ) const;
};

#endif