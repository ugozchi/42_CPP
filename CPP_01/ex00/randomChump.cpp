#include "Zombie.hpp"

void    randomChump( std::string name ) {
    Zombie zOnStack(name);
    zOnStack.announce();
}