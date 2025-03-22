#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
protected:
    std::string     _type;

public:
    Animal( void );
    Animal( std::string type );
    Animal( const Animal& src );
    Animal& operator=( const Animal& src);
    virtual ~Animal();

    std::string     getType( void ) const;
    virtual void    makeSound( void ) const = 0;
};

#endif