#include "Zombie.hpp"

int main( void )
{
    Zombie  *z1 = newZombie("Frankenstein");
    z1->announce();

    randomChump("Solomon Grundy");
    delete z1;
}