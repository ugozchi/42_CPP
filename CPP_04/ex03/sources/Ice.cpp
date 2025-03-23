#include "Ice.hpp"
#include "Character.hpp"

Ice::Ice( void ) : AMateria( "ice" ) {}

Ice::Ice( const Ice& src ) : AMateria( src ) {}

Ice& Ice::operator=( const Ice& src ) {
    if (this != &src)
        AMateria::operator=(src);
    return (*this);
}

Ice::~Ice() {}

AMateria*   Ice::clone( void ) const { return new Ice(*this); }

void Ice::use( ICharacter& target ) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}