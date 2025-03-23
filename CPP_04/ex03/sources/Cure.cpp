#include "Cure.hpp"
#include "Character.hpp"

Cure::Cure( void ) : AMateria( "cure" ) {}

Cure::Cure( const Cure& src ) : AMateria( src ) {}

Cure& Cure::operator=( const Cure& src ) {
    if (this != &src)
        AMateria::operator=(src);
    return (*this);
}

Cure::~Cure() {}

AMateria*   Cure::clone( void ) const { return new Cure(*this); }

void Cure::use( ICharacter& target ) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}