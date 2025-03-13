#include "Zombie.hpp"

Zombie::Zombie( const std::string &name ) : _name( name ) {
    std::cout << _name << ": created" << std::endl;
}

Zombie::~Zombie( void ) {
    std::cout << _name << ": destroyed" << std::endl;
}

void    Zombie::announce( void ) const {
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}