#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
    std::string     _name;

public:
    DiamondTrap( void );
    DiamondTrap( std::string name );
    DiamondTrap( const DiamondTrap& src );
    ~DiamondTrap();

    DiamondTrap& operator=( const DiamondTrap& src );

    using   ScavTrap::attack;
    void    whoAmI( void );
};

#endif