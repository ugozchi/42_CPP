#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain*	_brain;
    
public:
    Dog( void );
    Dog( const Dog& src );
    Dog& operator=( const Dog& src );
    ~Dog();

    void        makeSound( void ) const;
};

#endif