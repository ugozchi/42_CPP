#ifndef WRONGDOG_HPP
# define WRONGDOG_HPP

#include "WrongAnimal.hpp"

class WrongDog : public WrongAnimal
{
public:
	void	makeSound( void ) const;

	WrongDog();
	WrongDog( const WrongDog& src );
	WrongDog& operator=( const WrongDog& src );
	~WrongDog();
};

#endif