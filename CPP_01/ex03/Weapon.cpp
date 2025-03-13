#include "Weapon.hpp"

Weapon::Weapon( std::string type ) : _type( type ) {}

Weapon::~Weapon( void ) {}

const std::string&  Weapon::getType( void ) const {
    return (_type);
}

void                Weapon::setType( std::string new_value ) {
    _type = new_value;
}