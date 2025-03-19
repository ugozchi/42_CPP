#include "ClapTrap.hpp"

/*
	.   -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'   .
	|                         Constructors / Destructor                         |
	'   -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'   '
*/
ClapTrap::ClapTrap( void ) {

}

ClapTrap::ClapTrap( std::string name ) {

}

ClapTrap::ClapTrap( const ClapTrap& src ) {

}

ClapTrap::~ClapTrap() {

}

/*
	.   -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'   .
	|                          Assignment Operator                              |
	'   -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'   '
*/
ClapTrap& ClapTrap::operator=( const ClapTrap& src ) {

}


/*
	.   -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'   .
	|                            Attributs d'Instances                             |
	'   -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'   '
*/
std::string		ClapTrap::getName( void ) const { return _name; }
unsigned int	ClapTrap::getHitPoints( void ) const { return _hitPoints; }
unsigned int	ClapTrap::getEnergyPoints( void ) const { return _energy; }
unsigned int	ClapTrap::getAttackDamage( void ) const { return _damage; }

/*
	.   -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'   .
	|                           Actions Functions                               |
	'   -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'   '
*/
void	attack( const std::string& target );
void	takeDamage( unsigned int amount );
void	beRepaired( unsigned int amount );