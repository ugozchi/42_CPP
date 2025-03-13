#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon& weapon ) : _name(name), _weapon(weapon) {}

HumanA::~HumanA( void ) {}

void    HumanA::attack( void ) const {
    std::cout << _name << "attacks with their " << _weapon.getType() << std::endl;
}