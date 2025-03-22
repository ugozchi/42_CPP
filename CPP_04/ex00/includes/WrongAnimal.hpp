#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
protected:
	std::string	type;

public:
	WrongAnimal();
	WrongAnimal( const WrongAnimal& src );
	WrongAnimal& operator=( const WrongAnimal& src);
	~WrongAnimal();
    
	std::string		getType( void ) const;
	void			makeSound( void ) const;

};

#endif