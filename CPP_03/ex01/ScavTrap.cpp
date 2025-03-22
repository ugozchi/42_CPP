#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void ) : ClapTrap() {
	std::cout << "ScavTrap default constructor called for " << _name << std::endl;
	_hitPoints = 100;
	_energy = 50;
	_damage = 20;
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap( name ) {
	std::cout << "ScavTrap constructor called for " << _name << std::endl;
	_hitPoints = 100;
	_energy = 50;
	_damage = 20;
}

ScavTrap::ScavTrap( const ScavTrap& src ) : ClapTrap( src ){
	std::cout << "ScavTrap copy constructor called for " << _name << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap default destructor called for " << _name << std::endl;
}

ScavTrap&	ScavTrap::operator=( const ScavTrap& src ) {
	if (this != &src)
	{
		static_cast<ClapTrap&>(*this) = src;
		std::cout << "ScavTrap assignment operator used for " << _name << std::endl;
    }
    return (*this);
}

void	ScavTrap::attack( const std::string& target ) {
	if (_energy && _hitPoints)
	{
		_energy--;
		std::cout << "ScavTrap " << _name << " attacks " << target;
		std::cout << ", causing " << _damage << " points of damage!" << std::endl;
	}
	else if (!_energy && _hitPoints)
		std::cout << "ScavTrap " << _name << " does not have energy to attack " << target << std::endl;
	else
		std::cout << "ScavTrap " << _name << " is dead and cannot attack " << target << std::endl;
}

void	ScavTrap::guardGate( void ) {
	std::cout << "ScavTrap " << _name << " is now in Gate keeper mode" << std::endl;
}