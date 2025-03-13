#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie
{
private:
        std::string _name;

public:
    Zombie();
    // Zombie( const std::string &name );
    ~Zombie();
    void    announce(void) const;
    void    setName( std::string name );

};

Zombie* zombieHorde( int N, std::string name );

#endif