#include "ClapTrap.hpp"

/*
	.   -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'   .
	|                         Constructors / Destructor                         |
	'   -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'   '
*/
ClapTrap::ClapTrap( void ) : _name("no_one"), _hitPoints(10), _energy(10), _damage(0) {
	std::cout << "ClapTrap default constructor called for " << _name << std::endl;
}

ClapTrap::ClapTrap( std::string name ) : _name(name), _hitPoints(10), _energy(10), _damage(0) {
	std::cout << "ClapTrap constructor called for " << _name << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap& src ) {
	_name = src._name;
	_hitPoints = src._hitPoints;
	_energy = src._energy;
	_damage = src._damage;
	std::cout << "ClapTrap copy constructor called for " << _name << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap default destructor called for " << _name << std::endl;
}

/*
	.   -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'   .
	|                          Assignment Operator                              |
	'   -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'   '
*/
ClapTrap& ClapTrap::operator=( const ClapTrap& src ) {
	if (this != &src) {
		_name = src._name;
		_hitPoints = src._hitPoints;
		_energy = src._energy;
		_damage = src._damage;
	}
	std::cout << "ClapTrap assignment operator used for " << _name << std::endl;
	return (*this);
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
void	ClapTrap::attack( const std::string& target ) {
	if (_energy && _hitPoints) {
		_energy--;
		std::cout   << "ClapTrap " << _name << " attacks " << target
					<< ", causing " << _damage << " points of damage!" << std::endl;
	}
	else if (!_energy && _hitPoints)
		std::cout << "ClapTrap " << _name << " does not have energy to attack " << target << std::endl;
	else
		std::cout << "ClapTrap " << _name << " is dead and cannot attack " << target << std::endl;

}

void	ClapTrap::takeDamage( unsigned int amount ) {
	if (_hitPoints >= amount)
	{
		std::cout << _name << " loses " << amount << " hit points" <<std::endl;
		_hitPoints -= amount;
	}
	else
	{
		std::cout << _name << " loses " << _hitPoints << " hit points" <<std::endl;
		_hitPoints = 0;
	}

	if (!_hitPoints)
		std::cout << _name << " is dead" << std::endl;
}

void	ClapTrap::beRepaired( unsigned int amount ) {
	if (_energy && _hitPoints)
	{
		_hitPoints += amount;
		_energy--;
		std::cout << _name << " repairs itself of " << amount << " points" << std::endl;
	}
	else if (!_energy)
		std::cout << _name << " has no energy to repair itself!" << std::endl;
	else
		std::cout << _name << " is dead and cannot be repaired!" << std::endl;

}